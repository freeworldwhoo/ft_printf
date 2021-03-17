/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 18:46:15 by rnbou             #+#    #+#             */
/*   Updated: 2021/03/17 17:09:28 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*f_w_helper(t_tags tag, int len)
{
	char *ret;

	if ((tag.flags >> 3) % 2 == 1 && tag.flags % 2 != 1)
		ret = ft_get_zeros(len);
	else
		ret = ft_get_space(len);
	return (ret);
}

void	ft_printf_s(t_tags tag, va_list l)
{
	char	*fw;
	int		i;
	int		len;
	char	*var;

	var = (char *)va_arg(l, char*);
	if (var == NULL)
		var = "(null)";
	len = ft_strlen(var);
	if (tag.precision < len && tag.precision >= 0)
		fw = f_w_helper(tag, tag.f_w - tag.precision);
	else
		fw = f_w_helper(tag, tag.f_w - len);
	if (tag.flags % 2 == 0)
		ft_putstr(fw);
	i = 0;
	while (i < len && i < (tag.precision + ((len + 1) * (tag.precision < 0))))
		ft_putchar(var[i++]);
	if (tag.flags % 2 == 1)
		ft_putstr(fw);
	free(fw);
}
