# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpico-co <gpico-co@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 16:31:16 by gpico-co          #+#    #+#              #
#    Updated: 2024/12/12 17:49:09 by gpico-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -g

SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJ_SERVER = ${SRC_SERVER:.c=.o}
OBJ_CLIENT = ${SRC_CLIENT:.c=.o}

$(NAME_SERVER): $(OBJ_SERVER)
	${CC} ${FLAGS} ${OBJ_SERVER} -o ${NAME}

$(NAME_CLIENT): $(OBJ_CLIENT)
	${CC} ${FLAGS} ${OBJ_CLIENT} -o ${NAME}

all: $(NAME_SERVER) $(NAME_CLIENT)

clean:
	${RM} ${OBJ_SERVER} ${OBJ_CLIENT} ${NAME}

fclean: clean
	${RM} ${NAME_SERVE} ${NAME_CLIENT}

re: clean all

PHONY: all clean fclean re
