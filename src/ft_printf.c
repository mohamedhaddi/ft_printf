#include "libft/libft.h"
#include "libftprintf.h"

// don't forget to also handle %, search and test this case well

void	jusitfy(int mfwidth_val, char padding_char, char specifier, t_arg arg)
{
	if ((specifier == 'd' || specifier == 'i') && arg.intdata < 0 && padding_char == '0') // if the padding is 0 character, unlike the space character, we show the minus sign first when it's a negative number
		ft_putchar_fd('-', 1);
	while (mfwidth_val-- > 0)
		ft_putchar_fd(padding_char, 1);
}

void	format(char specifier, int precision_val, t_arg arg)
{
	if (specifier == 'd' || specifier == 'i' || specifier == 'u' || specifier == 'x' || specifier == 'X')
	{
		if ((specifier == 'd' || specifier == 'i') && arg.intdata < 0 && padding_char != '0')
			ft_putchar_fd('-', 1);
		// if (plus_found)
		//	ft_putchar_fd('+', 1);
		/* precision begins here */
		while (precision_val-- > 0)
			ft_putchar_fd('0', 1);
		/* precision ends here */

		/* diuxX arg output begins here */
		if (specifier == 'd' || specifier == 'i' || specifier == 'u')
			ft_putui_fd(arg.intdata < 0 ? arg.intdata * -1 : arg.intdata, 1);
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
		return arg.intdata < 0 ? ft_ulen(-1*arg.intdata) : ft_ulen(arg.intdata);
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

int	isspecifier(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X'
			|| c == 'c' || c == 's' || c == 'p' || c == '%')
	{
		specifier = c;
		return (1);
	}
	return (0);
}

int	isflag(char c)
{
	if (ft_isdigit(c) || c == '-' || c == '0' || c == '.' || c == '*' || c == '%')
		return 1;
	return 0;
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
		else if (num == 0 && !precisiondot_found)
			zeroflag_found = 1;
		else if (precisiondot_found && num < 0)
			num = -1; // if the - sign is present in the precision value, then we cancel the precision.
	}
	else // if the value is a normal number, loop through it all and convert it to int
	{
		num = *str - 48;
		while (ft_isdigit(*(++str)))
			num = (num * 10) + (*str - 48);
	}
	return (num);
}

void	initialize()
{
	minusflag_found = 0;
	// plus_found = 0;
	zeroflag_found = 0;
	precisiondot_found = 0;
	mfwidth_val = 0;
	precision_val = -1; // if a precision is zero, it doesn't mean that there is no precision, it applies a precision of 0, that's why the intialization is set to negative, if there was no precision specified it will be set to negative.
	padding_char = ' ';

	arg.intdata = 0;
	arg.uintdata = 0;
	arg.stringdata = 0;
}

int	ft_printf(const char *s, ...)
{
	char *str; // this will point to the string literal and we'll loop through it
	// t_arg arg; // gets the arguments
	// all the following variables are declared in libftprintf.h and they serve to collect all the data that exist after each % sign.
	// there are two types of this data:
		// boolean: for flags (-; 0; .;) and mfw, and it is either: 1 (found) or 0 (not found)
		// value: minimum field width value; precision value
	initialize();
	counter = 0;	 // this counts the number of characters that will be printed. this is the value that printf returns.
	va_start(ap, s); // makes ap point to the first unnamed argument
	str = (char *)s;
	while (*str)
	{
		counter++;
		/* all of the following code will be in a separate function
		 * containing calls to more separate functions */

		/* formatting begins here */
		if (*str == '%' && (isspecifier(*(str + 1)) || isflag(*(str + 1))))
		{
			str++;
			/* data collection begins here */
			while (*str && !isspecifier(*str))	// while the conversion specifier is not found, collect all data in between the '%' and the specifier.
			{
				minusflag_found = (*str == '-' && !precisiondot_found) ? 1 : minusflag_found;
				// plus_found = (*str == '+') ? 1 : plus_found;
				// %
				zeroflag_found = (*str == '0') ? 1 : zeroflag_found;
				precisiondot_found = (*str == '.') ? 1 : precisiondot_found;
				if (*str != '0' && (ft_isdigit(*str) || *str == '*')) // we don't want 0 flag to be counted as one of these numbers
				{
					if (precisiondot_found)
						precision_val = *(str - 1) == '-' ? -1 : num_check(str);
					else
						mfwidth_val = num_check(str);
					/* begin incrementing str */
					if (*str == '*')
						str++;
					else
						while (ft_isdigit(*str))
							str++;
					/* end incrementing str */
				}
				else
					str++;
			}
			/* data collection ends here */

			if (!*str) // maybe the % is at the end of the string
				break;

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
						precision_val = 0; // replacing -1 with 0 to avoid conflicts with cancelling the mfw, hopefully not gonna affect anything else
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
				if (((specifier == 'd' || specifier == 'i' || specifier == 'u' || specifier == 'x' || specifier == 'X') && precisiondot_found) || minusflag_found)
					padding_char = ' ';
			}
			if (mfwidth_val < arg_len || (precisiondot_found && precision_val < 0)) // cancel the mfw if it's less than arg_len OR if the precision_val is negative
				mfwidth_val = 0;
			else if (mfwidth_val != 0) // setting the real mfwidth value depending on the arg and the precision
			{
				if (precision_val >= 0)
					mfwidth_val -= (mfwidth_val >= arg_len + precision_val) ? arg_len + precision_val : mfwidth_val;
				else
					mfwidth_val -= (mfwidth_val >= arg_len) ? arg_len : mfwidth_val;
				// if (plus_found)
				// mfwidth_val--;
				if ((specifier == 'd' || specifier == 'i') && arg.intdata < 0)
					mfwidth_val--;
			}
			if (!minusflag_found) // applying the right justification and then formatting
			{
				/* justification begins here */
				jusitfy(mfwidth_val, padding_char, specifier, arg);
				/* justification ends here */

				/* precision and arg output begins here */
				format(specifier, precision_val, arg);
				/* precision and arg output ends here */
			}
			else // applying the left justification and then formatting
			{
				/* precision and arg output begins here */
				format(specifier, precision_val, arg);
				/* precision and arg output ends here */

				/* justification begins here */
				jusitfy(mfwidth_val, padding_char, specifier, arg);
				/* justification ends here */

			}
			/* minimum field width management ends here */

			str++;	// getting out of the while loop means we've found the specifier. we increment to the next character after it.
			// don't forget to count the final output's characters
		}
		/* formatting ends here */

		else
		{
			if (*str != '%') // print normal stuff that is not formatting
				ft_putchar_fd(*(str++), 1);
			else // if *str is %, but the next character is neither a flag nor a specifier
			{
				*(str + 1) ? ft_putchar_fd(*(++str), 1) : 0; // if next character isn't nul, increment to it and print it.
				str++;
			}
		}

		/* reinitialize data here */
		initialize();

		/* unglobalize variables that do not need to be global */
	}

	va_end(ap);
	return (counter);
}
