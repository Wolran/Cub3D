/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:43:15 by alde-fre          #+#    #+#             */
/*   Updated: 2023/11/02 17:56:54 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "game.h"

int	map_iterate(
		t_data *const game,
		t_map *const map,
		int (*func)(t_data *const game, t_map *const map, t_v2i const pos))
{
	t_v2i		pos;
	int			error;

	pos[y] = 1;
	pos[x] = 0;
	while (pos[x] < map->size[x])
	{
		error = func(game, map, pos);
		if (error)
			return (error);
		pos[x]++;
	}
	return (0);
}
