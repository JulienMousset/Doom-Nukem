/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:24:13 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/03 18:56:44 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		count_columns(char *s)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		while (s[i] && s[i] != ' ')
		{
			res++;
			i++;
		}
	}
	return (res);
}

int		count_lines(t_map *map, char *file)
{
	int		read;
	int		fd;
	int		i;
	int		previous;

	i = 0;
	previous = -1;
	fd = open(file, O_RDONLY);
	while ((read = get_next_line(fd, &map->line)))
	{
		if (i >= 1)
		{
			map->nb_columns = count_columns(map->line);
			if ((previous != -1 && previous != map->nb_columns))
			{
				ft_memdel((void **)&(map->line));
				return (0);
			}
			previous = map->nb_columns;
		}
		i++;
		ft_memdel((void **)&(map->line));
	}
	close(fd);
	return (i - 1);
}

int		check_map(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (is_valid(s, i))
			i++;
		else
			return (0);
	}
	return (1);
}

int		check_file(t_env *env, char *file)
{
	int		read;
	int		fd;
	int		first;

	first = 0;
	if ((fd = open(file, O_DIRECTORY)) != -1
	|| (fd = open(file, O_RDONLY)) == -1)
		exit_program(env, ERR_DIR);
	close(fd);
	fd = open(file, O_RDONLY);
	while ((read = get_next_line(fd, &env->map->line)))
	{
		if (!(check_map(env->map->line)) ||
		(first == 0 && !is_valid_first_line(env->map, env->map->line, &first)))
		{
			ft_memdel((void **)&(env->map->line));
			return (0);
		}
		ft_memdel((void **)&(env->map->line));
	}
	close(fd);
	return (1);
}

int		parsing(t_env *env, char *file)
{
	int		fd;

	if (!(check_file(env, file)))
		exit_program(env, ERR_WRONG);
	if (!(env->map->nb_lines = count_lines(env->map, file)))
		exit_program(env, ERR_LINE);
	env->ed.nb_lines_bcpy = env->map->nb_lines;
	if (!(env->map->board = (char **)malloc(sizeof(char *) *
					(env->map->nb_lines))))
		return (0);
	fd = open(file, O_RDONLY);
	if (!(fill_board(env, fd)))
		exit_program(env, ERR_BOARD);
	close(fd);
	if (!(check_board(env->map)))
		exit_program(env, ERR_BORDER);
	if (!(env->map->board_cpy = board_cpy(env->map->board,
					env->map->nb_lines, env->map->nb_columns)))
		exit_program(env, ERR_MALLOC);
	return (1);
}
