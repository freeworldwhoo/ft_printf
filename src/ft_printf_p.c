/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 13:10:56 by rnbou             #+#    #+#             */
/*   Updated: 2021/03/17 17:09:08 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_p(t_tags tag, va_list l)
{
	t_tags tag1;

	tag1.precision = tag.precision;
	tag1.f_w = tag.f_w;
	tag1.flags = tag.flags % 2;
	tag1.flags += 1 << 2;
	tag1.flags += ((tag.flags >> 3) % 2) << 3;
	tag1.l_m = 3;
	tag1.c_c = 8;
	tag1.flags += 1 << 5;
	ft_printf_u(tag1, l);
}
