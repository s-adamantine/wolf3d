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

void			draw_square(t_env *e)
{
	int	x;
	int	y;
	int	h;

	x = 350;
	y = 100;
	h = 100;
	while (y++ < 150)
	{
		printf("y is %d\n", y);
		insert_bitmap(e->img, 350, y, COLOR);
	}
}

int				main(int argc, char **argv)
{
	t_env*		e;

	e = setup_environment(argc, argv);
	render(e);
	mlx_loop(e->mlx);
	return (0);
}
