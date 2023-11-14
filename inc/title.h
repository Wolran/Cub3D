/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <alde-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:18:37 by vmuller           #+#    #+#             */
/*   Updated: 2023/11/12 06:47:10 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TITLE_H
# define TITLE_H

# include "engine.h"

typedef struct s_title		t_title;

static char const *const	g_titles[] = {
	"A terrible chill runs up your spine...",
	"You have retrieved the rope, go towards the exit!",
};

struct s_title
{
	float	time;
	char	*str;
};

void	title_put(t_title *const title, char const *str, float const time);
void	title_update(t_engine *const eng, t_title *const title, float const dt);

#endif 
