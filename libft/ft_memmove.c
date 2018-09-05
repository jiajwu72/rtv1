/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:22:48 by klin              #+#    #+#             */
/*   Updated: 2017/11/13 12:06:44 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cpy_dst;
	char	*cpy_src;

	cpy_src = (char *)src;
	cpy_dst = dst;
	if (cpy_src <= cpy_dst)
	{
		cpy_dst += len - 1;
		cpy_src += len - 1;
		while (len--)
			*cpy_dst-- = *cpy_src--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
