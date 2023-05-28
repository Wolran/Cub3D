/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:58:59 by vmuller           #+#    #+#             */
/*   Updated: 2023/05/28 20:36:26 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

static int	check_one_arg(char current)
{
	if (current == FLOOR)
		return (0);
	if (current == WALL)
		return (1);
	if (current == 'E' || current == 'W' || current == 'S' || current == 'N')
		return (2);
	if (!ft_isspace(current))
		ft_error("map is invalid");
	return (3);
}

static void	check_with_around_arg(char pre, char current, char next)
{
	if (ft_isspace(current)
		&& ((pre != 0 && pre != WALL && !ft_isspace(pre))
			|| (next != 0 && next != WALL && !ft_isspace(next))))
		ft_error("map is invalid");
	if ((pre == 0 || next == 0) \
	&& (current != WALL && !ft_isspace(current)))
		ft_error("map is invalid");
}

static void	check_x_axis(size_t x, size_t y, char **map)
{
	char	left_x;
	char	right_x;

	left_x = 0;
	if (x != 0)
		left_x = map[y][x - 1];
	right_x = map[y][x + 1];
	check_with_around_arg(left_x, map[y][x], right_x);
}

static void	check_y_axis(size_t x, size_t y, char **map)
{
	char	up_y;
	char	down_y;

	up_y = 0;
	if (y != 0 && x < ft_strlen(map[y - 1]))
			up_y = map[y - 1][x];
	down_y = 0;
	if (map[y + 1] && x < ft_strlen(map[y + 1]))
		down_y = map[y + 1][x];
	check_with_around_arg(up_y, map[y][x], down_y);
}

void	test_map(char **map, t_game *game)
{
	size_t	x;
	size_t	y;
	int		content_flag[4];

	game->max_x = 0;
	ft_memset(content_flag, 0, sizeof(int) * 4);
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			content_flag[check_one_arg(map[y][x])]++;
			check_x_axis(x, y, map);
			check_y_axis(x, y, map);
		}
		if (game->max_x < x)
			game->max_x = x;
		game->max_y = y + 1;
	}
	if (!(content_flag[0] && content_flag[1] && content_flag[2] == 1))
		ft_error("map is invalid");
	game->map = map;
}
