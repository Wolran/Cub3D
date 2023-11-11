/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 08:45:45 by vmuller           #+#    #+#             */
/*   Updated: 2023/11/11 10:51:33 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/all.h"

static void	_hook_update(
			t_entity *const self,
			t_data *const game,
			float const dt)
{
	(void)dt;
	if (ft_mouse(game->eng, 3).pressed && \
		ray_box_intersection(game->cam.pos, v3frot((t_v3f){1.0f}, \
		game->cam.rot), self->aabb, &(float){0.0f}) && \
		game->state == 1)
	{
		game->state = 2;
		game->selected_model = 9;
	}
}

static void	_hook_display(t_entity *const self, t_data *const game)
{
	t_transform	trans;

	trans.rotation = self->rot;
	trans.resize = (t_v3f){.1f, .1f, .1f};
	trans.translation = self->aabb.pos + (t_v3f){0.3f, 0.62f, 0.3f};
	mesh_put(game->eng, &game->cam, trans, &game->models[13]);
}

// mesh_put(eng, &game->cam, (t_transform){{M_PI_2, 0.0f}, {.125f, .125f, .125f}, game->map.spawn + (t_v3f){.0f, 2.1f, 0.f}}, &game->models[13]);

static void	_hook_destroy(t_entity *const self, t_data *const game)
{
	(void)self;
	(void)game;
}

t_entity	*e_hook_add(t_data *const game, t_v3f const pos, t_v2f rot)
{
	t_entity	*ent;

	ent = entity_add(game, pos);
	if (ent == NULL)
		return (NULL);
	ent->update = &_hook_update;
	ent->display = &_hook_display;
	ent->destroy = &_hook_destroy;
	ent->dir = (t_v3f){0};
	ent->rot = rot + (t_v2f){M_PI_2, 0.0f};
	ent->mesh = &game->models[13];
	ent->aabb.dim = (t_v3f){0.6f, 0.6f, 0.6f};
	ent->aabb.pos = pos - (t_v3f){0.3f, 0.62f, 0.3f};
	ent->aabb.type = AABB_IMMOVABLE;
	ent->type = ENTITY_HOOK;
	return (ent);
}
