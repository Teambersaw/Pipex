/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:04:54 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/05 15:20:02 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	char	*path;

	(void) av;
	(void) ac;
	//if (ac != 5)
	//	return (0);
	path = get_path(envp, av[2]);
	if (!path)
		return (0);
	if (execve(path, &av[2], envp) == -1)
		perror("error d'execve");
	return (0);
}
