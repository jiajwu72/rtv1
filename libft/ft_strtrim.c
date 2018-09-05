/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:47:09 by klin              #+#    #+#             */
/*   Updated: 2017/11/15 11:48:35 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		test1(char const *s)
{
	int		val;

	val = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		val++;
		s++;
	}
	return (val);
}

static int		test2(char const *s)
{
	int		val;
	int		i;

	val = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			val++;
		else
			val = 0;
		i++;
	}
	return (val);
}

char			*ft_strtrim(char const *s)
{
	int		start;
	int		size;
	int		i;
	char	*result;

	if (!s)
		return ((char*)s);
	i = 0;
	start = test1(s);
	if (start == (int)ft_strlen(s))
		size = start;
	else
		size = ft_strlen(s) - start - test2(s);
	result = (char*)malloc(sizeof(*result) * size + 1);
	if (result)
	{
		while (i < size)
		{
			result[i] = s[start + i];
			i++;
		}
		result[i] = '\0';
		return (result);
	}
	return (NULL);
}
