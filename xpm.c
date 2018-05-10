/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 20:45:48 by sadamant          #+#    #+#             */
/*   Updated: 2018/05/09 20:50:14 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_image		*new_xpm_image(t_env *e, char *name, int w, int h)
{
	t_image	*xpm;

	xpm = (t_image *)malloc(sizeof(t_image));
	xpm->w = w;
	xpm->h = h;
	xpm->id = mlx_xpm_file_to_image(e->mlx, name, &w, &h);
	xpm->bitmap = mlx_get_data_addr(xpm->id, &(xpm->bpp), &(xpm->sline), &(xpm->endian));
	return (xpm);
}
