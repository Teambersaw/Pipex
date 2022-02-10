/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:04:54 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/10 19:25:50 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char	*str, int fd)
{
	if (fd > -1)
		close(fd);
	perror(str);
	exit(EXIT_FAILURE);
}

int	ft_execute(char *cmd, char **envp, int fd)
{
	char	*path;
	char	**s_cmd;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
		ft_error("Malloc failure", fd);
	path = get_path(envp, s_cmd[0]);
	if (path == NULL)
	{
		ft_free(s_cmd, NULL);
		return (-1);
	}
	if (execve(path, s_cmd, envp) == -1)
		return (-1);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	if (ac != 5)
	{
		write(2, "Wrong number of arguments\n", 26);
		return (1);
	}
	if (ft_fork(av, envp) == -1)
		ft_error("error", -1);
	return (0);
}
