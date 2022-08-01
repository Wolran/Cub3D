/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:19:22 by alde-fre          #+#    #+#             */
/*   Updated: 2020/10/10 14:15:46 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2f	v_dir(float rot, float len)
{
	return (v_2f(cosf(rot) * len, sinf(rot) * len));
}

t_vec2f	v_abs(t_vec2f a)
{
	if (a.x < 0)
		a.x = -a.x;
	if (a.y < 0)
		a.y = -a.y;
	return (a);
}

t_vec2f	v_norm_f(t_vec2f a, float len)
{
	if (a.x >= 0)
		a.x = len;
	else
		a.x = -len;
	if (a.y >= 0)
		a.y = len;
	else
		a.y = -len;
	return (a);
}
