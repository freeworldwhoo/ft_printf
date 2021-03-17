/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 01:19:02 by rnbou             #+#    #+#             */
/*   Updated: 2021/03/17 17:08:08 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_c(t_tags tag, va_list l)
{
	char c;
	char *fw;

	fw = ft_get_space(tag.f_w - 1);
	c = va_arg(l, int);
	if (tag.flags % 2 != 1)
	{
		ft_putstr(fw);
		ft_putchar(c);
	}
	else
	{
		ft_putchar(c);
		ft_putstr(fw);
	}
	free(fw);
}
