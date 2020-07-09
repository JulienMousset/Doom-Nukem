/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_nukem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:30:04 by jmousset          #+#    #+#             */
/*   Updated: 2020/06/03 21:00:41 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	surface_processing(t_env *env)
{
	SDL_LockSurface(env->surface);
	if (!env->map->bool_win && !env->map->bool_dead &&
	!env->map->intro && env->menu < 10 && !env->map->final_score)
		image_to_window(env, env->map);
	if (env->map->hurt == 1)
	{
		SDL_FillRect(env->surface, NULL, 0xFF0000);
		env->map->hurt = 0;
	}
	SDL_UnlockSurface(env->surface);
}

void	render_processing(t_env *env)
{
	SDL_Rect	rect;

	surface_processing(env);
	if (!env->map->final_score && !env->map->intro)
	{
		!env->map->intro ? fps_think(env) : 0;
		text_manager(env, env->map, env->map->board);
		if ((env->map->bool_win || env->map->bool_dead))
		{
			end_game(env, env->map);
			env->map->final_score++;
		}
	}
	env->text = SDL_CreateTextureFromSurface(env->rend, env->surface);
	rect = (SDL_Rect) {.x = 0, .y = 0, .w = env->w, .h = env->h};
	SDL_RenderCopy(env->rend, env->text, NULL, &rect);
	if ((!env->map->bool_dead && !env->map->bool_win && !env->map->intro))
		hud(env, env->map, env->map->board);
	display_menu(env);
	SDL_DestroyTexture(env->text);
}

int		sdl_loop(t_env *env)
{
	env->ticks = SDL_GetTicks();
	while (!env->map->close_requested)
	{
		while (SDL_PollEvent(&env->event))
		{
			if ((!env->map->bool_dead && !env->map->bool_win &&
			!env->map->intro)
			|| (env->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE ||
			env->event.key.keysym.scancode == SDL_SCANCODE_SPACE ||
			env->event.type == SDL_QUIT))
				events(env);
		}
		multiple_events(env);
		if (env->map->intro)
			intro(env, env->map);
		render_processing(env);
		disable_mouse(env);
		SDL_RenderPresent(env->rend);
		process_music(env);
	}
	return (1);
}

int		doom_nukem(char *file, int is_arg)
{
	t_env	*env;
	int		close_requested;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		free_and_display_usage(env, ERR_MALLOC);
	if (!(env->map = (t_map *)malloc(sizeof(t_map))))
		free_and_display_usage(env, ERR_MALLOC);
	env_init(env);
	if (!(parsing(env, file)))
		free_and_display_usage(env, ERR_USAGE);
	pre_set_values(env, file);
	set_values(env, env->map);
	sdl_init(env);
	init_menu(env, is_arg);
	sdl_loop(env);
	if (env->map->close_requested >= 2)
	{
		close_requested = env->map->close_requested - 1;
		free_program(env);
		editor_switch(close_requested);
		return (1);
	}
	else if (env->map->close_requested == 1)
		close_program(env, 0);
	return (1);
}
