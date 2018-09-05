/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:25:02 by klin              #+#    #+#             */
/*   Updated: 2017/11/15 16:40:05 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	find_len;
	size_t	i;
	size_t	res;

	i = 0;
	if (*find == '\0')
		return ((char *)str);
	i = 0;
	find_len = ft_strlen(find);
	while (*str && i < len)
	{
		res = len - i;
		if (res < find_len)
			return (NULL);
		if (ft_memcmp(str, find, find_len) == 0)
			return ((char*)str);
		str++;
		i++;
	}
	return (NULL);
}
