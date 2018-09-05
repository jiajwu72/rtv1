/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:33:26 by jwu               #+#    #+#             */
/*   Updated: 2018/04/26 14:33:27 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				put_pixel(int a, int b, t_env e, t_color color)
{
	int				i;

	i = (a * 4) + (b * e.image.s_line);
	e.image.pixel_img[i] = color.b;
	e.image.pixel_img[++i] = color.g;
	e.image.pixel_img[++i] = color.r;
}

void				def_xyam(int x, int y, double *xam, double *yam)
{
	double			asp;

	asp = (double)WINX / (double)WINY;
	if (WINX > WINY)
	{
		*xam = ((x + 0.5) / WINX) * asp - (((WINX - WINY) / (double)WINY) / 2);
		*yam = ((WINY - (WINY - y)) + 0.5) / WINY;
	}
	else if (WINY > WINX)
	{
		*xam = (x + 0.5) / WINX;
		*yam = (((WINY - (WINY - y)) + 0.5) / WINY) /
		asp - (((WINY - WINX) / (double)WINX) / 2);
	}
	else
	{
		*xam = (x + 0.5) / WINX;
		*yam = ((WINY - (WINY - y)) + 0.5) / WINY;
	}
}

t_vect				inter_pt(t_vect o, t_vect dir, double t)
{
	return (somme(o, produit_const(t, dir)));
}

void				def_block(t_env *e, t_ray light_ray,
					double dist_to_close, t_obj *close_obj)
{
	double			inter;

	while (e->obj)
	{
		if (e->obj != close_obj)
			if ((inter = e->obj->inter(light_ray, e->obj)) > 0 &&
				inter < dist_to_close)
				e->blocked = 1;
		e->obj = e->obj->next;
	}
}
