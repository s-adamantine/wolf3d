/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 20:30:06 by sadamant          #+#    #+#             */
/*   Updated: 2018/03/07 20:30:08 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		is_zero(double value)
{
	if (value >= -0.000001 && value <= 0.000001)
		return (1);
	return (0);
}

int		is_piover2(double value)
{
	if (value >= (M_PI / 2 - 0.000001) && value <= (M_PI / 2 + 0.000001))
		return (1);
	return (0);
}

int		is_pi(double value)
{
	if (value >= (M_PI - 0.000001) && value <= (M_PI + 0.000001))
		return (1);
	return (0);
}

int		is_3piover2(double value)
{
	if (value >= ((3 * M_PI) / 2 - 0.000001) && value <= ((3 * M_PI) / 2 + 0.000001))
		return (1);
	return (0);
}

int		is_2pi(double value)
{
	if (value >= ((2 * M_PI) - 0.000001) && value <= ((2 * M_PI) + 0.000001))
		return (1);
	return (0);
}
