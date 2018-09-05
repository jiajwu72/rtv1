/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:57:43 by jwu               #+#    #+#             */
/*   Updated: 2018/05/17 18:57:44 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cylindre			*get_cylindre(t_obj *obj)
{
	return ((t_cylindre *)(obj->data));
}

t_cylindre			*cylindre(t_vect center, t_vect axis,
								double r, t_color color)
{
	t_cylindre		*s;

	if ((s = malloc(sizeof(t_cylindre))) == NULL)
		return (NULL);
	s->centre = center;
	s->axis = normalize(axis);
	s->r = r;
	s->color = color;
	return (s);
}

t_vect				cylindre_normal(t_obj *obj, t_vect p)
{
	double		m;
	t_vect		res;

	m = dot(difference(p, obj->pos), obj->dir);
	res = somme(obj->pos,
			produit_const(m, obj->dir));
	res = normalize(difference(p, res));
	return (res);
}

double				cylindre_inter(t_ray ray, t_obj *obj)
{
	double a;
	double b;
	double c;
	double d;
	double t;

	a = dot(ray.d, ray.d) - (dot(ray.d, obj->dir) *
		dot(ray.d, obj->dir));
	b = 2 * (dot(ray.d, difference(ray.o, obj->pos))
		- (dot(ray.d, obj->dir) * dot(difference(
			ray.o, obj->pos), obj->dir)));
	c = dot(difference(ray.o, obj->pos), difference(ray.o,
		obj->pos)) - (dot(difference(ray.o,
		obj->pos), obj->dir)
		* dot(difference(ray.o, obj->pos),
		obj->dir)) - pow(get_cylindre(obj)->r, 2);
	d = pow(b, 2) - 4 * a * c;
	if (d >= 0)
	{
		t = (-b - sqrt(d)) / (2 * a);
		if (t < 0)
			return ((-b + sqrt(d)) / (2 * a));
		return (t);
	}
	return (-1);
}

t_obj				*init_cylindre(t_vect c, t_vect v,
					double angle, t_color color)
{
	t_obj			*obj;

	if ((obj = malloc(sizeof(t_obj))) == NULL)
		return (NULL);
	obj->data = cylindre(c, v, angle, color);
	obj->color = color;
	obj->inter = &cylindre_inter;
	obj->normal = &cylindre_normal;
	obj->pos = c;
	obj->dir = normalize(v);
	obj->next = NULL;
	return (obj);
}
