#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

int minusflag_found;
int zeroflag_found;
int precisiondot_found;
int precision_val;
int mfwidth_val; // about "mfwidth_found": it's not a thing
				 // because if mfwidth_val > 0 : it's found
				 // but if it was = 0, it's considered as
				 // not found since 0 is default anyway:
				 // if we justified by 0 nothing will happen
va_list ap;
char specifier;
char *output; // will contain the argument and apply formatting to it
int arg_len; // how many digits or characters the argument has
int counter;

int	ft_printf(const char *s, ...);

#endif
