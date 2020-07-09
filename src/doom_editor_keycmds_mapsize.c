/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_editor_keycmds_mapsize.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 20:02:51 by julien            #+#    #+#             */
/*   Updated: 2020/06/03 19:14:07 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		e_add_lines(t_env *e)
{
	char		**newboard;
	char		**oldboard;
	SDL_Point	pos;

	if (e->map->nb_lines >= 100)
		return ;
	if (!(newboard = (char **)malloc(sizeof(char *) * e->map->nb_lines + 2)))
		exit_program(e, "Map allocation failed. Exiting safely.\n");
	pos = (SDL_Point){-1, -1};
	while (++pos.y < e->map->nb_lines + 1)
	{
		if (!(newboard[pos.y] = (char *)malloc(sizeof(char) *
						e->map->nb_columns + 1)))
			exit_program(e, "Map allocation failed. Exiting safely.\n");
		while (++pos.x < e->map->nb_columns)
			if (pos.y == e->map->nb_lines)
				newboard[pos.y][pos.x] = '0';
			else
				newboard[pos.y][pos.x] = e->map->board[pos.y][pos.x];
		pos.x = -1;
	}
	oldboard = e->map->board;
	e->map->board = newboard;
	ft_tabdel(oldboard, e->map->nb_lines);
	e->map->nb_lines++;
}

void		e_rem_lines(t_env *e)
{
	char		**newboard;
	char		**oldboard;
	SDL_Point	pos;

	if (e->map->nb_lines <= 4)
		return ;
	if (!(newboard = (char **)malloc(sizeof(char *) * e->map->nb_lines)))
		exit_program(e, "Map allocation failed. Exiting safely.\n");
	pos = (SDL_Point){-1, -1};
	while (++pos.y < e->map->nb_lines)
	{
		if (!(newboard[pos.y] = (char *)malloc(sizeof(char) *
						e->map->nb_columns + 1)))
			exit_program(e, "Map allocation failed. Exiting safely.\n");
		while (++pos.x < e->map->nb_columns)
			newboard[pos.y][pos.x] = e->map->board[pos.y][pos.x];
		pos.x = -1;
	}
	oldboard = e->map->board;
	e->map->board = newboard;
	ft_tabdel(oldboard, e->map->nb_lines);
	e->map->nb_lines--;
}

void		e_add_columns(t_env *e)
{
	char		**newboard;
	char		**oldboard;
	SDL_Point	pos;

	if (e->map->nb_columns >= 100)
		return ;
	if (!(newboard = (char **)malloc(sizeof(char *) * e->map->nb_lines + 1)))
		exit_program(e, "Map allocation failed. Exiting safely.\n");
	pos = (SDL_Point){-1, -1};
	while (++pos.y < e->map->nb_lines)
	{
		if (!(newboard[pos.y] = (char *)malloc(sizeof(char) *
						e->map->nb_columns + 2)))
			exit_program(e, "Map allocation failed. Exiting safely.\n");
		while (++pos.x < e->map->nb_columns)
			newboard[pos.y][pos.x] = e->map->board[pos.y][pos.x];
		newboard[pos.y][pos.x] = '0';
		pos.x = -1;
	}
	oldboard = e->map->board;
	e->map->board = newboard;
	ft_tabdel(oldboard, e->map->nb_lines);
	e->map->nb_columns++;
}

void		e_rem_columns(t_env *e)
{
	char		**newboard;
	char		**oldboard;
	SDL_Point	pos;

	if (e->map->nb_columns <= 4)
		return ;
	if (!(newboard = (char **)malloc(sizeof(char *) * e->map->nb_lines + 1)))
		exit_program(e, "Map allocation failed. Exiting safely.\n");
	pos = (SDL_Point){-1, -1};
	while (++pos.y < e->map->nb_lines)
	{
		if (!(newboard[pos.y] = (char *)malloc(sizeof(char) *
						e->map->nb_columns)))
			exit_program(e, "Map allocation failed. Exiting safely.\n");
		while (++pos.x < e->map->nb_columns)
			newboard[pos.y][pos.x] = e->map->board[pos.y][pos.x];
		pos.x = -1;
	}
	oldboard = e->map->board;
	e->map->board = newboard;
	ft_tabdel(oldboard, e->map->nb_lines);
	e->map->nb_columns--;
}
