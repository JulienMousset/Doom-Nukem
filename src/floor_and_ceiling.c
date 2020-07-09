/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:21:02 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/05/27 14:06:31 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	set_casting_values(t_thread *t)
{
	if (t->ns_or_ew == 0 && t->ray_dir.x > 0)
	{
		t->floor.x = t->block.x;
		t->floor.y = t->block.y + t->wall_x;
	}
	else if (t->ns_or_ew == 0 && t->ray_dir.x < 0)
	{
		t->floor.x = t->block.x + 1.0;
		t->floor.y = t->block.y + t->wall_x;
	}
	else if (t->ns_or_ew == 1 && t->ray_dir.y > 0)
	{
		t->floor.x = t->block.x + t->wall_x;
		t->floor.y = t->block.y;
	}
	else
	{
		t->floor.x = t->block.x + t->wall_x;
		t->floor.y = t->block.y + 1.0;
	}
	t->dist_wall = t->perp;
	t->dist_play = 0.0;
}

void	floor_casting(t_thread *t, t_env *env, t_map *map, int x)
{
	int			y;
	double		weight;

	t->y_end = t->y_end < 0 ? 0 : t->y_end;
	t->y_end = t->y_end > env->h ? env->h : t->y_end;
	y = t->y_end - 1;
	while (++y < env->h)
	{
		t->dist_curr = (env->h - map->i) /
			(2.0 * y - (map->h2 - map->i * 0.06) * 2.0);
		weight = (t->dist_curr - t->dist_play) / (t->dist_wall - t->dist_play);
		t->curr_floor.x = weight * t->floor.x + (1.0 - weight) * map->pos.x;
		t->curr_floor.y = weight * t->floor.y + (1.0 - weight) * map->pos.y;
		t->tex.x = (int)(t->curr_floor.x * TS) % TS;
		t->tex.y = (int)(t->curr_floor.y * TS) % TS;
		t->color = get_pixel(t->env->t[map->fac.x], t->tex.x, t->tex.y);
		t->color = darken(env, t->color, t->dist_curr, env->map->item_candle);
		put_pixel(t->env, x, y, t->color);
	}
}

void	floor_and_ceiling(t_thread *t, t_env *env, t_map *map, int x)
{
	int			y;
	double		weight;

	set_casting_values(t);
	t->y_start = t->y_start < 0 ? 0 : t->y_start;
	t->y_start = t->y_start > env->h ? env->h : t->y_start;
	map->i = 680 * map->jump;
	y = -1;
	while (++y < t->y_start)
	{
		t->dist_curr = (env->h + map->i) /
			((map->h2 - map->i * 0.04) * 2.0 - y * 2.0);
		weight = (t->dist_curr - t->dist_play) / (t->dist_wall - t->dist_play);
		t->curr_floor.x = weight * t->floor.x + (1.0 - weight) * map->pos.x;
		t->curr_floor.y = weight * t->floor.y + (1.0 - weight) * map->pos.y;
		t->tex.x = (int)(t->curr_floor.x * TS) % TS;
		t->tex.y = (int)(t->curr_floor.y * TS) % TS;
		t->color = get_pixel(env->t[map->fac.y], t->tex.x, t->tex.y);
		t->color = darken(env, t->color, t->dist_curr, env->map->item_candle);
		put_pixel(env, x, y, t->color);
	}
	floor_casting(t, env, map, x);
}
