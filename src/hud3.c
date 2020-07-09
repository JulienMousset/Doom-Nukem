/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 20:06:36 by julien            #+#    #+#             */
/*   Updated: 2020/06/01 18:38:47 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	run_hud(t_env *env, t_map *map)
{
	t_coord		c;
	SDL_Rect	rect;

	if (map->item_heels && map->run)
	{
		c = coord(env, 3, 0);
		rect = (SDL_Rect){c.x, c.y, env->h / 6, env->h / 6};
		SDL_RenderCopy(env->rend, env->hud[ID_SHIFT_ON], NULL, &rect);
	}
	else if (map->item_heels)
	{
		c = coord(env, 4, 0);
		rect = (SDL_Rect){c.x, c.y, env->h / 6, env->h / 6};
		SDL_RenderCopy(env->rend, env->hud[ID_SHIFT_OFF], NULL, &rect);
	}
}

void	shop_hud(t_env *env, t_map *map, char **board)
{
	int			id;
	t_coord		c;
	SDL_Rect	rect;

	id = board[(int)(map->pos.x + map->dir.x)][(int)(map->pos.y + map->dir.y)];
	if (id >= FIRST_SHOP_99 && id <= LAST_SHOP_99)
	{
		c = coord(env, 5, 0);
		rect = (SDL_Rect){c.x, c.y, env->h / 4, env->h / 4};
		SDL_RenderCopy(env->rend, env->hud[ID_TAG_99], NULL, &rect);
	}
	else if (id >= FIRST_SHOP_15 && id <= LAST_SHOP_15)
	{
		c = coord(env, 5, 0);
		rect = (SDL_Rect){c.x, c.y, env->h / 4, env->h / 4};
		SDL_RenderCopy(env->rend, env->hud[ID_TAG_15], NULL, &rect);
	}
	else if (id >= FIRST_SHOP_5 && id <= LAST_SHOP_5)
	{
		c = coord(env, 5, 0);
		rect = (SDL_Rect){c.x, c.y, env->h / 4, env->h / 4};
		SDL_RenderCopy(env->rend, env->hud[ID_TAG_5], NULL, &rect);
	}
}
