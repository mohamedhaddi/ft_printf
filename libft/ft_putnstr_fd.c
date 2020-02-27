/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:15:11 by mhaddi            #+#    #+#             */
/*   Updated: 2020/02/27 02:22:37 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern int	g_counter;

void		ft_putnstr_fd(char *s, size_t n, int fd)
{
	if (s)
		write(fd, s, n);
	g_counter += n;
}
