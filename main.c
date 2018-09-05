/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:33:24 by jwu               #+#    #+#             */
/*   Updated: 2018/05/12 17:33:25 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int						expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->image.img, 0, 0);
	return (0);
}

void					put_manuel(void)
{
	ft_putendl("--------------Man--------------------------");
	ft_putendl("deplacement:		up down left right");
	ft_putendl("altitude:		4  1");
	ft_putendl("rotation: 		w a s d e r");
	ft_putendl("luminosite:		+/-");
	ft_putendl("------------- end--------------------------");
}

int						main(int ac, char **av)
{
	t_env				e;

	if (ac != 2)
	{
		ft_putendl("usage: ./rtv1 [file]");
		return (0);
	}
	init(&e);
	if (ft_read(av[1], &e) == 1)
	{
		put_manuel();
		rot(&(e.obj), init_vect(0, 0, 0));
		trans(&(e.obj), init_vect(0, 0, 0));
		draw(&e);
		mlx_hook(e.win, 2, 1L << 0, key_hook, &e);
		mlx_hook(e.win, 17, 18, close_win, &e);
		mlx_loop(e.mlx);
		mlx_expose_hook(e.win, expose_hook, &e);
	}
	return (0);
}
