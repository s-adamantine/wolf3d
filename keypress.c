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

void	move_camera(int keycode, t_env *e)
{
	if (keycode == LEFT)
		e->p->cov += 10 * (M_PI / 180);
	if (keycode == RIGHT)
		e->p->cov -= 10 * (M_PI / 180);
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
	return (0);
}
