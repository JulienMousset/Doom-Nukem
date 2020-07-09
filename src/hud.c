/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:02:24 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/03/06 18:46:09 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

t_coord	coord(t_env *env, int id, int n)
{
	t_coord	c;

	if (id == 1)
	{
		c.x = env->map->hud_margin.x;
		c.y = env->map->hud_margin.y + env->h / 12 * 0.8 * n;
	}
	if (id == 2)
	{
		c.x = env->map->hud_margin.x;
		c.y = env->map->hud_margin.y;
	}
	if (id == 3)
		c = (t_coord) {.x = 10, .y = per(env->h, 95)};
	if (id == 4)
	{
		c.x = 10;
		c.y = per(env->h, 95);
	}
	if (id == 5)
		c = (t_coord) {.x = env->w / 2, .y = env->h - 100};
	return (c);
}

void	print_mini_sprite(t_env *env, int id, t_coord margin, int scale)
{
	t_coord	p;
	t_coord	tex;
	int		size;

	p = (t_coord) {.x = 0, .y = 0};
	size = TS * scale;
	while (p.y < size)
	{
		tex.y = p.y * TS / size;
		p.x = 0;
		while (p.x < size)
		{
			tex.x = p.x * TS / size;
			env->map->color = get_pixel(env->t[id], tex.x, tex.y);
			if (env->map->color != 0)
				put_pixel(env, margin.x + p.x - 25, margin.y
				+ p.y, env->map->color);
			p.x++;
		}
		p.y++;
	}
}

void	print_hearts2(t_env *env, t_map *map)
{
	int			i;
	t_coord		c;
	SDL_Rect	rect;

	i = -1;
	while (++i < map->container - (map->pick_heart / 2 + map->pick_heart % 2))
	{
		c = coord(env, 2, 20);
		rect = (SDL_Rect){c.x, c.y, env->h / 4, env->h / 4};
		SDL_RenderCopy(env->rend, env->hud[ID_CONTAINER_EMPTY], NULL, &rect);
		map->hud_margin.x += env->h / 12 + env->h / 48;
	}
	map->hud_margin.x = -env->h / 24;
}

void	print_hearts(t_env *env, t_map *map)
{
	int			i;
	t_coord		c;
	SDL_Rect	rect;

	i = -1;
	map->hud_margin.x = (-env->h / 12) / 1.5;
	while (++i < map->pick_heart / 2)
	{
		c = coord(env, 2, 0);
		rect = (SDL_Rect){c.x, c.y, env->h / 4, env->h / 4};
		SDL_RenderCopy(env->rend, env->hud[ID_CONTAINER_RED], NULL, &rect);
		map->hud_margin.x += env->h / 12 + env->h / 48;
	}
	i = -1;
	while (++i < map->pick_heart % 2)
	{
		c = coord(env, 2, 20);
		rect = (SDL_Rect){c.x, c.y, env->h / 4, env->h / 4};
		SDL_RenderCopy(env->rend, env->hud[ID_CONTAINER_HALF], NULL, &rect);
		map->hud_margin.x += env->h / 12 + env->h / 48;
	}
	print_hearts2(env, map);
}

void	hud(t_env *env, t_map *map, char **board)
{
	int			n;
	t_coord		c;
	SDL_Rect	rect;

	n = 2;
	print_hearts(env, map);
	c = coord(env, 1, n++);
	rect = (SDL_Rect){c.x, c.y, env->h / 6, env->h / 6};
	SDL_RenderCopy(env->rend, env->hud[ID_COIN - 49], NULL, &rect);
	c = coord(env, 1, n++);
	rect = (SDL_Rect){c.x, c.y, env->h / 6, env->h / 6};
	SDL_RenderCopy(env->rend, env->hud[ID_KEY - 49], NULL, &rect);
	n++;
	print_items_hud(env, map, n);
	shop_hud(env, map, board);
	run_hud(env, map);
}
