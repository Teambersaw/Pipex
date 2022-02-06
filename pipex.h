/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:05:10 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/06 23:17:45 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <fcntl.h>
#include <sys/wait.h>
# include "libft/libft.h"

char	*get_path(char **envp, char *cmd);
void	ft_free(char	**tab);
int		ft_execute(char *cmd, char **envp);
void	ft_fork(int fd1, int fd2, char **av, char **envp);

#endif