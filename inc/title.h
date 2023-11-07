/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:18:37 by vmuller           #+#    #+#             */
/*   Updated: 2023/11/07 15:50:04 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TITLE_H
# define TITLE_H

# include "engine.h"

typedef struct s_title t_title;

static char const *const g_titles[] =
{
	"Un frisson vous parcourt l'echine...",
};

struct s_title
{
	float time;
	char *str;
};

void	title_put(t_title *const title, char const *str, float const time);
void	title_update(t_engine *const eng, t_title *const title, float const dt);

#endif 