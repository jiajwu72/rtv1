/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:26:16 by klin              #+#    #+#             */
/*   Updated: 2017/11/13 12:50:15 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	char			*cpystr1;
	unsigned int	len;

	if (*str2 == '\0')
		return ((char *)str1);
	len = ft_strlen(str2);
	cpystr1 = (char *)str1;
	while (*cpystr1)
	{
		if (ft_memcmp(cpystr1, str2, len) == 0)
			return (cpystr1);
		cpystr1++;
	}
	return (NULL);
}
