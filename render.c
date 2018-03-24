/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:32:17 by sadamant          #+#    #+#             */
/*   Updated: 2018/03/14 21:36:32 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** goes through the entire window and if there's a wall intersection, finds the distance of
** wall to player, and draws the wall.
*/
void		render(t_env *e)
{
	t_ray	*ray;
	t_ray	*rh;
	t_ray	*rv;
	int		x;

	x = 0;
	ray = ft_memalloc(sizeof(t_ray));
	ray->a = e->p->cov + (e->p->fov / 2);
	while (ray->a > e->p->cov - (e->p->fov / 2))
	{
		if (angled(ray->a))
		{
			rv = cast_vertical(e->world, e->p, ray);
			rh = cast_horizontal(e->world, e->p, ray);
			//this actually needs to be the distance, and needs to account for if
			//you don't find a wall.
			if (rv && rh)
			{
				ray->x = (rv->x < rh->x) ? rv->x : rh->x;
				ray->y = (rv->y < rh->y) ? rv->y : rh->y;
			}
		}
		else if (is_piover2(ray->a) || is_3piover2(ray->a))
			cast_horizontal(e->world, e->p, ray);
		else if (is_zero(ray->a) || is_pi(ray->a) || is_2pi(ray->a))
			cast_vertical(e->world, e->p, ray);
		ray->a -= e->p->fov / e->win->w;
		if (ray->x && ray->y)
			draw_wallpiece(e, ray, x);
		x++;
	}
	print_image(e);
}
