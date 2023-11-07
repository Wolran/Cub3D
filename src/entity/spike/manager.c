/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:33:08 by alde-fre          #+#    #+#             */
/*   Updated: 2023/11/06 07:23:43 by vmuller          ###   ########.fr       */
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
	trans.resize = (t_v3f){1.0f, 1.0f, 1.0f};
	trans.translation = self->aabb.pos;
	trans.translation[y] = self->aabb.pos[y] + fminf(sinf(value / 2.f * M_PI) * 2.f, 0.25f) * 0.5f - 0.25f;
	mesh_put(game->eng, &game->cam, trans, &game->models[1]);
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
	ent->rot = (t_v2f){rot[x], M_PI_2};
	ent->mesh = &game->models[2];
	ent->type = ENTITY_SPIKE;
	return (ent);
}

void	spike_attack(t_data *const game, t_entity *const self)
{
	const t_v3f	dir = v3froty((t_v3f){.5f}, self->rot[x]);
	t_v3f		player;
	int i;
	
	i = 1;
	player = self->aabb.pos + self->aabb.dim / 2.;
	player[y] = self->aabb.pos[y];
	while (i++ < 10)
		e_spike_add(game, player + dir * (float)i, self->rot)->dir[x] = ((float)i - 1.f) * 0.2f;
		
}
