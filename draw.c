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

static t_type	set_walltype(t_dir dir)
{
	if (dir == NORTH)
		return (ANNE);
	if (dir == SOUTH)
		return (WOOD);
	if (dir == EAST)
		return (STONE);
	if (dir == WEST)
		return (URCHINS);
	return (0);
}

void			draw_wallpiece(t_env *e, t_ray *ray, int x)
{
	int		wall_h;
	int		topmost_pixel;
	int		i;
	t_wall	*wall;
	double	x_offset;

	i = 0;
	if (ray->s == INT_MAX)
		return ;
	if (!(wall = ft_memalloc(sizeof(t_wall))))
		return ;
	wall->type = set_walltype(ray->dir);
	wall_h = (int)(e->p->c / ray->s) + 1;
	wall_h = (wall_h > WINDOW_W) ? WINDOW_W : wall_h;
	topmost_pixel = (WINDOW_W / 2) - (wall_h / 2);
	x_offset = (ray->dir == EAST || ray->dir == WEST) ? \
		ray->y - (((int)ray->y / TILE_SIZE) * TILE_SIZE) : \
		ray->x - (((int)ray->x / TILE_SIZE) * TILE_SIZE);
	wall->x_texture = ((double) x_offset / TILE_SIZE) * e->textures[wall->type]->w;
	while (i <= wall_h)
	{
		wall->y_texture = ((double) i / wall_h ) * e->textures[wall->type]->h;
		insert_bitmap(e->img, x, topmost_pixel + i, grab_color(e, \
			wall->x_texture, wall->y_texture, wall->type));
		i++;
	}
}
