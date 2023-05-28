/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:59:04 by vmuller           #+#    #+#             */
/*   Updated: 2023/05/28 20:11:42 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/parsing.h"

void	executing(t_game *game)
{
	printf("EA = %p\n", game->wall.img_ptr[0]);
	printf("WE = %p\n", game->wall.img_ptr[1]);
	printf("SO = %p\n", game->wall.img_ptr[2]);
	printf("NO = %p\n", game->wall.img_ptr[3]);
	printf("C = %d\n", game->color[0]);
	printf("F = %d\n", game->color[1]);
	for (int i = 0; game->map[i]; i++)
		printf("%s\n", game->map[i]);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = parsing(ac, av);
	executing(game);
}
