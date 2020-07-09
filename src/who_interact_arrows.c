/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who_interact_arrows.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:27:17 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/01 18:42:27 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		is_pickable(t_map *map, int id)
{
	return (((id >= FIRST_FREE && id <= LAST_FREE) || ((id == ID_RHEART ||
						id == ID_RHEART_HALF) &&
					map->pick_heart < map->container * 2)) ? 1 : 0);
}

int		is_destroyable(t_map *map, int id)
{
	return ((id >= FIRST_DESTRUCT && id <= LAST_DESTRUCT && map->item_axe) ?
			1 : 0);
}

int		is_walk(int id)
{
	return ((id == '0' || id == ID_HEART_SHOP || id == ID_KEY_SHOP ||
				(id >= FIRST_WALK && id <= LAST_WALK)) ? 1 : 0);
}

int		is_door_closed(t_map *map, int id, int x, int y)
{
	if ((id == ID_DOOR_C || id == ID_GDOOR_C) && map->pick_key)
	{
		if (x != map->anim[A_DOORS].block.x && y != map->anim[A_DOORS].block.y)
		{
			map->pick_key--;
			play_sfx(map, ID_SFX_UNLOCK);
			play_sfx(map, ID_SFX_DOOR_OPEN);
		}
		if (is_not_busy(map->anim[A_DOORS]))
		{
			map->anim[A_DOORS].block = (t_coord) {.x = x, .y = y};
			ticks_init(&map->anim[A_DOORS].ticks);
		}
		return (0);
	}
	return (1);
}

int		is_door(t_map *map, int id, int x, int y)
{
	if (!is_door_closed(map, id, x, y))
		return (0);
	if (id == ID_DOOR_HEART && map->pick_heart >= 6)
	{
		if (is_not_busy(map->anim[A_DOORS]))
		{
			play_sfx(map, ID_SFX_DOOR_OPEN);
			map->anim[A_DOORS].block = (t_coord) {.x = x, .y = y};
			ticks_init(&map->anim[A_DOORS].ticks);
		}
		return (1);
	}
	return (0);
}
