/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:04:54 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/04 15:05:55 by jrossett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	char	**path;
	int		i;

	i = -1;
	(void) av;
	(void) ac;
	//if (ac != 5)
	//	return (0);
	path = get_path(envp);
	get_access(path, av[2]);
	return (0);
}
