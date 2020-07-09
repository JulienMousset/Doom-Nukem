/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_audio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:29:26 by jmousset          #+#    #+#             */
/*   Updated: 2020/06/05 12:23:24 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

Mix_Music	*load_music(t_env *env, char *filename)
{
	Mix_Music	*music;

	if (!(music = Mix_LoadMUS(filename)))
		exit_program(env, (char *)Mix_GetError());
	return (music);
}

Mix_Chunk	*load_sfx(t_env *env, char *filename)
{
	Mix_Chunk	*sfx;

	if (!(sfx = Mix_LoadWAV(filename)))
		exit_program(env, (char *)Mix_GetError());
	return (sfx);
}

void		init_music(t_env *env)
{
	env->map->music[0] = load_music(env, DEATH);
	env->map->music[1] = load_music(env, EDITOR);
	env->map->music[2] = load_music(env, LEVEL_1);
	env->map->music[3] = load_music(env, LEVEL_2);
	env->map->music[4] = load_music(env, LEVEL_3);
	env->map->music[5] = load_music(env, STORE);
	env->map->music[6] = load_music(env, TITLE);
}

void		init_sfx_2(t_env *env)
{
	env->map->sfx[24] = load_sfx(env, SFX_MUSHROOM_2);
	env->map->sfx[25] = load_sfx(env, SFX_NICKEL);
	env->map->sfx[26] = load_sfx(env, SFX_PENNY);
	env->map->sfx[27] = load_sfx(env, SFX_POOP);
	env->map->sfx[28] = load_sfx(env, SFX_ROCK_1);
	env->map->sfx[29] = load_sfx(env, SFX_ROCK_2);
	env->map->sfx[30] = load_sfx(env, SFX_ROCK_3);
	env->map->sfx[31] = load_sfx(env, SFX_SECRET);
	env->map->sfx[32] = load_sfx(env, SFX_SOLUTION);
	env->map->sfx[33] = load_sfx(env, SFX_TEAR_1);
	env->map->sfx[34] = load_sfx(env, SFX_TEAR_2);
	env->map->sfx[35] = load_sfx(env, SFX_UNLOCK);
	env->map->sfx[36] = load_sfx(env, SFX_URN_1);
	env->map->sfx[37] = load_sfx(env, SFX_URN_2);
	env->map->sfx[38] = load_sfx(env, SFX_URN_3);
}

void		init_sfx(t_env *env)
{
	env->map->sfx[0] = load_sfx(env, SFX_BUTTON);
	env->map->sfx[1] = load_sfx(env, SFX_DEATH_1);
	env->map->sfx[2] = load_sfx(env, SFX_DEATH_2);
	env->map->sfx[3] = load_sfx(env, SFX_DEATH_3);
	env->map->sfx[4] = load_sfx(env, SFX_DOOR_OPEN);
	env->map->sfx[5] = load_sfx(env, SFX_ENEMY_BABY_1);
	env->map->sfx[6] = load_sfx(env, SFX_ENEMY_BABY_2);
	env->map->sfx[7] = load_sfx(env, SFX_ENEMY_DEATH);
	env->map->sfx[8] = load_sfx(env, SFX_ENEMY_ROTTY_1);
	env->map->sfx[9] = load_sfx(env, SFX_ENEMY_ROTTY_2);
	env->map->sfx[10] = load_sfx(env, SFX_ENEMY_WIZOOB);
	env->map->sfx[11] = load_sfx(env, SFX_EXPLOSION);
	env->map->sfx[12] = load_sfx(env, SFX_GAMBLE_1);
	env->map->sfx[13] = load_sfx(env, SFX_GAMBLE_2);
	env->map->sfx[14] = load_sfx(env, SFX_GAMBLE_3);
	env->map->sfx[15] = load_sfx(env, SFX_HEART_DOWN);
	env->map->sfx[16] = load_sfx(env, SFX_HEART_UP);
	env->map->sfx[17] = load_sfx(env, SFX_HIT);
	env->map->sfx[18] = load_sfx(env, SFX_ITEM);
	env->map->sfx[19] = load_sfx(env, SFX_KEY);
	env->map->sfx[20] = load_sfx(env, SFX_MAP);
	env->map->sfx[21] = load_sfx(env, SFX_MENU_1);
	env->map->sfx[22] = load_sfx(env, SFX_MENU_2);
	env->map->sfx[23] = load_sfx(env, SFX_MUSHROOM_1);
	init_sfx_2(env);
}
