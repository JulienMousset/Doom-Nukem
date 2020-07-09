/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_editor_keycmds_other.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 20:03:06 by julien            #+#    #+#             */
/*   Updated: 2020/06/03 20:55:46 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	e_save(t_env *e)
{
	if (e_save_map(e))
		e_write_map(e);
}

int		e_save_map(t_env *e)
{
	e->ed.info_opacity = 255;
	if (!e_mapcheck(e))
	{
		display_info(e, 8);
		return (0);
	}
	display_info(e, 9);
	return (1);
}

void	e_write_map(t_env *e)
{
	SDL_Point	pos;
	int			fd;

	pos = (SDL_Point){-1, -1};
	if (!(fd = open(e->map->level, O_WRONLY | O_CREAT | O_TRUNC)))
		exit_program(e, "Failed to save the map.\nExiting safely.\n");
	write_metadata(e, fd);
	while (++pos.y < e->map->nb_lines)
	{
		while (++pos.x < e->map->nb_columns)
		{
			write(fd, &e->map->board[pos.y][pos.x], 1);
			if (pos.x + 1 != e->map->nb_columns)
				write(fd, " ", 1);
		}
		write(fd, "\n", 1);
		pos.x = -1;
	}
	close(fd);
}

void	e_save_and_play(t_env *e)
{
	if (e_save_map(e))
	{
		e_write_map(e);
		e->ed.quit = 2;
	}
}

int		e_mapcheck(t_env *e)
{
	SDL_Point move;

	move = (SDL_Point){-1, 0};
	while (++move.x < e->map->nb_columns)
		if (e_mapcheck_isblock(e->map->board[move.y][move.x]))
			return (0);
	move = (SDL_Point){0, -1};
	while (++move.y < e->map->nb_lines)
		if (e_mapcheck_isblock(e->map->board[move.y][move.x]))
			return (0);
	move = (SDL_Point){-1, e->map->nb_lines - 1};
	while (++move.x < e->map->nb_columns)
		if (e_mapcheck_isblock(e->map->board[move.y][move.x]))
			return (0);
	move = (SDL_Point){e->map->nb_columns - 1, -1};
	while (++move.y < e->map->nb_lines)
		if (e_mapcheck_isblock(e->map->board[move.y][move.x]))
			return (0);
	return (1);
}
