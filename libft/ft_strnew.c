/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:41:02 by klin              #+#    #+#             */
/*   Updated: 2017/11/15 15:32:06 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*result;

	result = (char *)malloc(sizeof(*result) * size + 1);
	if (!result)
		return (NULL);
	ft_bzero(result, size + 1);
	return (result);
}
