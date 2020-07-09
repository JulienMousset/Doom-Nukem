/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:25:20 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/03 20:20:09 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		choose_color(t_map *map, char id)
{
	int	color;

	color = 0;
	if (id == '1' || id == '2' || id == '3' ||
		id == '=' || id == '>' || id == '?')
		color = MARRON_3;
	else if (id == '4')
		color = DARK_BLUE;
	else if (id == '5')
		color = BOCA90;
	else if (id == '7')
		color = PINK;
	else if (id == '6' || id == '8')
		color = M_BROWN;
	else if (id == '9')
		color = GY;
	else if (id == ':' || id == ';')
		color = GG;
	else if (id == ';')
		color = GR;
	((id == '=' || id == '>' || id == '?') && map->item_xray) ?
		color = ACQUA : 0;
	return (color);
}

void	put_n_pixel(t_env *env, int xx, int yy, char id)
{
	t_map	*map;
	int		color;
	int		x;
	int		y;
	t_coord	coord;

	map = env->map;
	color = (id == 0) ? MARBLE : choose_color(env->map, id);
	xx *= map->mm_block_size;
	yy *= map->mm_block_size;
	coord.x = map->mm_center.x - map->mm_vis / 2 * map->mm_block_size;
	coord.y = map->mm_center.y - map->mm_vis / 2 * map->mm_block_size;
	y = -1;
	while (++y < map->mm_block_size)
	{
		x = -1;
		while (++x < map->mm_block_size)
		{
			if (((coord.x + x + xx < map->mm_end.x) && (coord.x + x +
							xx > map->mm_start.x)) &&
					((coord.y + y + yy < map->mm_end.y) && (coord.y + y +
						yy > map->mm_start.y)))
				put_pixel(env, coord.x + x + xx, coord.y + y + yy, color);
		}
	}
}

void	draw_mini_background(t_env *env, t_map *map)
{
	int		block;
	int		x;
	int		y;
	int		color;

	block = map->mm_block_size;
	y = -1;
	while (++y < map->mm_size)
	{
		x = -1;
		while (++x < map->mm_size)
		{
			color = MARRON_0;
			if (y < block)
				color = north(env->map, x);
			if (y > map->mm_size - block)
				color = south(env->map, x);
			if (x < block)
				color = west(env->map, y);
			if (x > map->mm_size - block)
				color = east(env->map, y);
			put_pixel(env, map->mm_start.x + x, map->mm_start.y + y, color);
		}
	}
}

void	draw_minimap(t_env *env, t_map *map)
{
	int		x;
	int		y;
	t_coord	c;

	draw_mini_background(env, map);
	c.x = map->pos.y - map->mm_vis / 2;
	c.y = map->pos.x - map->mm_vis / 2;
	y = 0;
	while (y < map->mm_vis)
	{
		x = 0;
		while (x < map->mm_vis)
		{
			if ((c.x + x >= 0) && (c.x + x < map->nb_columns) &&
					(c.y + y >= 0) && (c.y + y < map->nb_lines) &&
					map->board[c.y + y][c.x + x] >= FIRST_WALL &&
					map->board[c.y + y][c.x + x] <= LAST_WALL)
				put_n_pixel(env, x, y, map->board[c.y + y][c.x + x]);
			if (c.x + x == (int)map->pos.y && c.y + y == (int)map->pos.x)
				put_n_pixel(env, x, y, 0);
			x++;
		}
		y++;
	}
}
