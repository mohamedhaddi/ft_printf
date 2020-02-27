/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:35:28 by mhaddi            #+#    #+#             */
/*   Updated: 2020/02/27 02:44:02 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

int		num_check(va_list ap)
{
	int num;

	if (*g_str == '*')
	{
		num = va_arg(ap, int);
		if (num < 0 && !g_precisiondot_found)
		{
			num *= -1;
			g_minusflag_found = 1;
		}
		else if (num == 0 && !g_precisiondot_found)
			g_zeroflag = 1;
		else if (g_precisiondot_found && num < 0)
		{
			num = -1;
			g_precisiondot_found = 0;
		}
	}
	else
	{
		num = *g_str - 48;
		while (ft_isdigit(*(++g_str)))
			num = (num * 10) + (*g_str - 48);
	}
	return (num);
}

void	collect_data(va_list ap)
{
	while (*g_str && !isspecifier(*g_str))
	{
		g_minusflag_found = (*g_str == '-') ? 1 : g_minusflag_found;
		g_zeroflag = (*g_str == '0' && !g_precisiondot_found) ? 1 : g_zeroflag;
		g_precisiondot_found = (*g_str == '.') ? 1 : g_precisiondot_found;
		g_prec_val = (*g_str == '.' && !ft_isdigit(*(g_str + 1)) &&
		*(g_str + 1) != '-') ? 0 : g_prec_val;
		g_minus_a_dot = (*g_str == '.' && *(g_str + 1) == '-') ?
		1 : g_minus_a_dot;
		if ((*g_str == '0' && g_precisiondot_found) ||
		(*g_str != '0' && (ft_isdigit(*g_str) || *g_str == '*')))
		{
			if (g_precisiondot_found && *(g_str - 1) != '-')
				g_prec_val = num_check(ap);
			else
				g_mfwidth_val = num_check(ap);
			if (*g_str == '*')
				g_str++;
			else
				while (ft_isdigit(*g_str))
					g_str++;
		}
		else
			g_str++;
	}
}
