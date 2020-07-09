/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who_enemies.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 13:57:30 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/04 17:30:16 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		is_any_wall(int id)
{
	return ((id >= '1' && id <= '>') ? 1 : 0);
}

void	isaac_is_attacked(t_map *map, t_sprite *spr)
{
	ticks_init(&spr->ticks_attack);
	if (ticks_passed(&spr->ticks_attack, 1))
	{
		if (spr->i + 49 == ID_ROTTY)
			play_sfx(map, randomy(ID_SFX_ENEMY_ROTTY_1, ID_SFX_ENEMY_ROTTY_2));
		else if (spr->i + 49 == ID_WIZOOB)
			play_sfx(map, ID_SFX_ENEMY_WIZOOB);
		ticks_reset(&spr->ticks_attack);
		isaac_hurt(map);
	}
}

int		is_isaac_near(t_map *map, t_sprite *spr, t_coord pos)
{
	t_coord	pos_spr;
	t_coord	c;
	t_coord	i;

	pos_spr = (t_coord) {(int)spr->x, (int)spr->y};
	c.y = -2;
	while (++c.y <= 1)
	{
		c.x = -2;
		while (++c.x <= 1)
		{
			i = (t_coord) {.x = pos.x + c.x, .y = pos.y + c.y};
			if (pos_spr.x == i.x && pos_spr.y == i.y)
			{
				isaac_is_attacked(map, spr);
				return (1);
			}
		}
	}
	spr->ticks_attack = 0;
	return (0);
}
