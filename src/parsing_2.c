/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:24:24 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/04 18:54:08 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		check_board(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->nb_lines)
	{
		j = 0;
		while (j < map->nb_columns)
		{
			if ((i == 0 || j == 0 || i == map->nb_lines - 1 ||
						j == map->nb_columns - 1) && ((map->board[i][j] == '0')
							|| map->board[i][j] > LAST_SOLID_WALL ||
							map->board[i][j] == ID_WALL_GLASS))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		is_valid(char *s, int i)
{
	if ((is_valid_char(s[i]) && ((s[i + 1] == ' ') || s[i + 1] == '\0')) ||
			((s[i] == ' ') && (is_valid_char(s[i + 1]))))
		return (1);
	return (0);
}

void	filling(t_env *env, int i, int *j, int *player)
{
	if (!ft_strcmp(env->map->tmp[*j], "q"))
	{
		(*player)++;
		if (*player > 1)
		{
			ft_arraydel(env->map->tmp);
			ft_memdel((void **)&(env->map->line));
			exit_program_in_tab(env, &i, ERR_PLAYER);
		}
		env->map->board[i][*j] = '0';
		env->map->orig_ppos = (SDL_Point){.x = i, .y = *j};
		env->map->pos_cpy = (t_complex) {.x = i + 0.1, .y = *j + 0.1};
	}
	else if (is_valid_char(env->map->tmp[*j][0]))
		env->map->board[i][*j] = env->map->tmp[*j][0];
	(*j)++;
}

int		fill_board2(t_env *env, int *i, int *j, int *player)
{
	env->map->tmp = ft_strsplit(env->map->line, ' ');
	if (!(env->map->board[*i] = (char *)malloc(sizeof(char)
					* (env->map->nb_columns + 1))))
		return (0);
	*j = 0;
	while (env->map->tmp[*j])
		filling(env, *i, j, player);
	env->map->board[*i][*j] = 0;
	return (1);
}

int		fill_board(t_env *env, int fd)
{
	int		read;
	int		i;
	int		j;
	int		player;
	int		k;

	player = 0;
	i = 0;
	k = 0;
	while ((read = get_next_line(fd, &env->map->line)))
	{
		if (k >= 1)
		{
			if (!fill_board2(env, &i, &j, &player))
				return (0);
			i++;
			ft_arraydel(env->map->tmp);
		}
		k++;
		ft_memdel((void **)&(env->map->line));
	}
	if (player == 0)
		exit_program(env, ERR_NO_PLAYER);
	return (1);
}
