/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:42:27 by jwu               #+#    #+#             */
/*   Updated: 2018/05/12 17:42:28 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere			*get_sphere(t_obj *obj)
{
	return ((t_sphere *)(obj->data));
}

t_sphere			*sphere(t_vect o, double r, t_color color)
{
	t_sphere		*s;

	if ((s = malloc(sizeof(t_sphere))) == NULL)
		return (NULL);
	s->o = o;
	s->r = r;
	s->color = color;
	return (s);
}

t_vect				sphere_normal(t_obj *obj, t_vect p)
{
	t_vect			normal;

	normal = somme(p, negative(obj->pos));
	return (normal);
}

double				sphere_inter(t_ray ray, t_obj *s)
{
	double			a;
	double			b;
	double			c;
	double			disc;
	double			r;

	a = 1;
	b = 2 * ((ray.o.x - s->pos.x) * ray.d.x + (ray.o.y - s->pos.y) * ray.d.y +
		(ray.o.z - s->pos.z) * ray.d.z);
	c = pow(ray.o.x - s->pos.x, 2) + pow(ray.o.y - s->pos.y, 2) +
		pow(ray.o.z - s->pos.z, 2) - pow(get_sphere(s)->r, 2);
	disc = b * b - 4 * c;
	if (disc > 0)
	{
		r = ((-b - sqrt(disc)) / 2) - 0.000001;
		if (r > 0)
			return (r);
		else
		{
			r = ((sqrt(disc) - b) / 2) - 0.000001;
			return (r);
		}
	}
	return (-1);
}

t_obj				*init_sphere(t_vect o, double r, t_color color)
{
	t_obj			*obj;

	if ((obj = malloc(sizeof(t_obj))) == NULL)
		return (NULL);
	obj->data = sphere(o, r, color);
	obj->color = color;
	obj->inter = &sphere_inter;
	obj->normal = &sphere_normal;
	obj->pos = o;
	obj->dir = init_vect(0, 0, 0);
	obj->next = NULL;
	return (obj);
}
