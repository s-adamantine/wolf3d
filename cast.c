/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:56:47 by sadamant          #+#    #+#             */
/*   Updated: 2018/03/07 16:00:58 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	angled(double value)
{
	if (is_zero(value) || is_piover2(value) || is_3piover2(value) || \
		is_pi(value) || is_2pi(value))
		return (0);
	return (1);
}

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

/*
** finds grid coordinates along the ray path to check for wall presence
** 1 if there's a wall, -1 if there isn't.
*/
static int	cast_horizontal(t_world *world, t_player *p, t_ray *ray)
{
	first_hintersection(ray, world, p);
	while (check_wall(world, ray->x, ray->y) == 0)
	{
		if (is_piover2(ray->a))
			ray->y -= world->tile;
		else if (is_3piover2(ray->a))
			ray->y += world->tile;
		else
		{
			ray->x += world->tile/tan(ray->a);
			ray->y += (ray->a > 0 && ray->a < M_PI) ? -world->tile : world->tile;
		}
	}
	return (check_wall(world, ray->x, ray->y));
}

static int	cast_vertical(t_world *world, t_player *p, t_ray *ray)
{
	first_vintersection(ray, world, p);
	while (check_wall(world, ray->x, ray->y) == 0)
	{
		if (is_zero(ray->a))
			ray->x += world->tile;
		else if (is_pi(ray->a))
			ray->x -= world->tile;
		else
		{
			ray->x += (ray->a < (M_PI / 2) || ray->a > ((3 * M_PI) / 2)) ? \
				world->tile : -world->tile;
			ray->y += -world->tile * tan(ray->a);
		}
	}
	return (check_wall(world, ray->x, ray->y));
}

/*
** goes through the entire window and if there's a wall intersection, finds the distance of
** wall to player, and draws the wall.
*/
void		render(t_env *e)
{
	t_ray	*ray;
	int		x;

	x = 0;
	ray = ft_memalloc(sizeof(t_ray));
	ray->a = e->p->cov + (e->p->fov / 2);
	while (ray->a > e->p->cov - (e->p->fov / 2))
	{
		if (angled(ray->a))
		{
			cast_horizontal(e->world, e->p, ray);
			cast_vertical(e->world, e->p, ray);
		}
		else if (is_zero(ray->a) || is_pi(ray->a) || is_2pi(ray->a))
			cast_vertical(e->world, e->p, ray);
		else if (is_piover2(ray->a) || is_3piover2(ray->a))
			cast_horizontal(e->world, e->p, ray);
		ray->a -= e->p->fov / e->win->w;
		draw_wallpiece(e, ray, x);
		x++;
		// printf("intersects at %f, %f", ray->x, ray->y);
	}
	print_image(e);
}
