/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:03:58 by vmuller           #+#    #+#             */
/*   Updated: 2023/11/02 17:58:41 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	map_set(t_map *const map, t_v2i const pos, t_cell const cell)
{	
	if (pos[x] < 0 || pos[x] >= map->size[x]
		|| pos[y] < 0 || pos[y] >= map->size[y])
		return ;
	map->data[pos[x]][pos[y]] = cell;
}

void	map_fill(
			t_map *const map,
			t_v2i pos1,
			t_v2i pos2,
			t_cell const cell)
{
	t_v2i	pos;
	t_v2i	dir;

	dir = pos2 - pos1;
	dir = (dir < (t_v2i){0, 0}) + -(dir >= (t_v2i){0, 0});
	pos2 += dir;
	pos[x] = pos1[x];
	while (pos[x] != pos2[x])
	{
		pos[y] = pos1[y];
		while (pos[y] != pos2[y])
		{
				map_set(map, pos, cell);
			pos[y] += dir[y];
		}
		pos[x] += dir[x];
	}
}
