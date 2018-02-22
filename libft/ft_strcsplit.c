/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:25:45 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/22 12:25:47 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** splits a string into an array of integers, delimited by c
*/

char	*ft_strcsplit(char const *s, char c)
{
	int		i;
	char	*split;

	i = 0;
	if (!s)
		return (NULL);
	split = NULL;
	split = ft_memalloc(sizeof(char) * (ft_wordcount(s, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
			split[i++] = *s;
		s++;
	}
	split[i] = '\0';
	return (split);
}
