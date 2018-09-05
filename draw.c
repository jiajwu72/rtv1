/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:36:26 by jwu               #+#    #+#             */
/*   Updated: 2018/05/12 17:36:26 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color				gg(t_env *e, t_color color, t_obj *obj, double dt)
{
	int				r;
	int				g;
	int				b;

	r = ((color.r * e->luminosite + obj->color.r) * dt) * 0.5;
	g = ((color.g * e->luminosite + obj->color.g) * dt) * 0.5;
	b = ((color.b * e->luminosite + obj->color.b) * dt) * 0.5;
	return (init_color(r, g, b));
}

t_color				final_color(t_env *e, t_obj *obj,
					t_vect inter, t_light *l)
{
	double			angle;
	t_vect			light_vec;
	t_vect			normal;

	normal = obj->normal(obj, inter);
	light_vec = normalize(difference(inter, l->pos));
	angle = dot(normal, negative(light_vec));
	if (angle <= 0)
		return (init_color(0, 0, 0));
	else
		return (gg(e, l->color, obj, angle));
}

t_color				gere_color(t_vect inter_pos, t_obj *close_obj, t_env *e)
{
	t_ray			light_ray;
	t_light			*l;
	t_obj			*obj;
	double			dist_to_close;

	l = e->light;
	obj = e->obj;
	e->fcolor = eclairer(close_obj->color, e->ambiance);
	while (e->light)
	{
		e->blocked = 0;
		light_ray = init_ray(e->light->pos,
			normalize(difference(inter_pos, e->light->pos)));
		dist_to_close = close_obj->inter(light_ray, close_obj);
		def_block(e, light_ray, dist_to_close, close_obj);
		e->obj = obj;
		if (e->blocked == 0)
			e->fcolor = normalize_color(add_color(e->fcolor, final_color(
			e, close_obj, inter_pos, e->light)));
		e->light = e->light->next;
	}
	e->light = l;
	return (e->fcolor);
}

t_color				ray_trace(t_env *e, t_ray ray)
{
	t_color			color;
	t_obj			*obj;
	t_obj			*win_obj;
	double			inter;

	e->dist = 99999;
	obj = e->obj;
	while (obj)
	{
		inter = obj->inter(ray, obj);
		if (e->dist > inter && inter > 0)
		{
			e->dist = inter;
			color = obj->color;
			win_obj = obj;
		}
		obj = obj->next;
	}
	if (e->dist - 0.0001 > 0 && e->dist != 99999)
	{
		return (gere_color(somme(ray.o,
		produit_const(e->dist, ray.d)), win_obj, e));
	}
	return (init_color(0, 0, 0));
}

void				draw(t_env *e)
{
	int				x;
	int				y;
	double			xamnt;
	double			yamnt;

	y = 0;
	while (y < WINY)
	{
		x = 0;
		while (x < WINX)
		{
			def_xyam(x, y, &xamnt, &yamnt);
			put_pixel(x, y, *e, ray_trace(e, init_ray(e->camera.pos, normalize(
				somme(somme(e->camera.dir,
				produit_const(xamnt - 0.5, e->camera.right)),
				produit_const(yamnt - 0.5, e->camera.down))))));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->image.img, 0, 0);
}
