#!/bin/sh

# HOW TO USE ME:
	# Run this file with the desired specifier as argument, e.g.:
	# ./check.sh d
	# ./check.sh x
	# ./check.sh c

# WARNING:
	# You may need to apply the following changes to this and main.c file:
	# 1. If you don't use libft, replace the command below:
		# gcc -Wall -Werror -Wextra main.c *.a libft/*.a
		# with just:
		# gcc -Wall -Werror -Wextra main.c *.a
		# and change main.c file accordingly by removing #include "libft/libft.h"

	# 2. If your header file isn't named "libftprintf.h", replace:
		# #include "libftprintf.h"
		# with the right name of your header file.

RED='\033[0;31m'
GRN='\033[0;32m'
NC='\033[0m'

if  [[ $1 = "d" || $1 = "i" || $1 = "u" || $1 = "x" || $1 = "X" || $1 = "c" ]]; then

	make re
	gcc -Wall -Werror -Wextra main.c *.a libft/*.a
	./a.out $1 ft_printf > ft_printf_results.txt
	./a.out $1 og_printf > printf_results.txt

	diff ft_printf_results.txt printf_results.txt > diff.txt
	printf "${RED}You have "
	cat -e diff.txt | grep "<" | wc -l | tr -d " " | tr -d "\n"
	printf " errors.${NC}\n"

	while true; do
		read -p "Do you wish to open Vim to see the differences? [y/n] " yn
		case $yn in
			[Yy]* ) vimdiff ft_printf_results.txt printf_results.txt; break;;
			[Nn]* ) exit;;
			* ) echo "Please answer yes or no.";;
		esac
	done

else
    echo "${RED}Specifier not found.${NC}"
fi
