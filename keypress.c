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

void	move_player(int keycode, t_env *e)
{
	if (keycode == W)
		e->p->x += cos(e->r->a) * SPEED;
	if (keycode == A)
		e->p->y += sin(e->r->a) * SPEED;
	if (keycode == S)
		e->p->x -= cos(e->r->a) * SPEED;
	if (keycode == D)
		e->p->y -= sin(e->r->a) * SPEED;
		render(e);
}

void	move_camera(int keycode, t_env *e)
{
	if (keycode == LEFT)
		e->p->cov += 10 * (M_PI / 180);
	if (keycode == RIGHT)
		e->p->cov -= 10 * (M_PI / 180);
	printf("cov: %f\n", e->p->cov * (180 / M_PI));
	render(e);
}

int		handle_keypress(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(e->mlx, e->wid);
		exit(EXIT_SUCCESS);
	}
	if (keycode == LEFT || keycode == RIGHT || keycode == UP || keycode == DOWN)
		move_camera(keycode, e);
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		move_player(keycode, e);
	return (0);
}
