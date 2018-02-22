/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:59:40 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/22 15:03:52 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_world		*setup_world(char **argv)
{
	t_world		*world;

	world = ft_memalloc(sizeof(t_world));
	world->map = parse_file(argv);
	return (world);
}
