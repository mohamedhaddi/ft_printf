# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/28 23:33:17 by mhaddi            #+#    #+#              #
#    Updated: 2020/02/28 23:33:19 by mhaddi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c initialize.c collect.c calculate.c justify.c format.c print.c predicates.c patch.c libftprintf.h
OBJ = ft_printf.o initialize.o collect.o calculate.o justify.o format.o print.o predicates.o patch.o

all: $(NAME)

$(NAME): $(SRC)
	(cd libft; make)
	gcc $(CFLAGS) -c $^
	ar rcs $@ $(OBJ)

clean:
	(cd libft; make clean)
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	(cd libft; make fclean)
	rm -f $(NAME)

re: fclean all

