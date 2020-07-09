/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tnt_explosion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:25:20 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/04 17:30:24 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		is_secret(t_map *map)
{
	return ((map->id == ID_SECRET1 ||
				map->id == ID_SECRET2 ||
				map->id == ID_SECRET3) ? 1 : 0);
}

int		is_destroy(t_map *map, int id)
{
	if (id == ID_ROCK1 || id == ID_ROCK2 || id == ID_SKULL)
		play_sfx(map, randomy(ID_SFX_ROCK_1, ID_SFX_ROCK_3));
	else if (id == ID_MUSHROOM1 || id == ID_MUSHROOM2)
		play_sfx(map, randomy(ID_SFX_MUSHROOM_1, ID_SFX_MUSHROOM_2));
	else if (id == ID_URN)
		play_sfx(map, randomy(ID_SFX_URN_1, ID_SFX_URN_3));
	else if (id == ID_POOP)
		play_sfx(map, ID_SFX_POOP);
	return ((id >= FIRST_DESTRUCT && id <= LAST_DESTRUCT) ? 1 : 0);
}

void	damage_near_blocks(t_env *env, t_coord i)
{
	if (is_secret(env->map))
	{
		play_sfx(env->map, ID_SFX_SECRET);
		env->map->board[i.x][i.y] = '0';
	}
	if (is_enemy_id(env->map->id) || is_destroy(env->map, env->map->id))
		realloc_array(env, i.x, i.y, env->map->id);
	else if (env->map->id == ID_TNT && !ft_lst_iter(env->map,
	env->map->tnt_lst, i))
	{
		ft_lst_add(&env->map->tnt_lst, ft_lst_new(env, i.x, i.y));
		tnt_explosion(env, i.x, i.y);
	}
	else if (is_isaac(env->map, i))
	{
		env->map->pick_heart--;
		env->map->item_swallowed ? env->map->pick_coin++ : 0;
		isaac_hurt(env->map);
	}
}

void	tnt_explosion(t_env *env, int x, int y)
{
	t_coord		c;
	t_coord		i;

	c.y = -1;
	if (env->map->first_tnt.x == -1)
		env->map->first_tnt = (t_coord) {.x = x, .y = y};
	while (c.y <= 1)
	{
		c.x = -1;
		(c.y == 0 && c.x == 0) ? c.x++ : 0;
		while (c.x <= 1)
		{
			i = (t_coord) {.x = x + c.x, .y = y + c.y};
			env->map->id = is_id(env->map, i);
			damage_near_blocks(env, i);
			c.x++;
		}
		c.y++;
	}
	play_sfx(env->map, ID_SFX_EXPLOSION);
}
