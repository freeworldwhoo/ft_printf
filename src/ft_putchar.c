/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 21:08:12 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/21 21:08:17 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	static int	*counter;
	int			i;
	char		k;

	k = (char)c;
	if (counter == NULL)
	{
		counter = (int *)malloc(sizeof(int));
		counter[0] = 0;
	}
	if (c != 300)
	{
		counter[0] += 1;
		write(1, &k, 1);
		i = counter[0];
	}
	else
	{
		i = counter[0];
		free(counter);
		counter = NULL;
	}
	return (i);
}
