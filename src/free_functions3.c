/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:53:51 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/05/20 17:55:07 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	free_ed_textures(t_env *env)
{
	int		i;

	i = -1;
	while (++i < NUM_TEX)
	{
		if (env && *env->ed.tex && env->ed.tex[i])
			SDL_DestroyTexture(env->ed.tex[i]);
	}
	i = -1;
	while (++i < 18)
	{
		if (env && *env->ed.text_tex && env->ed.text_tex[i])
			SDL_DestroyTexture(env->ed.text_tex[i]);
	}
}

void	free_sounds(t_map *map)
{
	int i;

	i = -1;
	while (i++ < NUM_MUSIC - 1)
	{
		if (map && *map->music && map->music[i])
			Mix_FreeMusic(map->music[i]);
	}
	i = -1;
	while (i++ < NUM_SFX - 1)
	{
		if (map && *map->sfx && map->sfx[i])
			Mix_FreeChunk(map->sfx[i]);
	}
}

void	free_doors(t_env *env)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 12)
		{
			if (env && **env->doors && env->doors[i][j])
				SDL_FreeSurface(env->doors[i][j]);
		}
	}
}
