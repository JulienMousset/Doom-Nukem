/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_audio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:15:09 by jmousset          #+#    #+#             */
/*   Updated: 2020/06/05 12:21:40 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	init_audio(t_env *env)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0)
		exit_program(env, (char *)Mix_GetError());
	init_music(env);
	init_sfx(env);
	env->map->music_on = 1;
	env->map->sfx_on = 1;
	env->map->volume_music = 50;
	env->map->volume_sfx = 50;
}

void	play_sfx(t_map *map, int i)
{
	if (map->sfx_on)
		Mix_PlayChannel(-1, map->sfx[i], 0);
}

void	play_music(t_map *map, int i)
{
	if (map->music_on)
		Mix_PlayMusic(map->music[i], -1);
}

void	process_music(t_env *env)
{
	Mix_VolumeMusic(env->map->volume_music);
	Mix_Volume(-1, env->map->volume_sfx);
	if (env->map->music_on && !Mix_PlayingMusic() && !env->map->transition
	&& !env->map->menu_transition && !env->map->intro)
	{
		if (env->map->lvl_music == 2)
			play_music(env->map, ID_LEVEL_2);
		else if (env->map->lvl_music == 3)
			play_music(env->map, ID_LEVEL_3);
		else
			play_music(env->map, ID_LEVEL_1);
	}
}
