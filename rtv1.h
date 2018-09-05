/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:35:14 by jwu               #+#    #+#             */
/*   Updated: 2018/04/30 16:50:43 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "libft/libft.h"
# include <math.h>
# include "mlx.h"
# define WINX		500
# define WINY		500
# define PI			3.14

/*
** struct
*/
typedef struct		s_vect
{
	double			x;
	double			y;
	double			z;
}					t_vect;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

/*
** ray = o + d * t
*/
typedef struct		s_ray
{
	t_vect			o;
	t_vect			d;
	double			t;
}					t_ray;

typedef struct		s_obj
{
	void			*data;
	t_vect			pos;
	t_vect			dir;
	double			t;
	double			(*inter)(t_ray, struct s_obj*);
	t_vect			(*normal)(struct s_obj*, t_vect);
	t_color			color;
	t_color			fcolor;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_camera
{
	t_vect			pos;
	t_vect			dir;
	t_vect			right;
	t_vect			down;
	t_vect			look_at;
	t_vect			v;
}					t_camera;

typedef struct		s_light
{
	t_vect			pos;
	double			luminosite;
	struct s_color	color;
	struct s_light	*next;
}					t_light;

typedef struct		s_plane
{
	t_vect			normal;
	double			distance;
	struct s_color	color;
}					t_plane;

typedef struct		s_sphere
{
	t_vect			o;
	double			r;
	struct s_color	color;
}					t_sphere;

typedef struct		s_cone
{
	t_vect			c;
	t_vect			v;
	t_vect			normal;
	double			angle;
	struct s_color	color;
}					t_cone;

typedef struct		s_cylindre
{
	t_vect			centre;
	t_vect			axis;
	double			r;
	struct s_color	color;
}					t_cylindre;

typedef struct		s_image
{
	void			*img;
	char			*pixel_img;
	int				bpp;
	int				ed;
	int				s_line;
	int				width;
	int				height;
}					t_image;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_image			image;
	t_obj			*obj;
	struct s_light	*light;
	t_camera		camera;
	int				has_cam;
	int				blocked;
	t_color			fcolor;
	double			dist;
	double			ambiance;
	double			luminosite;
}					t_env;

/*
** parsing
*/
int					ft_read(char *file, t_env *env);
void				ver1(char **s, int *ok, t_obj **obj);
void				ver2(char **s, int *ok, t_obj **obj);
void				ver3(char **val, int *ok, t_light **l);
void				ver4(char **val, int *ok, t_env *e);

/*
** init
*/
void				init(t_env *env);
void				init_img(t_env *e);
t_color				init_color(int r, int g, int b);
t_ray				init_ray(t_vect o, t_vect d);
t_vect				init_vect(double x, double y, double z);
t_camera			init_camera(t_vect pos, t_vect look_at, t_vect v);
t_vect				init_cam_dir(t_vect pos, t_vect look_at);
t_vect				init_cam_right(t_vect v, t_vect dir);
t_vect				init_cam_down(t_vect right, t_vect dir);
t_light				*init_light(t_vect pos, t_color color);
t_sphere			*sphere(t_vect o, double r, t_color color);
t_obj				*init_sphere(t_vect o, double r, t_color color);
t_plane				*plane(t_vect n, double d, t_color color);
t_obj				*init_plane(t_vect o, double r, t_color color);
t_obj				*init_cone(t_vect c, t_vect v, double angle, t_color color);
t_obj				*init_cylindre(t_vect c, t_vect v,
					double angle, t_color color);

/*
** calcul
*/
t_vect				unit(t_vect v, t_vect v1);
double				squar_length(t_vect v);
t_vect				somme(t_vect v1, t_vect v2);
t_vect				difference(t_vect v1, t_vect v2);
t_vect				produit_const(double a, t_vect v2);
t_vect				quotient_const(double a, t_vect v2);
t_vect				produit(t_vect v1, t_vect v2);
t_vect				quotient(t_vect v1, t_vect v2);
t_vect				quotient_const(double a, t_vect v1);
t_vect				cross_product(t_vect u, t_vect v);
t_vect				negative(t_vect v);
double				magnitude(t_vect v);
double				dot(t_vect v1, t_vect v2);
t_vect				normalize(t_vect v);
void				add_light(t_light **alst, t_light *new);
void				add_obj(t_obj **alst, t_obj *new);
t_plane				*get_plane(t_obj *obj);
t_sphere			*get_sphere(t_obj *obj);
t_cone				*get_cone(t_obj *obj);
t_vect				sphere_normal(t_obj *obj, t_vect p);
double				sphere_inter(t_ray ray, t_obj *s);
double				plane_inter(t_ray r, t_obj *obj);
t_vect				plane_normal(t_obj *o, t_vect v);
double				cone_inter(t_ray ray, t_obj *s);
t_vect				cone_normal(t_obj *obj, t_vect p);
double				cylindre_inter(t_ray ray, t_obj *s);
t_vect				cylindre_normal(t_obj *obj, t_vect p);
void				rot_x(t_vect *v, int signe);
void				rot_y(t_vect *v, int signe);
void				rot_z(t_vect *v, int signe);

/*
** color
*/
t_color				eclairer(t_color color, double a);
t_color				assombrir(t_color color, double a);
t_color				add_color(t_color c1, t_color c2);
t_color				soust_color(t_color c1, t_color c2);
t_color				mult_color(t_color c1, t_color c2);
t_color				compose(t_color c1, t_color c2);
t_color				normalize_color(t_color color);

/*
** key hook
*/
int					key_hook(int key, t_env *env);
void				move_rot(int key, t_env *env);
int					close_win(t_env *e);
void				cam_dep(int key, t_env *e);
/*
** util
*/
void				mode_color(t_color *v);
void				put_pixel(int a, int b, t_env e, t_color color);
void				def_xyam(int x, int y, double *xam, double *yam);
void				print_cam(t_camera cam);
t_vect				inter_pt(t_vect o, t_vect dir, double t);
void				def_block(t_env *e, t_ray light_ray,
					double dist_to_close, t_obj *close_obj);

/*
** draw
*/
void				draw(t_env *e);
void				rot(t_obj **obj, t_vect v);
void				trans(t_obj **obj, t_vect v);
void				aug_lum(t_light **light);
void				modif_lum(t_env *e);

/*
** free
*/
void				free_env(t_env *e);
#endif
