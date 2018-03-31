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

static double	constrain_cov(t_player *p)
{
	if (p->cov < ((-M_PI / 2) + p->fov))
		p->cov += (2 * M_PI);
	if (p->cov > (2.5 * M_PI) - p->fov / 2)
		p->cov -= (2 * M_PI);
	return (p->cov);
}

/*
** goes through the entire window and if there's a wall intersection, finds the distance of
** wall to player, and draws the wall.
*/
void			render(t_env *e)
{
	t_ray	*rh;
	t_ray	*rv;
	int		x;

	x = 0;
	e->p->cov = constrain_cov(e->p);
	e->r->a = e->p->cov + (e->p->fov / 2);
	while (e->r->a > e->p->cov - (e->p->fov / 2))
	{
		if (angled(e->r->a))
		{
			rv = cast_vertical(e->world, e->p, e->r);
			rh = cast_horizontal(e->world, e->p, e->r);
			//needs to account for if rh or rv doesn't exist
			if (rv && rh)
			{
				e->r->x = (rh->s < rv->s) ? rh->x : rv->x;
				e->r->y = (rh->s < rv->s) ? rh->y : rv->y;
			}
			// else if (rv && !rh)
			// {
			// 	ray->x = rv->x;
			// 	ray->y = rv->y;
			// }
			// else if (rh && !rv)
			// {
			// 	ray->x = rh->x;
			// 	ray->y = rh->y;
			// }
		}
		else if (is_piover2(e->r->a) || is_3piover2(e->r->a))
			cast_horizontal(e->world, e->p, e->r);
		else if (is_zero(e->r->a) || is_pi(e->r->a) || is_2pi(e->r->a))
			cast_vertical(e->world, e->p, e->r);
		e->r->a -= e->p->fov / e->win->w;
		if (e->r->x && e->r->y)
			draw_wallpiece(e, e->r, x);
		x++;
	}
	print_image(e);
}
