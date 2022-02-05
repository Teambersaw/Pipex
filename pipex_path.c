/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:01:33 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/05 15:20:15 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	while (env[++i])
		free(env[i]);
	free(env);
	perror("error d'access");
	return (NULL);
}
