/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_td.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 22:41:57 by rnbou             #+#    #+#             */
/*   Updated: 2021/03/17 17:09:39 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_td(t_tags tag, va_list l, char *str)
{
	int		*table;
	size_t	len;
	size_t	i;
	size_t	l1;

	tag.c_c = 0;
	table = (int *)va_arg(l, int*);
	len = (size_t)va_arg(l, size_t);
	i = 0;
	l1 = ft_strlen(str);
	str[l1 - 1] = 'd';
	while (i < len - 1)
		ft_printf_rep(str, table[i++]);
	ft_printf_rep(str, table[i]);
}
