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

static int		set_color(char dir)
{
	if (dir == 'N')
		return (NORTH);
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
	double	dist;
	int		h;
	int		wall_height;
	int		y;
	int		i;
	int		j;
	int		x_texture;
	int		y_texture;
	int		color;
	int		x_offset;


	i = 0;
	j = 0;
	if (ray->s == INT_MAX)
		return ;
	dist = ray->s * cos(ray->a - e->p->cov);
	h = (int)(e->p->c / dist) + 1;
	color = set_color(ray->dir);
	h = (h > WINDOW_W) ? WINDOW_W : h;
	y = (WINDOW_W / 2) - (h / 2);
	x_offset = (e->r->dir == 'E' || e->r->dir == 'W') ?(int)ray->y % TILE_SIZE : \
		(int)ray->x % TILE_SIZE;
	x_texture = ((double) x_offset / TILE_SIZE) * e->xpm->w;
	// if (sharfy)
	// 	printf("y_texture: ");
	wall_height = h;
	while (h)
	{
		y_texture = ((double) j / wall_height ) * e->xpm->h;
		// printf("y_texture: %d, %f, %d, %d \n", y_texture, (double)j / \
		// 	wall_height, j, wall_height);
		j++;
		if (e->r->dir == 'N')
			color = e->xpm->bitmap[y_texture * e->xpm->w + x_texture];
			// color = e->xpm->bitmap[i * e->xpm->w + x_texture];
		insert_bitmap(e->img, x, y, color);
		// printf("color :%d, and grabbed: %d\n", color, get_color(e->img, x, y));
		i++;
		y++;
		h--;
	}
	if (sharfy)
		printf("\n");
}
