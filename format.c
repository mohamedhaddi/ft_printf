/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:38:42 by mhaddi            #+#    #+#             */
/*   Updated: 2020/02/27 02:39:55 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

void	format(va_list ap)
{
	g_str++;
	collect_data(ap);
	if (!*g_str)
		return ;
	calc_precision(ap);
	calc_mfw();
	if (patch())
		;
	else if (!g_minusflag_found)
	{
		jusitfy();
		print();
	}
	else
	{
		print();
		jusitfy();
	}
	g_str++;
}
