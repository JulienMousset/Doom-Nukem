/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 19:41:20 by jmousset          #+#    #+#             */
/*   Updated: 2020/06/03 22:02:19 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	set_walls(t_thread *t, t_map *map, int x_start)
{
	if (t->ns_or_ew == 0)
		t->perp = (t->block.x - map->pos.x +
				(1 - t->step.x) / 2) / t->ray_dir.x;
	else
		t->perp = (t->block.y - map->pos.y +
				(1 - t->step.y) / 2) / t->ray_dir.y;
	t->line_height = (int)(t->env->h / t->perp);
	set_line_values(t);
	t->y_start = -t->line_start + map->h2;
	(t->y_start < 0) ? t->y_start = 0 : 0;
	t->y_end = t->line_end + map->h2;
	(t->y_end >= t->env->h) ? t->y_end = t->env->h - 1 : 0;
	map->z_buffer[x_start] = t->perp;
	t->id = map->board[t->block.x][t->block.y] - 49;
}

void	dda(t_thread *t)
{
	t->hit = 0;
	while (!t->hit)
	{
		if (t->side.x < t->side.y)
		{
			t->side.x += t->delta.x;
			t->block.x += t->step.x;
			t->ns_or_ew = 0;
		}
		else
		{
			t->side.y += t->delta.y;
			t->block.y += t->step.y;
			t->ns_or_ew = 1;
		}
		t->hit = is_hit(t);
		if ((t->hit) && t->saved == 1 && (t->glass_hit == 0))
			t->saved = 2;
		else if ((t->hit) && t->saved == 3 && (t->glass_hit == 0))
			t->saved = 0;
	}
}

void	set_dda_values(t_thread *t, t_map *map)
{
	if (t->ray_dir.x < 0)
	{
		t->step.x = -1;
		t->side.x = (map->pos.x - t->block.x) * t->delta.x;
	}
	else
	{
		t->step.x = 1;
		t->side.x = (t->block.x + 1.0 - map->pos.x) * t->delta.x;
	}
	if (t->ray_dir.y < 0)
	{
		t->step.y = -1;
		t->side.y = (map->pos.y - t->block.y) * t->delta.y;
	}
	else
	{
		t->step.y = 1;
		t->side.y = (t->block.y + 1.0 - map->pos.y) * t->delta.y;
	}
}

void	*ray_casting(void *vt)
{
	t_thread	*t;
	t_map		*map;

	t = (t_thread *)vt;
	map = t->env->map;
	while (t->x_start < t->x_end)
	{
		glass_wall_init(t);
		t->camera_x = 2 * t->x_start / (double)t->env->w - 1;
		t->ray_dir.x = map->dir.x + map->plane.x * t->camera_x;
		t->ray_dir.y = map->dir.y + map->plane.y * t->camera_x;
		t->block = (t_coord) {.x = map->pos.x, .y = map->pos.y};
		t->delta.x = fabs(1 / t->ray_dir.x);
		t->delta.y = fabs(1 / t->ray_dir.y);
		set_dda_values(t, map);
		dda(t);
		set_walls(t, map, t->x_start);
		draw_line(t->env, t, t->x_start, t->y_start);
		floor_and_ceiling(t, t->env, map, t->x_start);
		t->x_start++;
		glass_wall_reset(t);
	}
	return (0);
}

void	image_to_window(t_env *env, t_map *map)
{
	isaac_moves(map);
	animation_manager(env, env->map->anim);
	create_threads(env, FOR_WALLS);
	sprites(env, env->map);
	map->item_map ? draw_minimap(env, env->map) : 0;
	map->bool_tear ? 0 : draw_aim(env);
	map->bool_tear ? shoot_tear(env, env->map) : 0;
	(map->reset_ticks) ? reset_game(env, map) : 0;
	enemies(map);
	set_boundaries(map);
}
