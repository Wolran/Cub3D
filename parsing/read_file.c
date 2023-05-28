/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:58:48 by vmuller           #+#    #+#             */
/*   Updated: 2023/05/28 19:59:08 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

t_pars	*read_file(int fd)
{
	t_pars	*pars;

	pars = (t_pars *)malloc(sizeof(t_pars));
	if (!pars)
		ft_error("malloc failed");
	read_element(fd, pars);
	pars->map = read_map(fd);
	return (pars);
}
