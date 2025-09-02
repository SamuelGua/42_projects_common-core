/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:29:37 by scely             #+#    #+#             */
/*   Updated: 2024/01/16 16:15:51 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**add_slash(char **path)
{
	int		i;
	int		x;
	char	**path2;

	i = 0;
	x = 0;
	while (path[x])
		x++;
	path2 = malloc(sizeof(char *) * (x + 1));
	if (!path2)
		return (NULL);
	while (path[i])
	{
		path2[i] = ft_strjoin(path[i], "/");
		if (!path2)
			return (NULL);
		i++;
	}
	path2[i] = NULL;
	ft_free(path);
	return (path2);
}

char	**find_path(char **envp)
{
	char	**path;
	int		i;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
		if (!envp[i])
			return (NULL);
	}
	path = ft_split(&envp[i][5], ':');
	if (!path)
		return (NULL);
	path = add_slash(path);
	return (path);
}

char	*good_path(char **cmd, char **path)
{
	int		i;
	char	*s;

	s = NULL;
	i = 0;
	if (cmd[0] == NULL)
		return (s);
	if (access(cmd[0], X_OK) == 0)
		s = ft_strdup(cmd[0]);
	else
	{
		while (path[i])
		{
			s = ft_strjoin(path[i], cmd[0]);
			if (!path)
				return (NULL);
			if (access(s, F_OK | X_OK) == 0)
				break ;
			free(s);
			s = NULL;
			i++;
		}	
	}
	return (s);
}

char	**temp_set(char *s, char **cmd, char **temp)
{
	temp[0] = ft_strdup(s);
	if (cmd[1] == NULL)
		temp[1] = NULL;
	else
		temp[1] = ft_strdup(cmd[1]);
	temp[2] = NULL;
	free(s);
	ft_free(cmd);
	return (temp);
}

char	**set_execve(char **path, char *av)
{
	char	**cmd;
	char	**temp;
	char	*s;

	cmd = ft_split(av, 32);
	temp = malloc(sizeof(char *) * (2 + 1));
	if (!temp)
		return (NULL);
	s = good_path(cmd, path);
	ft_free(path);
	if (s == NULL)
	{
		if (cmd != NULL)
			ft_free(cmd);
		free(temp);
		return (ft_putstr_fd("command not found\n", 1), NULL);
	}
	else
		temp = temp_set(s, cmd, temp);
	return (temp);
}
