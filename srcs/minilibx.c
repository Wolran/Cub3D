/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:19:22 by alde-fre          #+#    #+#             */
/*   Updated: 2020/10/10 14:15:46 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx.h"

int	create_ge(t_game *ge, char *title, t_vec2u wsize)
{
	ge->win_size = wsize;
	ge->title = title;
	ge->mlx = mlx_init();
	ge->win = mlx_new_window(ge->mlx, wsize.x, wsize.y, ge->title);
	ge->img = (t_img *)mlx_new_image(ge->mlx, wsize.x, wsize.y);
	ge->pixels = (t_color *)ge->img->data;
	return (1);
}

void	clear_ge(t_game *ge, t_color col)
{
	t_uint32	i;

	i = 0;
	while (i < ge->win_size.x * ge->win_size.y)
	{
		ge->pixels[i] = col;
		i++;
	}
}

void	put_ge(t_game *ge)
{
	mlx_put_image_to_window(ge->mlx, ge->win, ge->img, 0, 0);
}

void	calc_dda(t_game *ge)
{
	ge->r_map = v_2u(ge->r_pos.x, ge->r_pos.y);
	ge->r_delta = v_abs(v_2f(1 / ge->r_dir.x, 1 / ge->r_dir.y)); //need to fix divide by zero
	ge-> r_step = v_norm_f(ge->r_dir, 1);
	
	if (ge->r_dir.x < 0)
		ge->r_side.x = (ge->r_pos.x - ge->r_map.x) * ge->r_delta.x;
	else
		ge->r_side.x = (ge->r_map.x + 1 - ge->r_pos.x) * ge->r_delta.x;
		
	if (ge->r_dir.y < 0)
		ge->r_side.y = (ge->r_pos.y - ge->r_map.y) * ge->r_delta.y;
	else
		ge->r_side.y = (ge->r_map.y + 1 - ge->r_pos.y) * ge->r_delta.y;
}

int	start_ge(t_game *ge, int (func)(t_game *))
{
	mlx_loop_hook(ge->mlx, func, ge);
	mlx_loop(ge->mlx);
	return (1);
}
