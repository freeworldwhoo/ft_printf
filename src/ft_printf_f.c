/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:56:57 by rnbou             #+#    #+#             */
/*   Updated: 2021/03/17 17:08:46 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_ld(t_tags tag, va_list l)
{
	t_long_double	var;
	size_t			*table_float;

	var.l = va_arg(l, long double);
	if (var.ld.p == 32767)
		ft_put_nan(tag, var.ld.s, var.ld.m);
	else
	{
		table_float = new_table(514);
		table_float[256] = var.ld.q;
		table_float[257] = ((size_t)(var.ld.m)) << 1;
		bit_shift(&table_float, var.ld.p - 16383, 514);
		ft_display_float(tag, table_float, 514, var.ld.s);
		free(table_float);
	}
}

void	ft_printf_dl(t_tags tag, va_list l)
{
	t_double	var;
	size_t		*table_float;

	var.f = va_arg(l, double);
	if (var.d.p == 2047)
		ft_put_nan(tag, var.d.s, var.d.m);
	else
	{
		table_float = new_table(66);
		table_float[32] = var.d.p != 0;
		table_float[33] = ((size_t)(var.d.m)) << 12;
		bit_shift(&table_float, var.d.p - 1023, 66);
		ft_display_float(tag, table_float, 66, var.d.s);
		free(table_float);
	}
}

void	ft_printf_f(t_tags tag, va_list l)
{
	if (tag.l_m == 3)
		ft_printf_ld(tag, l);
	else
		ft_printf_dl(tag, l);
}
