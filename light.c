/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:42:02 by jwu               #+#    #+#             */
/*   Updated: 2018/05/12 17:42:02 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light				*init_light(t_vect pos, t_color color)
{
	t_light			*l;

	if ((l = malloc(sizeof(t_light))) == NULL)
		return (NULL);
	l->pos = pos;
	l->color = color;
	l->luminosite = 1;
	l->next = NULL;
	return (l);
}

void				add_light(t_light **alst, t_light *new)
{
	if (!*alst)
		*alst = new;
	else
	{
		new->next = *alst;
		*alst = new;
	}
}
