/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 15:10:01 by jwu               #+#    #+#             */
/*   Updated: 2018/06/01 15:10:18 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				rot_x(t_vect *v, int signe)
{
	v->y = cos(0.1 * signe) * v->y - sin(0.1 * signe) * v->z;
	v->z = sin(0.1 * signe) * v->y + cos(0.1 * signe) * v->z;
}

void				rot_y(t_vect *v, int signe)
{
	v->x = cos(0.1 * signe) * v->x + sin(0.1 * signe) * v->z;
	v->z = -sin(0.1 * signe) * v->x + cos(0.1 * signe) * v->z;
}

void				rot_z(t_vect *v, int signe)
{
	v->x = cos(0.1 * signe) * v->x - sin(0.1 * signe) * v->y;
	v->y = sin(0.1 * signe) * v->x + cos(0.1 * signe) * v->y;
}
