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
	return 0x00000000;
}
void			draw_wallpiece(t_env *e, t_ray *ray, int x)
{
	double	dist;
	int		h;
	int		y;
	int		color;

	if (ray->s == INT_MAX)
		return ;
	dist = ray->s * cos(ray->a - e->p->cov);
	h = (int)((e->world->wall_h / dist) * e->p->d) + 1; //you can precompute w->wall_h / p->d bc that's always the same
	color = set_color(ray->dir);
	y = (e->win->h / 2) - (h/2);
	while (h)
	{
		insert_bitmap(e->img, x, y, color);
		y++;
		h--;
	}
}
