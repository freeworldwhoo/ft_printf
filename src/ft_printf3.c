/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:22:23 by rnbou             #+#    #+#             */
/*   Updated: 2021/03/17 17:10:29 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_f_w(char *out, int *j)
{
	int ret;
	int i;

	ret = 0;
	i = ft_in1(out[*j], "0123456789");
	while (out[*j] != '\0' && i != -1)
	{
		ret = ret * 10 + i;
		(*j)++;
		i = ft_in1(out[*j], "0123456789");
	}
	return (ret);
}

int		get_precision(char *out, int *j)
{
	int ret;
	int i;

	ret = -1;
	if (out[*j] == '.')
	{
		(*j)++;
		ret = 0;
	}
	i = ft_in1(out[*j], "0123456789");
	while (out[*j] != '\0' && i != -1)
	{
		ret = ret * 10 + i;
		(*j)++;
		i = ft_in1(out[*j], "0123456789");
	}
	return (ret);
}

int		get_l_m(char *out, int *j)
{
	int i;
	int ret;
	int i1;

	ret = 0;
	i1 = 0;
	i = ft_in1(out[*j], "lhLjz");
	if (i != -1)
	{
		i1 = ft_in1(out[*j + 1], "lh");
		if (i1 == -1)
			ret = i + 1;
		else
		{
			ret = i + 5;
			if (i == i1)
				(*j)++;
		}
		(*j)++;
	}
	return (ret);
}

int		get_c_c(char *out, int *j)
{
	if (out[*j] != '\0')
		return (ft_in1(out[*j], "cspdiouxXf%FbBDS") + 1);
	return (0);
}

void	get_tags(char **out, t_tags **tags)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (out[k] != NULL)
	{
		j = 0;
		(*tags)[i].flags = get_flags(out[k + 1], &j);
		(*tags)[i].f_w = get_f_w(out[k + 1], &j);
		(*tags)[i].precision = get_precision(out[k + 1], &j);
		(*tags)[i].l_m = get_l_m(out[k + 1], &j);
		(*tags)[i].c_c = get_c_c(out[k + 1], &j);
		i++;
		k += 2;
	}
}
