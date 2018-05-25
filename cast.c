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

static int		check_wall(t_world *world, double x, double y)
{
	if (x < 0 || y < 0)
		return (-1);
	if (x >= (world->w * TILE_SIZE) || y >= (world->h * TILE_SIZE))
		return (-1);
	if (world->map[(int)y / TILE_SIZE][(int)x / TILE_SIZE] == 'x')
		return (1);
	return (0);
}

static t_ray	*get_first_hint(double a, t_player *p)
{
	t_ray	*rh;

	rh = ft_memalloc(sizeof(t_ray));
	rh->a = a;
	rh->y = (int)(p->y / TILE_SIZE) * TILE_SIZE;
	if (tophalf(rh->a))
	{
		rh->x = p->x + (p->y - rh->y) / tan(rh->a);
		rh->y -= 1;
		rh->dir = 'N';
	}
	else
	{
		rh->y += TILE_SIZE;
		rh->x = p->x + (p->y - rh->y) / tan(rh->a);
		rh->dir = 'S';
	}
	return (rh);
}

static t_ray	*get_first_vint(double a, t_player *p)
{
	t_ray	*rv;

	rv = ft_memalloc(sizeof(t_ray));
	rv->a = a;
	rv->x = (int)(p->x / TILE_SIZE) * TILE_SIZE;
	if (righthalf(rv->a))
	{
		rv->x += TILE_SIZE;
		rv->y = p->y + (p->x - rv->x) * tan(rv->a);
		rv->dir = 'E';
	}
	else
	{
		rv->y = p->y + (p->x - rv->x) * tan(rv->a);
		rv->x -= 1;
		rv->dir = 'W';
	}
	return (rv);
}

t_ray			*cast_horizontal(t_world *world, t_player *p, double angle)
{
	int		wall;
	double	dx;
	double	dy;
	t_ray	*rh;

	rh = get_first_hint(angle, p);
	dx = TILE_SIZE / tan(rh->a);
	dy = TILE_SIZE;
	while (!(wall = check_wall(world, rh->x, rh->y)))
	{
		rh->x += tophalf(rh->a) ? dx : -dx;
		rh->y += tophalf(rh->a) ? -dy : dy;
	}
	rh->y = ((int)rh->y % TILE_SIZE == 0) ? rh->y : rh->y + 1;
	rh->x = p->x + (p->y - rh->y) / tan(rh->a);
	rh->s = (wall == 1) ? distance(rh, p) : INT_MAX;
	return (rh);
}

t_ray			*cast_vertical(t_world *world, t_player *p, double angle)
{
	int		wall;
	double	dx;
	double	dy;
	t_ray	*rv;

	rv = get_first_vint(angle, p);
	dx = TILE_SIZE;
	dy = TILE_SIZE * fabs(tan(rv->a));
	while (!(wall = check_wall(world, rv->x, rv->y)))
	{
		rv->y += tophalf(rv->a) ? -dy : dy;
		rv->x += righthalf(rv->a) ? dx : -dx;
	}
	rv->x = ((int)rv->x % TILE_SIZE == 0) ? rv->x : rv->x + 1;
	rv->y = p->y + (p->x - rv->x) * tan(rv->a);
	rv->s = (wall == 1) ? distance(rv, p) : INT_MAX;
	return (rv);
}
