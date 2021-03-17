/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:22:23 by rnbou             #+#    #+#             */
/*   Updated: 2021/03/17 17:10:22 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del_ilist(t_ilist *ilist)
{
	if (ilist != NULL)
	{
		ft_del_ilist(ilist->next);
		free(ilist);
	}
}

char	**get_separate(char *d, int *i)
{
	char	**out;
	t_ilist	*p;

	p = ft_sep(d, i);
	out = getall(d, p, *i);
	ft_del_ilist(p);
	return (out);
}

int		ft_in1(char c, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		get_flags(char *out, int *j)
{
	int ret;
	int i;

	ret = 0;
	if (out[*j] == '%')
		(*j)++;
	i = ft_in1(out[*j], "-+#0 ");
	while (out[*j] != '\0' && i != -1)
	{
		if ((ret >> i) % 2 == 0)
			ret += 1 << i;
		(*j)++;
		i = ft_in1(out[*j], "-+#0 ");
	}
	return (ret);
}
