/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:57:26 by vmuller           #+#    #+#             */
/*   Updated: 2023/06/16 00:33:38 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "struct.h"
# include "engine.h"
# include "vector.h"

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
void	test_map(char **map, t_data *game);
void	test_file(t_pars *pars, t_data *game, t_engine *eng);
int		parsing(int ac, char **av, t_engine *eng, t_data *game);
void	ft_error(char *message);

#endif
