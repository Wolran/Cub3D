/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:19:22 by alde-fre          #+#    #+#             */
/*   Updated: 2020/10/10 14:15:46 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

float	v_cross(t_vec2f a, t_vec2f b)
{
	return (a.x * b.y - b.x * a.y);
}

float	v_dot(t_vec2f a, t_vec2f b)
{
	return (a.x * b.x + a.y * b.y);
}

t_vec2f	v_norm(t_vec2f a, float n)
{
	float	l;

	l = sqrt(a.x * a.x + a.y * a.y);
	a = v_mul(v_div(a, l), n);
	return (a);
}

t_vec2u	v_2u(unsigned int x, unsigned int y)
{
	t_vec2u	a;

	a.x = x;
	a.y = y;
	return (a);
}

t_vec2f	v_2f(float x, float y)
{
	t_vec2f	a;

	a.x = x;
	a.y = y;
	return (a);
}
