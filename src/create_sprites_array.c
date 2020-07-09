/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprites_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:26:10 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/03 20:48:46 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		realloc_array(t_env *env, int x, int y, int id)
{
	t_sprite	*new;
	int			i;
	int			j;

	if (!(new = (t_sprite *)malloc(sizeof(t_sprite)
	* env->map->nb_sprites - 1)))
		exit_program(env, ERR_MALLOC);
	i = 0;
	j = 0;
	while (i + j < env->map->nb_sprites)
	{
		if ((env->map->s[i].x == x + 0.5 && env->map->s[i].y == y + 0.5) && !j)
		{
			(id >= 0) ? gain_item(env->map, id) : 0;
			env->map->board[x][y] = '0';
			j++;
		}
		new[i] = env->map->s[i + j];
		i++;
	}
	env->map->nb_sprites--;
	ft_memdel((void **)&(env->map->s));
	env->map->s = new;
}

t_sprite	add_sprite(t_map *map, double x, double y, int i)
{
	t_sprite	new;

	new.x = x + 0.5;
	new.y = y + 0.5;
	new.hp = is_enemy_id(i) ? 6 : 3;
	new.ticks_move = 0;
	new.ticks_attack = 0;
	new.old_pos = (t_coord) {0, 0};
	if (i == ID_WIZOOB)
		set_wizoob_area(map, &new, x, y);
	if (i == ID_HEART_SHOP)
		new.i = ID_RHEART - 49;
	else if (i == ID_KEY_SHOP)
		new.i = ID_KEY - 49;
	else
		new.i = i - 49;
	return (new);
}

void		alloc_arrays(t_env *env)
{
	if (!(env->map->s = (t_sprite *)malloc(sizeof(t_sprite)
	* env->map->nb_sprites)))
		exit_program(env, ERR_MALLOC);
	if (!(env->map->spr_order = (int *)malloc(sizeof(int)
	* env->map->nb_sprites)))
		exit_program(env, ERR_MALLOC);
	if (!(env->map->spr_dist = (double *)malloc(sizeof(double)
	* env->map->nb_sprites)))
		exit_program(env, ERR_MALLOC);
}

int			nb_sprites(t_map *map)
{
	int		y;
	int		x;
	int		i;

	i = 0;
	y = 0;
	while (y < map->nb_lines)
	{
		x = 0;
		while (x < map->nb_columns)
		{
			if (map->board[y][x] >= FIRST_SPR)
				i++;
			if (map->board[y][x] == ID_LEVER_OFF)
				map->nb_lever++;
			x++;
		}
		y++;
	}
	if (map->nb_lever == 0)
		open_lever_doors(map);
	return (i);
}

void		create_sprites_array(t_env *env)
{
	int		y;
	int		x;
	int		i;

	env->map->nb_sprites = nb_sprites(env->map);
	alloc_arrays(env);
	i = 0;
	y = 0;
	while (y < env->map->nb_lines)
	{
		x = 0;
		while (x < env->map->nb_columns)
		{
			if (env->map->board[y][x] >= FIRST_SPR)
			{
				env->map->s[i] = add_sprite(env->map, y, x,
				env->map->board[y][x]);
				i++;
			}
			x++;
		}
		y++;
	}
}
