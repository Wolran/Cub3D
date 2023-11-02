/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:13:49 by vmuller           #+#    #+#             */
/*   Updated: 2023/11/02 19:39:35 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static inline void	__control(
	t_engine *const eng,
	t_camera *const cam,
	double const dt)
{
	t_v2f const	dir = (t_v2f){cosf(cam->rot), sinf(cam->rot)};
	t_v2f const	off = (t_v2f){-sinf(cam->rot), cosf(cam->rot)};
	t_v2f		vel;

	vel = (t_v2f){0};
	if (eng->keys[K_UP])
		vel += dir;
	if (eng->keys[K_DOWN])
		vel -= dir;
	if (eng->keys[K_RIGHT])
		vel += off;
	if (eng->keys[K_LEFT])
		vel -= off;
	if (eng->keys[XK_Right])
		cam->rot += dt * 2;
	if (eng->keys[XK_Left])
		cam->rot -= dt * 2;
	if (cam->rot < -M_PI)
		cam->rot += M_PI * 2;
	else if (cam->rot > M_PI)
		cam->rot -= M_PI * 2;
	cam->pos += ft_v2fnorm(vel, dt * 2.0f);
}

static inline int	__loop(t_engine *eng, t_data *game, double dt)
{
	__control(eng, &game->cam, dt);
	ft_clear(eng, (t_color){0});
	ray_render(eng, &game->map, &game->cam);
	return 1;
}

int	main(int argc, char **argv)
{
	t_engine	*eng;
	t_data		data;

	(void)argc;
	eng = ft_eng_create(250 * 4, 130 * 4, "cube3D");
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
	return (0);
}