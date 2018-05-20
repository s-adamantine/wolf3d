/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:59:40 by sadamant          #+#    #+#             */
/*   Updated: 2018/03/13 13:29:03 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_world		*setup_world(char **argv)
{
	t_world		*world;

	world = ft_memalloc(sizeof(t_world));
	world->wall_h = WALL_H;
	world->map = parse_file(argv, world);
	world->tile = TILE_SIZE;
	return (world);
}

static t_player		*setup_player(void)
{
	t_player	*p;

	p = ft_memalloc(sizeof(t_player));
	p->x = 150;
	p->y = 150;
	p->h = 75;
	p->c = WALL_H * PLAYER_TO_PLANE;
	p->fov = M_PI / 3;
	p->cov = 120 * (M_PI / 180);
	return (p);
}

t_env				*setup_environment(int argc, char **argv)
{
	t_env	*e;

	if (argc != 2)
	{
		ft_putendl_fd("Welcome to Wolf3D!", 2);
		exit_error("usage: ./maps/mapfile");
	}
	e = ft_memalloc(sizeof(t_env));
	e->world = setup_world(argv);
	e->p = setup_player();
	e->mlx = mlx_init();
	e->wid = mlx_new_window(e->mlx, WINDOW_W, WINDOW_H, "wolf3d");
	e->img = new_image(e, WINDOW_W, WINDOW_H);
	mlx_hook(e->wid, 2, 0, handle_keypress, e);
	mlx_hook(e->wid, 17, 0, quit_program, e);
	return (e);
}
