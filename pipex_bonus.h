/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teambersaw <teambersaw@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:49:53 by teambersaw        #+#    #+#             */
/*   Updated: 2022/02/07 23:50:05 by teambersaw       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft/libft.h"

void 	ft_error(void);
void	ft_free(char	**tab);
int		ft_execute(char *cmd, char **envp);
char	*get_path(char **envp, char *cmd);
int		ft_fork(char *av, char **envp);

#endif