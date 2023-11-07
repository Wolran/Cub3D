/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:33:08 by alde-fre          #+#    #+#             */
/*   Updated: 2023/11/07 16:00:47 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/all.h"
#include "title.h"

int	can_see_aabb(t_data *const game, t_v3f const pos, t_aabb *const box)
{
	const t_v3f	self_center = box->pos + box->dim / 2.f;
	const t_v3f	diff = self_center - pos;
	float		dist;

	return (ray_box_intersection(pos, diff, *box, &dist)
		&& cast_ray(&game->map, pos, diff, 99999.f).dist > dist);
}

int is_point_on_screen(t_data *const game, t_v3f const pos, t_aabb *const box)
{
	t_v3f const	on_screen = project_point(pos, &game->cam);

	if (can_see_aabb(game, pos, box) == 0
		|| (on_screen[x] < 0.0f || on_screen[y] < 0.0f
		|| on_screen[x] >= (float)game->cam.surface->size[x]
		|| on_screen[y] >= (float)game->cam.surface->size[y]
		|| on_screen[z] < 0.0f))
		return (0);
	return (1);
}

int is_entity_on_screen(t_data *const game, t_entity *const entity)
{
	t_entity *const	player = game->entities.data;
	t_aabb *const box =  &player->aabb;

	if ((is_point_on_screen(game, entity->aabb.pos, box) || \
	is_point_on_screen(game, entity->aabb.pos \
	+ (t_v3f){entity->aabb.dim[x]}, box) || \
	is_point_on_screen(game, entity->aabb.pos \
	+ (t_v3f){0.f, 0.f, entity->aabb.dim[z]}, box) || \
	is_point_on_screen(game, entity->aabb.pos \
	+ (t_v3f){entity->aabb.dim[x], 0.f, entity->aabb.dim[z]}, box) || \
	is_point_on_screen(game, entity->aabb.pos \
	+ (t_v3f){0.f, entity->aabb.dim[y]}, box) || \
	is_point_on_screen(game, entity->aabb.pos \
	+ (t_v3f){entity->aabb.dim[x], entity->aabb.dim[y]}, box) || \
	is_point_on_screen(game, entity->aabb.pos + \
	(t_v3f){0.f, entity->aabb.dim[y], entity->aabb.dim[z]}, box) || \
	is_point_on_screen(game, entity->aabb.pos + \
	(t_v3f){entity->aabb.dim[x], entity->aabb.dim[y], entity->aabb.dim[z]}, box)))
		return (1);
	return (0);
}

static void	_enemy_update(
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
	if (is_entity_on_screen(game, self) == 0)
	{
		self->rot[x] = atan2f(diff[z], diff[x]);
		if (dist < 2.0f && can_see_aabb(game, self_center, &player->aabb))
			title_put(&game->title, g_titles[0], 3.0f);
		if (self->dir[x] <= 0.5f && dist < 1.0f)
		{
			self->dir[x] = 5.0f;
			enemy_attack(game, self);
		}
		else if (dist > 1.0f)
		{
			self->vel = v3fnorm(diff + (t_v3f){0.f, -diff[y]
					+ 0.0001f, 0.f}, dt * fmaxf(fminf(dist - (2.f - 1.2f), 7.f), 1.2f));
			self->aabb.type = AABB_MOVABLE;
		}
	}
	if (self->dir[x] > 0.0f)
		self->dir[x] = fmaxf(self->dir[x] - dt, 0.0f);
}

static void	_enemy_display(t_entity *const self, t_data *const game)
{
	t_transform	trans;

	trans.rotation = self->rot + (t_v2f){M_PI_2, 0.0f};
	trans.resize = (t_v3f){1.1f, 1.1f, 1.1f};
	trans.translation = self->aabb.pos + (t_v3f){.15f, .0f, .15f};
	mesh_put(game->eng, &game->cam, trans, &game->models[10]);
}

static void	_enemy_destroy(t_entity *const self, t_data *const game)
{
	(void)self;
	(void)game;
}

t_entity	*e_enemy_add(t_data *const game, t_v3f const pos, t_v2f rot)
{
	t_entity	*ent;

	ent = entity_add(game, pos);
	if (ent == NULL)
		return (NULL);
	ent->update = &_enemy_update;
	ent->display = &_enemy_display;
	ent->destroy = &_enemy_destroy;
	ent->aabb.type = AABB_MOVABLE;
	ent->dir = (t_v3f){0.f};
	ent->rot = rot;
	ent->aabb = (t_aabb){pos - (t_v3f){.15f, .0f, .15f}, {.3f, .85f, .3f}, AABB_IMMOVABLE};
	ent->mesh = &game->models[10];
	ent->type = ENTITY_ENEMY;
	return (ent);
}

void	enemy_attack(t_data *const game, t_entity *const self)
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
