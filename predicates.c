/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:44:44 by mhaddi            #+#    #+#             */
/*   Updated: 2020/02/27 01:49:21 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

int	is_di(char c)
{
	if (c == 'd' || c == 'i')
		return (1);
	return (0);
}

int	isdiuxx(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	isspecifier(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X'
			|| c == 'c' || c == 's' || c == 'p' || c == '%')
	{
		g_sp = c;
		return (1);
	}
	return (0);
}

int	isflag(char c)
{
	if (ft_isdigit(c) || c == '-' || c == '0' || c == '.' || c == '*'
	|| c == '%')
		return (1);
	return (0);
}
