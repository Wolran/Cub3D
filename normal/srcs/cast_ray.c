/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:17:19 by vmuller           #+#    #+#             */
/*   Updated: 2023/11/02 19:40:59 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast_ray.h"

static inline void	__setup_ray_step_delta_dist(
	t_ray *const ray,
	enum e_xy const d)
{
	if (ray->dir[d] != 0.0f)
		ray->delta_dist[d] = fabsf(1.0f / ray->dir[d]);
	else
		ray->delta_dist[d] = 1e30f;
	if (ray->dir[d] < 0)
	{
		ray->step[d] = -1;
		ray->side_dist[d] = (ray->start[d] - ray->pos[d]) * ray->delta_dist[d];
	}
	else
	{
		ray->step[d] = 1;
		ray->side_dist[d] = (ray->pos[d] + 1.0f - ray->start[d])
			* ray->delta_dist[d];
	}
}

static inline void	__setup_ray(
	t_ray *const ray,
	t_v2f *const pos,
	t_v2f *const dir)
{
	ray->pos = (t_v2i){(*pos)[x], (*pos)[y]};
	ray->dir = *dir;
	ray->start = *pos;
	ray->side = x;
	__setup_ray_step_delta_dist(ray, x);
	__setup_ray_step_delta_dist(ray, y);
}

static inline void	__loop_ray(
	t_map *const map,
	t_ray *const ray,
	int max_dist)
{
	t_v2i	inc;
	int		flag;

	inc = (t_v2i){0, 0};
	flag = 1;
	while (flag && max_dist)
	{
		inc[x] = (ray->side_dist[x] <= ray->side_dist[y]);
		inc[y] = (ray->side_dist[y] <= ray->side_dist[x]);
		ray->pos += inc * ray->step;
		ray->side_dist += (t_v2f){inc[x], inc[y]} * ray->delta_dist;
		flag = (map_get(map, ray->pos) == (t_cell){0});
		--max_dist;
	}
	ray->side = inc[y];
	ray->dist = ray->side_dist[ray->side] - ray->delta_dist[ray->side];
	ray->end = ray->start + ray->dist * ray->dir;
}

t_ray	cast_ray(
	t_map *const map,
	t_v2f *const pos,
	t_v2f *const dir,
	float const max_dist)
{
	t_ray	ray;

	__setup_ray(&ray, pos, dir);
	__loop_ray(map, &ray, max_dist);
	return (ray);
}
