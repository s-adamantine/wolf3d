/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:32:17 by sadamant          #+#    #+#             */
/*   Updated: 2018/03/13 13:32:27 by sadamant         ###   ########.fr       */
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
	}
	print_image(e);
}
