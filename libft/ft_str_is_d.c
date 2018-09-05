/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 17:52:40 by klin              #+#    #+#             */
/*   Updated: 2018/05/22 14:19:37 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		test_double(char *s, int i)
{
	int		i2;

	i2 = i;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
		i++;
	}
	if (i == i2)
		return (0);
	return (1);
}

int				ft_str_is_d(char *s)
{
	int		i;

	i = 0;
	if (s[i] && (s[i] == 45 || s[i] == 43))
		i++;
	while (s[i])
	{
		if (s[i] == 46 || s[i] == 44)
			return (test_double(s, ++i));
		else if (s[i] < 48 || s[i] > 57)
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}
