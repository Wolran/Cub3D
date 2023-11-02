/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:49:54 by vmuller           #+#    #+#             */
/*   Updated: 2023/11/02 19:28:40 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include "game.h"
# include "cast_ray.h"
# include "camera.h"

typedef enum e_cell_side
{
	north,
	south,
	west,
	east,
}	t_cell_side;

void		get_tex_pos(t_ray *const ray, t_v2f *const tex_pos);
t_cell_side	get_real_side(t_ray *const ray);
t_color		ray_to_pixel(
				t_map *const map,
				t_ray *const ray);

void		ray_render(
				t_engine *const eng,
				t_map *const map,
				t_camera *const cam);

#endif
