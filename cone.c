/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:57:28 by jwu               #+#    #+#             */
/*   Updated: 2018/05/17 18:57:29 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cone				*get_cone(t_obj *obj)
{
	return ((t_cone *)(obj->data));
}

t_cone				*cone(t_vect c, t_vect v, double angle, t_color color)
{
	t_cone		*s;

	if ((s = malloc(sizeof(t_cone))) == NULL)
		return (NULL);
	s->c = c;
	s->v = normalize(v);
	s->angle = angle;
	s->color = color;
	return (s);
}

t_vect				cone_normal(t_obj *obj, t_vect p)
{
	double		m;
	t_vect		res;

	m = pow(magnitude(difference(p, obj->pos)), 2) /
		dot(obj->dir, difference(p, obj->pos));
	res = somme(obj->pos, produit_const(m, obj->dir));
	res = normalize(difference(p, res));
	return (res);
}

double				cone_inter(t_ray ray, t_obj *s)
{
	double	a;
	double	b;
	double	c;
	double	d;
	t_vect	co;

	co = difference(ray.o, s->pos);
	a = dot(ray.d, ray.d) - (1 + pow(tan(get_cone(s)->angle
		* PI / 180), 2)) * pow(dot(ray.d, s->dir), 2);
	b = 2 * (dot(ray.d, co) - (1 + pow(tan(get_cone(s)->angle
		* PI / 180), 2)) * dot(ray.d, s->dir) *
		dot(co, s->dir));
	c = dot(co, co) - (1 + pow(tan(get_cone(s)->angle *
		PI / 180), 2)) * pow(dot(co, s->dir), 2);
	if ((d = b * b - 4 * a * c) >= 0)
	{
		if ((s->t = (-b - sqrt(d)) / (2 * a)) < 0 &&
				(-b + sqrt(d)) / (2 * a) < 0)
			return (s->t = -1);
	}
	else
		s->t = 0;
	return (s->t);
}

t_obj				*init_cone(t_vect c, t_vect v, double angle, t_color color)
{
	t_obj			*obj;

	if ((obj = malloc(sizeof(t_obj))) == NULL)
		return (NULL);
	obj->data = cone(c, v, angle, color);
	obj->color = color;
	obj->inter = &cone_inter;
	obj->normal = &cone_normal;
	obj->pos = c;
	obj->dir = normalize(v);
	obj->next = NULL;
	return (obj);
}
