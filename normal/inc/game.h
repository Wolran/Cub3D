/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:13:47 by vmuller           #+#    #+#             */
/*   Updated: 2023/11/02 17:03:15 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "engine.h"
# include "parsing.h"
# include "raycaster.h"
# include "camera.h"
#define AZERTY
# include "keys.h"

int		game_init(t_engine *const eng, t_data *const game, char **argv);
void	game_destroy(t_data *const game);

struct s_data
{
	t_engine	*eng;
	t_map		map;
	t_camera	cam;
};

#endif
