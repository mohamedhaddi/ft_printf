/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:46:50 by mhaddi            #+#    #+#             */
/*   Updated: 2020/02/27 02:23:00 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern int			g_counter;

static int			len_count(unsigned int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	nb = n;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (n == 0) ? 1 : i;
}

static unsigned int	power(int len)
{
	unsigned int	n;

	n = 1;
	while (--len > 0)
		n = n * 10;
	return (n);
}

void				ft_putui_fd(unsigned int n, int fd)
{
	char			s;
	int				len;

	len = len_count(n);
	while (len > 0)
	{
		s = (n / power(len)) % 10 + '0';
		write(fd, &s, 1);
		g_counter++;
		len--;
	}
}
