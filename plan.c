/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:42:42 by jwu               #+#    #+#             */
/*   Updated: 2018/05/12 17:42:43 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_plane				*get_plane(t_obj *obj)
{
	return ((t_plane *)(obj->data));
}

t_plane				*plane(t_vect n, double d, t_color color)
{
	t_plane		*s;

	if ((s = malloc(sizeof(t_plane))) == NULL)
		return (NULL);
	s->normal = n;
	s->distance = d;
	s->color = color;
	return (s);
}

double				plane_inter(t_ray ray, t_obj *s)
{
	double			a;
	double			b;

	a = dot(ray.d, get_plane(s)->normal);
	if (a == 0)
		return (-1);
	b = dot(get_plane(s)->normal, somme(ray.o,
		negative(produit_const(get_plane(s)->distance, get_plane(s)->normal))));
	return (-b / a);
}

t_vect				plane_normal(t_obj *o, t_vect v)
{
	v.x = 0;
	return (get_plane(o)->normal);
}

t_obj				*init_plane(t_vect o, double r, t_color color)
{
	t_obj			*obj;

	if ((obj = malloc(sizeof(t_obj))) == NULL)
		return (NULL);
	obj->data = plane(o, r, color);
	obj->color = color;
	obj->inter = &plane_inter;
	obj->normal = &plane_normal;
	obj->next = NULL;
	obj->dir = o;
	obj->pos = init_vect(0, 0, 0);
	return (obj);
}
