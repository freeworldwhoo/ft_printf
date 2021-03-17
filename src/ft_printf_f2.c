/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:56:57 by rnbou             #+#    #+#             */
/*   Updated: 2021/03/17 17:08:59 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_fl(t_tags tag, size_t *table_float, char **part_fl, int dim)
{
	int		ret;
	int		i;
	size_t	*table;
	size_t	*t;

	table = new_table(dim / 2 + 1);
	t = table + 1;
	ft_cp(table_float + (dim / 2), &t, dim / 2);
	i = 0;
	while (i < tag.precision)
	{
		ft_multiply(&table, dim / 2);
		(*part_fl)[i++] = table[0] + '0';
		table[0] = 0;
	}
	ft_multiply(&table, dim / 2);
	if (tag.precision != 0)
		ret = regulate_fl(part_fl, table[0], tag.precision);
	else if ((table_float[dim / 2 - 1] % 2 == 0 &&
				ver_carry(table + 1, dim / 2) == 0) || table[0] < 5)
		ret = 0;
	else
		ret = 1;
	free(table);
	return (ret);
}

void	ft_display_float1(int s, t_tags tag, char *part_int, char *part_fl)
{
	if (s == 1)
		ft_putchar('-');
	else if ((tag.flags >> 1) % 2 == 1)
		ft_putchar('+');
	else if ((tag.flags >> 4) % 2 == 1)
		ft_putchar(' ');
	ft_putstr(part_int);
	if (tag.precision != 0 || (tag.flags >> 2) % 2 == 1)
		ft_putchar('.');
	ft_putstr(part_fl);
}

void	ft_display_float(t_tags tag, size_t *table_float, int dim, int s)
{
	char	*part_int;
	char	*part_fl;
	char	*f_w;
	int		i;

	if (tag.precision == -1)
		tag.precision = 6;
	part_fl = ft_strnew(tag.precision + 1);
	i = ft_fl(tag, table_float, &part_fl, dim);
	part_int = ft_int(table_float, dim, i, tag);
	i = ((tag.flags >> 1) % 2 == 1 || (tag.flags >> 4) % 2 == 1 || s == 1) +
		((tag.flags >> 2) % 2 == 1 || tag.precision != 0);
	f_w = ft_get_space(tag.f_w - ft_strlen(part_int) - ft_strlen(part_fl) - i);
	if (tag.flags % 2 == 0)
		ft_putstr(f_w);
	ft_display_float1(s, tag, part_int, part_fl);
	if (tag.flags % 2 == 1)
		ft_putstr(f_w);
	free(f_w);
	free(part_int);
	free(part_fl);
}

void	ft_put_nan(t_tags tag, int s, size_t m)
{
	char	*spaces;
	int		i;

	i = ((tag.flags >> 1) % 2 == 1 || s == 1 || (tag.flags >> 4) % 2 == 1);
	spaces = ft_get_space(tag.f_w - 3 - i * (m == 0));
	if (tag.flags % 2 == 0)
		ft_putstr(spaces);
	if (s == 1 && m == 0)
		ft_putchar('-');
	else if ((tag.flags >> 1) % 2 == 1 && m == 0)
		ft_putchar('+');
	else if ((tag.flags >> 4) % 2 == 1 && m == 0)
		ft_putchar(' ');
	if (m != 0)
		ft_putstr("nan");
	else
		ft_putstr("inf");
	if (tag.flags % 2 == 1)
		ft_putstr(spaces);
	free(spaces);
}
