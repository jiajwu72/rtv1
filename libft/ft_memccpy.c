/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:05:03 by klin              #+#    #+#             */
/*   Updated: 2017/11/13 13:23:05 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*destcopy;
	unsigned char		*srccopy;

	destcopy = (unsigned char *)dest;
	srccopy = (unsigned char *)src;
	while (n > 0)
	{
		*destcopy = *srccopy;
		if (*srccopy == (unsigned char)c)
			return (++destcopy);
		srccopy++;
		destcopy++;
		n--;
	}
	return (NULL);
}
