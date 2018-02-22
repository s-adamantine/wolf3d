/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 13:44:00 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/01 14:04:37 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

double	ft_atof(char *str)
{
	double	nbr;

	nbr = ft_atoi(str++);
	if (*str++ == '.')
		nbr += (ft_atoi(str) / pow(10, ft_strlen(str)));
	return (nbr);
}
