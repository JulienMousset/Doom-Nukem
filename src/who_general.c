/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who_general.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:02:56 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/05/01 19:00:21 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int	is_id(t_map *map, t_coord c)
{
	return (map->board[c.x][c.y]);
}

int	is_enemy_id(int id)
{
	return (id >= FIRST_ENEMY && id <= LAST_ENEMY) ? 1 : 0;
}

int	is_beggar(int id)
{
	return ((id >= 'g' && id <= 'j') ? 1 : 0);
}

int	is_not_busy(t_anim anim)
{
	return ((anim.block.x == -1 && anim.block.y == -1) ? 1 : 0);
}

int	is_isaac(t_map *map, t_coord c)
{
	return ((int)map->pos.x == c.x && (int)map->pos.y == c.y) ? 1 : 0;
}
