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

static int		grab_color(char dir, t_image *texture, int x_texture, int y_texture)
{
	if (dir == 'N')
		return (texture->bitmap[y_texture * texture->w + x_texture]);
	if (dir == 'S')
		return (SOUTH);
	if (dir == 'E')
		return (EAST);
	if (dir == 'W')
		return (WEST);
	return (0x00000000);
}

void			draw_wallpiece(t_env *e, t_ray *ray, int x)
{
	int		wall_h;
	int		topmost_pixel;
	int		i;
	int		x_texture;
	int		y_texture;
	double	x_offset;

	i = 0;
	if (ray->s == INT_MAX)
		return ;
	wall_h = (int)(e->p->c / ray->s) + 1;
	wall_h = (wall_h > WINDOW_W) ? WINDOW_W : wall_h;
	topmost_pixel = (WINDOW_W / 2) - (wall_h / 2);
	x_offset = (ray->dir == 'E' || ray->dir == 'W') ? \
		ray->y - (((int)ray->y / TILE_SIZE) * TILE_SIZE) : \
		ray->x - (((int)ray->x / TILE_SIZE) * TILE_SIZE);
	x_texture = ((double) x_offset / TILE_SIZE) * e->texture->w;
	while (i <= wall_h)
	{
		y_texture = ((double) i / wall_h ) * e->texture->h;
		insert_bitmap(e->img, x, topmost_pixel + i, grab_color(ray->dir, e->texture, x_texture, y_texture));
		i++;
	}
}
