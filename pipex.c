/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:04:54 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/11 12:39:37 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_free(char	**tab, char	*str)
{
	int	i;

	i = -1;
	if (str)
		free(str);
	if (tab)
	{
		while (tab[++i])
			free(tab[i]);
		free(tab);
	}
	return (NULL);
}

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
