/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:02:52 by mhaddi            #+#    #+#             */
/*   Updated: 2020/02/25 21:54:09 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
static int	len_count(unsigned long n)
{
	int				i;
	unsigned long	nb;

	nb = n;
	i = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (n == 0 ? 1 : i);
}

static unsigned long long	sixteen_power(int len)
{
	unsigned long long	n;

	n = 1;
	while (--len > 0)
		n = n * 16;
	return (n);
}

void ft_putptr_fd(unsigned long n, int fd)
{
	int				len;
	char			remainder;
	int				other_digit_found;

	other_digit_found = 0;
	len = len_count(n);
	while (len > 0)
	{
		remainder = (n / sixteen_power(len)) % 16; // calculates the modulo starting from the very left so we don't need to invert it
		if ((remainder || n == 0) || other_digit_found) // if 0 was found at the very beginning, don't print it, unless it's 0 because n == 0
		{
			other_digit_found = 1;
			if (remainder < 10)
				ft_putchar_fd(48 + remainder, 1);
			else
				ft_putchar_fd(87 + remainder, fd);
		}
		len--;
	}
}
