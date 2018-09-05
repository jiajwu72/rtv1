/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:24:31 by jwu               #+#    #+#             */
/*   Updated: 2018/05/12 17:24:31 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect				init_vect(double x, double y, double z)
{
	t_vect			v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vect				somme(t_vect v1, t_vect v2)
{
	t_vect			v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return (v);
}

t_vect				difference(t_vect v1, t_vect v2)
{
	t_vect			v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return (v);
}

t_vect				produit_const(double a, t_vect v2)
{
	t_vect			v;

	v.x = a * v2.x;
	v.y = a * v2.y;
	v.z = a * v2.z;
	return (v);
}

t_vect				produit(t_vect v1, t_vect v2)
{
	t_vect			v;

	v.x = v1.x * v2.x;
	v.y = v1.y * v2.y;
	v.z = v1.z * v2.z;
	return (v);
}
