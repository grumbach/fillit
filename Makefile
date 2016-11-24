# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 19:58:53 by agrumbac          #+#    #+#              #
#    Updated: 2016/11/24 20:22:15 by agrumbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ./main.c

LIBFT = libft.a

SRCO = $(SRC:.c=.o)

SRCH = fillit.h libft.h

SRCGH = fillit.h.gch libft.h.gch

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all:${NAME}

${NAME}:
	${CC} -I ${SRCH} -c ${SRC} ${CFLAGS}
	${CC} ${SRCO} -o ${NAME} ${LIBFT}

.PHONY: clean fclean

clean:
	rm -f ${SRCO}
	rm -f ${SRCGH}

fclean: clean
	rm -f ${NAME}

re: fclean all
