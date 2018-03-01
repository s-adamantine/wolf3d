/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:49:44 by sadamant          #+#    #+#             */
/*   Updated: 2018/03/01 17:43:05 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <math.h>
#include <stdio.h>

#include "libft.h"
#include "mlx.h"

# define W_WIDTH 750
# define W_HEIGHT 750

# define WALL_H 100
# define TILE_SIZE 64

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
	double		x;
	double		y;
	double		dx;
	double		dy;
	double		a;
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

t_image			*new_image(t_env *e);
t_env			*setup_environment(int argc, char **argv);
void			exit_error(char *str);
void			pixel_to_image(t_image *image, int x, int y, int color);
void			print_image(t_env *);
void			render(t_env *e);
int				handle_keypress(int keycode, t_env *e);
char			**parse_file(char **argv, t_world *world);
