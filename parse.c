/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:09:28 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/22 14:47:56 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	**parse_file(char **argv)
{
	int		i;
	int		fd;
	char	*line;
	char	**map;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		i++;
	map = ft_memalloc(sizeof(char *) * (i + 1));
	close(fd);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) > 0)
		map[i++] = ft_strcsplit(line, ' ');
	return (map);	
}
