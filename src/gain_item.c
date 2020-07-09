/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gain_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 18:08:41 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/04/28 18:20:56 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	set_boundaries(t_map *map)
{
	if (map->pick_heart < 0)
		map->pick_heart = 0;
	if (map->pick_heart > map->container * 2)
		map->pick_heart = map->container * 2;
	if (map->pick_coin > 99)
		map->pick_coin = 99;
	if (map->pick_key > 99)
		map->pick_key = 99;
}

void	gain_item4(t_map *map, int id)
{
	if (id == ID_CRICKET)
	{
		map->item_cricket = 1;
		play_sfx(map, ID_SFX_ITEM);
	}
	else if (id >= FIRST_SHOP && id <= LAST_SHOP)
		buy_item(map, id);
	else if ((id == ID_HEART_SHOP || id == ID_KEY_SHOP) && map->pick_coin >= 5)
	{
		map->pick_coin -= 5;
		id == ID_HEART_SHOP ? gain_item(map, ID_RHEART) :
			gain_item(map, ID_KEY);
	}
	if (id >= FIRST_ITEM && id <= LAST_ITEM)
		map->score += 50;
}

void	gain_item3(t_map *map, int id)
{
	if (id == ID_DINNER)
	{
		map->container++;
		map->item_dinner = 1;
		play_sfx(map, ID_SFX_ITEM);
		gain_item(map, ID_RHEART);
	}
	else if (id == ID_SWALLOWED)
	{
		map->item_swallowed = 1;
		play_sfx(map, ID_SFX_ITEM);
	}
	else if (id == ID_VAMPIRE)
	{
		map->item_vampire = 1;
		play_sfx(map, ID_SFX_ITEM);
	}
	else if (id == ID_ODD)
	{
		map->item_odd = 1;
		map->odd_ticks = SDL_GetTicks();
	}
	gain_item4(map, id);
}

void	gain_item2(t_map *map, int id)
{
	if (id == ID_KEY)
	{
		map->pick_key++;
		play_sfx(map, ID_SFX_KEY);
	}
	else if (id == ID_MAP)
	{
		map->item_map = 1;
		play_sfx(map, ID_SFX_MAP);
	}
	else if (id == ID_HEELS)
	{
		map->item_heels = 1;
		play_sfx(map, ID_SFX_ITEM);
	}
	else if (id == ID_CANDLE)
	{
		map->item_candle = CANDLE_INT;
		play_sfx(map, ID_SFX_ITEM);
	}
	gain_item3(map, id);
}

void	gain_item(t_map *map, int id)
{
	if (is_destroyable(map, id))
		pickup_chance(map, id);
	if (id == ID_COIN)
	{
		map->pick_coin++;
		play_sfx(map, ID_SFX_PENNY);
	}
	else if (id == ID_NICKEL)
	{
		map->pick_coin += 5;
		play_sfx(map, ID_SFX_NICKEL);
	}
	else if (id == ID_RHEART)
	{
		map->pick_heart += 2;
		play_sfx(map, ID_SFX_HEART_UP);
	}
	else if (id == ID_RHEART_HALF)
	{
		map->pick_heart++;
		play_sfx(map, ID_SFX_HEART_DOWN);
	}
	gain_item2(map, id);
}
