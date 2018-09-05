/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:08:26 by klin              #+#    #+#             */
/*   Updated: 2017/11/14 18:35:39 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoa_result(unsigned int n, int n_size, int tab_size,
		int negatif)
{
	char			*str;
	int				i;

	i = 0;
	str = (char*)malloc(sizeof(*str) * tab_size + 1 + negatif);
	if (!str)
		return (NULL);
	if (negatif)
		str[i++] = '-';
	while (i < (tab_size + negatif))
	{
		str[i] = (n / n_size + '0');
		n %= n_size;
		n_size /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	unsigned int	val;
	int				tab_size;
	int				n_size;
	int				negatif;

	n_size = 1;
	tab_size = 1;
	negatif = 0;
	if (n < 0)
		negatif = 1;
	val = ABS(n);
	while ((val / 10) > 0)
	{
		val /= 10;
		n_size *= 10;
		tab_size++;
	}
	val = ABS(n);
	return (ft_itoa_result(val, n_size, tab_size, negatif));
}
