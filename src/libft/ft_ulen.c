/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:46:50 by mhaddi            #+#    #+#             */
/*   Updated: 2019/11/04 22:30:12 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			len_count(unsigned int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	nb = (n >= 0) ? n : -n;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (n == 0) ? 1 : i;
}

int				ft_ulen(unsigned int n)
{
	int				len;
	unsigned int	nb;

	nb = (n >= 0) ? n : -n;
	len = len_count(nb);
	len = (n >= 0) ? len : len + 1;
	return len;
}
