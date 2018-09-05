/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:17:58 by klin              #+#    #+#             */
/*   Updated: 2017/11/15 11:42:49 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	size;
	unsigned int	i;
	char			*result;
	char			*copy;

	if (!f || !s)
		return ((char*)s);
	size = ft_strlen(s);
	i = 0;
	copy = (char*)s;
	result = (char*)malloc(sizeof(*result) * size + 1);
	if (!result)
		return (NULL);
	while (i < size)
	{
		result[i] = f(i, copy[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
