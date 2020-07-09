/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:30:17 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/05/07 20:43:42 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	vertical_loop(t_thread *t, t_env *env, t_map *map)
{
	int		y;

	y = map->y_start;
	while (y < map->y_end)
	{
		t->i = (y - map->v_move) - map->h2 + map->spr.height / 2;
		t->tex.y = ((t->i * TS) / map->spr.height);
		sprite_selector(t, env, map);
		if (t->color != 0)
			put_pixel(env, t->x_start, y, t->color);
		y++;
	}
}

void	*horizontal_loop(void *vt)
{
	t_thread	*t;
	t_env		*env;
	t_map		*map;

	t = (t_thread *)vt;
	env = t->env;
	map = t->env->map;
	t->dif = map->x_end - map->x_start;
	t->x_start = map->x_start + t->dif * t->n / THREADS;
	t->x_end = map->x_start + t->dif * (t->n + 1) / THREADS;
	while (t->x_start < t->x_end)
	{
		t->tex.x = (int)(256 * (t->x_start - (-map->spr.width / 2 +
						map->ssx)) * TS / map->spr.width) / 256;
		if (map->transform.y > 0 && t->x_start > 0 && t->x_start < env->w &&
				map->transform.y < map->z_buffer[t->x_start])
			vertical_loop(t, env, env->map);
		t->x_start++;
	}
	return (0);
}

void	save_sprite_id(t_map *map, int i)
{
	map->id = map->s[map->spr_order[i]].i;
	map->spr_block.x = map->s[map->spr_order[i]].x - 0.5;
	map->spr_block.y = map->s[map->spr_order[i]].y - 0.5;
	map->spr.x = map->s[map->spr_order[i]].x - map->pos.x;
	map->spr.y = map->s[map->spr_order[i]].y - map->pos.y;
}

void	set_sprite_values(t_env *env, t_map *map, int i)
{
	save_sprite_id(map, i);
	map->inv_det = 1.0 /
		(map->plane.x * map->dir.y - map->dir.x * map->plane.y);
	map->transform.x = map->inv_det *
		(map->dir.y * map->spr.x - map->dir.x * map->spr.y);
	map->transform.y = map->inv_det *
		(-map->plane.y * map->spr.x + map->plane.x * map->spr.y);
	map->ssx = (int)((env->w / 2) * (1 + map->transform.x / map->transform.y));
	map->spr.height = abs((int)(env->h / map->transform.y));
	map->d = (map->jump < 0) ?
		-env->h * 0.8 * map->jump : -env->h * 0.4 * map->jump;
	map->v_move = (int)(map->d / map->transform.y);
	map->y_start = -map->spr.height / 2 + map->h2 + map->v_move;
	(map->y_start < 0) ? map->y_start = 0 : 0;
	map->y_end = map->spr.height / 2 + map->h2 + map->v_move;
	(map->y_end >= env->h) ? map->y_end = env->h - 1 : 0;
	map->spr.width = abs((int)(env->h / map->transform.y));
	map->x_start = -map->spr.width / 2 + map->ssx;
	(map->x_start < 0) ? map->x_start = 0 : 0;
	(map->x_start >= env->w) ? map->x_start = env->w - 1 : 0;
	map->x_end = map->spr.width / 2 + map->ssx;
	(map->x_end < 0) ? map->x_end = 0 : 0;
	(map->x_end >= env->w) ? map->x_end = env->w - 1 : 0;
}

void	sprites(t_env *env, t_map *map)
{
	map->i = 0;
	while (map->i < map->nb_sprites)
	{
		map->spr_order[map->i] = map->i;
		map->spr_dist[map->i] = (
				(map->pos.x - map->s[map->i].x) *
				(map->pos.x - map->s[map->i].x) +
				(map->pos.y - map->s[map->i].y) *
				(map->pos.y - map->s[map->i].y));
		map->i++;
	}
	bubble_sort(map->spr_order, map->spr_dist, map->nb_sprites);
	map->i = 0;
	while (map->i < map->nb_sprites)
	{
		set_sprite_values(env, map, map->i);
		create_threads(env, FOR_SPRITES);
		map->i++;
	}
}
