/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:58:27 by klin              #+#    #+#             */
/*   Updated: 2017/11/13 11:40:58 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destcpy;
	char		*srccpy;

	destcpy = (char *)dest;
	srccpy = (char *)src;
	while (n > 0)
	{
		*destcpy++ = *srccpy++;
		n--;
	}
	return (dest);
}
