# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 19:58:53 by agrumbac          #+#    #+#              #
#    Updated: 2016/11/29 22:05:40 by agrumbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c checkblock.c readnstore.c fillit.c square.c

LIBFT = libft.a

SRCO = $(SRC:.c=.o)

SRCH = fillit.h libft.h

SRCGH = $(SRCH:.h=.h.gch)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: ${NAME}

${NAME}:
	@echo " ______ _____ _      _      _____ _______"
	@echo "|  ____|_   _| |    | |    |_   _|__   __|"
	@echo "| |__    | | | |    | |      | |    | |"
	@echo "|  __|   | | | |    | |      | |    | |"
	@echo "| |     _| |_| |____| |____ _| |_   | |"
	@echo "|_|    |_____|______|______|_____|  |_|\n"
	@${CC} -I ${SRCH} -c ${SRC} ${CFLAGS}
	@${CC} ${SRCO} -o ${NAME} ${LIBFT}

.PHONY: clean fclean test

clean:
	rm -f ${SRCO}
	rm -f ${SRCGH}

fclean: clean
	rm -f ${NAME}

re: fclean all

test: fclean
	${CC} ${SRC} -o ${NAME} ${LIBFT}
	rm -f ${SRCGH}
