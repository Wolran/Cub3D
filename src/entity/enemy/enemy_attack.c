/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_attack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 04:05:25 by vmuller           #+#    #+#             */
/*   Updated: 2023/11/10 04:11:45 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/all.h"

void	enemy_scp_attack(t_data *const game, t_entity *const self)
{
	const t_v3f	dir = v3froty((t_v3f){.5f}, self->rot[x]);
	t_v3f		player;
	int			i;

	i = 1;
	player = self->aabb.pos + self->aabb.dim / 2.;
	player[y] = self->aabb.pos[y];
	while (i++ < 5)
		e_spike_add(game, player + dir * (float)i,
			self->rot)->dir[x] = ((float)i - 1.f) * 0.2f;
}
