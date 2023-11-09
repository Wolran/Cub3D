/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_scp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:33:08 by alde-fre          #+#    #+#             */
/*   Updated: 2023/11/09 09:06:52 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/all.h"
#include "title.h"

static void	_enemy_scp_attack(t_data *const game, t_entity *const self)
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

static void	_enemy_scp_update(
			t_entity *const self,
			t_data *const game,
			float const dt)
{
	t_entity *const	player = game->entities.data;
	const t_v3f		self_center = self->aabb.pos + self->aabb.dim / 2.f;
	const t_v3f		player_center = player->aabb.pos + player->aabb.dim / 2.f;
	const t_v3f		diff = player_center - self_center;
	const float		dist = v3fmag(diff);

	self->aabb.type = AABB_IMMOVABLE;
	if (dist < 1.5f && can_see_aabb(game, self_center, &player->aabb, 99999.0f) && is_entity_on_screen(game, self) == 0)
	{
		title_put(&game->title, g_titles[0], 0.5f);
		if (self->dir[y] >= 1.0f)
			printf("Tu t'fe tap mec\n");
		self->dir[y] = fminf(self->dir[y] + dt , 1.001f);
		
	}
	else
		self->dir[y] = fmaxf(self->dir[y] - dt * 0.8f, 0.0f);
	if (is_entity_on_screen(game, self) == 0)
	{
		self->rot[x] = atan2f(diff[z], diff[x]);
		if (self->dir[x] <= 0.5f && dist < 1.0f)
		{
			self->dir[x] = 5.0f;
			_enemy_scp_attack(game, self);
		}
		else if (dist > .5f)
		{
			self->vel = v3fnorm(diff + (t_v3f){0.f, -diff[y]
					+ 0.0001f, 0.f}, dt * 5.f);
			self->aabb.type = AABB_MOVABLE;
		}
	}
	if (self->dir[x] > 0.0f)
		self->dir[x] = fmaxf(self->dir[x] - dt, 0.0f);
}

static void	_enemy_scp_display(t_entity *const self, t_data *const game)
{
	t_transform	trans;

	trans.rotation = self->rot + (t_v2f){M_PI_2, 0.0f};
	trans.resize = (t_v3f){1.1f, 1.1f, 1.1f};
	trans.translation = self->aabb.pos + (t_v3f){.15f, .0f, .15f};
	mesh_put(game->eng, &game->cam, trans, &game->models[10]);
}

static void	_enemy_scp_destroy(t_entity *const self, t_data *const game)
{
	(void)self;
	(void)game;
}

t_entity	*e_enemy_scp_add(t_data *const game, t_v3f const pos, t_v2f rot)
{
	t_entity	*ent;

	ent = entity_add(game, pos);
	if (ent == NULL)
		return (NULL);
	ent->update = &_enemy_scp_update;
	ent->display = &_enemy_scp_display;
	ent->destroy = &_enemy_scp_destroy;
	ent->aabb.type = AABB_MOVABLE;
	ent->dir = (t_v3f){0.f};
	ent->rot = rot;
	ent->aabb = (t_aabb){pos - (t_v3f){.15f, .0f, .15f}, {.3f, .85f, .3f}, AABB_IMMOVABLE};
	ent->mesh = &game->models[10];
	ent->type = ENTITY_ENEMY_SCP;
	return (ent);
}

