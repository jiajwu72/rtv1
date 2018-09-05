/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:47:58 by klin              #+#    #+#             */
/*   Updated: 2017/11/13 18:01:40 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_atoi_result(const char *str, int i, int negatif)
{
	int val;

	val = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		val *= 10;
		val += (str[i] - '0');
		i++;
	}
	if (negatif == 1)
		val = -val;
	return (val);
}

int				ft_atoi(const char *str)
{
	int		i;
	int		negatif;

	i = 0;
	negatif = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		negatif = 1;
		i++;
	}
	return (ft_atoi_result(str, i, negatif));
}
