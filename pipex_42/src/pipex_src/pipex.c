/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:29:45 by scely             #+#    #+#             */
/*   Updated: 2024/01/17 14:15:56 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>

void	close_fd(int fd_1, int fd_2)
{
	close(fd_1);
	close(fd_2);
}

int	child_process(char **cmd, int *tunnel, char **av, char **path)
{
	int	fd_infile;

	close(tunnel[0]);
	cmd = set_execve(path, av[2]);
	if (cmd == NULL)
	{
		close(tunnel[1]);
		return (126);
	}
	fd_infile = open(av[1], O_RDONLY);
	if (fd_infile < 0)
	{
		if (cmd != NULL)
			ft_free(cmd);
		close(tunnel[1]);
		return (perror("infile error"), 1);
	}
	dup2(fd_infile, STDIN_FILENO);
	dup2(tunnel[1], STDOUT_FILENO);
	close_fd(fd_infile, tunnel[1]);
	close(fd_infile);
	execve(cmd[0], cmd, 0);
	(ft_free(path), ft_free(cmd));
	exit (-1);
}

int	main_process(char **cmd, int *tunnel, char **av, char **path)
{
	int	fd_outfile;

	close(tunnel[1]);
	cmd = set_execve(path, av[3]);
	if (cmd == NULL)
	{
		close(tunnel[0]);
		return (126);
	}
	fd_outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_outfile < 0)
	{
		if (cmd != NULL)
			ft_free(cmd);
		close(tunnel[0]);
		return (perror("outfile error "), 1);
	}
	dup2(fd_outfile, STDOUT_FILENO);
	dup2(tunnel[0], STDIN_FILENO);
	close_fd(fd_outfile, tunnel[0]);
	close(fd_outfile);
	execve(cmd[0], cmd, 0);
	(ft_free(path), ft_free(cmd));
	exit(-1);
}

int	pipex(char **av, char **path)
{
	int		tunnel[2];
	pid_t	p_pid1;
	char	**cmd;

	cmd = NULL;
	if (pipe(tunnel) == -1)
		return (1);
	p_pid1 = fork();
	if (p_pid1 == -1)
		return (perror("invalid fork "), 1);
	if (p_pid1 == 0)
		return (child_process(cmd, tunnel, av, path));
	p_pid1 = fork();
	if (p_pid1 == -1)
		return (perror("invalid fork "), 1);
	if (p_pid1 == 0)
		return (main_process(cmd, tunnel, av, path));
	ft_free(path);
	close_fd(tunnel[0], tunnel[1]);
	return (wait_childs(p_pid1));
}

int	main(int ac, char **av, char **envp)
{
	char	**path;
	int		code_err;

	path = NULL;
	if (ac != 5)
		return (ft_putstr_fd(("Wrong numbers of arguments"), 1), -1);
	if (envp[0] == NULL)
		return (ft_putstr_fd("environement unknow", 2), -1);
	path = find_path(envp);
	if (path == NULL)
		return (ft_putstr_fd("path doesn't exist", 1), -1);
	code_err = pipex(av, path);
	return (code_err);
}
