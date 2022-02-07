/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:01:33 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/07 14:10:30 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_child1(int *fd, int fd1, char **av, char **envp)
{
	close(fd[0]);
	if (dup2(fd1, STDIN_FILENO) == -1)
		return (-1);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (-1);
	if (ft_execute(av[2], envp) == -1)
		return (-1);
	close(fd[1]);
	return (0);
}

int	ft_child2(int *fd, int fd2, char **av, char **envp)
{
	close(fd[1]);
	if (dup2(fd2, STDOUT_FILENO) == -1)
		return (-1);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		return (-1);
	if (ft_execute(av[3], envp) == -1)
		return (-1);
	close(fd[0]);
	return (0);
}

int	ft_fork(int fd1, int fd2, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;

	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
		if (ft_child1(fd, fd1, av, envp) == -1)
			return (-1);
	pid2 = fork();
	if (pid2 < 0)
		return (-1);
	if (pid2 == 0)
		if (ft_child2(fd, fd2, av, envp) == -1)
			return (-1);
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
	return (0);
}

void	ft_free(char	**tab)
{
	int	i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

char	*get_path(char **envp, char *cmd)
{
	char	**env;
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	env = ft_split(envp[i] + 5, ':');
	i = -1;
	while (env[++i])
	{
		tmp = ft_strjoin(env[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, X_OK | F_OK) == 0)
		{
			ft_free(env);
			return (path);
		}
		free(path);
	}
	i = -1;
	ft_free(env);
	return (NULL);
}
