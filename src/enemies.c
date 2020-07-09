/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:56:29 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/05 18:57:04 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	enemy_rotty(t_map *map, t_coord pos_player, int i)
{
	t_coord	pos_spr;

	if (map->s[i].i + 49 == ID_ROTTY)
	{
		ticks_init(&map->s[i].ticks_move);
		pos_spr = (t_coord) {map->s[i].x - 0.5, map->s[i].y - 0.5};
		if (bresenham(map, pos_spr, pos_player) &&
				!is_isaac_near(map, &map->s[i], pos_player))
		{
			if (ticks_passed(&map->s[i].ticks_move, 1))
			{
				ticks_reset(&map->s[i].ticks_move);
				if (map->board[map->new_pos.x][map->new_pos.y] == '0')
				{
					move_enemy(map, pos_spr, i, ID_ROTTY);
					if (randomy(0, 1))
						play_sfx(map, randomy(ID_SFX_ENEMY_ROTTY_1,
									ID_SFX_ENEMY_ROTTY_2));
				}
			}
		}
	}
}

void	enemy_baby(t_map *map, t_coord pos_player, int i)
{
	t_coord		pos_spr;

	if (map->s[i].i + 49 == ID_BABY1)
	{
		ticks_init(&map->s[i].ticks_attack);
		pos_spr = (t_coord) {map->s[i].x - 0.5, map->s[i].y - 0.5};
		if (bresenham(map, pos_spr, pos_player) &&
				ticks_passed(&map->s[i].ticks_attack, 2.5))
		{
			ticks_reset(&map->s[i].ticks_attack);
			play_sfx(map, randomy(ID_SFX_ENEMY_BABY_1, ID_SFX_ENEMY_BABY_2));
			isaac_hurt(map);
			if (map->item_swallowed)
				gain_item(map, ID_COIN);
		}
	}
}

void	enemy_dople(t_map *map, t_coord pos_player, int i)
{
	t_coord		pos_spr;
	t_coord		c;

	if (map->s[i].i + 49 == ID_DOPLE)
	{
		c = (t_coord) {0, 0};
		if (map->s[i].old_pos.y == 0 && map->s[i].old_pos.y == 0)
			map->s[i].old_pos = (t_coord) {pos_player.x, pos_player.y};
		pos_spr = (t_coord) {map->s[i].x - 0.5, map->s[i].y - 0.5};
		if (bresenham(map, pos_spr, pos_player))
		{
			if (set_dople_direction(map, i, pos_player, &c))
			{
				if ((map->board[pos_spr.x + c.x][pos_spr.y + c.y] == '0') &&
						((pos_spr.x + c.x) < map->nb_columns) &&
						((pos_spr.y + c.y) < map->nb_lines))
				{
					map->new_pos = (t_coord) {pos_spr.x + c.x, pos_spr.y + c.y};
					move_enemy(map, pos_spr, i, ID_DOPLE);
				}
			}
			set_dople_sprite(map, c);
			is_isaac_near(map, &map->s[i], pos_player);
		}
	}
}

void	enemy_wizoob(t_map *map, t_coord pos_player, int i)
{
	t_coord	pos_spr;

	if (map->s[i].i + 49 == ID_WIZOOB)
	{
		ticks_init(&map->s[i].ticks_move);
		pos_spr = (t_coord) {map->s[i].x - 0.5, map->s[i].y - 0.5};
		if (bresenham(map, pos_spr, pos_player))
		{
			if (ticks_passed(&map->s[i].ticks_move, 1.5))
			{
				ticks_reset(&map->s[i].ticks_move);
				map->new_pos = pos_spr;
				while (map->board[map->new_pos.x][map->new_pos.y] != '0')
				{
					map->new_pos.x = randomy(map->s[i].old_pos.x,
							map->s[i].new_pos.x);
					map->new_pos.y = randomy(map->s[i].old_pos.y,
							map->s[i].new_pos.y);
				}
				move_enemy(map, pos_spr, i, ID_WIZOOB);
				set_wizoob_sprite(map);
			}
			is_isaac_near(map, &map->s[i], pos_player);
		}
	}
}

void	enemies(t_map *map)
{
	int		i;
	t_coord	pos_player;

	i = -1;
	pos_player = (t_coord) {(int)map->pos.x, (int)map->pos.y};
	while (++i < map->nb_sprites)
	{
		enemy_rotty(map, pos_player, i);
		enemy_baby(map, pos_player, i);
		enemy_dople(map, pos_player, i);
		enemy_wizoob(map, pos_player, i);
	}
}
