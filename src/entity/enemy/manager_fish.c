/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_fish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:39:50 by vmuller           #+#    #+#             */
/*   Updated: 2023/11/08 20:54:25 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/all.h"

// static void	_enemy_fish_attack(t_data *const game, t_entity *const self)
// {
// 	(void)game;
// 	(void)self;
// }

static void	_enemy_fish_update(
			t_entity *const self,
			t_data *const game,
			float const dt)
{
	(void) self;
	(void) game;
	(void) dt;
}

static void	_enemy_fish_display(t_entity *const self, t_data *const game)
{
	t_transform	trans;

	trans.rotation = self->rot + (t_v2f){M_PI_2, 0.0f};
	trans.resize = (t_v3f){1.1f, 1.1f, 1.1f};
	trans.translation = self->aabb.pos + (t_v3f){.15f, .0f, .15f};
	mesh_put(game->eng, &game->cam, trans, &game->models[6]);
	self->dead = 1;
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
	ent->aabb = (t_aabb){pos - (t_v3f){.15f, .0f, .15f}, {.3f, .3f, .3f}, AABB_MOVABLE};
	ent->mesh = &game->models[6];
	ent->type = ENTITY_ENEMY_FISH;
	return (ent);
}

