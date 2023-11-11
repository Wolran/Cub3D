/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_fish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:39:50 by vmuller           #+#    #+#             */
/*   Updated: 2023/11/11 09:58:08 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/all.h"
#include "particle/particle.h"

static void	_enemy_fish_part(
			t_particle	*part,
			t_data *const game,
			t_entity *const	self,
			const t_v3f	diff)
{
	const t_v3f		self_center = self->aabb.pos + self->aabb.dim / 2.f;
	const float		dist = v3fmag(diff);

	part = particle_add(game, self_center + (t_v3f) \
		{ft_rand(-0.15f, 0.150f), ft_rand(-0.15f, 0.08f), \
		ft_rand(-0.15f, 0.150f)} + diff / dist * 0.2f, \
		(t_v3f){0.f, ft_rand(-.3f, -.15f)});
	part->force = 5.0f;
	part->spr = game->sprites[5];
	part->death_time = ft_rand(.5f, 0.7f);
}

static void	_enemy_fish_update(
			t_entity *const self,
			t_data *const game,
			float const dt)
{
	t_entity *const	player = game->entities.data;
	const t_v3f		self_center = self->aabb.pos + self->aabb.dim / 2.f;
	const t_v3f		diff = player->aabb.pos + player->aabb.dim \
		/ 2.f - self_center;
	const float		dist = v3fmag(diff);
	t_particle		part;

	self->rot[x] = atan2f(diff[z], diff[x]);
	if (dist > 1.0f)
	{
		self->vel = v3fnorm((t_v3f){diff[x], 0.f, diff[z]}, dt * .6f);
		if (dist > 15.f)
			self->vel = (t_v3f){0.f, 0.f, 0.f};
		else if (map_get(&game->map, v3ftoi(self_center)) == cell_wall)
		{
			_enemy_fish_part(&part, game, self, diff);
			self->vel = v3fnorm((t_v3f){diff[x], 0.f, diff[z]}, dt * .2f);
		}
	}
	self->dir[y] += dt;
}

static void	_enemy_fish_display(t_entity *const self, t_data *const game)
{
	t_transform	trans;
	t_v3f		slide;

	slide = v3frot((t_v3f){.3f, 0.f, 0.f}, self->rot);
	trans.rotation = (t_v2f){self->rot[x], 0.f};
	trans.resize = (t_v3f){fabsf(sinf(self->dir[y] * 4.f)) \
		* 0.1f + 0.5f, 0.5f, 0.5f};
	trans.translation = self->aabb.pos + self->aabb.dim / 2.f;
	trans.translation[y] = self->aabb.pos[y];
	mesh_put(game->eng, &game->cam, trans, &game->models[6]);
}

static void	_enemy_fish_destroy(t_entity *const self, t_data *const game)
{
	(void)self;
	(void)game;
}

t_entity	*e_enemy_fish_add(t_data *const game, t_v3f const pos, t_v2f rot)
{
	t_entity	*ent;

	ent = entity_add(game, pos);
	if (ent == NULL)
		return (NULL);
	ent->update = &_enemy_fish_update;
	ent->display = &_enemy_fish_display;
	ent->destroy = &_enemy_fish_destroy;
	ent->aabb.type = AABB_MOVABLE;
	ent->dir = (t_v3f){0.f};
	ent->rot = rot;
	ent->dir[y] = ft_rand(0.f, 10.f);
	ent->aabb = (t_aabb){pos - (t_v3f){.15f, .0f, .15f}, \
		{.3f, .3f, .3f}, AABB_NONE};
	ent->mesh = &game->models[6];
	ent->type = ENTITY_ENEMY_FISH;
	return (ent);
}
