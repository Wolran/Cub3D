/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:19:22 by alde-fre          #+#    #+#             */
/*   Updated: 2020/10/10 14:15:46 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
# define MINILIBX_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "utils.h"
# include "vector.h"

typedef struct s_gameengine	t_game;
typedef struct s_keys		t_keys;
typedef union u_color		t_color;

//### GameEngine ###
int		create_ge(t_game *ge, char *title, t_vec2u wsize);
void	clear_ge(t_game *ge, t_color col);
void	put_ge(t_game *ge);
void	calc_dda(t_game *ge);
int		start_ge(t_game *ge, int (func)(t_game *));

//void	destroyGameEngine(t_game *ge);

struct s_keys
{
	t_uint8	pressed;
	t_uint8	held;
	t_uint8	released;
};

struct s_gameengine
{
	t_vec2u			win_size;
	char			*title;
	t_img			*mlx;
	void			*win;
	t_img			*img;
	t_color			*pixels;
	
	float			rot;
	t_vec2f			pos;
	float			fov;
	
	float			adj;
	t_vec2f			dir;
	t_vec2f			plane;
	t_vec2f			start;
	
	t_vec2u			r_map;
	t_vec2f			r_pos;
	t_vec2f			r_dir;
	t_vec2f			r_delta;
	t_vec2f			r_side;
	t_vec2f			r_step;
};

union u_color
{
	t_uint32	d;

	struct
	{
		t_uint8	b;
		t_uint8	g;
		t_uint8	r;
		t_uint8	a;
	};
};

#endif
