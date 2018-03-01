/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:56:47 by sadamant          #+#    #+#             */
/*   Updated: 2018/03/02 14:00:55 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** checks whether there is a wall at a specific ex and ey.
** return 1 if the ray hits a wall, 0 if hasn't yet hit a wall, and
** -1 if the ray reached map boundaries.
*/
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
	if ((ray->a >= -0.000001 && ray->a <= 0.000001) || \
			(ray->a >= ((2 * M_PI) - 0.000001) && ray->a <= ((2 * M_PI) + 0.000001)))
		ray->x = ((p->x / world->tile) + 1) * world->tile;
	else if (ray->a >= (M_PI - 0.000001) && ray->a <= (M_PI + 0.000001))
		ray->x = (p->x / world->tile) * world->tile;
	else
		ray->x = p->x + (int)((p->y - ray->y) / tan(ray->a));
}

/*
** finds grid coordinates along the ray path to check for wall presence
** 1 if there's a wall, -1 if there isn't.
*/
static int	cast_horizontal(t_world *world, t_player *p, t_ray *ray)
{
	first_hintersection(ray, world, p);
	while (check_wall(world, ray->x, ray->y) == 0)
	{
		printf("checking: %d, %d ", (int)ray->x / world->tile, (int)ray->y / world->tile);
		printf("returning: %d \n", check_wall(world, ray->x, ray->y));
		if (ray->a >= -0.000001 && ray->a <= 0.000001)
			ray->x += world->tile;
		else if (ray->a >= (M_PI - 0.000001) && ray->a <= (M_PI + 0.000001))
			ray->x -= world->tile;
		else
		{
			ray->x += world->tile/tan(ray->a);
			ray->y += (ray->a > 0 && ray->a < (M_PI / 2)) ? -world->tile : world->tile;
		}
	}
	printf("last check: %d, %d ", (int)ray->x / world->tile, (int)ray->y / world->tile);
	return (check_wall(world, ray->x, ray->y));
}

/*
** this is really pseudocode though
static int	cast_ray()
{
	if ((cast_horizontal(e->world, e->p, alpha) == 1) || (cast_vertical(e->world, e->p, alpha) == 1))
		draw_wall();
	else
		draw_nothing();
}
*/

/*
** goes through the entire window and if there's a wall intersection, finds the distance of
** wall to player, and draws the wall.
*/
void		render(t_env *e)
{
	t_ray	*ray;
	int	i;

	i = 0;
	ray = ft_memalloc(sizeof(t_ray));
	ray->a = e->p->cov + (e->p->fov / 2);
	printf("%d\n", cast_horizontal(e->world, e->p, ray));
	/*
	while (ray->a > e->p->cov - (e->p->fov / 2))
	{
		ray->a = (ray->a > (2 * M_PI)) ? ray->a - (2 * M_PI) : ray->a;
		cast_horizontal(e->world, e->p, ray);
//		cast_vertical(e->world, e->p, alpha);
		ray->a -= e->p->fov / e->win->w;
	}*/
}
