/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:17:42 by sadamant          #+#    #+#             */
/*   Updated: 2018/05/17 14:17:50 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** finds the distance and then applies a fisheye correction
*/

double		distance(t_ray *r, t_player *p)
{
	double	dist;

	dist = sqrt(pow((p->x - r->x), 2) + pow((p->y - r->y), 2));
	dist *= cos(r->a - p->cov);
	return (dist);
}
