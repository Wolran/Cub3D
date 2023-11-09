/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_fish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:39:50 by vmuller           #+#    #+#             */
/*   Updated: 2023/11/09 05:36:59 by vmuller          ###   ########.fr       */
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

t_transform	*init_trans(t_transform *trans, 
						t_v2f const rot, 
						t_v3f const resize, 
						t_v3f const translation)
{	
	trans->rotation = rot;
	trans->resize = resize;
	trans->translation = translation;
	return (trans);
}


static void	_enemy_fish_display(t_entity *const self, t_data *const game)
{
	t_transform	trans;
	t_v3f		slide;
	t_v3f const	dir = v3frot((t_v3f){.3f}, self->rot);

	slide = v3frot((t_v3f){.3f, 0.f, 0.f}, self->rot); 

	init_trans(&trans, self->rot, (t_v3f){0.2f, 0.2f, 0.2f}, \
		self->aabb.pos + self->aabb.dim / 2.f);
	mesh_put(game->eng, &game->cam, trans, &game->models[3]);
	
	init_trans(&trans, trans.rotation ,  (trans.resize * 0.7f), \
		(trans.translation + (3.0f * dir * slide )));
	mesh_put(game->eng, &game->cam, trans, &game->models[6]);

	init_trans(&trans, trans.rotation, (trans.resize * 0.7f), \
		(trans.translation + (0.5f * slide)));
	mesh_put(game->eng, &game->cam, trans, &game->models[6]);
	
	init_trans(&trans, trans.rotation, (trans.resize * 0.7f), \
		(trans.translation + (0.4f * slide)));
	mesh_put(game->eng, &game->cam, trans, &game->models[6]);
	
	init_trans(&trans, trans.rotation, (trans.resize * 0.7f), \
		(trans.translation + (0.2f * slide)));
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
	ent->aabb = (t_aabb){pos - (t_v3f){.15f, .0f, .15f}, {.3f, .3f, .3f}, AABB_MOVABLE};
	ent->mesh = &game->models[6];
	ent->type = ENTITY_ENEMY_FISH;
	return (ent);
}

