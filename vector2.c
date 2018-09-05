/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:46:39 by jwu               #+#    #+#             */
/*   Updated: 2018/05/12 17:46:39 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double				dot(t_vect v1, t_vect v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vect				normalize(t_vect v)
{
	double n;

	n = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (init_vect(v.x / n, v.y / n, v.z / n));
}

t_vect				cross_product(t_vect u, t_vect v)
{
	return (init_vect(u.y * v.z - u.z * v.y,
		u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x));
}

t_vect				negative(t_vect v)
{
	return (init_vect(-v.x, -v.y, -v.z));
}

t_vect				quotient_const(double a, t_vect v2)
{
	t_vect			v;

	v.x = v2.x / a;
	v.y = v2.y / a;
	v.z = v2.z / a;
	return (v);
}
