/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:11:09 by rnbou             #+#    #+#             */
/*   Updated: 2021/03/17 17:08:20 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_part_int(size_t *table_float, size_t **part_i, int dim, int l)
{
	size_t			*add;
	unsigned int	i;
	size_t			*int_table;

	add = new_table(l);
	add[l - 1] = 1;
	int_table = new_table(dim);
	ft_cp(table_float, &int_table, dim);
	i = 0;
	while (i < (unsigned int)l * 64)
	{
		if ((int_table)[dim - 1] % 2 == 1)
			ft_add_int(part_i, add, l);
		ft_add_int(&add, add, l);
		bit_shift(&int_table, -1, dim);
		i++;
	}
	free(add);
	free(int_table);
}

int		ft_count(size_t n)
{
	int nbr;

	nbr = 0;
	while (n != 0)
	{
		n = n / 10;
		nbr++;
	}
	return (nbr);
}

char	*ft_itoa1(size_t n, int i)
{
	char			*str;
	int				l;

	if (i == 0)
		l = ft_count(n);
	else
		l = 18;
	str = (char *)malloc(sizeof(char) * (l + 1));
	str[l--] = '\0';
	str[l--] = '0' + n % 10;
	n = n / 10;
	while (l != -1)
	{
		str[l--] = '0' + n % 10;
		n = n / 10;
	}
	return (str);
}

char	*int_to_str(size_t *part_i, int l)
{
	char	*ret;
	char	*a1;
	char	*a2;
	int		i;

	i = 0;
	while (part_i[i] == 0 && i < l)
		i++;
	if (i == l)
		return (ft_strdup("0"));
	ret = ft_strdup("");
	a1 = ft_itoa1(part_i[i++], 0);
	a2 = ret;
	ret = ft_strjoin(ret, a1);
	free(a1);
	free(a2);
	while (i < l)
	{
		a1 = ft_itoa1(part_i[i++], 1);
		a2 = ret;
		ret = ft_strjoin(ret, a1);
		free(a1);
		free(a2);
	}
	return (ret);
}

char	*ft_int(size_t *table_float, int dim, int carry, t_tags tag)
{
	size_t	*part_i;
	int		l;
	size_t	*carry_table;
	char	*ret;

	tag.c_c = 0;
	l = (64 * (dim / 2) * 7 / 23) / 18 + 1;
	part_i = new_table(l);
	get_part_int(table_float, &part_i, dim / 2, l);
	carry_table = new_table(l);
	carry_table[l - 1] = carry;
	ft_add_int(&part_i, carry_table, l);
	free(carry_table);
	ret = int_to_str(part_i, l);
	free(part_i);
	return (ret);
}
