/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 05:54:24 by alde-fre          #+#    #+#             */
/*   Updated: 2023/10/23 17:46:12 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "entity/all.h"
#include "particle/particle.h"

static int	__sprite_init(t_engine *const eng, t_data *const game)
{
	game->sprites[0] = ft_sprite_p(eng, "assets/block.xpm");
	game->sprites[1] = ft_sprite_p(eng, "assets/camera.xpm");
	game->sprites[2] = ft_sprite_p(eng, "assets/HEHE.xpm");
	game->sprites[3] = ft_sprite_p(eng, "assets/gui/hotbar/slot.xpm");
	game->sprites[4] = ft_sprite_p(eng, "assets/gui/health/full.xpm");
	game->sprites[5] = NULL;
	return (0);
}

static int	__models_init(t_engine *const eng, t_data *const game)
{
	game->selected_model = 11;
	game->models[0] = mesh_load(eng, "models/items/wand.obj");
	game->models[1] = mesh_load(eng, "models/projectile.obj");
	game->models[2] = mesh_load(eng, "models/items/sword.obj");
	game->models[3] = mesh_load(eng, "models/torch.obj");
	game->models[4] = mesh_load(eng, "models/items/hand.obj");
	game->models[5] = mesh_load(eng, "models/herse.obj");
	game->models[6] = mesh_load(eng, "models/tableau/tab1.obj");
	game->models[7] = mesh_load(eng, "models/tableau/tab2.obj");
	game->models[8] = mesh_load(eng, "models/tableau/tab3.obj");
	game->models[9] = mesh_load(eng, "models/tableau/tab4.obj");
	game->models[10] = mesh_load(eng, "models/173.obj");
	game->models[11] = mesh_load(eng, "models/faux.obj");
	game->models[12] = (t_mesh){0};
	return (0);
}

int	game_init(t_engine *const eng, t_data *const game, char **argv)
{
	*game = (t_data){.eng = eng};
	__sprite_init(eng, game);
	__models_init(eng, game);
	game->minimap = ft_sprite(eng, 120, 120);
	if (game->minimap == NULL)
		return (game_destroy(game), 1);
	game->entities = vector_create(sizeof(t_entity));
	if (game->entities.data == NULL)
		return (game_destroy(game), 1);
	game->map = pars_file(game, eng, (char *)argv[1]);
	if (game->map.data == NULL)
		return (game_destroy(game), 1);
	game->menu = menu_create();
	if (game->menu.data.data == NULL)
		return (game_destroy(game), 1);
	if (menu_settings_create(eng, game))
		return (game_destroy(game), 1);
	game->menu.selected = 3;
	game->cam = camera_create(eng, (t_v2i){eng->win_x / 2, eng->win_y / 2});
	game->cam.pos = game->map.spawn + (t_v3f){0.0f, 0.8f, 0.0f};
	game->cam.rot = (t_v2f){0.0f, 0.0f};
	game->cam.fog_color = (t_color){0x040018};
	game->holding = (t_holding){{0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0.0f};
	game->show_settings = 0;
	game->box = (t_aabb){game->map.spawn - (t_v3f){0.16f, 0.0f, 0.16f},
	{0.32f, 0.825f, 0.32f}};
	game->sensitivity = 0.2f;
	game->particles = vector_create(sizeof(t_particle));
	if (game->particles.data == NULL)
		return (game_destroy(game), 1);
	mlx_mouse_move(eng->mlx, eng->win, 500, 260);
	eng->mouse_x = 500;
	eng->mouse_y = 260;
	ft_hide_cursor(game->eng);
	return (0);
}
