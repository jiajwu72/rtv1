/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 01:06:50 by jwu               #+#    #+#             */
/*   Updated: 2018/05/24 01:06:50 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				ver1(char **val, int *ok, t_obj **obj)
{
	t_color			color;

	if ((int)ft_sstrlen(val) == 8
		&& ft_str_is_d(val[1]) && ft_str_is_d(val[2]) && ft_str_is_d(val[3])
		&& ft_str_is_d(val[4])
		&& ft_str_is_num(val[5]) && ft_str_is_num(val[6]) &&
		ft_str_is_num(val[7]))
	{
		color = init_color(ft_atoi(val[5]), ft_atoi(val[6]), ft_atoi(val[7]));
		if (ft_strcmp(val[0], "sphere") == 0)
		{
			*ok = 1;
			*obj = init_sphere(init_vect(ft_ato_double(val[1]),
				ft_ato_double(val[2]), ft_ato_double(val[3])),
				ft_ato_double(val[4]), color);
		}
		else if (ft_strcmp(val[0], "plane") == 0)
		{
			*ok = 1;
			*obj = init_plane(init_vect(ft_ato_double(val[1]),
				ft_ato_double(val[2]),
				ft_ato_double(val[3])), ft_ato_double(val[4]), color);
		}
	}
}

void				ver2(char **val, int *ok, t_obj **obj)
{
	t_color			color;

	if ((int)ft_sstrlen(val) == 11 && ft_str_is_d(val[1]) &&
ft_str_is_d(val[2]) && ft_str_is_d(val[3]) && ft_str_is_d(val[4]) &&
ft_str_is_d(val[5]) && ft_str_is_d(val[6]) && ft_str_is_d(val[7]) &&
ft_str_is_num(val[8]) && ft_str_is_num(val[9]) && ft_str_is_num(val[10]))
	{
		color = init_color(ft_atoi(val[8]), ft_atoi(val[9]), ft_atoi(val[10]));
		if (ft_strcmp(val[0], "cone") == 0)
		{
			*ok = 1;
			*obj = init_cone(init_vect(ft_ato_double(val[1]),
			ft_ato_double(val[2]), ft_ato_double(val[3])), init_vect(
			ft_ato_double(val[4]), ft_ato_double(val[5]),
			ft_ato_double(val[6])), ft_ato_double(val[7]), color);
		}
		else if (ft_strcmp(val[0], "cylindre") == 0)
		{
			*ok = 1;
			*obj = init_cylindre(init_vect(ft_ato_double(val[1]),
ft_ato_double(val[2]), ft_ato_double(val[3])), init_vect(ft_ato_double(val[4]),
ft_ato_double(val[5]), ft_ato_double(val[6])), ft_ato_double(val[7]), color);
		}
	}
}

void				ver3(char **val, int *ok, t_light **l)
{
	t_color			color;

	if ((int)ft_sstrlen(val) == 7 && ft_str_is_d(val[1]) &&
ft_str_is_d(val[2]) && ft_str_is_d(val[3]) && ft_str_is_num(val[4]) &&
ft_str_is_num(val[5]) && ft_str_is_num(val[6]))
	{
		color = init_color(ft_atoi(val[4]), ft_atoi(val[5]), ft_atoi(val[6]));
		if (ft_strcmp(val[0], "light") == 0)
		{
			*ok = 2;
			*l = init_light(init_vect(ft_ato_double(val[1]),
				ft_ato_double(val[2]), ft_ato_double(val[3])), color);
		}
	}
}

void				ver4(char **val, int *ok, t_env *env)
{
	if ((int)ft_sstrlen(val) == 10
		&& ft_str_is_d(val[1]) && ft_str_is_d(val[2]) && ft_str_is_d(val[3])
		&& ft_str_is_d(val[4]) && ft_str_is_d(val[5]) && ft_str_is_d(val[6])
		&& ft_str_is_d(val[7]) && ft_str_is_d(val[8]) && ft_str_is_d(val[9]))
	{
		if (ft_strcmp(val[0], "camera") == 0)
		{
			*ok = 3;
			env->has_cam = 1;
			env->camera = init_camera(init_vect(ft_ato_double(val[1]),
ft_ato_double(val[2]), ft_ato_double(val[3])), init_vect(ft_ato_double(val[4]),
ft_ato_double(val[5]), ft_ato_double(val[6])), init_vect(ft_ato_double(val[7]),
ft_ato_double(val[8]), ft_ato_double(val[9])));
		}
	}
}
