/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:58:56 by vmuller           #+#    #+#             */
/*   Updated: 2023/06/16 00:34:38 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	ft_atorgb(char *element)
{
	int	rgb;
	int	i;
	int	num;

	rgb = 0;
	i = 0;
	while (++i < 4)
	{
		num = 0;
		if (!('0' <= *element && *element <= '9'))
			ft_error("color is invalid");
		while ('0' <= *element && *element <= '9')
		{
			num = (num * 10) + (*element - '0');
			if (num > 255)
				ft_error("color is invalid");
			element++;
		}
		if (*element == ',')
			element++;
		rgb = rgb << 8 | num;
	}
	return (rgb);
}

void	test_element(char **element, t_data *game)
{
	int	i;

	i = -1;
	while (++i < COLOR)
	{
		game->sprite[i] = ft_sprite_p(game->eng, element[i]);
		if (!game->sprite[i])
			ft_error("image path is invalid");
	}
	i = COLOR - 1;
	while (++i < TYPE)
		game->color[i - COLOR] = ft_atorgb(element[i]);
}

void	test_file(t_pars *pars, t_data *game, t_engine *eng)
{
	game->eng = eng;
	test_map(pars->map, game);
	test_element(pars->element, game);
}
