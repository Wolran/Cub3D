/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 05:50:21 by alde-fre          #+#    #+#             */
/*   Updated: 2023/11/11 01:15:24 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/entity.h"

void	entities_update(t_data *const game, float const dt)
{
	t_entity	*ent;
	t_length	index;

	index = 0;
	while (index < game->entities.size)
	{
		ent = &((t_entity *)game->entities.data)[index];
		ent->update(ent, game, dt);
		ent->time_alive += dt;
		++index;
	}
}

void	entities_display(t_data *const game)
{
	t_entity	*ent;
	t_length	index;

	ent = game->entities.data;
	index = 0;
	while (index < game->entities.size)
	{
		ent = &((t_entity *)game->entities.data)[index];
		ent->display(ent, game);
		put_3d_point(game->eng, &game->cam, ent->aabb.pos, 0.05f);
		put_3d_point(game->eng, &game->cam, ent->aabb.pos + \
			ent->aabb.dim, 0.05f);
		++index;
	}
}

void	entities_destroy(t_data *const game)
{
	t_entity	*ent;
	t_length	index;

	index = 0;
	while (index < game->entities.size)
	{
		ent = &((t_entity *)game->entities.data)[index];
		if (ent->dead)
		{
			ent->destroy(ent, game);
			vector_erase(&game->entities, index);
		}
		else
			index++;
	}
}
