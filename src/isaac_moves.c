/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isaac_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:47:57 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/05/07 21:47:44 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	jump(t_map *map)
{
	map->jump = -0.1 * map->isaac_high;
	if (map->isaac_high == JUMP_LIMIT)
		map->isaac_dir = 0;
	else if (map->isaac_high == 0)
	{
		map->jump_bool = 0;
		map->isaac_dir = 1;
		map->space_times = 0;
	}
}

void	fly(t_map *map)
{
	map->jump = -0.1 * map->isaac_high;
	if (map->isaac_high == FLY_LIMIT)
		map->fly_bool = 0;
	else if (map->isaac_high == 0)
	{
		map->fly_bool = 0;
		map->isaac_dir = 1;
	}
}

void	crouch(t_map *map)
{
	map->jump = 0.1 * map->isaac_high;
	if (map->isaac_high == CROUCH_LIMIT)
		map->crouch_bool = 0;
	else if (map->isaac_high == 0)
	{
		map->crouch_bool = 0;
		map->isaac_dir = 1;
	}
}

void	spacebar_pressed(t_map *map)
{
	if (map->space_times == 0)
		first_spacebar_pressed(map);
	else if (map->space_times == 1)
	{
		if (!ticks_passed(&map->isaac_ticks, 1))
		{
			map->jump_bool = 0;
			map->fly_bool = 1;
			map->space_times++;
			ticks_init(&map->isaac_ticks);
		}
	}
	else if (map->space_times == 2 && map->isaac_high)
	{
		map->fly_bool = 1;
		map->isaac_dir = 0;
		map->space_times = 0;
		ticks_init(&map->isaac_ticks);
	}
	else if (map->space_times > 1)
		map->space_times = 0;
}

void	isaac_moves(t_map *map)
{
	if (map->jump_bool || map->fly_bool || map->crouch_bool)
	{
		if (ticks_passed(&map->isaac_ticks, 0.02))
		{
			ticks_reset(&map->isaac_ticks);
			map->isaac_dir ? map->isaac_high++ : map->isaac_high--;
			if (map->jump_bool)
				jump(map);
			else if (map->fly_bool)
				fly(map);
			else if (map->crouch_bool)
				crouch(map);
		}
	}
}
