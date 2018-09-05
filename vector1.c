/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 02:58:14 by jwu               #+#    #+#             */
/*   Updated: 2018/05/24 02:58:14 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double				magnitude(t_vect v)
{
	return (sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}

t_vect				unit(t_vect v, t_vect v1)
{
	if (v.x >= 0)
	{
		if (v1.x >= 0)
			return (v1);
		return (negative(v1));
	}
	if (v.x < 0)
	{
		if (v1.x < 0)
			return (v1);
	}
	return (negative(v1));
}
