/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:53:45 by vmuller           #+#    #+#             */
/*   Updated: 2023/11/02 17:17:13 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static inline void	__closed_error(
	t_engine *const eng,
	t_map *const map)
{
	map_destroy(eng, map);
	ft_putstr_fd("parsing error : map isn't closed\n", 2);
}

static inline int	__is_closed(t_map *const map, t_v2i pos)
{
	if (map_get(map, pos + (t_v2i){1, 0}) == 255)
		return (0);
	if (map_get(map, pos + (t_v2i){-1, 0}) == 255)
		return (0);
	if (map_get(map, pos + (t_v2i){0, 1}) == 255)
		return (0);
	if (map_get(map, pos + (t_v2i){0, -1}) == 255)
		return (0);
	return (1);
}

int	is_map_closed(t_engine *const eng, t_map *const map)
{
	t_v2i	pos;

	pos[y] = 1;
	pos[x] = 0;
	while (pos[x] < map->size[x])
	{
		pos[y] = 0;
		while (pos[y] < map->size[y])
		{
			if (map_get(map, pos) == 0 && !__is_closed(map, pos))
				return (__closed_error(eng, map), 0);
			pos[y]++;
		}
		pos[x]++;
	}
	return (1);
}
