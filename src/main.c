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

void	test_ft_printf(char type, char *mainstr, int n1 , unsigned int n2, char c, int *p, char *s)
{
	printf("Result:\n");
	if (type == 'd' || type == 'i')
		ft_printf(mainstr, n1);
	else if (type == 'u' || type == 'x' || type == 'X')
		ft_printf(mainstr, n2);
	else if (type == 'c')
		ft_printf(mainstr, c);
	else if (type == 'p')
		ft_printf(mainstr, p);
	else if (type == 's')
		ft_printf(mainstr, s);
	else if (type == '%')
		ft_printf(mainstr);
	write(1, "\n", 1);
}

void	test_printf(char type, char *mainstr, int n1 , unsigned int n2, char c, int *p, char *s)
{
	printf("Result:\n");
	if (type == 'd' || type == 'i')
		printf(mainstr, n1);
	else if (type == 'u' || type == 'x' || type == 'X')
		printf(mainstr, n2);
	else if (type == 'c')
		printf(mainstr, c);
	else if (type == 'p')
		printf(mainstr, p);
	else if (type == 's')
		printf(mainstr, s);
	else if (type == '%')
		printf(mainstr, NULL);
	write(1, "\n", 1);
}

void check(char type, char *mainstr, int n1, unsigned int n2, char c, char *which_printf, int *p, char *s)
{
	printf("Test:\n%s", mainstr);
	if (type == 'd' || type == 'i')
		printf("With arg:\nint n = %d\n", n1);
	else if (type == 'u' || type == 'x' || type == 'X')
		printf("With arg:\nunsigned int n = %u\n", n2);
	else if (type == 'c')
		printf("With arg:\nchar c = %c\n", c);
	else if (type == 'p')
		printf("With arg:\nint *p = %p\n", p);
	else if (type == 's')
		printf("With arg:\nchar *s = %s\n", s);
	else if (type == '%')
		printf("With arg:\nNo arg.\n");

	if (strcmp(which_printf, "ft_printf"))
		test_ft_printf(type, mainstr, n1, n2, c, p, s);
	else if (strcmp(which_printf, "og_printf"))
		test_printf(type, mainstr, n1, n2, c, p, s);
}

int	main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	int n = 5;
	char *type = "diuxXcps%";
	int n1[5] = {0, 1, -1, -2147483648, 2147483647};
	unsigned int n2[5] = {0, 1, 2, 16, 4294967295};
	char c[5] = {'c', '%', '\\', '/', '*'};
	int *p = (int *)0x7fff5f14ca48; // 0x0;
	char *s[5] = {"bruh", "", NULL, "s", "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"};

	setvbuf(stdout, NULL, _IONBF, 0);
	if (argc == 3)
	{
		while (i < 8)
		{
			if (*argv[1] == type[i])
				break;
			i++;
		}
		n = (type[i] == 'p') ? 1 : 5;
		while (j < n)
		{
			check(type[i], mystrcat("this is just a %", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %-", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %0", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %.", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %-.", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %.-", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %0-.", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %0.-", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %.0-", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %.-0", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %.-5", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %.-1", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %-.5", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %-.1", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %.5", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %.1", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %5.", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %1.", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %-5.", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %-1.", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %-5", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %-1", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %5", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %1", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %05", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %01", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %50", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %-50", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %050", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %-050", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %0-50", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %.50", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %.-50", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %.50-", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %.050", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %.-050", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %.0-50", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %20.50", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %-20.50", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %020.50", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %20.-50", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %-20.-50", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %020.-50", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %50.20", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %-50.20", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %050.20", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %50.-20", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %-50.-20", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %050.-20", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			check(type[i], mystrcat("this is just a %-0--00-30--300-0-...-50-3", type[i]), n1[j], n2[j], c[j], argv[2], p, s[j]);
			j++;
		}
	}
	return 0;
}
