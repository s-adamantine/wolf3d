/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:52:37 by sadamant          #+#    #+#             */
/*   Updated: 2018/03/13 11:53:27 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

int			quit_program(t_env *e)
{
	mlx_destroy_window(e->mlx, e->wid);
	exit(EXIT_SUCCESS);
	return (0);
}

int			main(int argc, char **argv)
{
	t_env	*e;

	e = setup_environment(argc, argv);
	render(e);
	mlx_loop(e->mlx);
	return (0);
}
