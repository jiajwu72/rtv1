/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcmp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:15:09 by klin              #+#    #+#             */
/*   Updated: 2018/01/15 15:23:44 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		index;

	index = 0;
	while (s1[index] == s2[index])
	{
		if (s1[index] == '\0')
			return (0);
		index++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
