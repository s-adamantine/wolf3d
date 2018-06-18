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

static int		grab_color(t_texture *t)
{
	return (t->textures[t->type]->bitmap[t->y * t->textures[t->type]->w +
			t->x]);
}

static double	grab_y_offset(t_env *e, t_ray *ray)
{
	double	perfect_distance;
	double	y_top_offset;

	perfect_distance = e->p->c / WINDOW_H;
	y_top_offset = (perfect_distance - ray->s) / (2 * perfect_distance);
	return (y_top_offset);
}

static void		setup_texture(t_texture *t, t_ray *ray)
{
	t->type = set_wallpaper(ray->dir);
	t->x_offset = (ray->dir == EAST || ray->dir == WEST) ? \
		ray->y - (((int)ray->y / TILE) * TILE) : \
		ray->x - (((int)ray->x / TILE) * TILE);
	t->x = ((double)t->x_offset / TILE) * t->textures[t->type]->w;
}

void			draw_wallpiece(t_env *e, t_texture *t, t_ray *ray, int x)
{
	int			wall_h;
	int			topmost_pixel;
	int			i;
	double		y_offset;
	double		y_increment;

	i = 0;
	if (ray->s == INT_MAX)
		return ;
	setup_texture(t, ray);
	wall_h = (int)(e->p->c / ray->s) + 1;
	wall_h = (wall_h > WINDOW_H) ? WINDOW_H : wall_h;
	topmost_pixel = (wall_h == WINDOW_H) ? 0 : (WINDOW_H / 2) - (wall_h / 2);
	y_offset = (wall_h == WINDOW_H) ? grab_y_offset(e, ray) : 0;
	y_increment = (1 - (y_offset * 2)) / wall_h;
	while (i <= wall_h)
	{
		t->y = (double)((i * y_increment) + y_offset) * t->textures[t->type]->h;
		insert_bitmap(e->img, x, topmost_pixel + i, grab_color(t));
		i++;
	}
}
