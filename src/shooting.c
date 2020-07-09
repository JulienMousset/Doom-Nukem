/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shooting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:14:45 by jmousset          #+#    #+#             */
/*   Updated: 2020/06/03 18:23:47 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	print_mini_tear(t_env *env, int id, t_coord margin, double scale)
{
	t_coord		p;
	t_coord		tex;
	int			size;
	int			id_0;

	p = (t_coord) {.x = 0, .y = 0};
	size = TS * scale;
	id_0 = env->map->item_cricket ? 1 : 0;
	while (p.y < size)
	{
		tex.y = p.y * TS / size;
		p.x = -1;
		while (++p.x < size)
		{
			tex.x = p.x * TS / size;
			env->map->color = get_pixel(env->tears[id_0][id], tex.x, tex.y);
			env->map->color = darken(env, env->map->color,
					env->map->perp, env->map->item_candle);
			if (env->map->color != 0)
				put_pixel(env, margin.x + p.x, margin.y + p.y, env->map->color);
		}
		p.y++;
	}
	if (id == 0)
		play_sfx(env->map, randomy(ID_SFX_TEAR_1, ID_SFX_TEAR_2));
}

void	print_tear(t_env *env, t_map *map)
{
	map->id = map->board[map->block.x][map->block.y];
	if (map->ns_or_ew == 0)
		map->perp = (map->block.x - map->pos.x +
				(1 - map->step.x) / 2) / map->ray_dir.x;
	else
		map->perp = (map->block.y - map->pos.y +
				(1 - map->step.y) / 2) / map->ray_dir.y;
	map->tear_scale = ((int)map->perp >= 10) ? SCALE_TEAR :
		(10 - (int)map->perp) * SCALE_TEAR;
	map->tear_pos.x = env->w / 2 - (TS * map->tear_scale) / 2;
	map->tear_pos.y = env->h / 2 - (TS * map->tear_scale) / 2;
	print_mini_tear(env, map->anim[A_TEAR].frames, map->tear_pos,
			map->tear_scale);
	if (!map->check_hit)
	{
		is_destroyed(env, map->id);
		map->check_hit = 1;
	}
}

void	dda_tear(t_map *map)
{
	map->hit = 0;
	while (!map->hit)
	{
		if (map->side.x < map->side.y)
		{
			map->side.x += map->delta.x;
			map->block.x += map->step.x;
			map->ns_or_ew = 0;
		}
		else
		{
			map->side.y += map->delta.y;
			map->block.y += map->step.y;
			map->ns_or_ew = 1;
		}
		if (is_tear_obstacle(map->board[map->block.x][map->block.y]))
			map->hit = 1;
	}
}

void	dda_values_tear(t_map *map)
{
	if (map->ray_dir.x < 0)
	{
		map->step.x = -1;
		map->side.x = (map->pos.x - map->block.x) * map->delta.x;
	}
	else
	{
		map->step.x = 1;
		map->side.x = (map->block.x + 1.0 - map->pos.x) * map->delta.x;
	}
	if (map->ray_dir.y < 0)
	{
		map->step.y = -1;
		map->side.y = (map->pos.y - map->block.y) * map->delta.y;
	}
	else
	{
		map->step.y = 1;
		map->side.y = (map->block.y + 1.0 - map->pos.y) * map->delta.y;
	}
}

void	shoot_tear(t_env *env, t_map *map)
{
	map->camera_x = 2 * (env->w / 2) / (double)env->w - 1;
	map->ray_dir.x = map->dir.x + map->plane.x * map->camera_x;
	map->ray_dir.y = map->dir.y + map->plane.y * map->camera_x;
	map->block = (t_coord) {.x = map->pos.x, .y = map->pos.y};
	map->delta.x = fabs(1 / map->ray_dir.x);
	map->delta.y = fabs(1 / map->ray_dir.y);
	dda_values_tear(map);
	dda_tear(map);
	print_tear(env, map);
}
