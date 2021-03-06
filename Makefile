# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 13:55:08 by jrossett          #+#    #+#              #
#    Updated: 2022/02/14 10:13:19 by jrossett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c pipex_path.c \

OBJS = ${SRCS:.c=.o}

NAME = pipex

${NAME}: ${OBJS}
		${MAKE} -s all -C libft
		${CC} ${CFLAGS} ${OBJS} libft/libft.a -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS}
	${MAKE} -s clean -C libft
	
fclean: clean
		rm -f ${NAME}
		${MAKE} -s fclean -C libft

re: fclean all

.PHONY: all re clean fclean