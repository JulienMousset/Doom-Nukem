/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 13:23:21 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/01 18:55:50 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	first_spacebar_pressed(t_map *map)
{
	if (!map->isaac_high)
	{
		map->jump_bool = 1;
		map->space_times++;
	}
	else if (map->isaac_high && !map->fly_bool)
	{
		map->crouch_bool = 1;
		map->isaac_dir = 0;
	}
	ticks_init(&map->isaac_ticks);
}

void	key_press4(t_env *env, t_map *map, SDL_Event event)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_LCTRL)
	{
		if (!map->jump_bool && !map->fly_bool &&
				!map->crouch_bool && !map->space_times)
		{
			ticks_init(&map->isaac_ticks);
			map->crouch_bool = 1;
			map->isaac_dir = 1;
			if (map->isaac_high)
				map->isaac_dir = 0;
		}
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_TAB && map->item_map)
	{
		map->opt = map->opt == 1 ? 2 : 1;
		set_mmap_values(env, map, map->opt);
		play_sfx(map, ID_SFX_MAP);
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_G)
		gamble(map, map->board);
	set_boundaries(map);
}

void	key_press3(t_env *env, t_map *map, SDL_Event event)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_1 && map->admin_mode)
		gain_item(map, ID_COIN);
	else if (event.key.keysym.scancode == SDL_SCANCODE_2 && map->admin_mode)
		gain_item(map, ID_KEY);
	else if (event.key.keysym.scancode == SDL_SCANCODE_3 && map->admin_mode)
		isaac_hurt(map);
	else if (event.key.keysym.scancode == SDL_SCANCODE_4 && map->admin_mode)
		gain_item(map, ID_RHEART);
	else if (event.key.keysym.scancode == SDL_SCANCODE_9)
		admin_mode(map);
	key_press4(env, map, event);
}

void	key_press2(t_env *env, t_map *map, SDL_Event event)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
	{
		if (map->intro)
		{
			map->intro = 0;
			env->font_size = env->h / 42;
			Mix_HaltMusic();
			map->transition = 0;
		}
		else
			spacebar_pressed(map);
		if (map->bool_dead)
			reset_game(env, map);
		else if (map->bool_win)
			level_processing(env);
	}
	else if (event.key.keysym.scancode == SDL_SCANCODE_R)
	{
		if (map->reset_ticks == 0)
			ticks_reset(&map->reset_ticks);
	}
	key_press3(env, map, event);
}

void	key_press(t_env *env, t_map *map, SDL_Event event)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_W
			|| event.key.keysym.scancode == SDL_SCANCODE_UP)
		map->up = 1;
	else if (event.key.keysym.scancode == SDL_SCANCODE_S
			|| event.key.keysym.scancode == SDL_SCANCODE_DOWN)
		map->down = 1;
	else if (event.key.keysym.scancode == SDL_SCANCODE_A
			|| event.key.keysym.scancode == SDL_SCANCODE_LEFT)
		map->left = 1;
	else if (event.key.keysym.scancode == SDL_SCANCODE_D
			|| event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
		map->right = 1;
	else if (event.key.keysym.scancode == SDL_SCANCODE_Q)
		map->strafe_left = 1;
	else if (event.key.keysym.scancode == SDL_SCANCODE_E)
		map->strafe_right = 1;
	else if (event.key.keysym.scancode == SDL_SCANCODE_F)
		interact_keys(map);
	else if (event.key.keysym.scancode == SDL_SCANCODE_LSHIFT &&
			map->item_heels)
		map->run = 1;
	else if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		map->close_requested = 1;
	key_press2(env, map, event);
}
