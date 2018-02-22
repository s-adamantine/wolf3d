/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:59:40 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/22 16:45:22 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_world		*setup_world(char **argv)
{
	t_world		*world;

	world = ft_memalloc(sizeof(t_world));
	world->wall_h = WALL_H;
	world->map = parse_file(argv);
	return (world);
}

t_window	*new_window(void)
{
	t_window	*win;

	win = ft_memalloc(sizeof(t_window));
	win->w = W_WIDTH;
	win->h = W_HEIGHT;
	return (win);
}

t_player	*setup_player(void)
{
	t_player	*p;

	p->x = 0;
	p->y = 0;
	p->h = 75;
	p->fov = 60;
	return (p);
}
