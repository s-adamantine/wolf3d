/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:58:48 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/21 15:16:06 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	clear_image(t_image *img)
{
	ft_bzero(img->bitmap, img->sline * img->h);
}

void	print_image(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img->id, 0, 0);
	clear_image(e->img);
}

void	pixel_to_image(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= image->w || y < 0 || y >= image->h)
		return ;
	ft_memcpy(&(image->bitmap)[(x++ * image->bpp / 8) + \
		(y * image->sline)], &color, image->bpp / 8);
}

t_image	*new_image(t_env *e)
{
	t_image	*img;

	img = ft_memalloc(sizeof(t_image));
	img->w = W_WIDTH;
	img->h = W_HEIGHT;
	img->id = mlx_new_image(e->mlx, W_WIDTH, W_HEIGHT);
	img->bitmap = mlx_get_data_addr(img->id, &(img->bpp), &(img->sline), \
			&(img->endian));
	return (img);
}
