/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendsw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 20:29:27 by sadamant          #+#    #+#             */
/*   Updated: 2017/12/09 20:29:33 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strendsw(char *big, char *small)
{
	if (!big || !small || ft_strlen(big) < ft_strlen(small))
		return (0);
	big = big + ft_strlen(big) - 1;
	small = small + ft_strlen(small) - 1;
	while (*small)
	{
		if (*big-- == *small--)
			;
		else
			return (0);
	}
	return (1);
}
