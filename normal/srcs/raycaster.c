/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:49:15 by vmuller           #+#    #+#             */
/*   Updated: 2023/11/02 19:54:48 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

typedef struct s_plane
{
	t_v2f	pos;
	t_v2f	dir_x;
	float	dist;
}	t_plane;

static inline void	__setup_plane(
	t_engine *const eng,
	t_plane *const plane,
	t_camera *const cam)
{
	float const	fsinx = sinf(cam->rot);
	float const	fcosx = cosf(cam->rot);

	(void)eng;
	plane->pos[x] = fcosx;
	plane->pos[y] = fsinx;
	plane->dir_x[x] = -fsinx;
	plane->dir_x[y] = fcosx;
	plane->dir_x *= cam->fov_ratio * (eng->screen->size[x] / (float)eng->screen->size[y]);
}

void	get_tex_pos(t_ray *const ray, t_v2f *const tex_pos)
{
	if (ray->side == x)
		(*tex_pos)[x] = ray->end[y];
	else
		(*tex_pos)[x] = ray->end[x];
	(*tex_pos)[x] -= floorf((*tex_pos)[x]);
	if (ray->side == x && ray->dir[x] < 0.0f)
		(*tex_pos)[x] = 1.0f - (*tex_pos)[x];
	if (ray->side == y && ray->dir[y] < 0.0f)
		(*tex_pos)[x] = 1.0f - (*tex_pos)[x];
}

t_cell_side	get_real_side(t_ray *const ray)
{
	if (ray->side == x)
		return (ray->dir[x] > 0.0f);
	else
		return (west + (ray->dir[y] > 0.0f));
}

t_color	ray_to_pixel(
	t_map *const map,
	t_ray *const ray)
{
	t_v2f			tex_pos;
	t_color			color;
	t_sprite		*spr;
	t_cell			block;

	block = map_get(map, ray->pos);
	if (block == cell_void)
		return ((t_color){0});
	spr = map->sprites[get_real_side(ray)];
	get_tex_pos(ray, &tex_pos);
	if (block == cell_wall)
		color = ft_get_color(spr,
				(t_v2i){tex_pos[x] * spr->size[x], 0});
	else
		color = (t_color){0};
	return (color);
}



void	ray_render(
			t_engine *const eng,
			t_map *const map,
			t_camera *const cam)
{
	int		pix;
	t_ray	ray;
	t_v2f	dir;
	t_plane	plane;
	t_color	col;

	__setup_plane(eng, &plane, cam);
		pix = 0;
		while (pix < eng->screen->size[x])
		{
			dir = plane.pos;
			dir += plane.dir_x * ((pix / (float)eng->screen->size[x] - 0.5f));
			ray = cast_ray(map, &cam->pos, &dir, cam->fog_distance * 2 + 1);
			col = ray_to_pixel(map, &ray);
			int height = (float)eng->screen->size[y] / (ray.dist);
			// ft_rect(eng, (t_v2i){pix, eng->screen->size[y] / 2 - height / 2}, (t_v2i){1, height}, col);
			pix++;
		}
	}
