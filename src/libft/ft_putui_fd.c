/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:46:50 by mhaddi            #+#    #+#             */
/*   Updated: 2020/02/14 09:55:50 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			len_count(unsigned int n)
{
	int				i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return i;
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
		len--;
	}
}
