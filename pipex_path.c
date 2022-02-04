/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:01:33 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/04 15:05:54 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_access(char **path, char *cmd)
{
	char	*str;
	int		i;

	i = -1;
	cmd = ft_strjoin("/", cmd);
	while (path[++i])
	{
		str = ft_strjoin(path[i], cmd);
		if (access(str, X_OK) == 0)
			return (str);
		printf("%s\n", str);
	}
	perror("pas de path");
	return (NULL);
}

char	**get_path(char **envp)
{
	char	*env;
	char	**path;
	int		i;

	i = -1;
	while (envp[++i])
		if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
			env = envp[i];
	env += 5;
	path = ft_split(env, ':');
	return (path);
}
