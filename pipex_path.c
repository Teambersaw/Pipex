/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:01:33 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/06 23:40:33 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_fork(int fd1, int fd2, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;

	if (pipe(fd) < 0)
		return (perror("Pipe"));
	pid = fork();
	if (pid < 0)
		return (perror("Fork"));
	if (pid == 0) // child
	{
		close(fd[0]);
		if (dup2(fd1, STDIN_FILENO) == -1)
			return (perror("Dup2"));
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			return (perror("Dup2"));
		if (ft_execute(av[2], envp) == -1)
			return (perror("Execve"));
		close(fd[1]);
	}
	wait(NULL);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("Fork"));
	if (pid2 == 0) // child
	{
		close(fd[1]);
		if (dup2(fd2, STDOUT_FILENO) == -1)
			return (perror("Dup2"));
		if (dup2(fd[0], STDIN_FILENO) == -1)
			return (perror("Dup2"));
		if (ft_execute(av[3], envp) == -1)
			return (perror("Execve"));
		close(fd[0]);
	}
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	close(fd1);
	close(fd2);
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
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	env = ft_split(envp[i] + 5, ':');
	i = -1;
	while(env[++i])
	{
		path = ft_strjoin(env[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, X_OK | F_OK) == 0)
			return (path);
	}
	i = -1;
	free(path);
	ft_free(env);
	perror("Access");
	return (NULL);
}
