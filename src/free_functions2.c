/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:50:52 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/05/01 17:52:38 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	free_beggars(t_env *env)
{
	int i;
	int j;

	i = -1;
	while (i++ < 3)
	{
		j = -1;
		while (j++ < 1)
		{
			if (env && **env->beggars && env->beggars[i][j])
				SDL_FreeSurface(env->beggars[i][j]);
		}
	}
	i = -1;
	while (i++ < 2)
	{
		if (env && *env->trophy && env->trophy[i])
			SDL_FreeSurface(env->trophy[i]);
	}
}

void	free_tears(t_env *env)
{
	int i;
	int j;

	i = -1;
	while (i++ < 1)
	{
		j = -1;
		while (j++ < 14)
		{
			if (env && **env->tears && env->tears[i][j])
				SDL_FreeSurface(env->tears[i][j]);
		}
	}
}

void	free_panels(t_env *env)
{
	int	i;

	i = -1;
	while (i++ < 6)
	{
		if (env && *env->panel && env->panel[i])
			SDL_FreeSurface(env->panel[i]);
	}
}

void	free_explosions(t_env *env)
{
	int i;
	int j;

	i = -1;
	while (i++ < 1)
	{
		j = -1;
		while (j++ < 7)
		{
			if (env && **env->explosions && env->explosions[i][j])
				SDL_FreeSurface(env->explosions[i][j]);
		}
	}
}

void	free_anim_ticks(t_env *env)
{
	int i;
	int j;

	i = -1;
	while (i++ < 2)
	{
		j = -1;
		while (j++ < 5)
		{
			if (env && **env->cyclic && env->cyclic[i][j])
				SDL_FreeSurface(env->cyclic[i][j]);
		}
	}
	i = -1;
	while (i++ < 1)
	{
		j = -1;
		while (j++ < 1)
		{
			if (env && **env->b && env->b[i][j])
				SDL_FreeSurface(env->b[i][j]);
		}
	}
}
