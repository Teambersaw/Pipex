/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:05:10 by jrossett          #+#    #+#             */
/*   Updated: 2022/02/10 16:53:17 by jrossett         ###   ########.fr       */
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
# include <sys/wait.h>
# include "libft/libft.h"

char	*get_path(char **envp, char *cmd);
void	ft_free(char	**tab);
void	ft_error(char	*str, int fd);
int		ft_execute(char *cmd, char **envp, int fd);
int		ft_fork(char **av, char **envp);
int		ft_child1(int *fd, char **av, char **envp);
int		ft_child2(int *fd, char **av, char **envp);

#endif