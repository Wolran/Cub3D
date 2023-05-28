/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:58:51 by vmuller           #+#    #+#             */
/*   Updated: 2023/05/28 19:59:08 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

static int	is_empty_line(char *line)
{
	while (*line && ft_isspace(*line))
		line++;
	if (*line == '\n' || *line == 0)
		return (1);
	return (0);
}

static char	*get_line_with_nullcheck(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		ft_error("map is wrong");
	return (line);
}

static char	*jump_to_firstline(int fd)
{
	char	*line;

	while (1)
	{
		line = get_line_with_nullcheck(fd);
		if (!is_empty_line(line))
			return (line);
		free(line);
	}
}

static char	*join_firstline_to_eof(char *firstline, int fd)
{
	char	*present_line;
	char	*next_line;
	char	*whole_line;

	present_line = firstline;
	next_line = get_next_line(fd);
	while (next_line && *next_line != '\n')
	{
		whole_line = ft_strjoin(present_line, next_line);
		free(present_line);
		free(next_line);
		present_line = whole_line;
		next_line = get_next_line(fd);
	}
	if (next_line)
		ft_error("map is wrong");
	return (whole_line);
}

char	**read_map(int fd)
{
	char	*firstline;
	char	*whole_line;
	char	**map;

	firstline = jump_to_firstline(fd);
	whole_line = join_firstline_to_eof(firstline, fd);
	map = ft_split(whole_line, '\n');
	free(whole_line);
	return (map);
}
