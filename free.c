/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 03:21:57 by jwu               #+#    #+#             */
/*   Updated: 2018/05/24 03:21:58 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				free_light(t_light **l)
{
	t_light		*light;

	if ((*l))
	{
		light = (*l)->next;
		free((*l));
		*l = NULL;
		free_light(&light);
	}
}

void				free_obj(t_obj **obj)
{
	t_obj		*o;

	if ((*obj))
	{
		o = (*obj)->next;
		free((*obj)->data);
		(*obj)->data = NULL;
		free((*obj));
		*obj = NULL;
		free_obj(&o);
	}
}

void				free_env(t_env *e)
{
	free_light(&(e->light));
	free_obj(&(e->obj));
	if (e->mlx)
		mlx_destroy_window(e->mlx, e->win);
}
