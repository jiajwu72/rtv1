/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:08:32 by klin              #+#    #+#             */
/*   Updated: 2017/11/15 11:41:47 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		size;
	int		i;
	char	*result;
	char	*copy;

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
		result[i] = f(copy[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
