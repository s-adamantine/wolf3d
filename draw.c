/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:37:35 by sadamant          #+#    #+#             */
/*   Updated: 2018/03/14 21:34:29 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			draw_midpoint(t_env *e)
{
	int	y;
	int	h;

	y = 325;
	h = 800;
	while (h--)
		insert_bitmap(e->img, 375, y++, 0x00FF0000);
}

static int		grab_color(t_env *e, int x_texture, int y_texture, t_type type)
{
	return (e->textures[type]->bitmap[y_texture * e->textures[type]->w + x_texture]);
}

static t_type	set_wallpaper(t_dir dir)
{
	if (dir == NORTH)
		return (BRICK);
	if (dir == SOUTH)
		return (WOOD);
	if (dir == EAST)
		return (STONE);
	if (dir == WEST)
		return (URCHINS);
	return (0);
}

static double	grab_y_offset(t_env *e, t_ray *ray)
{
	double	perfect_distance;
	double	y_top_offset;

	perfect_distance = e->p->c / WINDOW_H;
	y_top_offset = (perfect_distance - ray->s) / (2 * perfect_distance);
	return (y_top_offset);
}

void			setup_texture(t_texture *t, t_ray *ray, t_env *e)
{
	t->type = set_wallpaper(ray->dir);
	t->x_offset = (ray->dir == EAST || ray->dir == WEST) ? \
		ray->y - (((int)ray->y / TILE_SIZE) * TILE_SIZE) : \
		ray->x - (((int)ray->x / TILE_SIZE) * TILE_SIZE);
	t->x = ((double) t->x_offset / TILE_SIZE) * e->textures[t->type]->w;
}

/*
** temp is the wall height, but remaining static because it needs to be a counter
** the wall_h in wall->ytexture (the fifrst statement inside the while loop) needs
** to change to be a percentage of what it should be
*/
void			draw_wallpiece(t_env *e, t_ray *ray, int x)
{
	int		wall_h;
	int		topmost_pixel;
	int		i;
	t_texture	*t;
	double	y_offset;
	double	y_increment;

	i = 0;
	if (ray->s == INT_MAX)
		return ;
	if (!(t = ft_memalloc(sizeof(t_texture))))
		return ;
	setup_texture(t, ray, e);
	wall_h = (int)(e->p->c / ray->s) + 1;
	wall_h = (wall_h > WINDOW_H) ? WINDOW_H : wall_h;
	topmost_pixel = (wall_h == WINDOW_H) ? 0 : (WINDOW_H / 2) - (wall_h / 2);
	y_offset = (wall_h == WINDOW_H) ? grab_y_offset(e, ray) : 0;
	y_increment = (1 - (y_offset * 2)) / wall_h;
	while (i <= wall_h)
	{
		t->y = (double) ((i * y_increment) + y_offset) * e->textures[t->type]->h;
		insert_bitmap(e->img, x, topmost_pixel + i, grab_color(e, \
			t->x, t->y, t->type));
		i++;
	}
}
