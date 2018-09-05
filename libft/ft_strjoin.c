/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:46:12 by klin              #+#    #+#             */
/*   Updated: 2017/11/15 12:55:52 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*result;

	if (!s2)
		return ((char *)s1);
	else if (!s1)
		return ((char *)s2);
	size = ft_strlen(s1) + ft_strlen(s2);
	result = (char*)malloc(sizeof(result) * size + 1);
	if (result)
	{
		result = ft_strcpy(result, s1);
		result = ft_strcat(result, s2);
		return (result);
	}
	return (NULL);
}
