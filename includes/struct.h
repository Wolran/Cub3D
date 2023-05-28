/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:57:30 by vmuller           #+#    #+#             */
/*   Updated: 2023/05/28 19:59:08 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_pars
{
	char	*element[6];
	char	**map;
}	t_pars;

typedef struct s_wall
{
	void	*img_ptr[4];
	int		*texture[4];
	int		bytes_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_wall;

typedef struct s_game
{
	void	*mlx_ptr;
	t_wall	wall;
	int		color[2];
	char	**map;
	size_t	max_x;
	size_t	max_y;
}	t_game;

#endif
