/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <vmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:56:14 by alde-fre          #+#    #+#             */
/*   Updated: 2023/11/06 07:19:32 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H

# include "entity/entity.h"

t_entity	*entity_add(t_data *const game, t_v3f const pos);

t_entity	*e_player_add(t_data *const game, t_v3f const pos);
t_entity	*e_fireball_add(
				t_data *const game,
				t_v3f const pos,
				t_v2f const rot);
t_entity	*e_mimic_add(
				t_data *const game,
				t_v3f const pos,
				t_v2f const rot);
t_entity	*e_door_add(t_data *const game, t_v3f const pos, t_v2f const rot);
t_entity	*e_spike_add(t_data *const game, t_v3f const pos, t_v2f rot);
void		spike_attack(t_data *const game, t_entity *const self);
t_entity	*e_enemy_add(t_data *const game, t_v3f const pos, t_v2f rot);
void	enemy_attack(t_data *const game, t_entity *const self);

#endif
