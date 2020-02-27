/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:31:34 by mhaddi            #+#    #+#             */
/*   Updated: 2020/02/27 01:47:33 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	initialize_all(void)
{
	g_minusflag_found = 0;
	g_zeroflag = 0;
	g_precisiondot_found = 0;
	g_mfwidth_val = 0;
	g_og_prec_val = 0;
	g_og_mfw_val = 0;
	g_minus_a_dot = 0;
	g_prec_val = -1;
	g_pad_char = ' ';
	g_arg.idata = 0;
	g_arg.uidata = 0;
	g_arg.sdata = 0;
	g_arg.vpdata = 0;
}
