/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 23:18:30 by rnbou             #+#    #+#             */
/*   Updated: 2021/03/17 17:09:17 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_pr(t_tags tag, va_list l)
{
	char c;
	char *fw;

	(void)l;
	if ((tag.flags >> 3) % 2 == 1 && tag.flags % 2 == 0)
		fw = ft_get_zeros(tag.f_w - 1);
	else
		fw = ft_get_space(tag.f_w - 1);
	c = '%';
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
