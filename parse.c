/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:09:28 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/26 17:09:25 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		validate_map(t_world *world, char **map)
{
	int	i;
	int	j;

	j = -1;
	while (++j < world->h)
	{
		i = -1;
		while (++i < world->w)
			if (map[j][i] != '.' && map[j][i] != 'x')
				return (0);
	}
	return (1);
}

char			**parse_file(char **argv, t_world *world)
{
	int		i;
	int		fd;
	char	*line;
	char	**map;

	world->h = 1;
	fd = open(argv[1], O_RDONLY);
	if (get_next_line(fd, &line) == -1)
		exit_error("Input file does not seem to exist.");
	free(line);
	world->w = (int)ft_strlen(line);
	while (get_next_line(fd, &line) > 0)
	{
		if ((int)ft_strlen(line) != world->w)
			exit_error("Differing number of points per line in map.");
		world->h += 1;
		free(line);
	}
	if (!(map = ft_memalloc(sizeof(char *) * (world->h + 1))))
		exit_error("Failed to allocate memory");
	close(fd);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) > 0)
		map[i++] = line;
	if (!validate_map(world, map))
		exit_error("Map invalid.");
	free(line);
	return (map);
}
