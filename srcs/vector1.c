/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                            :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:19:22 by alde-fre          #+#    #+#             */
/*   Updated: 2020/10/10 14:15:46 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2f	v_add(t_vec2f a, t_vec2f b)
{
	a.x += b.x;
	a.y += b.y;
	return (a);
}

t_vec2f	v_sub(t_vec2f a, t_vec2f b)
{
	a.x -= b.x;
	a.y -= b.y;
	return (a);
}

t_vec2f	v_mul(t_vec2f a, float n)
{
	a.x *= n;
	a.y *= n;
	return (a);
}

t_vec2f	v_div(t_vec2f a, float n)
{
	a.x /= n;
	a.y /= n;
	return (a);
}

t_vec2f	v_rot(t_vec2f a, float rot)
{
	t_vec2f	b;

	b.x = a.x * cosf(rot) - a.y * sinf(rot);
	b.y = a.x * sinf(rot) + a.y * cosf(rot);
	return (b);
}
