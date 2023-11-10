/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:33:08 by alde-fre          #+#    #+#             */
/*   Updated: 2023/11/10 04:10:25 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/all.h"

static void	_spike_update(
			t_entity *const self,
			t_data *const game,
			float const dt)
{
	(void)dt;
	(void)game;
	self->dead = (self->time_alive - self->dir[x] >= 2.f);
}

static void	_spike_display(t_entity *const self, t_data *const game)
{
	t_transform	trans;
	float		value;

	value = fmaxf(self->time_alive - self->dir[x], 0.0f);

	trans.rotation = self->rot;
	trans.resize = (t_v3f){.2f, .2f, .2f};
	trans.translation = self->aabb.pos;
	trans.translation[y] = self->aabb.pos[y] + \
	fminf(sinf(value / 2.f * M_PI) * 2.f, 0.25f) * 0.5f - 0.25f;
	mesh_put(game->eng, &game->cam, trans, &game->models[11]);
}

static void	_spike_destroy(t_entity *const self, t_data *const game)
{
	(void)self;
	(void)game;
}

t_entity	*e_spike_add(t_data *const game, t_v3f const pos, t_v2f rot)
{
	t_entity	*ent;

	ent = entity_add(game, pos);
	if (ent == NULL)
		return (NULL);
	ent->update = &_spike_update;
	ent->display = &_spike_display;
	ent->destroy = &_spike_destroy;
	ent->dir = (t_v3f){0};
	ent->rot = (t_v2f){rot[x], -M_PI_4};
	ent->mesh = &game->models[11];
	ent->type = ENTITY_SPIKE;
	return (ent);
}
