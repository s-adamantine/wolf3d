/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:52:37 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/22 15:11:22 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

static t_env	*setup_environment(int argc, char **argv)
{
	t_env	*e;

	if (argc != 2)
	{
		ft_putendl_fd("Welcome to Wolf3D!", 2);
		exit_error("usage: ./maps/mapfile");
	}
	e = ft_memalloc(sizeof(t_env));
	e->mlx = mlx_init();
	e->img = new_image(e);
	e->world = setup_world(argv);
	e->win = mlx_new_window(e->mlx, e->img->w, e->img->h, "wolf3d");
	return (e);
}

int				main(int argc, char **argv)
{
	int			i;
	t_env*		e;

	e = setup_environment(argc, argv);
	mlx_loop(e->mlx);
	return (0);
}
