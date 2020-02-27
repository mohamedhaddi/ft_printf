/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   justify.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:39:43 by mhaddi            #+#    #+#             */
/*   Updated: 2020/02/27 01:47:29 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

void	jusitfy(void)
{
	if ((g_sp == 'd' || g_sp == 'i') && g_arg.idata < 0 &&
	g_pad_char == '0')
		ft_putchar_fd('-', 1);
	while (g_mfwidth_val-- > 0)
		ft_putchar_fd(g_pad_char, 1);
}
