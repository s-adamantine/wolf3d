/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:58:48 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/22 16:26:43 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	clear_image(t_image *img)
{
	ft_bzero(img->bitmap, img->sline * img->h);
	// free(img->bitmap);
}

void	print_text(t_env *e)
{
	mlx_put_text_and_value("cov: ", (int) (e->p->cov * (180 / M_PI)), 640, 20, COLOR, e);
	mlx_put_text_and_value("x: ", (int) e->p->x, 640, 40, COLOR, e);
	mlx_put_text_and_value("y: ", (int) e->p->y, 640, 60, COLOR, e);
}

void	print_image(t_env *e)
{
	draw_midpoint(e);
	mlx_put_image_to_window(e->mlx, e->wid, e->img->id, 0, 0);
	print_text(e);
	clear_image(e->img);
}

void	insert_bitmap(t_image *img, int x, int y, int color)
{
	if (x < 0 || x >= img->w || y < 0 || y >= img->h)
		return ;
	ft_memcpy(&(img->bitmap)[(x++ * img->bpp / 8) + \
		(y * img->sline)], &color, img->bpp / 8);
}

t_image	*new_image(t_env *e, int width, int height)
{
	t_image	*img;

	img = ft_memalloc(sizeof(t_image));
	img->w = width;
	img->h = height;
	img->id = mlx_new_image(e->mlx, width, height);
	img->bitmap = mlx_get_data_addr(img->id, &(img->bpp), &(img->sline), \
			&(img->endian));
	return (img);
}
