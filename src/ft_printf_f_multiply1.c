/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f_multiply1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 01:28:11 by rnbou             #+#    #+#             */
/*   Updated: 2021/03/17 17:08:41 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ver_carry(size_t *carry, int l)
{
	int i;

	i = 0;
	while (i < l)
	{
		if (carry[i] != 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_cp(size_t *c, size_t **b, int l)
{
	int i;

	i = 0;
	while (i < l)
	{
		(*b)[i] = c[i];
		i++;
	}
}

void	ft_and(size_t *a, size_t *b, size_t **c, int l)
{
	int i;

	i = 0;
	while (i < l)
	{
		(*c)[i] = a[i] & b[i];
		i++;
	}
}

void	ft_xor(size_t **a, size_t *b, int l)
{
	int i;

	i = 0;
	while (i < l)
	{
		(*a)[i] = (*a)[i] ^ b[i];
		i++;
	}
}

void	ft_add(size_t **a, size_t **b, int l)
{
	size_t *carry;

	carry = (size_t*)malloc(sizeof(size_t) * l);
	while (ver_carry(*b, l) == 1)
	{
		ft_and(*a, *b, &carry, l);
		ft_xor(a, *b, l);
		ft_cp(carry, b, l);
		bit_shift_left(b, 1, l);
	}
	free(carry);
}
