/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:53:51 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/04 19:23:03 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	free_lst(t_lst **lst)
{
	while (*lst != NULL)
		ft_lst_del(lst);
}

void	free_shared_structures_in_tab(t_env *env, int i)
{
	if (env && env->map)
	{
		if (env->map->s)
			ft_memdel((void **)&(env->map->s));
		if (env->map->spr_order)
			ft_memdel((void **)&(env->map->spr_order));
		if (env->map->spr_dist)
			ft_memdel((void **)&(env->map->spr_dist));
		if (env->map->board)
			ft_tabdel(env->map->board, i + 1);
		if (env->map->board_cpy)
			ft_tabdel(env->map->board_cpy, i + 1);
	}
}

void	free_shared_structures(t_env *env)
{
	if (env && env->map)
	{
		if (env->map->s)
			ft_memdel((void **)&(env->map->s));
		if (env->map->spr_order)
			ft_memdel((void **)&(env->map->spr_order));
		if (env->map->spr_dist)
			ft_memdel((void **)&(env->map->spr_dist));
		if (env->map->board)
			ft_tabdel(env->map->board, env->map->nb_lines);
		if (env->map->board_cpy)
			ft_tabdel(env->map->board_cpy, env->ed.nb_lines_bcpy);
	}
}

void	free_program(t_env *env)
{
	if (env && env->map && env->map->tnt_lst)
		free_lst(&env->map->tnt_lst);
	if (env && env->ft)
		TTF_CloseFont(env->ft);
	if (env && env->ft_help)
		TTF_CloseFont(env->ft_help);
	Mix_CloseAudio();
	free_textures(env);
	free_sounds(env->map);
	free_structures(env);
	free_shared_structures(env);
	if (env && env->surface)
		SDL_FreeSurface(env->surface);
	if (env && env->rend)
		SDL_DestroyRenderer(env->rend);
	if (env && env->win)
		SDL_DestroyWindow(env->win);
	if (env && env->map)
		ft_memdel((void **)&(env->map));
	if (env)
		ft_memdel((void **)&(env));
	TTF_Quit();
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}

void	free_textures(t_env *env)
{
	int		i;

	i = -1;
	while (++i < NUM_TEX)
	{
		if (env && *env->t && env->t[i])
			SDL_FreeSurface(env->t[i]);
		if (env && *env->hud && env->hud[i])
			SDL_DestroyTexture(env->hud[i]);
	}
	i = -1;
	while (++i < 3)
	{
		if (env && *env->image && env->image[i])
			SDL_FreeSurface(env->image[i]);
		if (env && *env->texture && env->texture[i])
			SDL_DestroyTexture(env->texture[i]);
	}
	free_doors(env);
	free_beggars(env);
	free_tears(env);
	free_panels(env);
	free_explosions(env);
	free_anim_ticks(env);
	free_ed_textures(env);
}
