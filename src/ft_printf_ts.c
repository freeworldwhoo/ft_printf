/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 22:56:19 by rnbou             #+#    #+#             */
/*   Updated: 2021/03/17 17:09:47 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_ts(t_tags tag, va_list l, char *str)
{
	char	**table;
	size_t	len;
	size_t	i;
	size_t	l1;

	tag.c_c = 0;
	table = (char **)va_arg(l, char**);
	len = (size_t)va_arg(l, size_t);
	i = 0;
	l1 = ft_strlen(str);
	str[l1 - 1] = 's';
	while (i < len - 1)
		ft_printf_rep(str, table[i++]);
	ft_printf_rep(str, table[i]);
}
