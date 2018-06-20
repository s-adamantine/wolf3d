/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:28:35 by sadamant          #+#    #+#             */
/*   Updated: 2018/06/18 12:32:54 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_type		set_wallpaper(t_dir dir)
{
	if (dir == NORTH)
		return (ICE);
	if (dir == SOUTH)
		return (BOXES);
	if (dir == EAST)
		return (BLUESTONE);
	if (dir == WEST)
		return (WOOD);
	return (0);
}

t_image		**load_textures(t_env *e)
{
	t_image **textures;

	if (!(textures = ft_memalloc(sizeof(t_image *) * 6)))
		exit_id(1);
	textures[BRICK] = new_xpm_image(e, "textures/brickwall.xpm", 564, 564);
	textures[WOOD] = new_xpm_image(e, "textures/wood.xpm", 900, 900);
	textures[BANANAS] = new_xpm_image(e, "textures/bananas.xpm", 649, 275);
	textures[ICE] = new_xpm_image(e, "textures/icewall.xpm", 1280, 804);
	textures[BLUESTONE] = new_xpm_image(e, "textures/bluestone.xpm", 1200, 630);
	textures[BOXES] = new_xpm_image(e, "textures/seriousboxes.xpm", 576, 576);
	return (textures);
}

t_image		*new_xpm_image(t_env *e, char *name, int w, int h)
{
	t_image	*xpm;

	if (!(xpm = (t_image *)malloc(sizeof(t_image))))
		exit_id(1);
	xpm->w = w;
	xpm->h = h;
	xpm->id = mlx_xpm_file_to_image(e->mlx, name, &w, &h);
	xpm->bitmap = (int *)mlx_get_data_addr(xpm->id, &(xpm->bpp), &(xpm->sline),
		&(xpm->endian));
	return (xpm);
}
