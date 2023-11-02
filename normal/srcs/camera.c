/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:32:25 by alde-fre          #+#    #+#             */
/*   Updated: 2023/11/02 17:23:44 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera	camera_create(void)
{
	t_camera	cam;

	cam.fog = 1;
	cam.fog_color = (t_color){0};
	cam.fog_distance = 12.0f;
	cam.fov = M_PI_4;
	cam.fov_ratio = 0.66f;
	cam.screen_dist = 1.0f;
	cam.pos = (t_v2f){0.0f};
	cam.rot = 0.0f;
	return (cam);
}


