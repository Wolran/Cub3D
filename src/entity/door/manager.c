/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:33:08 by alde-fre          #+#    #+#             */
/*   Updated: 2023/10/21 03:01:35 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/all.h"
#include "particle/particle.h"

static void	_door_update(
			t_entity *const self,
			t_data *const game,
			float const dt)
{
	(void)self;
	(void)game;
	(void)dt;
}

static void	_door_display(t_entity *const self, t_data *const game)
{
	t_transform	trans;

	trans.rotation = self->rot;
	trans.resize = (t_v3f){1.f, 1.f, 1.f};
	trans.translation = self->pos + (t_v3f){0.0f, 0.5f, 0.0f};
	mesh_put(game->eng, &game->cam, trans, self->mesh);
}

static void	_door_destroy(t_entity *const self, t_data *const game)
{
	(void)self;
	(void)game;
}

t_entity	*e_door_add(
				t_data *const game,
				t_v3f const pos,
				t_v2f const rot)
{
	t_entity	*ent;

	ent = entity_add(game, pos);
	if (ent == NULL)
		return (NULL);
	ent->update = &_door_update;
	ent->display = &_door_display;
	ent->destroy = &_door_destroy;
	ent->dir = (t_v3f){};
	ent->rot = rot;
	ent->mesh = &game->models[5];
	ent->type = ENTITY_DOOR;
	return (ent);
}
