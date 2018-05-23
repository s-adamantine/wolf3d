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

int				refresh_screen(t_env *e)
{
	double	dx_f;
	double	dx_s;
	double	dy_f;
	double	dy_s;

	dx_f = 0;
	dx_s = 0;
	dy_f = 0;
	dy_s = 0;
	e->p->v = (e->key->lshift == 1) ? RUN_SPEED : WALK_SPEED;
	(e->key->w || e->key->s) ? dx_f = cos(e->p->cov) : 0; // up/down
	(e->key->a || e->key->d) ? dx_s = sin(e->p->cov) : 0; // left/right
	dx_f *= (e->key->w) ? e->p->v : -e->p->v;
	dx_s *= (e->key->d) ? e->p->v : -e->p->v;
	(e->key->w || e->key->s) ? dy_f = sin(e->p->cov) : 0;
	(e->key->a || e->key->d) ? dy_s = cos(e->p->cov) : 0;
	dy_f *= (e->key->w) ? -e->p->v : e->p->v;
	dy_s *= (e->key->a) ? -e->p->v : e->p->v;
	(e->key->left) ? e->p->cov += 1 * (M_PI / 180) : 0;
	(e->key->right) ? e->p->cov -= 1 * (M_PI / 180) : 0;
	if (!out_of_bounds(e->world, e->p->x + dx_f + dx_s, e->p->y))
		e->p->x += (dx_f + dx_s);
	if (!out_of_bounds(e->world, e->p->x, e->p->y + dy_f + dy_s))
		e->p->y += (dy_f + dy_s);
	render(e);
	return (0);
}

int				handle_keyrelease(int keycode, t_env *e)
{
	(keycode == W) ? e->key->w = 0 : 0;
	(keycode == A) ? e->key->a = 0 : 0;
	(keycode == S) ? e->key->s = 0 : 0;
	(keycode == D) ? e->key->d = 0 : 0;
	(keycode == LEFT) ? e->key->left = 0 : 0;
	(keycode == RIGHT) ? e->key->right = 0 : 0;
	(keycode == LSHIFT) ? e->key->lshift = 0 : 0;
	return (0);
}

int				handle_keypress(int keycode, t_env *e)
{
	if (keycode == ESC)
		quit_program(e);
	(keycode == W) ? e->key->w = 1 : 0;
	(keycode == A) ? e->key->a = 1 : 0;
	(keycode == S) ? e->key->s = 1 : 0;
	(keycode == D) ? e->key->d = 1 : 0;
	(keycode == LEFT) ? e->key->left = 1 : 0;
	(keycode == RIGHT) ? e->key->right = 1 : 0;
	(keycode == LSHIFT) ? e->key->lshift = 1 : 0;
	return (0);
}
