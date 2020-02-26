#include <stdio.h>
#include <string.h>
#include "libftprintf.h"

int main(int argc, char *argv[]) {
	int asterisk1[6] = {0, -2, -40, 40, 1, 20};
	int asterisk2[6] = {0, 40, -1, 20, -40, 1};
	int n[5] = {0, 1, -1, -2147483648, 2147483647};
	char *s[5] = {"bruh", "", NULL, "s", "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"};
	int i = 0;
	int j = 0;

	if (argc == 2)
	{
		if (!strcmp(argv[1], "og_printf"))
		{
			while (i < 6)
			{
				j = 0;
				while (j < 5)
				{
					printf("this is just a %*d\n", asterisk1[i], n[j]);
					printf("this is just a %-.*d\n", asterisk1[i], n[j]);
					printf("this is just a %.*d\n", asterisk1[i], n[j]);
					printf("this is just a %*.d\n", asterisk1[i], n[j]);
					printf("this is just a %-*.d\n", asterisk1[i], n[j]);
					printf("this is just a %-*d\n", asterisk1[i], n[j]);
					printf("this is just a %0*d\n", asterisk1[i], n[j]);
					printf("this is just a %.*d\n", asterisk1[i], n[j]);

					printf("this is just a %*.*d\n", asterisk1[i], asterisk2[i], n[j]);
					printf("this is just a %-*.*d\n", asterisk1[i], asterisk2[i], n[j]);
					printf("this is just a %0*.*d\n", asterisk1[i], asterisk2[i], n[j]);

					printf("this is just a %*s\n", asterisk1[i], s[j]);
					printf("this is just a %-.*s\n", asterisk1[i], s[j]);
					printf("this is just a %.*s\n", asterisk1[i], s[j]);
					printf("this is just a %*.s\n", asterisk1[i], s[j]);
					printf("this is just a %-*.s\n", asterisk1[i], s[j]);
					printf("this is just a %-*s\n", asterisk1[i], s[j]);
					printf("this is just a %.*s\n", asterisk1[i], s[j]);

					printf("this is just a %*.*s\n", asterisk1[i], asterisk2[i], s[j]);
					printf("this is just a %-*.*s\n", asterisk1[i], asterisk2[i], s[j]);
					j++;
				}
				i++;
			}
		}
		else if (!strcmp(argv[1], "ft_printf"))
		{
			while (i < 6)
			{
				j = 0;
				while (j < 5)
				{
					ft_printf("this is just a %*d\n", asterisk1[i], n[j]);
					ft_printf("this is just a %-.*d\n", asterisk1[i], n[j]);
					ft_printf("this is just a %.*d\n", asterisk1[i], n[j]);
					ft_printf("this is just a %*.d\n", asterisk1[i], n[j]);
					ft_printf("this is just a %-*.d\n", asterisk1[i], n[j]);
					ft_printf("this is just a %-*d\n", asterisk1[i], n[j]);
					ft_printf("this is just a %0*d\n", asterisk1[i], n[j]);
					ft_printf("this is just a %.*d\n", asterisk1[i], n[j]);

					ft_printf("this is just a %*.*d\n", asterisk1[i], asterisk2[i], n[j]);
					ft_printf("this is just a %-*.*d\n", asterisk1[i], asterisk2[i], n[j]);
					ft_printf("this is just a %0*.*d\n", asterisk1[i], asterisk2[i], n[j]);

					ft_printf("this is just a %*s\n", asterisk1[i], s[j]);
					ft_printf("this is just a %-.*s\n", asterisk1[i], s[j]);
					ft_printf("this is just a %.*s\n", asterisk1[i], s[j]);
					ft_printf("this is just a %*.s\n", asterisk1[i], s[j]);
					ft_printf("this is just a %-*.s\n", asterisk1[i], s[j]);
					ft_printf("this is just a %-*s\n", asterisk1[i], s[j]);
					ft_printf("this is just a %.*s\n", asterisk1[i], s[j]);

					ft_printf("this is just a %*.*s\n", asterisk1[i], asterisk2[i], s[j]);
					ft_printf("this is just a %-*.*s\n", asterisk1[i], asterisk2[i], s[j]);
					j++;
				}
				i++;
			}
		}
	}
	return 0;
}
