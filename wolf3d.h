/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:49:44 by sadamant          #+#    #+#             */
/*   Updated: 2018/03/08 17:34:40 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <math.h>
#include <stdio.h>

#include "libft.h"
#include "mlx.h"

# define W_WIDTH 750
# define W_HEIGHT 750

# define WALL_H 64
# define TILE_SIZE 64

# define COLOR 0x00FFFFFF
# define ESC 53

typedef struct	s_image
{
	int			bpp;
	int			sline;
	int			endian;
	void		*id;
	char		*bitmap;
	int			w;
	int			h;
}				t_image;

typedef struct	s_plane
{
	double		cx;
	double		cy;
}				t_plane;

typedef struct	s_player
{
	double		x;
	double		y;
	double		h;
	double		d;
	double		fov;
	double		cov;
}				t_player;

typedef struct	s_ray
{
	double		x; //intersection ray
	double		y; //and here too!
	double		dx;
	double		dy;
	double		a; //the angle w/r to 0
}				t_ray;

typedef struct	s_world
{
	char		**map;
	int			tile;
	int			wall_h;
	int			w;
	int			h;
}				t_world;

typedef struct	s_window
{
	double		h;
	double		w;
}				t_window;

typedef struct	s_env
{
	void		*mlx;
	void		*wid;
	t_window	*win;
	t_image		*img;
	t_world		*world;
	t_player	*p;
}				t_env;

t_image			*new_image(t_env *e, int width, int height);
void			insert_bitmap(t_image *image, int x, int y, int color);
void			print_image(t_env *);

t_env			*setup_environment(int argc, char **argv);
void			exit_error(char *str);
void			render(t_env *e);
void			draw_wallpiece(t_env *e, t_ray *ray, int x);
int				handle_keypress(int keycode, t_env *e);
char			**parse_file(char **argv, t_world *world);

int				is_zero(double value);
int				is_piover2(double value);
int				is_pi(double value);
int				is_3piover2(double value);
int				is_2pi(double value);
