/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 17:29:52 by klin              #+#    #+#             */
/*   Updated: 2018/05/22 14:41:27 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			obj_pushback(t_obj **objs, t_obj *new)
{
	t_obj		*tmp;

	if (!*objs)
		*objs = new;
	else
	{
		tmp = *objs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static int		ft_verif(char **val, t_env *env)
{
	t_obj					*obj;
	t_light					*l;
	int						ok;

	ok = 0;
	ver1(val, &ok, &obj);
	ver2(val, &ok, &obj);
	ver3(val, &ok, &l);
	ver4(val, &ok, env);
	if (ok == 1)
		add_obj(&(env->obj), obj);
	if (ok == 2)
		add_light(&env->light, l);
	return (ok);
}

static int		ft_read_file(int fd, t_env *env)
{
	char		*line;
	char		**val;
	int			x;

	x = 0;
	while (get_next_line(fd, &line))
	{
		val = ft_strsplit(line, ' ');
		if (ft_verif(val, env) == 0)
			return (0);
		ft_free_sstr(&val);
		free(line);
		x++;
	}
	if (x == 0)
		return (0);
	return (1);
}

int				ft_read(char *file, t_env *env)
{
	int			fd;

	if ((fd = open(file, O_RDONLY)) != -1)
	{
		if (ft_read_file(fd, env) == 0 ||
			(env->light == NULL || env->obj == NULL || env->has_cam == 0))
		{
			ft_putendl("file error");
			close(fd);
			free_env(env);
			return (0);
		}
		close(fd);
		return (1);
	}
	close(fd);
	ft_putendl("Error: open file");
	free_env(env);
	return (0);
}
