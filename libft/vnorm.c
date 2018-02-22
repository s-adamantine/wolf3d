/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vnorm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:59:27 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/21 14:03:32 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	*vnorm(const double *v)
{
	int		i;
	int		n;
	double	mag;
	double	*vn;

	i = -1;
	n = 0;
	while (v[n])
		n++;
	mag = vmag(v, n);
	vn = ft_memalloc(sizeof(double) * (n + 1));
	while (++i < n)
		vn[i] = v[i] / mag;
	vn[n] = '\0';
	return (vn);
}
