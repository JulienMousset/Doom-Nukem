/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:36:32 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/05 19:50:05 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	fps_think(t_env *env)
{
	env->fps.x++;
	if (ticks_passed(&env->ticks, 1))
	{
		ticks_reset(&env->ticks);
		env->fps.y = env->fps.x;
		env->fps.x = 0;
	}
	if (!(env->fps_str = ft_itoa(env->fps.y)))
		exit_program(env, ERR_MALLOC);
	draw_text(env, env->fps_str, per(env->w, 98), per(env->h, 1));
	ft_memdel((void **)&(env->fps_str));
}

void	disable_mouse(t_env *env)
{
	if (!env->menu)
	{
		SDL_ShowCursor(SDL_DISABLE);
		SDL_SetRelativeMouseMode(SDL_TRUE);
		reset_mouse(env);
	}
	else
	{
		SDL_ShowCursor(SDL_ENABLE);
		SDL_SetRelativeMouseMode(SDL_FALSE);
	}
}

void	isaac_hurt(t_map *map)
{
	map->pick_heart--;
	if (map->item_swallowed == 1)
		map->pick_coin += 1;
	map->hurt = 1;
	if (map->pick_heart == 0)
	{
		map->bool_dead = 1;
		play_sfx(map, randomy(ID_SFX_DEATH_1, ID_SFX_DEATH_3));
		Mix_HaltMusic();
		play_music(map, ID_DEATH);
	}
	else
		play_sfx(map, ID_SFX_HIT);
}
