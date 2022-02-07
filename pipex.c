/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:04:54 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/07 12:05:27 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_execute(char *cmd, char **envp)
{
	char	*path;
	char	**s_cmd;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(envp, s_cmd[0]);
	if (path == NULL)
		return (-1);
	if (execve(path, s_cmd, envp) == -1)
		return (-1);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	int	fd1;
	int	fd2;

	if (ac != 5)
		return (0);
	fd1 = open(av[1], O_RDONLY);
	if (fd1 == -1)
	{
		perror("Open");
		exit(EXIT_FAILURE);
	}
	fd2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (fd2 == -1)
	{
		perror("Open");
		exit(EXIT_FAILURE);
	}
	if (ft_fork(fd1, fd2, av, envp) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	close(fd1);
	close(fd2);
	return (0);
}
