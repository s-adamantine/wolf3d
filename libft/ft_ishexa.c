/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 21:10:01 by sadamant          #+#    #+#             */
/*   Updated: 2017/12/12 21:10:06 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if the string is in the format 0xFFFFFF.
*/

int					ft_ishexa(char *str)
{
	int		i;

	i = 2;
	if (ft_strlen(str) != 8)
		return (0);
	if (str[0] != '0' && str[1] != 'x')
		return (0);
	while (i < 8)
	{
		if (!ft_isdigit(str[i]) && !(str[i] >= 'A' && str[i] <= 'F'))
			return (0);
		i++;
	}
	return (1);
}
