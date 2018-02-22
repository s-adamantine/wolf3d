/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 19:54:09 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/01 14:20:19 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	expand_line(char **line)
{
	char	*old_line;
	char	*expanded;

	old_line = *line;
	expanded = ft_strnew(ft_strlen(*line) + BUFF_SIZE);
	ft_strcpy(expanded, *line);
	free(old_line);
	*line = expanded;
}

/*
** grabs characters from the buffer to line (until a \n) and clears off
** grabbed characters from buffer.
** returns 1 if a line is read, 0 if you need to read more characters.
*/

int		transfer(char **line, char *buf)
{
	int		i;
	int		j;
	char	*grab;

	i = 0;
	j = 0;
	grab = ft_strnew(BUFF_SIZE);
	while (buf[i] && buf[i] != '\n')
	{
		grab[i] = buf[i];
		i++;
	}
	ft_strcat(*line, grab);
	free(grab);
	if (ft_strchr(buf, '\n'))
	{
		i++;
		while (buf[i])
			buf[j++] = buf[i++];
		buf[j] = '\0';
		return (1);
	}
	ft_bzero(buf, BUFF_SIZE);
	expand_line(line);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			r;
	static char	*buf;

	if (fd < 0 || !line)
		return (-1);
	*line = ft_memalloc(BUFF_SIZE);
	if (buf && transfer(line, buf))
		return (1);
	else
		buf = ft_strnew(BUFF_SIZE);
	while ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (transfer(line, buf))
			return (1);
	}
	if (r < 0)
		return (-1);
	if (**line)
		return (1);
	return (0);
}
