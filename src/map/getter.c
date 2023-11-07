/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:02:09 by vmuller           #+#    #+#             */
/*   Updated: 2023/09/28 11:41:45 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_cell	map_get(t_map const *const map, t_v3i const pos)
{
	if (pos[x] < 0 || pos[x] >= map->size[x]
		|| pos[y] < 0 || pos[y] >= map->size[y]
		|| pos[z] < 0 || pos[z] >= map->size[z])
		return (cell_void);
	return (map->data[pos[x]][pos[y]][pos[z]]);
}

t_v3i	map_size(t_map const *const map)
{
	return (map->size);
}
