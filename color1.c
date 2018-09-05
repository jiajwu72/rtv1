/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 02:36:22 by jwu               #+#    #+#             */
/*   Updated: 2018/05/16 02:36:23 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color				compose(t_color c1, t_color c2)
{
	return (assombrir(add_color(c1, c2), 2));
}

t_color				mult_color(t_color c1, t_color c2)
{
	return (init_color(c1.r * c2.r, c1.g * c2.g, c1.b * c2.b));
}

t_color				normalize_color(t_color color)
{
	color.r = color.r > 255 ? 255 : color.r;
	color.g = color.g > 255 ? 255 : color.g;
	color.b = color.b > 255 ? 255 : color.b;
	return (color);
}
