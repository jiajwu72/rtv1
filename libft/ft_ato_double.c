/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:20:23 by klin              #+#    #+#             */
/*   Updated: 2018/05/22 14:38:49 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double		calc_double(const char *str, int i)
{
	int		nb_d;
	double	val;

	nb_d = 1;
	val = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		val *= 10;
		val += (str[i] - '0');
		nb_d *= 10;
		i++;
	}
	return (val / nb_d);
}

static double		ft_ato_double_result(const char *str, int i, int negatif)
{
	double	val;
	double	val2;

	val = 0;
	val2 = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		val *= 10;
		val += (str[i] - '0');
		i++;
	}
	if (str[i] == 46 || str[i] == 44)
		val2 = (calc_double(str, ++i));
	val += val2;
	if (negatif == 1)
		val = -val;
	return (val);
}

double				ft_ato_double(const char *str)
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
	return (ft_ato_double_result(str, i, negatif));
}
