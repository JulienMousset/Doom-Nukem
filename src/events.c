/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:10:21 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/03 18:19:25 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	multiple_events(t_env *env)
{
	if (env->map->up == 1 || env->map->down == 1)
		up_or_down(env, env->map->board, env->map->dir);
	if (env->map->left == 1 || env->map->right == 1)
		left_or_right(env, env->map->rot_coef);
	if (env->map->strafe_left == 1 || env->map->strafe_right == 1)
		strafe(env, env->map->board, env->map->dir);
}

void	key_release(t_map *map, SDL_Event event)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_W
			|| event.key.keysym.scancode == SDL_SCANCODE_UP)
		map->up = 0;
	else if (event.key.keysym.scancode == SDL_SCANCODE_S
			|| event.key.keysym.scancode == SDL_SCANCODE_DOWN)
		map->down = 0;
	else if (event.key.keysym.scancode == SDL_SCANCODE_A
			|| event.key.keysym.scancode == SDL_SCANCODE_LEFT)
		map->left = 0;
	else if (event.key.keysym.scancode == SDL_SCANCODE_D
			|| event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
		map->right = 0;
	else if (event.key.keysym.scancode == SDL_SCANCODE_Q)
		map->strafe_left = 0;
	else if (event.key.keysym.scancode == SDL_SCANCODE_E)
		map->strafe_right = 0;
	else if (event.key.keysym.scancode == SDL_SCANCODE_LSHIFT)
		map->run = 0;
	else if (event.key.keysym.scancode == SDL_SCANCODE_R)
		map->reset_ticks = 0;
}

void	reset_player_movements(t_env *env)
{
	env->map->up = 0;
	env->map->down = 0;
	env->map->left = 0;
	env->map->right = 0;
	env->map->strafe_left = 0;
	env->map->strafe_right = 0;
}

void	events(t_env *env)
{
	if ((env->event.type == SDL_QUIT) || (env->event.type == SDL_KEYDOWN &&
				env->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
	{
		if (env->menu != 10 && (env->map->bool_dead || env->map->bool_win))
		{
			Mix_HaltMusic();
			env->menu = 10;
		}
		else
			env->map->close_requested = 1;
	}
	else if (env->event.type == SDL_KEYDOWN &&
			env->event.key.keysym.scancode == SDL_SCANCODE_M)
	{
		reset_player_movements(env);
		change_menu(env);
	}
	else if (env->event.type == SDL_KEYDOWN && !env->menu)
		key_press(env, env->map, env->event);
	else if (env->event.type == SDL_KEYUP && !env->menu)
		key_release(env->map, env->event);
	else if (!env->menu)
		mouse_events(env, env->map);
}
