/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:54:29 by klin              #+#    #+#             */
/*   Updated: 2018/04/27 16:54:32 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			quitte(int key, t_env *e)
{
	if (key == 53)
	{
		ft_putendl("Exit success");
		free_env(e);
		exit(0);
	}
}

static void			gere_lumin(int key, t_env *env)
{
	if (key == 69 || key == 78)
	{
		if (key == 69 && env->luminosite < 2)
			env->luminosite += 0.2;
		if (key == 78 && env->luminosite > 0.3)
			env->luminosite -= 0.2;
	}
}

static void			move(int key, t_env *env)
{
	if ((key <= 126 && key >= 123) || key == 83 || key == 86)
	{
		if (key == 124)
		{
			env->camera.pos.x += 1;
			env->camera.pos.z -= 1.2;
		}
		if (key == 123)
		{
			env->camera.pos.x -= 1;
			env->camera.pos.z += 1.2;
		}
		if (key == 126)
		{
			env->camera.pos.z += 1;
			env->camera.pos.x += 1.2;
		}
		if (key == 125)
		{
			env->camera.pos.z -= 1;
			env->camera.pos.x -= 1.2;
		}
	}
}

int					key_hook(int key, t_env *env)
{
	quitte(key, env);
	move(key, env);
	move_rot(key, env);
	gere_lumin(key, env);
	if (key == 53 || key == 69 || key == 78 ||
		(key <= 126 && key >= 123) || key == 83 || key == 86 ||
		(key <= 2 && key >= 0) || (key >= 13 && key <= 15))
		draw(env);
	return (0);
}

int					close_win(t_env *e)
{
	ft_putendl("Exit success");
	free_env(e);
	exit(0);
	return (0);
}
