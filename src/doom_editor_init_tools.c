/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_editor_init_tools.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 20:02:36 by julien            #+#    #+#             */
/*   Updated: 2020/06/03 15:20:52 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		editor_switch(int map_id)
{
	if (map_id == 1)
		doom_editor(PATH_LEVEL_1);
	else if (map_id == 2)
		doom_editor(PATH_LEVEL_2);
	else if (map_id == 3)
		doom_editor(PATH_LEVEL_3);
	else if (map_id == 4)
		doom_editor(PATH_LEVEL_0);
}

void		e_replace_player(t_env *e)
{
	e->map->board[e->map->orig_ppos.x][e->map->orig_ppos.y] = 'q';
}

int			e_events_hook(t_env *e)
{
	SDL_Event	t;

	if (SDL_PollEvent(&t))
	{
		if (e->ed.quit || t.type == SDL_QUIT
				|| (t.type == SDL_KEYUP
					&& t.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
			return ((e->ed.quit ? e->ed.quit : (e->ed.quit = 1)));
		if (t.type == SDL_KEYDOWN)
			e->ed.keys[t.key.keysym.scancode] = 1;
		else if (t.type == SDL_KEYUP)
			e->ed.keys[t.key.keysym.scancode] = 0;
		if (t.type == SDL_MOUSEMOTION)
			e->ed.mouse = (SDL_Point){t.motion.x, t.motion.y};
		if (t.type == SDL_MOUSEBUTTONDOWN && t.button.button == SDL_BUTTON_LEFT)
			e->ed.mouse_click.x = 1;
		if (t.type == SDL_MOUSEBUTTONUP && t.button.button == SDL_BUTTON_LEFT)
			e->ed.mouse_click.x = 0;
		if (t.type == SDL_MOUSEBUTTONDOWN
				&& t.button.button == SDL_BUTTON_RIGHT)
			e->ed.mouse_click.y = 1;
		if (t.type == SDL_MOUSEBUTTONUP && t.button.button == SDL_BUTTON_RIGHT)
			e->ed.mouse_click.y = 0;
	}
	return (0);
}

void		e_ttf_init(t_env *env)
{
	if (TTF_Init() != 0)
	{
		free_program(env);
		end((char *)TTF_GetError());
	}
	env->white = (SDL_Color) {255, 255, 255, 255};
}

void		e_offsets(t_env *e)
{
	if (e->ed.keys[SDL_SCANCODE_RIGHT] && e->ed.offset.x > -e->ed.zoom * 8)
		e->ed.offset.x = e->ed.offset.x - 1 * (e->ed.zoom / 40);
	if (e->ed.keys[SDL_SCANCODE_LEFT] && e->ed.offset.x < 0)
		e->ed.offset.x = e->ed.offset.x + 1 * (e->ed.zoom / 40);
	if (e->ed.keys[SDL_SCANCODE_DOWN] && e->ed.offset.y > -e->ed.zoom * 8)
		e->ed.offset.y = e->ed.offset.y - 1 * (e->ed.zoom / 40);
	if (e->ed.keys[SDL_SCANCODE_UP] && e->ed.offset.y < 0)
		e->ed.offset.y = e->ed.offset.y + 1 * (e->ed.zoom / 40);
}
