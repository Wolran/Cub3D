/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:59:04 by vmuller           #+#    #+#             */
/*   Updated: 2023/06/16 00:36:09 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	executing(t_engine *eng, t_data *game, double et)
{
	(void)eng;
	(void)et;
	printf("EA = %p\n", game->sprite[0]);
	printf("WE = %p\n", game->sprite[1]);
	printf("SO = %p\n", game->sprite[2]);
	printf("NO = %p\n", game->sprite[3]);
	printf("C = %d\n", game->color[0]);
	printf("F = %d\n", game->color[1]);
	for (int i = 0; game->map[i]; i++)
		printf("%s\n", game->map[i]);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		game;
	t_engine	*eng;

	eng = ft_eng_create(800, 600, "cub3d (plus que classique)");
	if (eng)
	{
		if (parsing(ac, av, eng, &game) == 0)
			ft_eng_play(eng, &game, &executing);
		else
			ft_putstr_fd("Error: Failed to initialise the game.\n", 1);
	}
}
