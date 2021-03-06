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

	if (!(world = ft_memalloc(sizeof(t_world))))
		exit_id(1);
	world->wall_h = WALL_H;
	world->map = parse_file(argv, world);
	return (world);
}

static void			position_player(t_player *p, char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				p->x = (i + 1) * TILE - TILE / 2;
				p->y = (j + 1) * TILE - TILE / 2;
				return ;
			}
			i++;
		}
		j++;
	}
	exit_error("Can't find player position. :(");
}

static t_player		*setup_player(t_env *e)
{
	t_player	*p;

	if (!(p = ft_memalloc(sizeof(t_player))))
		exit_id(1);
	position_player(p, e->world->map);
	p->v = WALK_SPEED;
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
	e->p = setup_player(e);
	e->mlx = mlx_init();
	e->wid = mlx_new_window(e->mlx, WINDOW_W, WINDOW_H, "wolf3d");
	e->img = new_image(e, WINDOW_W, WINDOW_H);
	e->key = ft_memalloc(sizeof(t_key));
	e->t = ft_memalloc(sizeof(t_texture));
	e->t->textures = load_textures(e);
	if (!e->world || !e->p || !e->mlx || !e->wid || !e->img || !e->key || !e->t)
		exit_id(1);
	mlx_hook(e->wid, KEYPRESS_EVENT, 0, handle_keypress, e);
	mlx_hook(e->wid, KEYRELEASE_EVENT, 0, handle_keyrelease, e);
	mlx_hook(e->wid, REDX_EVENT, 0, quit_program, e);
	mlx_loop_hook(e->mlx, refresh_screen, e);
	return (e);
}
