/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:57:26 by vmuller           #+#    #+#             */
/*   Updated: 2023/05/28 20:37:13 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./struct.h"
# include "./minilibft.h"
# include "../minilibx-linux/mlx.h"

# define EA 0
# define WE 1
# define SO 2
# define NO 3
# define C 4
# define F 5
# define COLOR 4
# define TYPE 6
# define WALL '1'
# define FLOOR '0'

# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 4096
# endif


int		open_file(char *file);
void	read_element(int fd, t_pars *pars);
char	**read_map(int fd);
t_pars	*read_file(int fd);
void	test_map(char **map, t_game *game);
t_game	*test_file(t_pars *pars);
t_game	*parsing(int ac, char **av);
void	ft_error(char *message);

#endif
