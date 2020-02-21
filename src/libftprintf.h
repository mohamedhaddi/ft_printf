#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

typedef struct s_arg {
	int intdata;
	unsigned int uintdata;
	char *stringdata;
} t_arg;
t_arg arg;
int minusflag_found;
// int plus_found;
int zeroflag_found;
int precisiondot_found;
int precision_val;
int og_precision_val; // keeps the original mfw value, helps patching a special case
int mfwidth_val; // about "mfwidth_found": it's not a thing
				 // because if mfwidth_val > 0 : it's found
				 // but if it was = 0, it's considered as
				 // not found since 0 is default anyway:
				 // if we justified by 0 nothing will happen
int og_mfw_val; // keeps the original mfw value, helps patching a special case
int minus_right_after_dot; // helps patching a special case of 0
va_list ap;
char specifier;
char padding_char;
int arg_len; // how many digits or characters the argument has
int counter;

int	ft_printf(const char *s, ...);

#endif
