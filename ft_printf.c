/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 23:41:21 by mhaddi            #+#    #+#             */
/*   Updated: 2020/02/27 02:44:36 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	loop_through(va_list ap)
{
	while (*g_str)
	{
		if (*g_str == '%' && (isspecifier(*(g_str + 1))
		|| isflag(*(g_str + 1))))
			format(ap);
		else
		{
			if (*g_str != '%')
				ft_putchar_fd(*(g_str++), 1);
			else
			{
				if (*(g_str + 1))
				{
					g_str++;
					while (*g_str == ' ')
						g_str++;
					ft_putchar_fd(*(g_str++), 1);
				}
			}
		}
		initialize_all();
	}
}

int		ft_printf(const char *s, ...)
{
	va_list ap;

	initialize_all();
	g_counter = 0;
	va_start(ap, s);
	g_str = (char *)s;
	loop_through(ap);
	va_end(ap);
	return (g_counter);
}
