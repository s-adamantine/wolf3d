/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:09:11 by sadamant          #+#    #+#             */
/*   Updated: 2018/04/13 18:09:16 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			tophalf(double value)
{
	if (value > 0 && value < M_PI)
		return (1);
	if (value > (2 * M_PI) && value < (3 * M_PI))
		return (1);
	return (0);
}

int			righthalf(double value)
{
	if (value < (M_PI / 2) || value > ((3 * M_PI) / 2))
		return (1);
	return (0);
}
