/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 13:47:46 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/05 19:20:12 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	move_enemy(t_map *map, t_coord pos_spr, int i, int enemy)
{
	map->board[pos_spr.x][pos_spr.y] = '0';
	map->s[i].x = map->new_pos.x + 0.5;
	map->s[i].y = map->new_pos.y + 0.5;
	map->board[map->new_pos.x][map->new_pos.y] = enemy;
}

int		set_dople_direction(t_map *map, int i, t_coord pos_player, t_coord *c)
{
	if (map->s[i].old_pos.x != pos_player.x ||
			map->s[i].old_pos.y != pos_player.y)
	{
		if (map->s[i].old_pos.x < pos_player.x)
			c->x = 1;
		else if (map->s[i].old_pos.x > pos_player.x)
			c->x = -1;
		if (map->s[i].old_pos.y < pos_player.y)
			c->y = 1;
		else if (map->s[i].old_pos.y > pos_player.y)
			c->y = -1;
		map->s[i].old_pos = (t_coord) {pos_player.x, pos_player.y};
		return (1);
	}
	return (0);
}

void	set_dople_sprite(t_map *map, t_coord c)
{
	if (c.y == -1)
		map->dople_spr = 21;
	else if (c.y == 1)
		map->dople_spr = 22;
	else if (c.x != 0)
		map->dople_spr = 0;
}

void	set_wizoob_sprite(t_map *map)
{
	int random;

	random = randomy(0, 3);
	if (random == 1)
		map->wiz_spr = 24;
	else if (random == 2)
		map->wiz_spr = 25;
	else if (random == 3)
		map->wiz_spr = 26;
	srand(time(NULL));
}

void	set_wizoob_area(t_map *map, t_sprite *new, int x, int y)
{
	new->old_pos.x = x;
	new->new_pos.x = x;
	new->old_pos.y = y;
	new->new_pos.y = y;
	while (!is_any_wall(map->board[new->old_pos.x][y]))
		new->old_pos.x--;
	while (!is_any_wall(map->board[new->new_pos.x][y]))
		new->new_pos.x++;
	while (!is_any_wall(map->board[x][new->old_pos.y]))
		new->old_pos.y--;
	while (!is_any_wall(map->board[x][new->new_pos.y]))
		new->new_pos.y++;
	new->old_pos.x += 1;
	new->old_pos.y += 1;
	new->new_pos.x -= 1;
	new->new_pos.y -= 1;
}
