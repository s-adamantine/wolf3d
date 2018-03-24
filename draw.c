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

void	draw_wallpiece(t_env *e, t_ray *ray, int x)
{
	double	dist; //distance from person to wall
	double	b;    //correction angle
	int		h;	  //height of the wall
	int		y;    //window y coordinate

	if (is_piover2(ray->a) || is_3piover2(ray->a))
	{
		dist = fabs(e->p->y - ray->y) / sin(ray->a);
	}
	else
		dist = fabs(e->p->x - ray->x) / fabs(cos(ray->a));
	b = ray->a - e->p->cov;
	dist *= cos(b);
	// printf("b is %f, cos(b) is %f, dist is: %f, ", b, cos(b), dist);
	h = (int)((e->world->wall_h / dist) * e->p->d) + 1; //you can precompute w->wall_h / p->d bc that's always the same
	// printf("h is %d\n", h);
	y = (e->win->h / 2) - (h/2); //the first coordinate that you want to write in
	while (h--)
		insert_bitmap(e->img, x, y++, COLOR);
}
