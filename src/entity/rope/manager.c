/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:20:51 by vmuller           #+#    #+#             */
/*   Updated: 2023/11/13 18:36:39 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/all.h"
#include "title.h"

static void	hardcore_mode(t_data *const game, t_v3f const pos, float const dt)
{
	int	i;

	i = -1;
	game->cam.fog_color = (t_color){0xFF8A0F0F};
	while (++i < 100)
	{
		game->cam.fog_distance = fmaxf(game->cam.fog_distance - dt, 6.0f);
		e_enemy_fish_add(game, pos + \
	(t_v3f){ft_rand(-6.0f, 6.0f), 0.0f, ft_rand(-6.0f, 6.0f)}, (t_v2f){0.f});
	}
}

static void	_rope_update(
			t_entity *const self,
			t_data *const game,
			float const dt)
{
	(void)dt;
	if (ft_mouse(game->eng, 3).pressed && \
		ray_box_intersection(game->cam.pos, v3frot((t_v3f){1.0f}, \
		game->cam.rot), self->aabb, &(float){0.0f}))
	{
		self->dead = 1;
		game->state = 1;
		title_put(&game->title, g_titles[1], 2.5f);
		hardcore_mode(game, self->aabb.pos, dt);
	}
}

static void	_rope_display(t_entity *const self, t_data *const game)
{
	t_transform	trans;

	trans.rotation = self->rot;
	trans.resize = (t_v3f){.125f, .125f, .125f};
	trans.translation = self->aabb.pos + (t_v3f){0.15f, 0.0f, 0.15f};
	mesh_put(game->eng, &game->cam, trans, &game->models[11]);
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
	ent->aabb.dim = (t_v3f){0.3f, 0.09f, 0.3f};
	ent->aabb.pos = pos - (t_v3f){0.15f, 0.0f, 0.15f};
	ent->aabb.type = AABB_IMMOVABLE;
	ent->type = ENTITY_ROPE;
	return (ent);
}
