/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buy_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 18:18:16 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/04/28 18:28:11 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	buy_item_99(t_map *map, int id)
{
	if (map->pick_coin >= 99)
	{
		map->pick_coin -= 99;
		if (id == ID_POLY)
			map->item_poly = 1;
		else if (id == ID_IPECAC)
			map->item_ipecac = 1;
		else if (id == ID_GODHEAD)
			map->item_godhead = 1;
		play_sfx(map, ID_SFX_ITEM);
	}
}

void	pickup_chance2(t_map *map, int id)
{
	if (id == ID_SKULL)
	{
		randomy(0, 2) == 0 ? gain_item(map, ID_KEY) : 0;
		play_sfx(map, randomy(ID_SFX_ROCK_1, ID_SFX_ROCK_3));
	}
	else if (id == ID_MUSHROOM1 || id == ID_MUSHROOM2)
	{
		map->r = randomy(0, 5);
		if (map->r == 0)
			gain_item(map, ID_COIN);
		else if (map->r == 2)
			gain_item(map, ID_KEY);
		else if (map->r == 4)
		{
			isaac_hurt(map);
			if (map->item_swallowed)
				gain_item(map, ID_RHEART_HALF);
		}
		play_sfx(map, randomy(ID_SFX_MUSHROOM_1, ID_SFX_MUSHROOM_2));
	}
}

void	pickup_chance(t_map *map, int id)
{
	if (id == ID_ROCK1 || id == ID_ROCK2 || id == ID_POOP)
	{
		randomy(0, 2) == 0 ? gain_item(map, ID_COIN) : 0;
		if (id == ID_ROCK1 || id == ID_ROCK2)
			play_sfx(map, randomy(ID_SFX_ROCK_1, ID_SFX_ROCK_3));
		else
			play_sfx(map, ID_SFX_POOP);
	}
	else if (id == ID_URN)
	{
		map->r = randomy(0, 5);
		if (map->r == 0)
			gain_item(map, ID_COIN);
		else if (map->r == 2)
			gain_item(map, ID_KEY);
		else if (map->r == 4)
			gain_item(map, ID_RHEART_HALF);
		play_sfx(map, randomy(ID_SFX_URN_1, ID_SFX_URN_3));
	}
	pickup_chance2(map, id);
}

void	buy_item2(t_map *map, int id)
{
	if (id == ID_AXE)
	{
		map->item_axe = 1;
		play_sfx(map, ID_SFX_ITEM);
	}
	else if (id == ID_XRAY)
	{
		map->item_xray = 1;
		play_sfx(map, ID_SFX_ITEM);
	}
}

void	buy_item(t_map *map, int id)
{
	(id >= FIRST_SHOP_99 && id <= LAST_SHOP_99) ? buy_item_99(map, id) : 0;
	if (map->pick_coin >= 15)
	{
		map->pick_coin -= 15;
		if (id == ID_QUARTER)
		{
			map->pick_coin += 25;
			map->item_quarter = 1;
			play_sfx(map, ID_SFX_ITEM);
		}
		else if (id == ID_LOV)
		{
			map->container++;
			map->pick_heart = map->container * 2;
			map->item_lov = 1;
			play_sfx(map, ID_SFX_ITEM);
		}
		else if (id == ID_MANTLE)
		{
			map->item_mantle = 1;
			play_sfx(map, ID_SFX_ITEM);
		}
		buy_item2(map, id);
	}
}
