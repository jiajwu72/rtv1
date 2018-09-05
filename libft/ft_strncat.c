/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:48:35 by klin              #+#    #+#             */
/*   Updated: 2017/11/15 14:53:28 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		cpt1;
	size_t		cpt2;

	cpt1 = 0;
	cpt2 = 0;
	if (!n)
		return (s1);
	while (s1[cpt1] != '\0')
		cpt1++;
	while (s2[cpt2] != '\0' && cpt2 < n)
	{
		s1[cpt1 + cpt2] = s2[cpt2];
		cpt2++;
	}
	s1[cpt1 + cpt2] = '\0';
	return (s1);
}
