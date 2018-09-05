/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:41:35 by jwu               #+#    #+#             */
/*   Updated: 2018/05/12 17:41:36 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect				init_cam_dir(t_vect pos, t_vect look_at)
{
	t_vect			diff_btw;

	diff_btw = init_vect(pos.x - look_at.x, pos.y -
		look_at.y, pos.z - look_at.z);
	return (normalize(negative(diff_btw)));
}

t_vect				init_cam_right(t_vect v, t_vect dir)
{
	return (normalize(cross_product(v, dir)));
}

t_vect				init_cam_down(t_vect right, t_vect dir)
{
	return (cross_product(right, dir));
}

t_camera			init_camera(t_vect pos, t_vect look_at, t_vect v)
{
	t_camera		camera;

	camera.look_at = look_at;
	camera.v = v;
	camera.pos = pos;
	camera.dir = init_cam_dir(camera.pos, look_at);
	camera.right = init_cam_right(v, camera.dir);
	camera.down = init_cam_down(camera.right, camera.dir);
	return (camera);
}
