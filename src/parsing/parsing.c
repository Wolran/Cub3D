/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:58:40 by vmuller           #+#    #+#             */
/*   Updated: 2023/06/16 00:34:16 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	free_pars(t_pars *pars)
{
	int	i;

	i = -1;
	while (++i < TYPE)
		free(pars->element[i]);
	free(pars);
}

int	parsing(int ac, char **av, t_engine *eng, t_data *game)
{
	int		fd;
	t_pars	*pars;

	if (ac != 2)
		return(1);
	fd = open_file(av[1]);
	pars = read_file(fd);
	test_file(pars, game, eng);
	close(fd);
	free_pars(pars);
	return (0);
}
