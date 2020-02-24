#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "libft/libft.h"
#include "libftprintf.h"

static char	*mystrcat(char *str, char c)
{
	char *s;
	int len;
	int i = 0;

	len = strlen(str);
	s = malloc(len + 4);
	while (i < len)
	{
		s[i] = str[i];
		i++;
	}
	s[i++] = c;
	s[i++] = '.';
	s[i++] = '\n';
	s[i] = 0;
	return s;
}

void	test_ft_printf(char type, char *mainstr, int n1 , unsigned int n2, char c)
{
	printf("Result:\n");
	if (type == 'd' || type == 'i')
		ft_printf(mainstr, n1);
	else if (type == 'u' || type == 'x' || type == 'X')
		ft_printf(mainstr, n2);
	else if (type == 'c')
		ft_printf(mainstr, c);
	write(1, "\n", 1);
}

void	test_printf(char type, char *mainstr, int n1 , unsigned int n2, char c)
{
	printf("Result:\n");
	if (type == 'd' || type == 'i')
		printf(mainstr, n1);
	else if (type == 'u' || type == 'x' || type == 'X')
		printf(mainstr, n2);
	else if (type == 'c')
		printf(mainstr, c);
	write(1, "\n", 1);
}

void check(char type, char *mainstr, int n1, unsigned int n2, char c, char *which_printf)
{
	printf("Test:\n%s", mainstr);
	if (type == 'd' || type == 'i')
		printf("With arg:\nint n = %d\n", n1);
	else if (type == 'u' || type == 'x' || type == 'X')
		printf("With arg:\nunsigned int n = %u\n", n2);
	else if (type == 'c')
		printf("With arg:\nchar c = %c\n", c);
	if (strcmp(which_printf, "ft_printf"))
		test_ft_printf(type, mainstr, n1, n2, c);
	else if (strcmp(which_printf, "og_printf"))
		test_printf(type, mainstr, n1, n2, c);
}

int	main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	char *type = "diuxXcps";
	int n1[5] = {0, 1, -1, -2147483648, 2147483647};
	unsigned int n2[5] = {0, 1, 2, 16, 4294967295};
	char c[5] = {'c', '%', '\\', '/', '*'};

	setvbuf(stdout, NULL, _IONBF, 0);
	if (argc == 3)
	{
		while (i < 8)
		{
			if (*argv[1] == type[i])
				break;
			i++;
		}
		while (j < 5)
		{
			check(type[i], mystrcat("this is just a %", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %-", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %0", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %.", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %-.", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %.-", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %0-.", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %0.-", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %.0-", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %.-0", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %.-5", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %.-1", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %-.5", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %-.1", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %.5", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %.1", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %5.", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %1.", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %-5.", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %-1.", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %-5", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %-1", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %5", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %1", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %05", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %01", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %20.50", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %-20.50", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %020.50", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %20.-50", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %-20.-50", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %020.-50", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %50.20", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %-50.20", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %050.20", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %50.-20", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %-50.-20", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %050.-20", type[i]), n1[j], n2[j], c[j], argv[2]);
			check(type[i], mystrcat("this is just a %-0--00-30--300-0-...-50-3", type[i]), n1[j], n2[j], c[j], argv[2]);
			j++;
		}
	}
	return 0;
}
