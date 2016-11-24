# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 19:58:53 by agrumbac          #+#    #+#              #
#    Updated: 2016/11/24 20:33:51 by agrumbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ./main.c

LIBFT = libft.a

SRCO = $(SRC:.c=.o)

SRCH = fillit.h libft.h

SRCGH = $(SRCH:.h=.h.gch)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all:${NAME}

${NAME}:
	@echo " ______ _____ _      _      _____ _______"
	@echo "|  ____|_   _| |    | |    |_   _|__   __|"
	@echo "| |__    | | | |    | |      | |    | |"
	@echo "|  __|   | | | |    | |      | |    | |"
	@echo "| |     _| |_| |____| |____ _| |_   | |"
	@echo "|_|    |_____|______|______|_____|  |_|"
	@${CC} -I ${SRCH} -c ${SRC} ${CFLAGS}
	@${CC} ${SRCO} -o ${NAME} ${LIBFT}

.PHONY: clean fclean

clean:
	@rm -f ${SRCO}
	@rm -f ${SRCGH}

fclean: clean
	@rm -f ${NAME}

re: fclean all
