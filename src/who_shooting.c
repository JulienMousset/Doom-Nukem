/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who_shooting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:35:24 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/04 22:47:43 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		is_tear_obstacle(int id)
{
	return (((id >= FIRST_WALL && id <= ID_SECRET3) || id >= ID_ROCK1) ? 1 : 0);
}

int		is_hit(t_thread *t)
{
	if (t->env->map->board[t->block.x][t->block.y] == ID_WALL_GLASS)
	{
		t->glass_hit = 1;
		if (t->saved == 0)
		{
			t->x_saved = t->x_start;
			t->saved = 1;
		}
	}
	if ((t->env->map->board[t->block.x][t->block.y] > '0') &&
			(t->env->map->board[t->block.x][t->block.y] < FIRST_SPR))
	{
		if (t->env->map->board[t->block.x][t->block.y] == ID_WALL_GLASS &&
				t->saved != 3)
			return (0);
		return (1);
	}
	else
		return (0);
}

void	damage_enemy(t_env *env, int id)
{
	if (!(query_hp(env->map, env->map->block.x, env->map->block.y, 1)))
	{
		if (id == ID_POOP)
			play_sfx(env->map, ID_SFX_POOP);
		if (!randomy(0, 3) && id == ID_POOP)
			drop(env->map, env->map->block.x, env->map->block.y, ID_COIN);
		else
		{
			is_enemy_id(id) ? play_sfx(env->map, ID_SFX_ENEMY_DEATH) : 0;
			realloc_array(env, env->map->block.x, env->map->block.y,
			env->map->id);
			if (env->map->item_vampire && is_enemy_id(id) && !randomy(0, 1) &&
					env->map->pick_heart < env->map->container * 2)
				gain_item(env->map, ID_RHEART_HALF);
			env->map->score += 10;
		}
	}
}

void	is_destroyed(t_env *env, int id)
{
	if (((id == ID_TNT) || (id == ID_MUSHROOM1) || (id == ID_MUSHROOM2)) &&
			is_not_busy(env->map->anim[A_BARREL]))
	{
		if (!(query_hp(env->map, env->map->block.x, env->map->block.y, 1)))
		{
			env->map->anim[A_BARREL].block.x = env->map->block.x;
			env->map->anim[A_BARREL].block.y = env->map->block.y;
			ticks_init(&env->map->anim[A_BARREL].ticks);
			if (id == ID_TNT)
			{
				tnt_explosion(env, env->map->block.x, env->map->block.y);
				ft_lst_realloc(env, env->map->tnt_lst);
				ft_lst_del(&env->map->tnt_lst);
				env->map->first_tnt = (t_coord) {.x = -1, .y = -1};
			}
			if ((id == ID_MUSHROOM1) || (id == ID_MUSHROOM2))
				play_sfx(env->map, randomy(ID_SFX_MUSHROOM_1,
				ID_SFX_MUSHROOM_2));
		}
	}
	else if (is_enemy_id(id) || (id == ID_POOP))
		damage_enemy(env, id);
}
