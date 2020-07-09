/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:03:57 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/05 12:24:11 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

SDL_Surface	*load_sprite(t_env *env, char *path)
{
	SDL_Surface	*surface;

	surface = IMG_Load(path);
	if (!surface)
		exit_program(env, (char *)SDL_GetError());
	return (surface);
}

SDL_Texture	*load_tex(t_env *env, char *path)
{
	SDL_Texture	*res;

	if (!(res = IMG_LoadTexture(env->rend, path)))
		exit_program(env, (char *)SDL_GetError());
	return (res);
}

void		load_sprites(t_env *env)
{
	int		i;

	load_paths(env->path);
	i = -1;
	while (++i < NUM_TEX)
	{
		env->t[i] = load_sprite(env, env->path[i]);
		env->hud[i] = load_tex(env, env->path[i]);
	}
	load_animations(env);
	create_sprites_array(env);
}
