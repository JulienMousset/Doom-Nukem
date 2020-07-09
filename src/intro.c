/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:12:37 by jmousset          #+#    #+#             */
/*   Updated: 2020/04/28 18:31:16 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	draw_intro(t_env *env, int id, t_coord margin, int scale)
{
	t_coord	p;
	t_coord	tex;
	int		size_h;
	int		size_w;

	p = (t_coord) {.x = 0, .y = 0};
	size_h = PH * scale;
	size_w = PW * scale;
	while (p.y < size_h)
	{
		tex.y = p.y * PH / size_h;
		p.x = 0;
		while (p.x < size_w)
		{
			tex.x = p.x * PW / size_w;
			env->map->color = get_pixel(env->panel[id], tex.x, tex.y);
			if (env->map->color != 0)
				put_pixel(env, margin.x + p.x, margin.y + p.y, env->map->color);
			p.x++;
		}
		p.y++;
	}
}

void	intro(t_env *env, t_map *map)
{
	env->font_size = env->h / 26;
	if (!map->intro_transition)
	{
		Mix_HaltMusic();
		play_music(map, ID_EDITOR);
		map->intro_transition = 1;
	}
	env->margin = (t_coord) {.x = env->w / 16, .y = env->h / 48};
	SDL_FillRect(env->surface, NULL, 0x000000);
	ticks_init(&map->anim[A_INTRO].ticks);
	draw_intro(env, map->anim[A_INTRO].frames, env->margin, 2);
	if (set_frame(&map->anim[A_INTRO]) >= map->anim[A_INTRO].max_frames)
	{
		map->intro = 0;
		map->anim[A_INTRO].ticks = 0;
		map->anim[A_INTRO].frames = 0;
		Mix_HaltMusic();
		map->transition = 0;
		env->font_size = env->h / 42;
	}
	draw_text(env, env->story[map->anim[A_INTRO].frames], env->w / 8,
	per(env->h, 70));
	draw_text(env, "Press [SPACEBAR] to skip", per(env->w, 63),
			per(env->h, 96));
	SDL_UpdateWindowSurface(env->win);
}
