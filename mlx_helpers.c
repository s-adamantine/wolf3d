/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 16:39:22 by sadamant          #+#    #+#             */
/*   Updated: 2018/05/11 16:39:24 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	mlx_put_text_and_value(char *str, int number, int x, int y, int color, t_env *e)
{
	char	*num;
	char	*joined;

	num = ft_itoa(number);
	joined = ft_strjoin(str, num);
	mlx_string_put(e->mlx, e->wid, x, y, color, joined);
	free(num);
	free(joined);
}
