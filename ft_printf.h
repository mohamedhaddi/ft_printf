/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:     */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 02:08:23 by mhaddi            #+#    #+#             */
/*   Updated: 2020/02/27 02:39:01 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct	s_arg {
	int				idata;
	unsigned int	uidata;
	char			*sdata;
	void			*vpdata;
}				t_arg;
t_arg g_arg;

char			g_sp;
char			*g_str;
int				g_counter;
int				g_arg_len;
int				g_prec_val;
int				g_zeroflag;
char			g_pad_char;
int				g_og_mfw_val;
int				g_og_prec_val;
int				g_minus_a_dot;
int				g_mfwidth_val;
int				g_minusflag_found;
int				g_precisiondot_found;

int				ft_printf(const char *s, ...);
void			initialize_all(void);
void			loop_through(va_list ap);
int				isspecifier(char c);
int				isflag(char c);
void			format(va_list ap);
void			collect_data(va_list ap);
int				num_check(va_list ap);
void			calc_precision(va_list ap);
t_arg			get_arg(va_list ap);
int				get_len(void);
int				is_di(char c);
int				isdiuxx(char c);
void			calc_mfw(void);
int				patch(void);
void			jusitfy(void);
void			print(void);

#endif
