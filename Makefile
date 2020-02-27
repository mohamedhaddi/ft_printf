NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c initialize.c collect.c calculate.c justify.c format.c print.c predicates.c patch.c libftprintf.h
OBJ = ft_printf.o initialize.o collect.o calculate.o justify.o format.o print.o predicates.o patch.o
# BSRC =
# BOBJ =

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

# bonus: $(BSRC)
# 	gcc $(CFLAGS) -c $^
# 	ar rcs $(NAME) $(BOBJ)
