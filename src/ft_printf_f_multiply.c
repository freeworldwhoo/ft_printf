/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f_multiply.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 19:42:41 by rnbou             #+#    #+#             */
/*   Updated: 2021/03/17 17:08:34 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_multiply(size_t **k, int l)
{
	size_t	*b;
	int		i;

	i = 0;
	b = (size_t *)malloc(sizeof(size_t) * l);
	while (i < l)
	{
		b[i] = (*k)[i];
		i++;
	}
	bit_shift_left(k, 3, l);
	bit_shift_left(&b, 1, l);
	ft_add(k, &b, l);
	free(b);
}
