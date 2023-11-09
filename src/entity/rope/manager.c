/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:20:51 by vmuller           #+#    #+#             */
/*   Updated: 2023/11/09 09:11:25 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/all.h"
#include "title.h"

static void	_rope_update(
			t_entity *const self,
			t_data *const game,
			float const dt)
{
	(void)dt;
	t_entity *const player = game->entities.data;
	if ((ft_mouse(game->eng, 3).pressed) && can_see_aabb(game, player->aabb.pos, &self->aabb, 1.0f))
	{
		game->selected_model = 12;
		self->dead = 1;
	}
}

static void	_rope_display(t_entity *const self, t_data *const game)
{
	t_transform	trans;

	trans.rotation = self->rot;
	trans.resize = (t_v3f){.8f, .8f, .8f};
	trans.translation = self->aabb.pos + (t_v3f){0.15f, 0.0f, 0.15f};
	mesh_put(game->eng, &game->cam, trans, &game->models[12]);
}

static void	_rope_destroy(t_entity *const self, t_data *const game)
{
	(void)self;
	(void)game;
}

t_entity	*e_rope_add(t_data *const game, t_v3f const pos, t_v2f rot)
{
	t_entity	*ent;

	ent = entity_add(game, pos);
	if (ent == NULL)
		return (NULL);
	ent->update = &_rope_update;
	ent->display = &_rope_display;
	ent->destroy = &_rope_destroy;
	ent->dir = (t_v3f){0};
	ent->rot = (t_v2f){rot[x], rot[y]};
	ent->mesh = &game->models[12];
	ent->aabb.dim = (t_v3f){0.3f, 0.2f, 0.3f};
	ent->aabb.pos = pos - (t_v3f){0.15f, 0.0f, 0.15f};
	ent->aabb.type = AABB_IMMOVABLE;
	ent->type = ENTITY_ROPE;
	return (ent);
}
