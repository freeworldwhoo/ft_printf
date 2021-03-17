/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcntfirstchar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 21:09:17 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/21 21:09:22 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strcntfirstchar(char *str, const char *charset)
{
	char			*ptr;
	int				index;
	unsigned int	count;
	unsigned int	tmp;

	ptr = str;
	count = 0;
	while (*ptr)
	{
		index = 0;
		tmp = count;
		while (charset[index])
			if (charset[index++] == *ptr)
				++count;
		if (count == tmp)
			return (count);
		++ptr;
	}
	return (count);
}
