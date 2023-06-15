/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:57:30 by vmuller           #+#    #+#             */
/*   Updated: 2023/06/16 00:32:24 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "engine.h"

typedef struct s_pars
{
	char	*element[6];
	char	**map;
}	t_pars;

struct s_data
{
	t_engine	*eng;
	t_sprite	*sprite[4];
	int			color[2];
	char		**map;
	size_t		max_x;
	size_t		max_y;
};

#endif
