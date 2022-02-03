# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrossett <jrossett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 13:55:08 by jrossett          #+#    #+#              #
#    Updated: 2022/02/03 14:04:45 by jrossett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c

OBJS = ${SRCS:.c=.o} 

NAME = pipex

${NAME}: ${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}
	
fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all re clean fclean