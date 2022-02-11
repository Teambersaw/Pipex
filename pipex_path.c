/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:01:33 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/11 18:49:26 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_child1(int *fd, char **av, char **envp)
{
	int	infile;

	close(fd[0]);
	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		ft_error("Open infile", infile);
	if (dup2(infile, STDIN_FILENO) == -1)
		ft_error("dup2 infile failed", infile);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error("dup2 cmd1 failed", infile);
	if (ft_execute(av[2], envp, infile) == -1)
		ft_error("command 1 not found", infile);
	close(infile);
	close(fd[1]);
	return (0);
}

int	ft_child2(int *fd, char **av, char **envp)
{
	int	outfile;

	close(fd[1]);
	outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (outfile == -1)
		ft_error("Open outfile", outfile);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		ft_error("dup2 outfile failed", outfile);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error("dup2 cmd2 failed", outfile);
	if (ft_execute(av[3], envp, outfile) == -1)
		ft_error("command 2 not found", outfile);
	close(outfile);
	close(fd[0]);
	return (0);
}

int	ft_fork(char **av, char **envp)
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
		if (ft_child1(fd, av, envp) != 0)
			return (-1);
	pid2 = fork();
	if (pid2 < 0)
		return (-1);
	if (pid2 == 0)
		if (ft_child2(fd, av, envp) != 0)
			return (-1);
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
	return (0);
}

char	*ft_norme(char **env, char *cmd)
{
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	while (env[++i])
	{
		tmp = ft_strjoin(env[i], "/");
		if (!tmp)
			return (ft_free(env, NULL));
		path = ft_strjoin(tmp, cmd);
		if (!path)
			return (ft_free(env, tmp));
		free(tmp);
		if (access(path, X_OK) == 0)
		{
			ft_free(env, NULL);
			return (path);
		}
		free(path);
	}
	return (ft_free(env, NULL));
}

char	*get_path(char **envp, char *cmd)
{
	char	*path;
	char	**env;
	int		i;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (envp[i] == NULL)
		return (NULL);
	env = ft_split(envp[i] + 5, ':');
	if (!env)
		return (NULL);
	path = ft_norme(env, cmd);
	if (path)
		return (path);
	return (NULL);
}
