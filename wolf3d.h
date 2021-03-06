/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:49:44 by sadamant          #+#    #+#             */
/*   Updated: 2018/05/11 16:39:01 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <limits.h>

# include "libft.h"
# include "mlx.h"

# define WINDOW_W 750
# define WINDOW_H 750

# define WALL_H 64
# define WALL_MARGIN 15
# define TILE 64
# define PLAYER_TO_PLANE 255

# define TEXTCOLOR 0x00FFFFFF
# define NORTH_C 0x00FFFFFF
# define SOUTH_C 0x0000ACE6
# define EAST_C 0x00CC9900
# define WEST_C 0x00802B

# define ESC 53

# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

# define W 13
# define A 0
# define S 1
# define D 2
# define LSHIFT 257

# define WALK_SPEED 2
# define RUN_SPEED 6

# define KEYPRESS_EVENT 2
# define KEYRELEASE_EVENT 3
# define REDX_EVENT 17

typedef enum	e_dir
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}				t_dir;

typedef enum	e_type
{
	BRICK,
	WOOD,
	BANANAS,
	ICE,
	BLUESTONE,
	BOXES
}				t_type;

typedef struct	s_key
{
	int			left;
	int			right;
	int			lshift;
	int			w;
	int			a;
	int			s;
	int			d;
}				t_key;

typedef struct	s_image
{
	int			bpp;
	int			sline;
	int			endian;
	void		*id;
	int			*bitmap;
	int			w;
	int			h;
	t_type		type;
}				t_image;

typedef struct	s_player
{
	double		x;
	double		y;
	double		h;
	double		c;
	double		fov;
	double		cov;
	int			v;
}				t_player;

typedef struct	s_ray
{
	double		x;
	double		y;
	double		s;
	double		a;
	t_dir		dir;
}				t_ray;

typedef struct	s_world
{
	char		**map;
	int			wall_h;
	int			w;
	int			h;
}				t_world;

typedef struct	s_window
{
	double		h;
	double		w;
}				t_window;

typedef struct	s_texture
{
	int			x;
	int			y;
	double		x_offset;
	double		y_offset;
	t_type		type;
	t_image		**textures;
}				t_texture;

typedef struct	s_env
{
	void		*mlx;
	void		*wid;
	t_window	*win;
	t_image		*img;
	t_world		*world;
	t_texture	*t;
	t_player	*p;
	t_ray		*r;
	t_key		*key;
}				t_env;

t_image			*new_image(t_env *e, int width, int height);
t_image			*new_xpm_image(t_env *e, char *name, int w, int h);
void			insert_bitmap(t_image *img, int x, int y, unsigned int color);
void			print_image(t_env *e);
void			exit_id(int i);
t_env			*setup_environment(int argc, char **argv);
void			exit_error(char *str);
int				quit_program(t_env *e);
void			render(t_env *e);
void			draw_wallpiece(t_env *e, t_texture *t, t_ray *ray, int x);
void			draw_midpoint(t_env *e);
int				handle_keypress(int keycode, t_env *e);
int				handle_keyrelease(int keycode, t_env *e);
int				refresh_screen(t_env *e);
char			**parse_file(char **argv, t_world *world);
int				tophalf(double value);
int				righthalf(double value);
int				get_color(t_image *img, int x, int y);
double			distance(t_ray *r, t_player *p);
t_ray			*cast_horizontal(t_world *world, t_player *p, double angle);
t_ray			*cast_vertical(t_world *world, t_player *p, double angle);
t_image			**load_textures(t_env *e);
t_type			set_wallpaper(t_dir dir);
void			mlx_put_text_and_value(char *str, int number, int x, int y, int color, t_env *e);

#endif
