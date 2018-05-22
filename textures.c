/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:25:44 by sadamant          #+#    #+#             */
/*   Updated: 2018/05/22 13:25:51 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int grab_texture_color(t_image *texture, t_ray *r)
{
    int x_offset;

    x_offset = (r->dir == 'N' || r->dir == 'S') ? (int) r->x % TILE_SIZE : \
        (int)r->y % TILE_SIZE;
    return (texture->bitmap[1 * texture->w + x_offset]);
}
