/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_editor_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 20:02:00 by julien            #+#    #+#             */
/*   Updated: 2020/06/04 18:57:17 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int			doom_editor(char *file)
{
	t_env		*e;
	SDL_Event	event;
	char		*level;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		free_and_display_usage(e, ERR_MALLOC);
	if (!(e->map = (t_map *)malloc(sizeof(t_map))))
		free_and_display_usage(e, ERR_MALLOC);
	env_init(e);
	e_init_structure(e, file);
	play_music(e->map, ID_EDITOR);
	e_replace_player(e);
	SDL_PollEvent(&event);
	editor_loop(e, editor_render_hook, e_events_hook);
	if (e->ed.quit == 2)
	{
		level = e->map->level;
		free_program(e);
		doom_nukem(level, 1);
	}
	free_program(e);
	return (1);
}

void		editor_loop(t_env *e, t_timerhook render, t_eventhook event)
{
	while (42)
	{
		render(1, e);
		if (event(e))
			break ;
	}
}

int			e_init_structure(t_env *env, char *file)
{
	e_var_init(env);
	if (!(parsing(env, file)))
		free_and_display_usage(env, ERR_USAGE);
	env->map->level = file;
	e_init(&env);
	load_sprites(env);
	load_tex2(env);
	init_audio(env);
	e_ttf_init(env);
	text_init(env);
	return (0);
}

int			e_init(t_env **e)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO |
				SDL_INIT_EVENTS | SDL_INIT_TIMER))
		exit_program(*e, (char *)SDL_GetError());
	if (Mix_Init(0))
		exit_program(*e, (char *)Mix_GetError());
	if (IMG_Init(0))
		exit_program(*e, (char *)IMG_GetError());
	SDL_CreateWindowAndRenderer(0, 0,
	SDL_WINDOW_BORDERLESS | SDL_WINDOW_FULLSCREEN_DESKTOP
	| SDL_WINDOW_INPUT_FOCUS, &(*e)->win, &(*e)->rend);
	SDL_GetDesktopDisplayMode(0, &(*e)->screen);
	SDL_SetRenderDrawBlendMode((*e)->rend, SDL_BLENDMODE_BLEND);
	return (0);
}

void		e_var_init(t_env *env)
{
	int keys_count;

	keys_count = -1;
	while (++keys_count < SDL_NUM_SCANCODES)
	{
		env->ed.keys[keys_count] = 0;
	}
	env->ed.offset = (SDL_Point){0, 0};
	env->ed.mouse = (SDL_Point){0, 0};
	env->ed.mouse_click = (SDL_Point){0, 0};
	env->ed.zoom = 400;
	env->ed.quit = 0;
	env->ed.pick_block = '1';
	env->ed.ek.b_add_lines = 0;
	env->ed.ek.b_rem_lines = 0;
	env->ed.ek.b_add_columns = 0;
	env->ed.ek.b_rem_columns = 0;
	env->ed.ek.b_lvmus = 0;
	env->ed.ek.b_save = 0;
	env->ed.info_texindex = 0;
	env->ed.info_opacity = 0;
}
