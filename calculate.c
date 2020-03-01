/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:34:22 by mhaddi            #+#    #+#             */
/*   Updated: 2020/02/27 02:40:30 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		get_len(void)
{
	if (g_sp == 'd' || g_sp == 'i')
		return (g_arg.idata < 0 ? ft_ulen(-1 * g_arg.idata) :
		ft_ulen(g_arg.idata));
	else if (g_sp == 'u')
		return (ft_ulen(g_arg.uidata));
	else if (g_sp == 's')
		return (ft_strlen(g_arg.sdata));
	else if (g_sp == 'x' || g_sp == 'X')
		return (ft_xlen(g_arg.uidata));
	else if (g_sp == 'p')
		return (ft_plen((unsigned long long)g_arg.vpdata) + 2);
	else
		return (1);
}

t_arg	get_arg(va_list ap)
{
	if (g_sp == 'd' || g_sp == 'i')
		g_arg.idata = va_arg(ap, int);
	else if (g_sp == 'u' || g_sp == 'x' || g_sp == 'X'
	|| g_sp == 'c')
		g_arg.uidata = va_arg(ap, unsigned int);
	else if (g_sp == '%')
	{
		g_arg.uidata = '%';
		g_sp = 'c';
	}
	else if (g_sp == 'p')
		g_arg.vpdata = va_arg(ap, void *);
	else
	{
		g_arg.sdata = va_arg(ap, char *);
		g_arg.sdata = !g_arg.sdata ? "(null)" : g_arg.sdata;
	}
	return (g_arg);
}

void	calc_precision(va_list ap)
{
	g_arg = get_arg(ap);
	g_arg_len = get_len();
	if (g_prec_val == 1)
		g_og_prec_val = g_prec_val;
	if (g_precisiondot_found)
	{
		if (isdiuxx(g_sp))
		{
			if (g_prec_val > g_arg_len)
				g_prec_val = g_prec_val - g_arg_len;
			else if (g_prec_val < 0)
				g_prec_val = -1;
			else
				g_prec_val = 0;
		}
		else if (g_sp == 's')
		{
			if (g_prec_val >= g_arg_len)
				g_prec_val = -1;
			else
				g_arg_len = g_prec_val;
		}
	}
}

void	calc_mfw(void)
{
	if (g_zeroflag)
		g_pad_char = '0';
	if ((isdiuxx(g_sp) && g_precisiondot_found) || g_minusflag_found)
		g_pad_char = ' ';
	g_og_mfw_val = g_mfwidth_val;
	if (g_mfwidth_val < g_arg_len)
		g_mfwidth_val = 0;
	else if (g_mfwidth_val > 0)
	{
		if (isdiuxx(g_sp))
		{
			if (g_prec_val >= 0)
				g_mfwidth_val -= (g_mfwidth_val >= g_arg_len + g_prec_val) ?
				g_arg_len + g_prec_val : g_mfwidth_val;
			else
				g_mfwidth_val -= (g_mfwidth_val >= g_arg_len) ?
				g_arg_len : g_mfwidth_val;
		}
		else if (g_sp == 'c' || g_sp == 'p' || g_sp == 's')
			g_mfwidth_val -= g_arg_len;
		if ((g_sp == 'd' || g_sp == 'i') && g_arg.idata < 0)
			g_mfwidth_val--;
		if (g_sp == 's' && g_minus_a_dot)
			g_mfwidth_val--;
	}
}
