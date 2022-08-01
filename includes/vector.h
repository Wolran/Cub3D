/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:19:22 by alde-fre          #+#    #+#             */
/*   Updated: 2020/10/10 14:15:46 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

typedef struct s_vec2f	t_vec2f;
typedef struct s_vec2u	t_vec2u;

t_vec2f	v_add(t_vec2f a, t_vec2f b);
t_vec2f	v_sub(t_vec2f a, t_vec2f b);
t_vec2f	v_mul(t_vec2f a, float n);
t_vec2f	v_div(t_vec2f a, float n);
t_vec2f	v_rot(t_vec2f a, float rot);

float	v_cross(t_vec2f a, t_vec2f b);
float	v_dot(t_vec2f a, t_vec2f b);
t_vec2f	v_norm(t_vec2f a, float n);
t_vec2u	v_2u(unsigned int x, unsigned int y);
t_vec2f	v_2f(float x, float y);

t_vec2f	v_dir(float rot, float len);
t_vec2f	v_abs(t_vec2f a);
t_vec2f	v_norm_f(t_vec2f a, float len);

struct s_vec2f
{
	float	x;
	float	y;
};

struct s_vec2u
{
	unsigned int	x;
	unsigned int	y;
};
#endif
