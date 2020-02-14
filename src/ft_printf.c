#include "libft/libft.h"
#include "libftprintf.h"

// don't forget to also handle %

void	jusitfy(int mfwidth_val, char padding_char)
{
	while (mfwidth_val-- > 0)
		ft_putchar_fd(padding_char, 1);
}

void	format(char specifier, int precision_val, t_arg arg)
{
	if (specifier == 'd' || specifier == 'i' || specifier == 'u' || specifier == 'x' || specifier == 'X')
	{
		/* precision begins here */
		while (precision_val-- > 0)
			ft_putchar_fd('0', 1);
		/* precision ends here */

		/* diuxX arg output begins here */
		if (specifier == 'd' || specifier == 'i')
			ft_putnbr_fd(arg.intdata, 1);
		else if (specifier == 'u')
			ft_putui_fd(arg.uintdata, 1);
		//else if (specifier == 'x') how to print hexa????
		//else // if specifier == X
		/* diuxX arg output ends here */

	}
	else if (specifier == 's')
		ft_putstr_fd(ft_substr(arg.stringdata, 0, precision_val > 0 ? precision_val : arg_len), 1); // s output. memory leak...
	else
	{
		/* c & p arg output begins here */
		if (specifier == 'c')
			ft_putchar_fd(arg.uintdata, 1);
		// else if (specifier == 'p') how to print hexa????
		/* c & p arg output ends here */
	}
}

t_arg	get_arg(char specifier)
{
	t_arg arg;

	if (specifier == 'd' || specifier == 'i')
	{
		arg.intdata = va_arg(ap, int);
		return arg;
	}
	else if (specifier == 'u' || specifier == 'x' || specifier == 'X' || specifier == 'c' || specifier == 'p')
	{
		arg.uintdata = va_arg(ap, unsigned int);
		return arg;
	}
	else // if (specifier == 's')
	{
		arg.stringdata = va_arg(ap, char *);
		return arg;
	}
}

int	get_len(t_arg arg, char specifier)
{
	if (specifier == 'd' || specifier == 'i')
		return arg.intdata < 0 ? ft_ulen(-1*(int)arg.intdata) + 1 : ft_ulen(arg.intdata);
	else if (specifier == 'u')
		return ft_ulen(arg.uintdata);
	else if (specifier == 's')
		return ft_strlen(arg.stringdata);
	else if (specifier == 'x' || specifier == 'X')
		return ft_xlen(arg.uintdata);
	else if (specifier == 'p')
		return ft_xlen(arg.uintdata) + 2;
	else // if (specifier == 'c')
		return 1;
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
	t_arg arg; // gets the arguments
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
			arg = get_arg(specifier);
			arg_len = get_len(arg, specifier);
			if (precisiondot_found)
			{
				if (specifier == 'd' || specifier == 'i' || specifier == 'u' || specifier == 'x' || specifier == 'X')
				{
					 if (precision_val > arg_len)
						precision_val = precision_val - arg_len;
					else
						precision_val = -1;
				}
				else if (specifier == 's')
				{
					if (precision_val >= arg_len)
						precision_val = -1;
				} // and other specifiers' precision is undefined behavior
			}
			/* precision management ends here */

			/* minimum field width management begins here */
			if (zeroflag_found) // setting the padding character (0 or space)
			{
				padding_char = '0';
				if (((specifier == 'd' || specifier == 'i' || specifier == 'u' || specifier == 'x' || specifier == 'X') && precision_val >= 0) || minusflag_found)
					padding_char = ' ';
			}
			mfwidth_val -= (precision_val >= 0) ? (arg_len + precision_val) : arg_len;
			if (!minusflag_found)
			{
				/* justification begins here */
				jusitfy(mfwidth_val, padding_char);
				/* justification ends here */

				/* precision and arg output begins here */
				format(specifier, precision_val, arg);
				/* precision and arg output ends here */
			}
			else
			{
				/* precision and arg output begins here */
				format(specifier, precision_val, arg);
				/* precision and arg output ends here */

				/* justification begins here */
				jusitfy(mfwidth_val, padding_char);
				/* justification ends here */
			}
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
