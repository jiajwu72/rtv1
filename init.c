/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:33:43 by jwu               #+#    #+#             */
/*   Updated: 2018/05/12 17:33:45 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void					init_img(t_env *e)
{
	(*e).image.img = mlx_new_image((*e).mlx, WINX, WINY);
	(*e).image.pixel_img = mlx_get_data_addr((*e).image.img, &((*e).image.bpp),
						&((*e).image.s_line), &((*e).image.ed));
}

void					init(t_env *env)
{
	env->luminosite = 1;
	env->ambiance = 0.2;
	env->obj = NULL;
	env->light = NULL;
	env->has_cam = 0;
	if ((env->mlx = mlx_init()) == NULL)
	{
		free_env(env);
		ft_putendl("Malloc Error");
		exit(0);
	}
	env->win = mlx_new_window(env->mlx, WINX, WINY, "RTV1");
	init_img(env);
}
