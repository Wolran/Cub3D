/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:18:43 by vmuller           #+#    #+#             */
/*   Updated: 2023/11/02 17:37:19 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "engine.h"

typedef struct s_camera	t_camera;

struct s_camera
{
	t_v2f		pos;
	float		rot;
	float		fov;
	float		fov_ratio;
	float		screen_dist;
	int			fog;
	t_color		fog_color;
	float		fog_distance;
};

t_camera	camera_create(void);

void		camera_update(t_camera *const cam);

#endif
