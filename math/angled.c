/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angled.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:34:29 by sadamant          #+#    #+#             */
/*   Updated: 2018/03/14 20:24:08 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int			angled(double value)
{
	if (is_zero(value) || is_piover2(value) || is_3piover2(value) || \
		is_pi(value) || is_2pi(value))
		return (0);
	return (1);
}
