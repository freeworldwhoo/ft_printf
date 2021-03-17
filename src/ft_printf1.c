/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:22:23 by rnbou             #+#    #+#             */
/*   Updated: 2021/03/17 17:10:14 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ilist	*ft_ilistnew(int i)
{
	t_ilist *l;

	l = malloc(sizeof(t_ilist));
	l->val = i;
	l->next = NULL;
	return (l);
}

int		ft_in(char c, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_sep1(int *i, int *j, char *d)
{
	(*i) += 1;
	if (d[*j] != '\0')
		(*j)++;
	while (ft_in(d[*j], "-+#0 "))
		(*j)++;
	while (ft_isdigit(d[*j]) == 1)
		(*j)++;
	if (d[*j] == '.')
		(*j)++;
	while (ft_isdigit(d[*j]) == 1)
		(*j)++;
	if (ft_in(d[*j], "hl"))
	{
		if (d[*j] == d[*j + 1])
			(*j)++;
		(*j)++;
	}
	else if (ft_in(d[*j], "Ljz"))
		(*j)++;
	if (ft_in(d[*j], "cspdiouxXf%FbBDS"))
		(*j)++;
}

t_ilist	*ft_sep(char *d, int *i)
{
	int		j;
	t_ilist	*l;
	t_ilist	*t;

	j = 0;
	l = ft_ilistnew(0);
	t = l;
	(*i) = 0;
	while (d[j] != '\0')
	{
		while (d[j] != '%' && d[j] != '\0')
			j++;
		t->next = ft_ilistnew(j);
		t = t->next;
		ft_sep1(i, &j, d);
		t->next = ft_ilistnew(j);
		t = t->next;
		(*i) += 1;
	}
	t->next = NULL;
	return (l);
}

char	**getall(char *d, t_ilist *p, int i)
{
	char	**out;
	t_ilist	*a;
	t_ilist	*b;
	int		j;

	out = (char **)malloc(sizeof(char *) * (i + 1));
	j = 0;
	a = p;
	b = a->next;
	while (j < i)
	{
		out[j++] = ft_strsub(d, a->val, b->val - a->val);
		a = b;
		b = a->next;
	}
	out[j] = NULL;
	return (out);
}
