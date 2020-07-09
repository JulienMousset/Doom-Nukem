/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:18:14 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/05/01 13:13:37 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	gamble_beggar_heart(t_map *map)
{
	isaac_hurt(map);
	map->run_anim = 1;
	map->i = randomy(0, 2);
	if (map->i == 1)
		gain_item(map, ID_KEY);
	else if (map->i == 2)
		map->pick_coin += 2;
}

void	interact_beggar(t_map *map, int id)
{
	if (id == ID_BLOOD_MACHINE && map->pick_heart)
	{
		isaac_hurt(map);
		gain_item(map, ID_COIN);
		map->run_anim = 1;
	}
	else if (id == ID_BEGGAR_COIN && map->pick_coin)
	{
		map->pick_coin--;
		map->run_anim = 1;
		randomy(0, 2) == 0 ? gain_item(map, ID_KEY) : 0;
	}
	else if (id == ID_BEGGAR_KEY && map->pick_key)
	{
		map->pick_key--;
		gain_item(map, ID_COIN);
		map->run_anim = 1;
	}
	else if (id == ID_BEGGAR_HEART && map->pick_heart)
		gamble_beggar_heart(map);
	play_sfx(map, randomy(ID_SFX_GAMBLE_1, ID_SFX_GAMBLE_3));
}

void	take_poster(t_map *map)
{
	map->poster_pos = (t_coord) {.x = 0, .y = 0};
	map->pick_coin += 5;
	map->pick_key += 1;
	map->pick_heart = map->container * 2;
	map->score += 100;
	play_sfx(map, ID_SFX_MAP);
	play_sfx(map, ID_SFX_SECRET);
}

void	interact_keys(t_map *map)
{
	t_coord		c;

	c.x = (int)(map->pos.x + map->dir.x);
	c.y = (int)(map->pos.y + map->dir.y);
	if ((c.x == map->poster_pos.x) && (c.y == map->poster_pos.y))
		take_poster(map);
	else if (is_id(map, c) == ID_LEVER_OFF)
	{
		drop(map, c.x, c.y, ID_LEVER_ON);
		play_sfx(map, ID_SFX_BUTTON);
		map->lever_counter++;
		if (map->lever_counter == map->nb_lever)
		{
			open_lever_doors(map);
			play_sfx(map, ID_SFX_SOLUTION);
			if (map->nb_lever_doors)
				ticks_init(&map->lever_ticks);
		}
	}
}

void	gamble(t_map *map, char **board)
{
	int		id;

	id = board[(int)(map->pos.x + map->dir.x)][(int)(map->pos.y + map->dir.y)];
	if (is_beggar(id) && (is_not_busy(map->anim[A_BEGGAR])))
		interact_beggar(map, id);
	if (map->run_anim)
	{
		map->anim[A_BEGGAR].block.x = (int)(map->pos.x + map->dir.x);
		map->anim[A_BEGGAR].block.y = (int)(map->pos.y + map->dir.y);
		ticks_init(&map->anim[A_BEGGAR].ticks);
		map->run_anim = 0;
	}
	set_boundaries(map);
}
