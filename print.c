/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:44:01 by mhaddi            #+#    #+#             */
/*   Updated: 2020/02/27 01:50:33 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

void	print(void)
{
	int i;

	if (isdiuxx(g_sp))
	{
		if (is_di(g_sp) && g_arg.idata < 0 && g_pad_char != '0')
			ft_putchar_fd('-', 1);
		i = g_prec_val;
		while (i-- > 0)
			ft_putchar_fd('0', 1);
		if (g_sp == 'd' || g_sp == 'i')
			ft_putui_fd(g_arg.idata < 0 ? g_arg.idata * -1 : g_arg.idata, 1);
		else if (g_sp == 'u')
			ft_putui_fd(g_arg.uidata, 1);
		else if (g_sp == 'x' || g_sp == 'X')
			ft_puthex_fd(g_arg.uidata, g_sp, 1);
	}
	else if (g_sp == 'c')
		ft_putchar_fd(g_arg.uidata, 1);
	else if (g_sp == 's')
		ft_putnstr_fd(g_arg.sdata, g_prec_val >= 0 ? g_prec_val : g_arg_len, 1);
	else
	{
		ft_putnstr_fd("0x", 2, 1);
		ft_putptr_fd((unsigned long long)g_arg.vpdata, 1);
	}
}
