/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:56:47 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/26 17:29:13 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** returns 1 if it hits a wall, and 0 if it doesn't.
*/
static int	cast_horizontal(t_world *world, t_player *p, double alpha)
{
	long	Fy;
	long	Fx;

	if (alpha == 0.00 || alpha == M_PI || alpha == 2 * M_PI) //idk about this 2 MPI business
	{
		Fy = 0;
		printf("hi\n");
	}
	else
		Fy = (alpha > 0 && alpha < (M_PI / 2)) ? (int)(p->y / world->tile) * \
			 world->tile - 1 : (int)(p->y / world->tile) * world->tile + world->tile;
	Fx = p->x + (int)((p->y - Fy) / tan(alpha));
	if (Fx / world->tile >= world->w)
		return (2);
	return ((world->map[Fy / world->tile][Fx / world->tile] == 'x') ? 1 : 0);
}

/*
** goes through the entire window and finds if wall intersection, finds the distance of
** wall to player, and draws the wall.
*/
void		render(t_env *e)
{
	double	alpha;
	int	i;

	i = 0;
	alpha = e->p->cov + (e->p->fov / 2);
	while (alpha > e->p->cov - (e->p->fov / 2))
	{
		cast_horizontal(e->world, e->p, alpha);
		alpha -= e->p->fov / e->win->w;
	}
	alpha = (alpha > M_PI) ? alpha - M_PI : alpha;
}
