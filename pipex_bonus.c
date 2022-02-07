/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:04:54 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/07 23:50:31 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void ft_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

int	ft_execute(char *cmd, char **envp)
{
	char	*path;
	char	**s_cmd;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(envp, s_cmd[0]);
	if (path == NULL)
	{
		ft_free(s_cmd);
		return (-1);
	}
	if (execve(path, s_cmd, envp) == -1)
		return (-1);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	int	fd1;
	int	fd2;
	int	i;

	i = 3;
	if (ac < 5)
		return (0);
	fd1 = open(av[1], O_RDONLY);
	if (fd1 == -1)
		ft_error();
	fd2 = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (fd2 == -1)
		ft_error();
	dup2(fd1, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	ft_fork(av[2], envp);
	while (i < ac - 2)
		if (ft_fork(av[i++], envp) == -1)
			ft_error();
	ft_execute(av[i], envp);
	close(fd1);
	close(fd2);
	return (0);
}