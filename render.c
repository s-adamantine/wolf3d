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

int sharfy;

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
	double	angle;

	x = 0;
	e->p->cov = constrain_cov(e->p);
	angle = e->p->cov + (e->p->fov / 2);
	while (angle > e->p->cov - (e->p->fov / 2))
	{
		sharfy = x == 375;
		rv = cast_vertical(e->world, e->p, angle);
		rh = cast_horizontal(e->world, e->p, angle);
		e->r = (rh->s < rv->s) ? rh : rv;
		free(rh);
		free(rv);
		if (sharfy) printf("chosen distance: %f\n", e->r->s);
		draw_wallpiece(e, e->r, x++);
		angle -= e->p->fov / e->win->w;
	}
	printf("x: %f, y: %f\n\n", e->p->x, e->p->y);
	print_image(e);
}
