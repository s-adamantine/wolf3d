/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:51:00 by sadamant          #+#    #+#             */
/*   Updated: 2018/05/23 17:51:05 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** should be able to load as many textures as we want
*/
t_image     **init_textures(t_env *e)
{
    t_image **textures;

    textures = ft_memalloc(sizeof(t_image *) * 8);
    textures[BRICK] = new_xpm_image(e, "textures/brickwall.xpm", 800, 533);
    textures[STONE] = new_xpm_image(e, "textures/stone.xpm", 1024, 1024);
    textures[URCHINS] = new_xpm_image(e, "textures/urchins.xpm", 450, 450);
    textures[WOOD] = new_xpm_image(e, "textures/wood.xpm", 900, 900);
    textures[BANANAS] = new_xpm_image(e, "textures/bananas.xpm", 649, 275);
    textures[ANNE] = new_xpm_image(e, "textures/anne.xpm", 800, 533);
    textures[TRIPPY] = new_xpm_image(e, "textures/trippyflowers.xpm", 1300, 1300);
    textures[BOXES] = new_xpm_image(e, "textures/seriousboxes.xpm", 576, 576);
    return (textures);
}

t_image		*new_xpm_image(t_env *e, char *name, int w, int h)
{
	t_image	*xpm;

	xpm = (t_image *)malloc(sizeof(t_image));
	xpm->w = w;
	xpm->h = h;
	xpm->id = mlx_xpm_file_to_image(e->mlx, name, &w, &h);
	xpm->bitmap = (int *)mlx_get_data_addr(xpm->id, &(xpm->bpp), &(xpm->sline), \
		&(xpm->endian));
	return (xpm);
}
