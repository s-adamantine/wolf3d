/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:56:47 by sadamant          #+#    #+#             */
/*   Updated: 2018/03/14 20:36:37 by sadamant         ###   ########.fr       */
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

static void	first_hintersection(t_ray *ray, t_world *world, t_player *p)
{
	ray->y = (ray->a > 0 && ray->a < M_PI) ? (int)(p->y / world->tile) * \
			 world->tile - 1 : (int)(p->y / world->tile) * world->tile + world->tile;
	if (is_piover2(ray->a) || is_3piover2(ray->a))
		ray->x = p->x;
	else
		ray->x = p->x + (int)((p->y - ray->y) / tan(ray->a));
}

static void first_vintersection(t_ray *ray, t_world *world, t_player *p)
{
	ray->x = (ray->a < (M_PI / 2) || ray->a > (3 * M_PI) / 2) ? \
		 (int)(p->x / world->tile) * world->tile + world->tile : \
		 (int)(p->x / world->tile) * world->tile - 1;
	ray->y = p->y + (p->x - ray->x) * tan(ray->a);
}

t_ray		*cast_horizontal(t_world *world, t_player *p, t_ray *ray)
{
	t_ray	*rh;

	rh = ft_memalloc(sizeof(t_ray));
	rh->a = ray->a;
	first_hintersection(rh, world, p);
	while (check_wall(world, rh->x, rh->y) == 0)
	{
		if (is_piover2(rh->a))
			rh->y -= world->tile;
		else if (is_3piover2(rh->a))
			rh->y += world->tile;
		else
		{
			rh->x += fabs(world->tile/tan(rh->a));
			rh->y += (rh->a > 0 && rh->a < M_PI) ? -world->tile : world->tile;
		}
	}
	return (rh);
}

t_ray		*cast_vertical(t_world *world, t_player *p, t_ray *ray)
{
	t_ray	*rv;

	rv = ft_memalloc(sizeof(t_ray));
	rv->a = ray->a;
	first_vintersection(rv, world, p);
	while (check_wall(world, rv->x, rv->y) == 0)
	{
		if (is_zero(rv->a))
			rv->x += world->tile;
		else if (is_pi(rv->a))
			rv->x -= world->tile;
		else
		{
			rv->x += (rv->a < (M_PI / 2) || rv->a > ((3 * M_PI) / 2)) ? \
				world->tile : -world->tile;
			rv->y += -world->tile * tan(rv->a);
		}
	}
	return (rv);
}
