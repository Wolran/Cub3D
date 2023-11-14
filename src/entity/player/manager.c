/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 08:05:41 by alde-fre          #+#    #+#             */
/*   Updated: 2023/11/13 12:58:25 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/all.h"
#include "entity/player.h"
#include "particle/particle.h"
#include "gameplay_utils.h"

static void	_player_update(
				t_entity *const self,
				t_data *const game,
				float const dt)
{
	player_control(self, game, dt);
	game->cam.pos = self->aabb.pos + (t_v3f){0.16f, 0.7f, 0.16f};
	game->cam.pos[y] += sinf(game->holding.energy_vel * 5.f) * 0.03f;
	game->cam.rot = self->rot;
}

static void	_player_display(t_entity *const self, t_data *const game)
{
	(void)self;
	(void)game;
}

static void	_player_destroy(t_entity *const self, t_data *const game)
{
	(void)self;
	(void)game;
}

t_entity	*e_player_add(t_data *const game, t_v3f const pos, t_v2f const rot)
{
	t_entity	*ent;

	ent = entity_add(game, pos);
	if (ent == NULL)
		return (NULL);
	ent->update = &_player_update;
	ent->display = &_player_display;
	ent->destroy = &_player_destroy;
	ent->dir = (t_v3f){0};
	ent->rot = rot;
	ent->max_health = 300.f;
	ent->health = ent->max_health;
	ent->mesh = &game->models[5];
	ent->aabb = (t_aabb){pos - (t_v3f){0.16f, 0.f, 0.16f},
	{0.32f, 0.825f, 0.32f}, AABB_MOVABLE};
	ent->type = ENTITY_PLAYER;
	return (ent);
}
