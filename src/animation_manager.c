/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:09:14 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/03 18:12:50 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	open_lever_doors(t_map *map)
{
	t_coord		c;

	c.x = -1;
	while (++c.x < map->nb_lines)
	{
		c.y = -1;
		while (++c.y < map->nb_columns)
		{
			if (is_id(map, c) == ID_DOOR_LEVER)
			{
				map->board[c.x][c.y] = ID_DOOR_O;
				map->nb_lever_doors++;
			}
		}
	}
}

void	drop(t_map *map, int x, int y, int id)
{
	int		i;

	i = -1;
	while (++i < map->nb_sprites)
	{
		if (map->s[i].x == x + 0.5 && map->s[i].y == y + 0.5)
		{
			map->board[x][y] = id;
			map->s[i].i = id - 49;
			break ;
		}
	}
}

int		set_frame(t_anim *anim)
{
	anim->frames = (SDL_GetTicks() - anim->ticks) / (anim->sec * INTERVAL);
	return (anim->frames);
}

void	stop_animation(t_env *env, t_anim *anim, t_coord c, int i)
{
	if (i == A_DOORS)
	{
		env->map->board[c.x][c.y] = (env->map->board[c.x][c.y] == ID_GDOOR_C) ?
			ID_GDOOR_O : ID_DOOR_O;
	}
	if (i == A_TEAR)
	{
		env->map->bool_tear = 0;
		env->map->check_hit = 0;
	}
	if (i == A_BARREL)
	{
		if (!randomy(0, 3) && is_id(env->map, anim[i].block) != ID_TNT)
			drop(env->map, anim[i].block.x, anim[i].block.y, ID_ODD);
		else
			realloc_array(env, anim[i].block.x, anim[i].block.y, -1);
	}
	if (i == A_CYCLIC)
	{
		ticks_reset(&anim[i].ticks);
		env->map->shine_freq = env->map->shine_freq < SHINE_FREQ ?
			env->map->shine_freq + 1 : 0;
	}
	else
		anim[i].ticks = 0;
}

void	animation_manager(t_env *env, t_anim *anim)
{
	int		i;
	t_coord	c;

	i = -1;
	while (++i < NUM_ANIM)
	{
		ticks_init(&anim[A_CYCLIC].ticks);
		if (anim[i].ticks)
		{
			c = anim[i].block;
			if (set_frame(&env->map->anim[i]) >= anim[i].max_frames)
			{
				stop_animation(env, anim, c, i);
				anim[i].frames = 0;
				anim[i].block = (t_coord) {.x = -1, .y = -1};
			}
		}
	}
	if (env->map->item_odd)
	{
		if (ticks_passed(&env->map->odd_ticks, 10))
			env->map->item_odd = 0;
	}
}
