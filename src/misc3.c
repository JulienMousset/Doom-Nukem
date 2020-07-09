/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:53:51 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/03 19:04:15 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	set_line_values(t_thread *t)
{
	int lh2;

	lh2 = t->line_height / 2;
	t->line_dif = lh2 * t->env->map->jump;
	t->line_start = lh2 + t->line_dif;
	t->line_end = lh2 - t->line_dif;
	if (t->line_start < 0)
		t->line_start = 0;
	if (t->line_end < 0)
		t->line_end = 0;
	if (t->line_start > t->line_height)
		t->line_start = t->line_height;
	if (t->line_end > t->line_height)
		t->line_end = t->line_height;
}

void	reset_mouse(t_env *env)
{
	SDL_WarpMouseInWindow(env->win, env->w / 2, env->h / 2);
}

void	set_level_id(t_map *map)
{
	if (map->lvl == 2)
	{
		map->fac.x = ID_FLOOR2;
		map->fac.y = ID_CEILING2;
	}
	else if (map->lvl == 3)
	{
		map->fac.x = ID_FLOOR3;
		map->fac.y = ID_CEILING3;
	}
	else
	{
		map->fac.x = ID_FLOOR1;
		map->fac.y = ID_CEILING1;
	}
}

int		query_hp(t_map *map, int x, int y, int damage)
{
	int	i;

	i = -1;
	while (++i < map->nb_sprites)
	{
		if (map->s[i].x == x + 0.5 && map->s[i].y == y + 0.5)
		{
			if (damage == 1)
				map->s[i].hp -= (map->item_cricket) ? 2 : 1;
			break ;
		}
	}
	if (map->s[i].hp < 0)
		map->s[i].hp = 0;
	return (map->s[i].hp);
}

void	level_processing(t_env *env)
{
	char *file;

	if (!ft_strcmp(env->map->level, "maps/level_1"))
		file = PATH_LEVEL_2;
	else if (!ft_strcmp(env->map->level, "maps/level_2"))
		file = PATH_LEVEL_3;
	else if (!ft_strcmp(env->map->level, "maps/level_3"))
		file = PATH_LEVEL_3;
	else
		file = PATH_LEVEL_0;
	ft_tabdel(env->map->board, env->map->nb_lines);
	ft_tabdel(env->map->board_cpy, env->map->nb_lines);
	if (!(parsing(env, file)))
		exit_program(env, ERR_USAGE);
	env->map->level = file;
	reset_game(env, env->map);
	env->map->menu_transition = 0;
}
