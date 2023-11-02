/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 05:54:24 by alde-fre          #+#    #+#             */
/*   Updated: 2023/11/02 17:50:18 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	game_init(t_engine *const eng, t_data *const game, char **argv)
{
	*game = (t_data){.eng = eng};
	game->map = pars_file(eng, (char *)argv[1]);
	if (game->map.data == NULL)
		return (game_destroy(game), 1);
	game->cam = camera_create();
	game->cam.pos = game->map.spawn + (t_v2f){0.0f, 0.0f};
	game->cam.rot = 0.f;
	game->cam.fog_color = (t_color){0x040018};
	return (0);
}
