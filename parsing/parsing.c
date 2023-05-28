/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:58:40 by vmuller           #+#    #+#             */
/*   Updated: 2023/05/28 19:59:08 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

static void	free_pars(t_pars *pars)
{
	int	i;

	i = -1;
	while (++i < TYPE)
		free(pars->element[i]);
	free(pars);
}

t_game	*parsing(int ac, char **av)
{
	int		fd;
	t_pars	*pars;
	t_game	*game;

	if (ac != 2)
		ft_error("argument must be one");
	fd = open_file(av[1]);
	pars = read_file(fd);
	game = test_file(pars);
	close(fd);
	free_pars(pars);
	return (game);
}
