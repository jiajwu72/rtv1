/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:43:58 by klin              #+#    #+#             */
/*   Updated: 2017/11/11 12:02:51 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*copy1;
	unsigned char	*copy2;
	size_t			i;

	copy1 = (unsigned char*)s1;
	copy2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (copy1[i] != copy2[i])
			return (copy1[i] - copy2[i]);
		i++;
	}
	return (0);
}
