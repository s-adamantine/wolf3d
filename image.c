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
}

void	print_image(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->wid, e->img->id, 0, 0);
	// mlx_put_text_and_value("x: ", (int) e->p->x, 640, 20, TEXTCOLOR, e);
	// mlx_put_text_and_value("y: ", (int) e->p->y, 640, 40, TEXTCOLOR, e);
	clear_image(e->img);
}

void	insert_bitmap(t_image *img, int x, int y, unsigned int color)
{
	if (x < 0 || x >= img->w || y < 0 || y >= img->h)
		return ;
	img->bitmap[(y * img->w + x)] = color;
}

int		get_color(t_image *img, int x, int y)
{
	return (img->bitmap[(y * img->w + x)]);
}

t_image	*new_image(t_env *e, int width, int height)
{
	t_image	*img;

	if (!(img = ft_memalloc(sizeof(t_image))))
		exit_id(1);
	img->w = width;
	img->h = height;
	img->id = mlx_new_image(e->mlx, width, height);
	img->bitmap = (int *)mlx_get_data_addr(img->id, &(img->bpp), &(img->sline),
			&(img->endian));
	return (img);
}
