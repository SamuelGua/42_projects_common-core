/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:41:30 by scely             #+#    #+#             */
/*   Updated: 2024/01/17 09:29:50 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int here_doc_2(char **av, int fd)
// {
// 	char buffer[1024];
// 	int 	lues;
// 	while(1)
// 	{
// 		if (ft_strncmp(av[1], "heredoc", ft_strlen("heredoc")) == 0)
// 			write (1, "heredoc> ", 10);
// 		lues = read(STDIN_FILENO, buffer, sizeof(buffer));
// 		if (ft_strncmp(av[2], buffer,ft_strlen(av[2])) == 0)
// 			break;
// 		write(fd, buffer, lues);
// 	}
// 	return (fd);
// }

// int main(int ac, char **av)
// {
// 	(void)ac;
//     int fd;
// 	fd = open("temp.txt", O_RDWR | O_APPEND | O_CREAT, 0777);
// 	here_doc_2(av, fd);
// 	close(fd);
// }