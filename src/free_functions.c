/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:53:51 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/04 19:17:42 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	free_and_display_usage(t_env *env, char *s)
{
	if (env && env->map && env->map->board)
		ft_tabdel(env->map->board, env->map->nb_lines);
	if (env && env->map && env->map->board_cpy)
		ft_tabdel(env->map->board_cpy, env->map->nb_lines);
	if (env && env->map)
		ft_memdel((void **)&(env->map));
	if (env)
		ft_memdel((void **)&(env));
	end(s);
}

void	free_program_in_tab(t_env *env, int *i)
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
	free_shared_structures_in_tab(env, *i);
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

void	free_structures(t_env *env)
{
	if (env && env->map)
	{
		if (env->map->hud_str)
			ft_memdel((void **)&(env->map->hud_str));
		if (env->map->z_buffer)
			ft_memdel((void **)&(env->map->z_buffer));
		if (env->fps_str)
			ft_memdel((void **)&(env->fps_str));
	}
}

void	exit_program(t_env *env, char *error)
{
	free_program(env);
	end(error);
}

void	close_program(t_env *env, int value)
{
	free_program(env);
	if (value)
		exit(EXIT_FAILURE);
	else if (!value)
		exit(EXIT_SUCCESS);
}
