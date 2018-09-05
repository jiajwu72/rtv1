/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:41:49 by jwu               #+#    #+#             */
/*   Updated: 2018/05/12 17:41:49 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color				init_color(int r, int g, int b)
{
	t_color			color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color				eclairer(t_color color, double a)
{
	return (init_color(color.r * a, color.g * a, color.b * a));
}

t_color				assombrir(t_color color, double a)
{
	return (init_color(color.r / a, color.g / a, color.b / a));
}

t_color				add_color(t_color c1, t_color c2)
{
	return (init_color(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b));
}

t_color				soust_color(t_color c1, t_color c2)
{
	return (init_color(c1.r - c2.r, c1.g - c2.g, c1.b - c2.b));
}
