/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 21:11:07 by ielmoudn          #+#    #+#             */
/*   Updated: 2019/07/21 21:11:12 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	*charset;

	if (!s || !c)
		return (NULL);
	if (!(charset = ft_strnew(2)))
		return (NULL);
	charset[0] = c;
	return (ft_strsplitchrset((char*)s, charset));
}
