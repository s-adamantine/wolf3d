/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 13:04:23 by sadamant          #+#    #+#             */
/*   Updated: 2018/06/18 13:04:27 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** check if the player will move out of the map bounds or will collide into a
** wall, with a margin  around the wall to prevent texture stretching
*/

static int		out_of_bounds(t_world *world, double x, double y)
{
	if (x < 0 || y < 0)
		return (1);
	if (x + WALL_MARGIN > (world->w * TILE) ||
		y + WALL_MARGIN > (world->h * TILE))
		return (1);
	if (world->map[(int)y / TILE][(int)x / TILE] == 'x')
		return (1);
	if (world->map[(int)(y + WALL_MARGIN) / TILE][(int)x / TILE] == 'x')
		return (1);
	if (world->map[(int)(y - WALL_MARGIN) / TILE][(int)x / TILE] == 'x')
		return (1);
	if (world->map[(int)(y) / TILE][(int)(x + WALL_MARGIN) / TILE] == 'x')
		return (1);
	if (world->map[(int)(y) / TILE][(int)(x - WALL_MARGIN) / TILE] == 'x')
		return (1);
	return (0);
}

/*
** f = forwards/backwards keypresses (W/S) and s = sideways keypresses (A/D)
*/

static void		recalculate_movement(t_key *key, t_player *p, t_world *world)
{
	double	dx_f;
	double	dx_s;
	double	dy_f;
	double	dy_s;

	p->v = (key->lshift == 1) ? RUN_SPEED : WALK_SPEED;
	dx_f = (key->w || key->s) ? cos(p->cov) : 0.0;
	dx_f *= (key->w) ? p->v : -p->v;
	dx_s = (key->a || key->d) ? sin(p->cov) : 0.0;
	dx_s *= (key->d) ? p->v : -p->v;
	dy_f = (key->w || key->s) ? sin(p->cov) : 0.0;
	dy_f *= (key->w) ? -p->v : p->v;
	dy_s = (key->a || key->d) ? cos(p->cov) : 0.0;
	dy_s *= (key->a) ? -p->v : p->v;
	(key->left) ? p->cov += 1 * (M_PI / 180) : 0;
	(key->right) ? p->cov -= 1 * (M_PI / 180) : 0;
	if (!out_of_bounds(world, p->x + dx_f + dx_s, p->y))
		p->x += (dx_f + dx_s);
	if (!out_of_bounds(world, p->x, p->y + dy_f + dy_s))
		p->y += (dy_f + dy_s);
}

int				refresh_screen(t_env *e)
{
	recalculate_movement(e->key, e->p, e->world);
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
