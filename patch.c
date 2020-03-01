/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:36:50 by mhaddi            #+#    #+#             */
/*   Updated: 2020/02/27 01:47:24 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	patch(void)
{
	if (isdiuxx(g_sp) && (g_arg.idata == 0 && g_arg.uidata == 0)
	&& g_precisiondot_found && ((g_prec_val == 0 && g_og_prec_val == 0)
	|| g_minus_a_dot))
	{
		if (g_mfwidth_val != 0)
			g_mfwidth_val++;
		if (g_og_mfw_val == 1)
			g_mfwidth_val = g_og_mfw_val;
		while (g_mfwidth_val-- > 0)
			ft_putchar_fd(' ', 1);
		return (1);
	}
	return (0);
}
