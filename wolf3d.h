/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:49:44 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/22 15:04:36 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "libft.h"
#include "mlx.h"

# define W_WIDTH 750
# define W_HEIGHT 750

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

typedef struct	s_world
{
	int			wall_h;
	char		**map;
}				t_world;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_image		*img;
	t_world		*world;
}				t_env;

t_image			*new_image(t_env *e);
t_world			*setup_world(char **argv);
void			exit_error(char *str);
void			pixel_to_image(t_image *image, int x, int y, int color);
void			print_image(t_env *);
char			**parse_file(char **argv);
