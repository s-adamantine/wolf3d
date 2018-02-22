/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 17:08:20 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/05 17:28:41 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	**matnew(int i, int j)
{
	int		n;
	double	**mat;

	n = -1;
	mat = ft_memalloc(sizeof(double *) * (i + 1));
	while (++n < j)
		mat[n] = ft_memalloc(sizeof(double) * (j + 1));
	return (mat);
}
