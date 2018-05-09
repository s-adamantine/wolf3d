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

static t_window		*new_window(void)
{
	t_window	*win;

	win = ft_memalloc(sizeof(t_window));
	win->w = W_WIDTH;
	win->h = W_HEIGHT;
	return (win);
}

static t_player		*setup_player(void)
{
	t_player	*p;

	p = ft_memalloc(sizeof(t_player));
	p->x = 144.778960;
	p->y = 156.426758;
	p->h = 75;
	p->c = WALL_H * PLAYER_TO_PLANE;
	p->fov = M_PI / 3;
	p->cov = 120 * (M_PI / 180);
	return (p);
}

static t_ray		*setup_ray(t_player *p)
{
	t_ray	*r;

	r = ft_memalloc(sizeof(t_ray));
	r->a = p->cov + (p->fov / 2);
	return (r);
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
	e->mlx = mlx_init();
	e->win = new_window();
	e->wid = mlx_new_window(e->mlx, e->win->w, e->win->h, "wolf3d");
	e->img = new_image(e, e->win->w, e->win->h);
	e->world = setup_world(argv);
	e->p = setup_player();
	e->r = setup_ray(e->p);
	mlx_hook(e->wid, 2, 0, handle_keypress, e);
	mlx_hook(e->wid, 17, 0, quit_program, e);
	return (e);
}
