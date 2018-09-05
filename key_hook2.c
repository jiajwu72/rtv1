/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 17:00:37 by klin              #+#    #+#             */
/*   Updated: 2018/05/24 17:00:51 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			move(int key, t_env *env)
{
	if (key == 86)
		env->camera.pos.y += 1;
	if (key == 83)
		env->camera.pos.y -= 1;
}

static void			mat_rotx(t_env *e, int key)
{
	int			signe;

	signe = key == 0 ? 1 : -1;
	rot_x(&(e->camera.dir), signe);
	rot_x(&(e->camera.v), signe);
}

static void			mat_roty(t_env *e, int key)
{
	int			signe;

	signe = key == 13 ? 1 : -1;
	rot_y(&(e->camera.dir), signe);
	rot_y(&(e->camera.v), signe);
}

static void			mat_rotz(t_env *e, int key)
{
	int			signe;

	signe = key == 14 ? 1 : -1;
	rot_z(&(e->camera.dir), signe);
	rot_z(&(e->camera.v), signe);
}

void				move_rot(int key, t_env *env)
{
	if ((key <= 2 && key >= 0) || (key >= 13 && key <= 15))
	{
		if (key == 0 || key == 2)
			mat_rotx(env, key);
		else if (key == 1 || key == 13)
			mat_roty(env, key);
		else if (key == 14 || key == 15)
			mat_rotz(env, key);
		env->camera.look_at = somme(env->camera.pos, env->camera.dir);
		env->camera = init_camera(env->camera.pos,
			env->camera.look_at, env->camera.v);
	}
	move(key, env);
}
