/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:32:47 by rnbou             #+#    #+#             */
/*   Updated: 2021/03/17 17:09:58 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*zeros_unsigned_int(t_tags tag, long long unsigned int nbr, int b)
{
	int		lenth;
	char	*zeros;
	int		prefix;

	lenth = number_lenth(tag, nbr, b);
	prefix = 0;
	if (b == 8 && (tag.flags >> 2) % 2 == 1)
		prefix = 1;
	else if (b == 16 && (tag.flags >> 2) % 2 == 1 &&
			(nbr != 0 || (tag.flags >> 5) % 2 == 1))
		prefix = 2;
	if (tag.precision == -1 && (tag.flags >> 3) % 2 == 1 && tag.flags % 2 != 1)
		zeros = ft_get_zeros(tag.f_w - lenth - prefix);
	else
		zeros = ft_get_zeros(tag.precision - lenth);
	return (zeros);
}

char	*space_unsigned_int(t_tags tag, long long unsigned int nbr, int b)
{
	char	*spaces;
	int		lenth;
	int		prefix;

	prefix = 0;
	lenth = number_lenth(tag, nbr, b);
	if (b == 8 && (tag.flags >> 2) % 2 == 1)
		prefix = 1;
	else if (b == 16 && (tag.flags >> 2) % 2 == 1 &&
			(nbr != 0 || (tag.flags >> 5) % 2 == 1))
		prefix = 2;
	if (tag.precision == -1 && (tag.flags >> 3) % 2 == 0)
		spaces = ft_get_space(tag.f_w - lenth - prefix);
	else if ((tag.precision != -1 || tag.flags % 2 == 1) &&
			tag.precision > lenth)
		spaces = ft_get_space(tag.f_w - tag.precision - prefix);
	else if ((tag.precision != -1 || tag.flags % 2 == 1) &&
			tag.precision <= lenth)
		spaces = ft_get_space(tag.f_w - lenth - prefix);
	else
		spaces = ft_get_space(0);
	return (spaces);
}

void	ft_printf_u1(t_u var, t_tags tag, int b, char *base)
{
	char *spaces;
	char *zeros;

	zeros = zeros_unsigned_int(tag, var.llu, b);
	spaces = space_unsigned_int(tag, var.llu, b);
	if (tag.flags % 2 == 0)
		ft_putstr(spaces);
	if (b == 8 && (tag.flags >> 2) % 2 == 1 && var.llu != 0)
		ft_putchar('0');
	else if (b == 16 && (tag.flags >> 2) % 2 == 1 != 0 &&
			(var.llu != 0 || (tag.flags >> 5) % 2 == 1))
	{
		if (tag.c_c == 8)
			ft_putstr("0x");
		else
			ft_putstr("0X");
	}
	ft_putstr(zeros);
	if (tag.precision != 0 || var.llu != 0)
		print_nbr(var.llu, base, b);
	if (tag.flags % 2 == 1)
		ft_putstr(spaces);
	free(spaces);
	free(zeros);
}

void	ft_printf_u(t_tags tag, va_list l)
{
	t_u				var;
	char			*base;
	unsigned int	b;

	b = (tag.c_c == 6) * 8 + (tag.c_c == 7) * 10 +
		(tag.c_c > 7 && tag.c_c < 10) * 16 + (tag.c_c == 13) * 2;
	if (tag.c_c == 9)
		base = ft_strdup("0123456789ABCDEF");
	else
		base = ft_strdup("0123456789abcdef");
	var.llu = va_arg(l, long long unsigned int);
	if (tag.l_m == 1)
		var.llu = var.lu;
	else if (tag.l_m == 2)
		var.llu = var.hu;
	else if (tag.l_m == 6)
		var.llu = var.hhu;
	else if (tag.l_m == 0)
		var.llu = var.u;
	ft_printf_u1(var, tag, b, base);
	free(base);
}
