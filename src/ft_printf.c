#include "libft/libft.h"
#include "libftprintf.h"

char	*get_arg(char specifier) // this is probably not gonna work correctly, functions have to be made. will get back to it later
{
	if (specifier == 'd' || specifier == 'i')
		return ft_itoa(va_arg(ap, int));
	else if (specifier == 'u' || specifier == 'x' || specifier == 'X' || specifier == 'c')
		return ft_itoa(va_arg(ap, unsigned int));	// itoa should probably be replaced with a new function that converts hexadecimal to ascii
	else if (specifier == 'p')
		return va_arg(ap, void *);
	else if (specifier == 's')
		return va_arg(ap, char *);
}

char	*diuxx_precision(char *output, int precision) // adds precision number of zeros to the beginning of the argument
{
	char *zeros;
	int i;

	i = 0;
	zeros = malloc(precision + 1);
	ft_bzero(zeros, precision + 1);
	while (i < precision)
		zeros[i++] = '0';
	return ft_strjoin(zeros, output); // memory leak...
}

int	isspecifier(char str)
{
	if (str == 'd' || str == 'i' || str == 'u' || str == 'x' || str == 'X'
			|| str == 'c' || str == 's' || str == 'p' || str == '%')
	{
		specifier = str;
		return (1);
	}
	return (0);
}

int num_check(char *str) // checks the nature of the precision or mfw's values and then converts it to an int
{
	int num;

	if (*str == '*') // if the value is an asterisk replace it with next argument and check if the argument itself contains any flags
	{
		num = va_arg(ap, int);
		if (num < 0 && !precisiondot_found)
		{
			num *= -1;
			minusflag_found = 1;
		}
		if (num == 0 && !precisiondot_found)
			zeroflag_found = 1;
	}
	else // if the value is a normal number, loop through it all and convert it to int
	{
		num = *str - 48;
		while (ft_isdigit(++*str))
			num = (num * 10) + (*str - 48);
	}
	return (num);
}

int	ft_printf(const char *s, ...)
{
	char *str; // this will point to the string literal and we'll loop through it

	// all the following variables are declared in libftprintf.h and they serve to collect all the data that exist after each % sign.
	// there are two types of this data:
		// boolean: for flags (-; 0; .;) and mfw, and it is either: 1 (found) or 0 (not found)
		// value: minimum field width value; precision value
	minusflag_found = 0;
	zeroflag_found = 0;
	precisiondot_found = 0;
	mfwidth_val = 0;
	precision_val = -1; // if a precision is zero, it doesn't mean that there is no precision, it applies a precision of 0, that's why the intialization is set to negative, if there was no precision specified it will be set to negative.
	counter = 0; // this counts the number of characters that will be printed. this is the value that printf returns.
	va_start(ap, s); // makes ap point to the first unnamed argument
	str = (char *)s;
	while (*str)
	{
		counter++;

		/* all of the following code will be in a separate function
		 * containing calls to more separate functions */

		/* formatting begins here */

		if (*str == '%')
		{
			str++;

			/* data collection begins here */

			while (!isspecifier(*str))	// while the conversion specifier is not found, collect all data in between the '%' and the specifier.
			{
				minusflag_found = (*str == '-') ? 1 : minusflag_found;
				zeroflag_found = (*str == '0') ? 1 : zeroflag_found;
				precisiondot_found = (*str == '.') ? 1 : precisiondot_found;
				if (ft_isdigit(*str) || *str == '*')
				{
					if (precisiondot_found)
						precision_val = num_check(str);
					else
						mfwidth_val = num_check(str);
				}
				str++;
			}
			if (precisiondot_found && precision_val < 0)
				precision_val = -1; // if the - sign is present in the precision value, then we cancel the precision.
			specifier = *(str++);	// getting out of the while loop means we've found the specifier. we assign it and then increment to the next character.

			/* data collection ends here */

			/* precision management begins here */

			output = ft_strdup(get_arg(specifier)); // with the help of va_arg (in get_arg) we get the argument according to the specifier we found, and assign to the string "output" which will change later after formatting.
			arg_len = ft_strlen(output);
			if (precisiondot_found)
			{
				if (specifier == 'd' || specifier == 'i' || specifier == 'u' || specifier == 'x' || specifier == 'X')
				{
					if (arg_len < precision_val)
						output = diuxx_precision(output, precision_val - arg_len);
				}
				else if (specifier == 's')
				{
					if (arg_len > precision_val)
						output = ft_substr(output, 0, precision_val); // memory leak...
				} // if other specifiers: undefined behavior
			}

			/* precision management ends here */

			/* minimum field width management begins here */
				/* code */
			/* minimum field width management ends here */

			// don't forget to count the final output's characters
		}

		/* formatting ends here */

		else
			ft_putchar_fd(*(str++), 1);

		/* reinitialize data here */
	}

	return (counter);
}
