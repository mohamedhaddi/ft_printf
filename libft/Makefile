# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddi <mhaddi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 22:25:27 by mhaddi            #+#    #+#              #
#    Updated: 2020/02/28 23:31:21 by mhaddi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
SRC = ft_putnstr_fd.c ft_plen.c ft_putptr_fd.c ft_puthex_fd.c ft_putui_fd.c ft_ulen.c ft_xlen.c ft_atoi.c ft_iswhitespace.c ft_putnbr_fd.c ft_strncmp.c ft_bzero.c ft_itoa.c ft_putstr_fd.c ft_strnstr.c ft_calloc.c ft_memccpy.c ft_split.c ft_strrchr.c ft_isalnum.c ft_memchr.c ft_strchr.c ft_strtrim.c ft_isalpha.c ft_memcmp.c ft_strdup.c ft_substr.c ft_isascii.c ft_memcpy.c ft_strjoin.c ft_tolower.c ft_isdigit.c ft_memmove.c ft_strlcat.c ft_toupper.c ft_islower.c ft_memset.c ft_strlcpy.c ft_isprint.c ft_putchar_fd.c ft_strlen.c ft_isupper.c ft_putendl_fd.c ft_strmapi.c
OBJ = ft_putnstr_fd.o ft_plen.o ft_putptr_fd.o ft_puthex_fd.o ft_putui_fd.o ft_ulen.o ft_xlen.o ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_islower.o ft_isprint.o ft_isupper.o ft_iswhitespace.o ft_itoa.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_split.o ft_strchr.o ft_strdup.o ft_strjoin.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strmapi.o ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o

all: $(NAME)

$(NAME): $(SRC)
	gcc $(CFLAGS) -c $^
	ar rcs $@ $(OBJ)

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
