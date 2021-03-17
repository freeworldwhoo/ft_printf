/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:22:23 by rnbou             #+#    #+#             */
/*   Updated: 2021/03/17 17:10:05 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_len_tags(char **out)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (out[k] != NULL)
	{
		k += 2;
		i++;
	}
	return (i);
}

void	replace_tags(t_tags tag, va_list l, char *str)
{
	t_f function;

	if (tag.c_c == 15)
		ft_printf_td(tag, l, str);
	else if (tag.c_c == 16)
		ft_printf_ts(tag, l, str);
	else
	{
		function = ft_get_functions(tag.c_c);
		if (function != NULL)
			function(tag, l);
	}
}

void	ft_printf_rep(char *d, ...)
{
	char	**out;
	int		i;
	t_tags	*tags;
	int		j;
	va_list	l;

	out = get_separate(d, &i);
	tags = malloc(sizeof(t_tags) * (i / 2 + 1));
	get_tags(out, &tags);
	va_start(l, d);
	j = -1;
	while (out[++j] != NULL)
	{
		if (j % 2 == 0)
			ft_putstr(out[j]);
		else
			replace_tags(tags[j / 2], l, out[j]);
	}
	va_end(l);
	free(tags);
	j = 0;
	while (j < i)
		free(out[j++]);
	free(out);
}

int		ft_printf(char *d, ...)
{
	char	**out;
	int		i;
	t_tags	*tags;
	int		j;
	va_list	l;

	out = get_separate(d, &i);
	tags = malloc(sizeof(t_tags) * (i / 2 + 1));
	get_tags(out, &tags);
	va_start(l, d);
	j = -1;
	while (out[++j] != NULL)
	{
		if (j % 2 == 0)
			ft_putstr(out[j]);
		else
			replace_tags(tags[j / 2], l, out[j]);
	}
	va_end(l);
	free(tags);
	j = 0;
	while (j < i)
		free(out[j++]);
	free(out);
	return (ft_putchar(300));
}
