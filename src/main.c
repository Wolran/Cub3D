/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:36:00 by alde-fre          #+#    #+#             */
/*   Updated: 2023/11/13 18:47:40 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "entity/entity.h"
#include "entity/all.h"
#include "particle/particle.h"
#include "aabb.h"
#include "gameplay_utils.h"

static inline void	__loop_2(t_engine *eng, t_data *game, double dt)
{
	if (game->cam.fog)
		shader_apply_depth(&game->cam);
	ft_memset(game->cam.depth_buffer, 0xFF, game->cam.surface->size[x]
		* game->cam.surface->size[y] * sizeof(float));
	holding_display(eng, &game->cam, &game->models[game->selected_model],
		&game->holding);
	hotbar_put(game);
	ft_circle(eng, eng->sel_spr->size / 2, 2, (t_color){0xFFFFFF});
	title_update(eng, &game->title, dt);
	ft_eng_sel_spr(eng, NULL);
	ft_put_sprite_s(eng, game->cam.surface, (t_v2i){0, 0}, 2);
	if (game->show_settings)
		menu_display(eng, &game->menu);
	else
	{
		minimap_display(eng, &game->map, &game->cam, game->minimap);
		ft_put_text(eng, (t_v2i){10, 120}, "[TAB] MENU", 2);
		ft_put_nbr(eng, (t_v2i){10, 150}, 1.f / dt, 2);
		ft_put_text(eng, (t_v2i){10, 180}, "ent:", 2);
		ft_put_nbr(eng, (t_v2i){68, 180}, vector_size(&game->entities), 2);
		ft_put_text(eng, (t_v2i){10, 210}, "par:", 2);
		ft_put_nbr(eng, (t_v2i){68, 210}, vector_size(&game->particles), 2);
	}
	game->holding.time_from_start += dt;
}

static int const	g_items[] = {3, 2, 5, 8, 0, 17};

static inline int	__main_menu(t_engine *eng, t_data *game, double dt)
{
	static float	stime = 0.0f;

	stime += dt;
	menu_update(eng, &game->menu);
	game->cam.pos = (t_v3f){-1.10f, 1.5f, 0.f};
	game->cam.rot = (t_v2f){0.f, -M_PI * 0.33};
	camera_update(&game->cam);
	ft_eng_sel_spr(eng, game->cam.surface);
	ft_memset(game->cam.depth_buffer, 0xFF, game->cam.surface->size[x]
		* game->cam.surface->size[y] * sizeof(float));
	ft_clear(eng, (t_color){0x040018});
	mesh_put(eng, &game->cam, (t_transform){{stime, 0.333f}, {1.f, 1.f, 1.f},
	{0.0f, -0.45f, 0.5f}}, &game->models[g_items[(int)(stime) % 6]]);
	ft_eng_sel_spr(eng, NULL);
	ft_put_sprite_s(eng, game->cam.surface, (t_v2i){0, 0}, 2);
	menu_display(eng, &game->menu);
	return (game->state != -2);
}

static inline int	__loop(t_engine *eng, t_data *game, double dt)
{
	if (game->state == -1)
		return (__main_menu(game->eng, game, dt));
	if (!game->show_settings && game->holding.click_energy < 0.1f)
		player_use_item(game, retrieve_player_hit(game));
	holding_update(&game->cam, &game->holding, dt);
	entities_update(game, dt);
	entities_destroy(game);
	collision_ent(game, &game->entities);
	if (game->show_settings)
		menu_update(eng, &game->menu);
	camera_update(&game->cam);
	ray_render(eng, &game->map, &game->cam);
	if (game->state == 2)
		mesh_put(eng, &game->cam, (t_transform) \
			{{sinf(game->holding.time_from_start) * 0.03f,
			cosf(game->holding.time_from_start * 0.842f) * 0.03f}, \
			{.6f, .6f, .6f}, cast_ray(&game->map, game->map.spawn, \
			(t_v3f){0.f, 1.0f}, 99999.0f).end
			- (t_v3f){0.01f, .465f, -0.05f}}, &game->models[13]);
	entities_display(game);
	particles_update(game, dt);
	if (ft_mouse(eng, 1).pressed)
		e_enemy_creep_add(game, game->cam.pos, (t_v2f){0.f});
	__loop_2(eng, game, dt);
	return (1);
}

int	main(int argc, char **argv)
{
	t_engine	*eng;
	t_data		data;

	(void)argc;
	srand(time(NULL));
	eng = ft_eng_create(250 * 4, 230 * 3, "cube3D");
	if (eng)
	{
		if (!game_init(eng, &data, argv))
		{
			ft_eng_play(eng, &data, __loop);
			game_destroy(&data);
		}
		else
			ft_putstr_fd("Error: Failed to initialise the game.\n", 1);
		ft_eng_destroy(eng);
	}
	else
		ft_putstr_fd("Error: Failed to initialise the engine.\n", 1);
	return (0);
}
