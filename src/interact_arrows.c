/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_arrows.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:36:52 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/03 19:46:27 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	curse_door(t_map *map, int id)
{
	if (id != ID_CDOOR && map->prev_id.x != ID_CDOOR &&
			map->prev_id.y == ID_CDOOR && !map->item_mantle)
		isaac_hurt(map);
	map->prev_id.y = map->prev_id.x;
	map->prev_id.x = id;
}

int		is_walkable(t_env *env, int id, int x, int y)
{
	if (id == ID_TROPHY)
	{
		env->map->bool_win = 1;
		if (!env->map->transition)
		{
			Mix_HaltMusic();
			play_music(env->map, ID_STORE);
		}
		return (0);
	}
	if (is_pickable(env->map, id) || is_shop(env->map, id,
	env->map->pick_coin) || is_destroyable(env->map, id))
		realloc_array(env, x, y, id);
	if (is_door(env->map, id, x, y))
		return (0);
	curse_door(env->map, id);
	return ((is_walk(id)) ? 1 : 0);
}
