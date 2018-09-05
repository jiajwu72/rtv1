/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:56:38 by klin              #+#    #+#             */
/*   Updated: 2017/11/11 12:24:24 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*copy;

	copy = (char*)s;
	while (*copy)
	{
		if (*copy == (char)c)
			return (copy);
		copy++;
	}
	if ((char)c == '\0')
		return (copy);
	return (NULL);
}
