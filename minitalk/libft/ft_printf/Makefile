# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpico-co <gpico-co@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 11:18:11 by gpico-co          #+#    #+#              #
#    Updated: 2024/10/15 11:18:13 by gpico-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Werror -Wall -Wextra -g
LIBFTDIR = ../
LIBFT = $(LIBFTDIR)libft.a
RM = rm -f

LIBFT_OBJS = $(addprefix $(LIBFTDIR), \
	ft_itoa.o \
	ft_strchr.o \
	ft_strdup.o \
	ft_strjoin.o \
	ft_strmapi.o \
	ft_strnstr.o \
	ft_strrchr.o \
	ft_substr.o \
	ft_split.o \
	ft_atoi.o \
	ft_isalnum.o \
	ft_isalpha.o \
	ft_isascii.o \
	ft_isdigit.o \
	ft_isprint.o \
	ft_isspace.o \
	ft_isvalidsign.o \
	ft_memcmp.o \
	ft_tolower.o \
	ft_toupper.o \
	ft_strncmp.o \
	ft_strlcat.o \
	ft_strlcpy.o \
	ft_strlen.o \
	ft_bzero.o \
	ft_calloc.o \
	ft_memchr.o \
	ft_memcpy.o \
	ft_memmove.o \
	ft_memset.o \
	ft_putchar_fd.o \
	ft_putendl_fd.o \
	ft_putnbr_fd.o \
	ft_putstr_fd.o \
	ft_striteri.o \
	ft_strtrim.o \
	ft_free.o \
	get_next_line.o)

SRCS = srcs/ft_printf.c \
       srcs/ft_printf_utils.c 

OBJS = $(SRCS:.c=.o)

%.o: %.c Makefile includes/ft_printf.h
	$(CC) $(FLAGS) -Iincludes -I$(LIBFTDIR)includes -c $< -o $@

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re

