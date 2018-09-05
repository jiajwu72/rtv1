/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:19:32 by klin              #+#    #+#             */
/*   Updated: 2017/11/11 12:50:12 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	int		size;

	size = ft_strlen(s);
	result = (char*)malloc(sizeof(*result) * size + 1);
	if (!result)
		return (NULL);
	result = ft_strcpy(result, s);
	return (result);
}
