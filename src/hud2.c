/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:02:24 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/03/06 18:46:09 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	print_items_hud5(t_env *env, t_map *map, int n)
{
	SDL_Rect	rect;
	t_coord		c;

	if (map->item_vampire)
	{
		c = coord(env, 1, n++);
		rect = (SDL_Rect){c.x, c.y, env->h / 6, env->h / 6};
		SDL_RenderCopy(env->rend, env->hud[ID_VAMPIRE - 49], NULL, &rect);
	}
	if (map->item_cricket)
	{
		c = coord(env, 1, n++);
		rect = (SDL_Rect){c.x, c.y, env->h / 6, env->h / 6};
		SDL_RenderCopy(env->rend, env->hud[ID_CRICKET - 49], NULL, &rect);
	}
	if (map->item_dinner)
	{
		c = coord(env, 1, n++);
		rect = (SDL_Rect){c.x, c.y, env->h / 6, env->h / 6};
		SDL_RenderCopy(env->rend, env->hud[ID_DINNER - 49], NULL, &rect);
	}
}

void	print_items_hud4(t_env *env, t_map *map, int n)
{
	SDL_Rect	rect;
	t_coord		c;

	if (map->item_mantle)
	{
		c = coord(env, 1, n++);
		rect = (SDL_Rect){c.x, c.y, env->h / 6, env->h / 6};
		SDL_RenderCopy(env->rend, env->hud[ID_MANTLE - 49], NULL, &rect);
	}
	if (map->item_candle == CANDLE_INT)
	{
		c = coord(env, 1, n++);
		rect = (SDL_Rect){c.x, c.y, env->h / 6, env->h / 6};
		SDL_RenderCopy(env->rend, env->hud[ID_CANDLE - 49], NULL, &rect);
	}
	if (map->item_swallowed)
	{
		c = coord(env, 1, n++);
		rect = (SDL_Rect){c.x, c.y, env->h / 6, env->h / 6};
		SDL_RenderCopy(env->rend, env->hud[ID_SWALLOWED - 49], NULL, &rect);
	}
	print_items_hud5(env, map, n);
}

void	print_items_hud3(t_env *env, t_map *map, int n)
{
	SDL_Rect	rect;
	t_coord		c;

	if (map->item_lov)
	{
		c = coord(env, 1, n++);
		rect = (SDL_Rect){c.x, c.y, env->h / 6, env->h / 6};
		SDL_RenderCopy(env->rend, env->hud[ID_LOV - 49], NULL, &rect);
	}
	if (map->item_xray)
	{
		c = coord(env, 1, n++);
		rect = (SDL_Rect){c.x, c.y, env->h / 6, env->h / 6};
		SDL_RenderCopy(env->rend, env->hud[ID_XRAY - 49], NULL, &rect);
	}
	if (map->item_axe)
	{
		c = coord(env, 1, n++);
		rect = (SDL_Rect){c.x, c.y, env->h / 6, env->h / 6};
		SDL_RenderCopy(env->rend, env->hud[ID_AXE - 49], NULL, &rect);
	}
	print_items_hud4(env, map, n);
}

void	print_items_hud2(t_env *env, t_map *map, int n)
{
	SDL_Rect	rect;
	t_coord		c;

	if (map->item_ipecac)
	{
		c = coord(env, 1, n++);
		rect = (SDL_Rect){c.x, c.y, env->h / 6, env->h / 6};
		SDL_RenderCopy(env->rend, env->hud[ID_IPECAC - 49], NULL, &rect);
	}
	if (map->item_godhead)
	{
		c = coord(env, 1, n++);
		rect = (SDL_Rect){c.x, c.y, env->h / 6, env->h / 6};
		SDL_RenderCopy(env->rend, env->hud[ID_GODHEAD - 49], NULL, &rect);
	}
	if (map->item_quarter)
	{
		c = coord(env, 1, n++);
		rect = (SDL_Rect){c.x, c.y, env->h / 6, env->h / 6};
		SDL_RenderCopy(env->rend, env->hud[ID_QUARTER - 49], NULL, &rect);
	}
	print_items_hud3(env, map, n);
}

void	print_items_hud(t_env *env, t_map *map, int n)
{
	SDL_Rect	rect;
	t_coord		c;

	if (map->item_map)
	{
		c = coord(env, 1, n++);
		rect = (SDL_Rect){c.x, c.y, env->h / 6, env->h / 6};
		SDL_RenderCopy(env->rend, env->hud[ID_MAP - 49], NULL, &rect);
	}
	if (map->item_heels)
	{
		c = coord(env, 1, n++);
		rect = (SDL_Rect){c.x, c.y, env->h / 6, env->h / 6};
		SDL_RenderCopy(env->rend, env->hud[ID_HEELS - 49], NULL, &rect);
	}
	if (map->item_poly)
	{
		c = coord(env, 1, n++);
		rect = (SDL_Rect){c.x, c.y, env->h / 6, env->h / 6};
		SDL_RenderCopy(env->rend, env->hud[ID_POLY - 49], NULL, &rect);
	}
	print_items_hud2(env, map, n);
}
