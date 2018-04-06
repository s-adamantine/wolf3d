/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:56:47 by sadamant          #+#    #+#             */
/*   Updated: 2018/03/14 23:20:54 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	check_wall(t_world *world, int x, int y)
{
	if (x < 0 || y < 0)
		return (-1);
	if (x >= (world->w * world->tile) || y >= (world->h * world->tile))
		return (-1);
	if (world->map[y / world->tile][x / world->tile] == 'x')
		return (1);
	return (0);
}

static t_ray	*first_hintersection(double a, t_world *world, t_player *p)
{
	t_ray	*rh;

	rh = ft_memalloc(sizeof(t_ray));
	rh->a = a;
	rh->y = (rh->a > 0 && rh->a < M_PI) ? (int)(p->y / world->tile) * \
			 world->tile - 1 : (int)(p->y / world->tile) * world->tile + world->tile;
	if (is_piover2(rh->a) || is_3piover2(rh->a))
		rh->x = p->x;
	else
		rh->x = p->x + (int)((p->y - rh->y) / tan(rh->a));
	if (rh->x < 0 || rh->y < 0)
		return (NULL);
	return (rh);
}

static t_ray	*first_vintersection(double a, t_world *world, t_player *p)
{
	t_ray	*rv;

	rv = ft_memalloc(sizeof(t_ray));
	rv->a = a;
	rv->x = (rv->a < (M_PI / 2) || rv->a > (3 * M_PI) / 2) ? \
		 (int)(p->x / world->tile) * world->tile + world->tile : \
		 (int)(p->x / world->tile) * world->tile - 1;
	rv->y = p->y + (p->x - rv->x) * tan(rv->a);
	if (rv->x < 0 || rv->y < 0)
		return (NULL);
	return (rv);
}

/*
** distance between the player and the ray.
*/
double		distance(t_ray *r, t_player *p)
{
	return (sqrt(pow((p->x - r->x), 2) + pow((p->y - r->y), 2)));
}

t_ray		*cast_horizontal(t_world *world, t_player *p, double angle)
{
	int		wall;
	t_ray	*rh;

	if (!(rh = first_hintersection(angle, world, p)))
		return (NULL);
	while ((wall = check_wall(world, rh->x, rh->y)) == 0)
	{
		if (!is_piover2(rh->a) && !is_3piover2(rh->a))
			rh->x += fabs(world->tile/tan(rh->a));
		rh->y += (rh->a > 0 && rh->a < M_PI) ? -world->tile : world->tile;
	}
	if (wall == -1)
		return (NULL);
	rh->s = distance(rh, p);
	return (rh);
}

t_ray		*cast_vertical(t_world *world, t_player *p, double angle)
{
	int		wall;
	t_ray	*rv;

	if (!(rv = first_vintersection(angle, world, p)))
		return (NULL);
	while ((wall = check_wall(world, rv->x, rv->y)) == 0)
	{
		if (!is_zero(rv->a) && !is_pi(rv->a))
			rv->y += -world->tile * tan(rv->a);
		rv->x += (rv->a < (M_PI / 2) || rv->a > ((3 * M_PI) / 2)) ? \
				world->tile : -world->tile;
	}
	if (wall == -1)
		return (NULL);
	rv->s = distance(rv, p);
	return (rv);
}
