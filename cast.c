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

static int	check_wall(t_world *world, double x, double y)
{
	if (sharfy) printf("check_wall x, y: %f, %f\n", x, y);
	if (x < 0 || y < 0)
		return (-1);
	if (x >= (world->w * world->tile) || y >= (world->h * world->tile))
		return (-1);
	if (world->map[(int)y / world->tile][(int)x / world->tile] == 'x')
		return (1);
	return (0);
}

static t_ray	*get_first_hint(double a, t_world *world, t_player *p)
{
	t_ray	*rh;

	rh = ft_memalloc(sizeof(t_ray));
	rh->a = a;
	rh->y = (int)(p->y / world->tile) * world->tile;
	if (tophalf(rh->a))
	{
		rh->x = p->x + (p->y - rh->y) / tan(rh->a);
		rh->y -= 1;
	}
	else
	{
		rh->y += world->tile;
		rh->x = p->x + (p->y - rh->y) / tan(rh->a);
	}
	return (rh);
}

static t_ray	*get_first_vint(double a, t_world *world, t_player *p)
{
	t_ray	*rv;

	rv = ft_memalloc(sizeof(t_ray));
	rv->a = a;
	rv->x = (int)(p->x / world->tile) * world->tile;
	if (righthalf(rv->a))
	{
		rv->x += world->tile;
		rv->y = p->y + (p->x - rv->x) * tan(rv->a);
	}
	else
	{
		rv->y = p->y + (p->x - rv->x) * tan(rv->a);
		rv->x -= 1;
	}

	return (rv);
}

double		distance(t_ray *r, t_player *p)
{
	return (sqrt(pow((p->x - r->x), 2) + pow((p->y - r->y), 2)));
}

double		fix_the_numbers(double fix_me) {
	double remainder = (int)fix_me % 64;

	if (remainder) {
		return fix_me + 1;
	}
	return fix_me;
}

t_ray		*cast_horizontal(t_world *world, t_player *p, double angle)
{
	int		wall;
	double	dx;
	double	dy;
	t_ray	*rh;

	rh = get_first_hint(angle, world, p);
	dx = world->tile/tan(rh->a);
	dy = world->tile;
	while (!(wall = check_wall(world, rh->x, rh->y)))
	{
		rh->x += tophalf(rh->a) ? dx : -dx;
		rh->y += tophalf(rh->a) ? -dy : dy;
	}
	rh->y = fix_the_numbers(rh->y);
	rh->x = p->x + (p->y - rh->y) / tan(rh->a);
	rh->s = (wall == 1) ? distance(rh, p) : INT_MAX;
	if (sharfy) printf("hori: %f, %f, %f\n", rh->x, rh->y, rh->s);
	return (rh);
}

t_ray		*cast_vertical(t_world *world, t_player *p, double angle)
{
	int		wall;
	double	dx;
	double	dy;
	t_ray	*rv;

	rv = get_first_vint(angle, world, p);
	dx = world->tile;
	dy = world->tile * fabs(tan(rv->a));
	while (!(wall = check_wall(world, rv->x, rv->y)))
	{
		rv->y += tophalf(rv->a) ? -dy : dy;
		rv->x += righthalf(rv->a) ? dx : -dx;
	}
	rv->x = fix_the_numbers(rv->x);
	rv->y = p->y + (p->x - rv->x) * tan(rv->a);
	rv->s = (wall == 1) ? distance(rv, p) : INT_MAX;
	if (sharfy) printf("vert: %f, %f, %f\n", rv->x, rv->y, rv->s);
	return (rv);
}
