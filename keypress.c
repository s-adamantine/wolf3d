/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:57:42 by sadamant          #+#    #+#             */
/*   Updated: 2018/03/13 14:55:59 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** check if the player will move out of the map bounds or will collide into a
** wall
*/

static int		out_of_bounds(t_world *world, double x, double y)
{
	if (x < 0 || y < 0)
		return (1);
	if (x > (world->w * world->tile) || y > (world->h * world->tile))
		return (1);
	if (world->map[(int)y / world->tile][(int)x / world->tile] == 'x')
		return (1);
	return (0);
}

void			move_player(int keycode, t_env *e)
{
	double	dx;
	double	dy;

	dx = (keycode == W || keycode == S) ? cos(e->p->cov) : sin(e->p->cov);
	dx *= (keycode == W || keycode == D) ? SPEED : -SPEED;
	dy = (keycode == W || keycode == S) ? sin(e->p->cov) : cos(e->p->cov);
	dy *= (keycode == W || keycode == A) ? -SPEED : SPEED;
	if (!out_of_bounds(e->world, e->p->x + dx, e->p->y))
		e->p->x += dx;
	if (!out_of_bounds(e->world, e->p->x, e->p->y + dy))
		e->p->y += dy;
	render(e);
}

void			move_camera(int keycode, t_env *e)
{
	if (keycode == LEFT)
		e->p->cov += 10 * (M_PI / 180);
	if (keycode == RIGHT)
		e->p->cov -= 10 * (M_PI / 180);
	render(e);
}

int				handle_keypress(int keycode, t_env *e)
{
	if (keycode == ESC)
		quit_program(e);
	if (keycode == LEFT || keycode == RIGHT || keycode == UP || keycode == DOWN)
		move_camera(keycode, e);
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		move_player(keycode, e);
	return (0);
}
