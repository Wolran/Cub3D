/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:48:47 by vmuller           #+#    #+#             */
/*   Updated: 2023/11/02 18:23:49 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	map_create(t_v2i const size)
{
	t_map	map;
	t_v2i	pos;

	if (size[x] <= 0 || size[y] <= 0)
		return ((t_map){0});
	map.data = malloc(sizeof(t_cell *) * size[x]);
	pos[x] = 0;
	while (pos[x] < size[x])
	{
		pos[y] = 0;
		map.data[pos[x]] = malloc(sizeof(t_cell) * size[y]);
		while (pos[y] < size[y])
		{
			ft_memset(map.data[pos[x]], 0, sizeof(t_cell) * size[y]);
			pos[y]++;
		}
		pos[x]++;
	}
	map.size = size;
	ft_memset(map.sprites, 0, sizeof(t_sprite *) * 4);
	return (map);
}

void	map_destroy(t_engine *const eng, t_map *const map)
{
	t_v2i		pos;
	t_length	i;

	pos[x] = 0;
	while (pos[x] < map->size[x])
	{
		free(map->data[pos[x]]);
		pos[x]++;
	}
	free(map->data);
	map->size = (t_v2i){0, 0};
	i = 0;
	while (i < 4)
	{
		if (map->sprites[i])
			ft_destroy_sprite(eng, map->sprites[i]);
		i++;
	}
}
