/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:02:09 by vmuller           #+#    #+#             */
/*   Updated: 2023/11/02 17:52:58 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_cell	map_get(t_map const *const map, t_v2i const pos)
{
	if (pos[x] < 0 || pos[x] >= map->size[x]
		|| pos[y] < 0 || pos[y] >= map->size[y])
		return (cell_void);
	return (map->data[pos[x]][pos[y]]);
}

t_v2i	map_size(t_map const *const map)
{
	return (map->size);
}
