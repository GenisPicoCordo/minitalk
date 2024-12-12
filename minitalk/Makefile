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

# Nombres de los ejecutables
NAME_SERVER = server
NAME_CLIENT = client

# Configuración del compilador
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

# Directorios de librerías y includes
LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)/libft.a
PRINTFDIR = libft/ft_printf/
PRINTF = $(PRINTFDIR)/libftprintf.a
INCLUDES = includes/

# Archivos fuente y objetos
SRC_SERVER = server.c
SRC_CLIENT = client.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

# Reglas principales
all: $(LIBFT) $(PRINTF) $(NAME_SERVER) $(NAME_CLIENT)

%.o: %.c Makefile $(INCLUDES)minitalk.h $(LIBFTDIR)libft.h $(PRINTFDIR)ft_printf.h
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIBFTDIR) -I$(PRINTFDIR) -c $< -o $@
	@echo "Compilando: $<"

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT) $(PRINTF)
	@echo "Compilando $(NAME_SERVER)..."
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) $(PRINTF) -o $(NAME_SERVER)
	@echo "$(NAME_SERVER) compilado correctamente!"

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT) $(PRINTF)
	@echo "Compilando $(NAME_CLIENT)..."
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) $(PRINTF) -o $(NAME_CLIENT)
	@echo "$(NAME_CLIENT) compilado correctamente!"

$(LIBFT):
	@echo "Compilando libft..."
	@$(MAKE) -C $(LIBFTDIR)

$(PRINTF):
	@echo "Compilando ft_printf..."
	@$(MAKE) -C $(PRINTFDIR)

# Reglas de limpieza
clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(PRINTFDIR)
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)
	@echo "Archivos objeto eliminados."

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	@$(MAKE) fclean -C $(PRINTFDIR)
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	@echo "Ejecutables eliminados."

re: fclean all

# Declaración de objetivos no generados
.PHONY: all clean fclean re
