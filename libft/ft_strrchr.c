/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:30:32 by klin              #+#    #+#             */
/*   Updated: 2017/11/11 12:23:24 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*copy;
	char	*result;

	copy = (char*)s;
	result = NULL;
	while (*copy)
	{
		if (*copy == (char)c)
			result = copy;
		copy++;
	}
	if ((char)c == '\0')
		result = copy;
	return (result);
}
