/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 00:01:02 by rnbou             #+#    #+#             */
/*   Updated: 2021/03/17 17:08:13 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*zeros_int(t_tags tag, long long int nbr)
{
	int						lenth;
	char					*zeros;
	long long unsigned int	c;

	if (nbr < 0)
		c = -nbr;
	else
		c = nbr;
	lenth = number_lenth(tag, c, 10);
	zeros = ft_get_zeros(tag.precision - lenth);
	if (tag.precision == -1 && (tag.flags >> 3) % 2 == 1 && tag.flags % 2 != 1)
	{
		if ((tag.flags >> 4) % 2 == 1 || nbr < 0 || (tag.flags >> 1) % 2 == 1)
			lenth++;
		free(zeros);
		zeros = ft_get_zeros(tag.f_w - lenth);
	}
	return (zeros);
}

char	*space_int(t_tags tag, long long int nbr)
{
	char					*spaces;
	long long unsigned int	c;
	int						lenth;
	int						s;

	s = nbr < 0;
	if (nbr < 0)
		c = -nbr;
	else
		c = nbr;
	lenth = number_lenth(tag, c, 10);
	if ((tag.precision == -1 && (tag.flags >> 3) % 2 == 0))
		spaces = ft_get_space(tag.f_w - lenth - s -
				((tag.flags >> 1) % 2 + (tag.flags >> 4) % 2 != 0) * 1);
	else if ((tag.precision != -1 || tag.flags % 2 == 1) &&
			tag.precision > lenth)
		spaces = ft_get_space(tag.f_w - tag.precision - s -
				((tag.flags >> 1) % 2 + (tag.flags >> 4) % 2 != 0) * 1);
	else if ((tag.precision != -1 || tag.flags % 2 == 1) &&
			tag.precision <= lenth)
		spaces = ft_get_space(tag.f_w - lenth - s -
				((tag.flags >> 1) % 2 + (tag.flags >> 4) % 2 != 0) * 1);
	else
		spaces = ft_get_space(0);
	return (spaces);
}

void	ft_printf_d1(t_d var, t_tags tag, char *zeros)
{
	long long unsigned int nbr;

	if (var.lld < 0)
	{
		ft_putchar('-');
		nbr = -var.lld;
	}
	else
	{
		nbr = var.lld;
		if ((tag.flags >> 1) % 2 == 1)
			ft_putchar('+');
		else if ((tag.flags >> 4) % 2 == 1)
			ft_putchar(' ');
	}
	ft_putstr(zeros);
	if (tag.precision != 0 || nbr != 0)
		print_nbr(nbr, "0123456789", 10);
}

void	ft_printf_d(t_tags tag, va_list l)
{
	t_d						var;
	char					*f_w;
	char					*zeros;

	var.lld = va_arg(l, long long int);
	if (tag.l_m == 1)
		var.lld = var.ld;
	else if (tag.l_m == 2)
		var.lld = var.hd;
	else if (tag.l_m == 6)
		var.lld = var.hhd;
	else if (tag.l_m == 0)
		var.lld = var.d;
	zeros = zeros_int(tag, var.lld);
	f_w = space_int(tag, var.lld);
	if (tag.flags % 2 == 0)
		ft_putstr(f_w);
	ft_printf_d1(var, tag, zeros);
	if (tag.flags % 2 == 1)
		ft_putstr(f_w);
	free(zeros);
	free(f_w);
}
