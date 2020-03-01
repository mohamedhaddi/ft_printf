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
LFT = libft/libft.a
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c initialize.c collect.c calculate.c justify.c format.c print.c predicates.c patch.c
OBJ = ft_printf.o initialize.o collect.o calculate.o justify.o format.o print.o predicates.o patch.o

all: $(NAME)

$(LFT):
	$(MAKE) -C libft/
	cp $(LFT) ./$(NAME)

$(NAME): $(LFT)
	gcc $(CFLAGS) -c $(SRC)
	ar rcs $@ $(OBJ)

clean:
	$(MAKE) -C libft/ clean
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	$(MAKE) -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
