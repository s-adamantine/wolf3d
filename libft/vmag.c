/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 05:34:15 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/06 14:09:53 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

double	vmag(const double *v, int n)
{
	int		i;
	double	mag;

	i = -1;
	mag = 0;
	while (++i < n)
		mag += (v[i] * v[i]);
	return (sqrt(mag));
}
