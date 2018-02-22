/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:57:42 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/22 16:29:12 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		handle_keypress(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(e->mlx, e->wid);
		exit(EXIT_SUCCESS);
	}
	return (1);
}
