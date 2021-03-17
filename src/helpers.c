/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnbou <rnbou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 01:01:00 by rnbou             #+#    #+#             */
/*   Updated: 2021/03/17 18:31:32 by rnbou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_space(int l)
{
	int		i;
	char	*ret;

	if (l < 0)
		l = 0;
	ret = (char *)malloc(l + 1);
	i = 0;
	while (i < l)
		ret[i++] = ' ';
	ret[i] = '\0';
	return (ret);
}

char	*ft_get_zeros(int l)
{
	int		i;
	char	*ret;

	if (l < 0)
		l = 0;
	ret = (char *)malloc(l + 1);
	ret[l] = '\0';
	i = 0;
	while (i < l)
		ret[i++] = '0';
	return (ret);
}

t_f		ft_get_functions(int i)
{
	t_f function;

	if (i == 1)
		function = &ft_printf_c;
	else if (i == 2)
		function = &ft_printf_s;
	else if (i == 3)
		function = &ft_printf_p;
	else if (i > 3 && i < 6)
		function = &ft_printf_d;
	else if ((i > 5 && i < 10) || i == 13)
		function = &ft_printf_u;
	else if (i == 10 || i == 12)
		function = &ft_printf_f;
	else if (i == 11)
		function = &ft_printf_pr;
	else if (i == 14)
		function = &ft_printf_base;
	else
		function = NULL;
	return (function);
}

void	print_nbr(long long unsigned int nbr, char *base, unsigned int b)
{
	if (nbr < b)
		ft_putchar(base[nbr]);
	else
	{
		print_nbr(nbr / b, base, b);
		print_nbr(nbr % b, base, b);
	}
}

int		number_lenth(t_tags tag, long long unsigned int nbr, int b)
{
	int i;

	i = 0;
	if (nbr == 0 && tag.precision == 0)
		return (0);
	else if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / b;
		i++;
	}
	return (i);
}
