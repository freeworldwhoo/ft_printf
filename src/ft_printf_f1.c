/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 01:45:26 by rnbou             #+#    #+#             */
/*   Updated: 2021/03/17 17:08:52 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	bit_shift_right(size_t **t, int shift, int o)
{
	unsigned int	l;
	size_t			res1;
	size_t			res2;
	int				i;
	unsigned int	a;

	l = -1 * shift;
	while (l != 0)
	{
		l--;
		a = l % 64 + 1;
		l = (l / 64) * 64;
		i = 0;
		res1 = 0;
		while (i < o)
		{
			res2 = ((*t)[i] << (64 - a));
			(*t)[i] = ((*t)[i] >> a) * (a != 64) + res1;
			res1 = res2;
			i++;
		}
	}
}

void	bit_shift_left(size_t **t, int l, int o)
{
	size_t			res1;
	size_t			res2;
	int				i;
	unsigned int	a;

	while (l != 0)
	{
		l--;
		a = l % 64 + 1;
		l = (l / 64) * 64;
		i = o - 1;
		res1 = 0;
		res2 = 0;
		while (i >= 0)
		{
			res2 = ((*t)[i] >> (64 - a));
			(*t)[i] = (((*t)[i]) << a) * (a != 64) + res1;
			res1 = res2;
			i--;
		}
	}
}

void	bit_shift(size_t **t, int shift, int l)
{
	if (shift < 0)
		bit_shift_right(t, shift, l);
	else if (shift > 0)
		bit_shift_left(t, shift, l);
}

size_t	*new_table(int l)
{
	size_t	*ret;
	int		i;

	ret = (size_t*)malloc(sizeof(size_t) * l);
	i = 0;
	while (i < l)
		ret[i++] = 0;
	return (ret);
}

int		regulate_fl(char **part_fl, size_t k, int precision)
{
	size_t	barow;
	char	c;

	if (k > 4)
	{
		barow = 1;
		while (barow != 0 && precision != 0)
		{
			c = (*part_fl)[precision - 1];
			(*part_fl)[precision - 1] = (c - '0' + barow) % 10 + '0';
			barow = (c - '0' + barow) / 10;
			precision--;
		}
	}
	else
		barow = 0;
	return (barow);
}
