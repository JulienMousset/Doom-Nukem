/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_editor_map_quad.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 20:03:35 by julien            #+#    #+#             */
/*   Updated: 2020/05/25 20:03:36 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		e_boolcheck(t_env *e, int sdl_scancode,
		int *b_check, void (*b_func)(t_env *))
{
	if (e->ed.keys[sdl_scancode])
	{
		if (*b_check == 0 && (*b_check = 1))
			b_func(e);
	}
	else
		*b_check = 0;
}

void		e_funcpoint(t_env *e, int block_id, SDL_Point coords)
{
	if (block_id != '0' && ((e->ed.keys[SDL_SCANCODE_E])
				|| ((e->ed.mouse_click.x && e->ed.mouse.x >= e->screen.w
						- ED_HUD_RIGHT_SIZE))
				|| (e->ed.mouse_click.x && e->ed.mouse.y >= e->screen.h
					- ED_HUD_BOTTOM_SIZE)))
		e->ed.pick_block = block_id;
	else if (coords.y >= 0 && coords.x >= 0 && e->ed.mouse_click.x
			&& e->map->board[coords.y][coords.x] != 'q'
			&& e->map->board[coords.y][coords.x] != 'b')
	{
		if (e->ed.pick_block == 'q' || e->ed.pick_block == 'b')
			e_place_unique(e, coords, e->ed.pick_block);
		else
			e->map->board[coords.y][coords.x] = e->ed.pick_block;
	}
	else if (coords.y >= 0 && coords.x >= 0 && e->ed.mouse_click.y
			&& e->map->board[coords.y][coords.x] != 'q'
			&& e->map->board[coords.y][coords.x] != 'b')
		e->map->board[coords.y][coords.x] = '0';
}

int			e_hover_mouse_blk(t_env *e, SDL_Rect rect, int is_hud)
{
	if (e->ed.mouse.x > rect.x && e->ed.mouse.x < rect.x + rect.w
			&& e->ed.mouse.y > rect.y && e->ed.mouse.y < rect.y + rect.h)
	{
		if (is_hud || e->ed.mouse.x < e->screen.w - ED_HUD_RIGHT_SIZE)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

void		e_drawsquare(t_env *e, SDL_Point pos, SDL_Point qc)
{
	SDL_Rect rect;

	rect = (SDL_Rect){qc.x + e->ed.offset.x, qc.y + e->ed.offset.y,
		e->ed.zoom * 0.1, e->ed.zoom * 0.1};
	SDL_RenderDrawRect(e->rend, &rect);
	SDL_SetRenderDrawColor(e->rend, 170, 110, 66, 255);
	SDL_RenderFillRect(e->rend, &rect);
	if (e->map->board[pos.y][pos.x] != '0')
		SDL_RenderCopy(e->rend, e->ed.tex[e->map->board[pos.y][pos.x] - '1'],
				0, &rect);
	if (e->map->board[pos.y][pos.x] >= LAST_SOLID_WALL + 8
			&& e->map->board[pos.y][pos.x] <= LAST_WALL)
	{
		SDL_SetRenderDrawColor(e->rend, 170, 110, 66, 72);
		SDL_RenderFillRect(e->rend, &rect);
	}
	if (e_hover_mouse_blk(e, rect, 0))
	{
		SDL_SetRenderDrawColor(e->rend, 255, 255, 255, 100);
		SDL_RenderFillRect(e->rend, &rect);
		e_funcpoint(e, e->map->board[pos.y][pos.x], pos);
	}
}

void		e_drawquad(t_env *e)
{
	SDL_Point	window_size;
	SDL_Point	qmv;
	SDL_Point	qc;

	SDL_GetWindowSize(e->win, &window_size.x, &window_size.y);
	qmv = (SDL_Point){0, 0};
	while (qmv.x < e->map->nb_columns
			&& (qc.x = qmv.x * e->ed.zoom * 0.1 - qmv.x)
			< window_size.x - e->ed.offset.x)
	{
		qc.x = qmv.x * e->ed.zoom * 0.1 - qmv.x;
		qmv.y = 0;
		while (qmv.y < e->map->nb_lines
				&& (qc.y = qmv.y * e->ed.zoom * 0.1 - qmv.y)
				< window_size.y + e->ed.zoom * 0.1 - e->ed.offset.y)
		{
			qc.y = qmv.y * e->ed.zoom * 0.1 - qmv.y;
			e_drawsquare(e, qmv, qc);
			qmv.y++;
		}
		qmv.x++;
	}
}
