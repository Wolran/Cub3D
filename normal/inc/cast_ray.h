/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:08:35 by alde-fre          #+#    #+#             */
/*   Updated: 2023/11/02 19:40:25 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_RAY_H
# define CAST_RAY_H

# include "map.h"

typedef struct s_ray	t_ray;

t_ray	cast_ray(
			t_map *const map,
			t_v2f *const pos,
			t_v2f *const dir,
			float const max_dist);

struct s_ray
{
	t_v2i	pos;
	t_v2f	dir;
	t_v2f	start;
	t_v2f	end;
	t_v2f	delta_dist;
	t_v2f	side_dist;
	t_v2i	step;
	int		side;
	float	dist;
};

#endif
