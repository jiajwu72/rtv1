/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 01:12:44 by jwu               #+#    #+#             */
/*   Updated: 2018/05/24 01:12:45 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				rot(t_obj **obj, t_vect v)
{
	(*obj)->dir = normalize(somme((*obj)->dir, v));
}

void				trans(t_obj **obj, t_vect v)
{
	(*obj)->pos = somme((*obj)->pos, v);
}