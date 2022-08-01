/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:19:22 by alde-fre          #+#    #+#             */
/*   Updated: 2020/10/10 14:15:46 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minilibx.h"
#include <stdio.h>

void	put_pixel(t_game *ge, int x, int y, t_color col)
{
	if (x < 0 || x >= (int)ge->win_size.x || y < 0 || y >= (int)ge->win_size.y)
			return ;
	ge->pixels[x + y * ge->win_size.x] = col;
}

int	main_loop(t_game *ge)
{
	t_uint32	x;
	float		mul;

	ge->rot += (1.0f / 60) / M_PI;
	ge->adj = (ge->win_size.x / 2) / tanf(ge->fov / 2);
	ge->dir = v_dir(ge->rot, ge->adj);
	ge->plane = v_dir(ge->rot + M_PI / 2, ge->win_size.x);
	ge->start = v_add(ge->pos, v_sub(ge->dir, v_mul(ge->plane, 0.5f)));
	ge->r_pos = ge->pos;
	
	clear_ge(ge, (t_color){0x00000000});
	x = 0;
	while (x++ < ge->win_size.x)
	{
		mul = (float)x / ge->win_size.x;
		ge->r_dir =  v_add(ge->start, v_mul(ge->plane, mul));
		calc_dda(ge);
		
		int i = 0;
		while (i < 100)
		{
			put_pixel(ge, ge->r_map.x, ge->r_map.y, (t_color){0x0000FF00});
			if (ge->r_side.x < ge->r_side.y)
			{
				ge->r_side.x += ge->r_delta.x;
				ge->r_map.x += ge->r_step.x;
			}
			else
			{
				ge->r_side.y += ge->r_delta.y;
				ge->r_map.y += ge->r_step.y;
			}
			i++;
		}
	}
	put_pixel(ge, ge->pos.x, ge->pos.y, (t_color){0x00FF0000});
	put_ge(ge);
	return (1);
}

int	main(void)
{
	t_game	ge;
	
	ge.rot = 0.0f;
	ge.pos = v_2f(255.5f, 255.5f);
	ge.fov = M_PI / 2;
	
	create_ge(&ge, "OUE OUE", v_2u(640, 480));
	start_ge(&ge, &main_loop);
	return (0);
}
