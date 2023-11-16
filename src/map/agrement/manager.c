/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:08:16 by alde-fre          #+#    #+#             */
/*   Updated: 2023/10/21 02:15:30 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "agrement.h"

void	map_agrement(t_data *const game, t_map *const map)
{
	ft_putstr_fd("[GEN] Generating alot of doors...\n", 1);
	map_iterate(game, map, map_gen_doors);
	ft_putstr_fd("[GEN] Generating simple rooms...\n", 1);
	map_iterate(game, map, map_gen_rooms);
	ft_putstr_fd("[GEN] Simplifying rooms layout...\n", 1);
	map_iterate(game, map, map_gen_merge_rooms);
	ft_putstr_fd("[GEN] Elevating ceillings...\n", 1);
	map_iterate(game, map, map_gen_elevate_rooms);
	ft_putstr_fd("[GEN] Map looks OKAY !\n", 1);
}
