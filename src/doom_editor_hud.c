/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_editor_hud.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 20:01:25 by julien            #+#    #+#             */
/*   Updated: 2020/05/25 20:01:27 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

SDL_Texture	*text2tex(t_env *e, TTF_Font *font, char *text, SDL_Color color)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	if (!(surface = TTF_RenderText_Solid(font, text, color)))
	{
		ft_putendl("Error during font surfacing.");
		ft_putendl("Exiting safely.");
		exit(1);
	}
	if (!(texture = SDL_CreateTextureFromSurface(e->rend, surface)))
	{
		ft_putendl("Error during font texturing.");
		ft_putendl("Exiting safely.");
		SDL_FreeSurface(surface);
		exit(1);
	}
	SDL_FreeSurface(surface);
	return (texture);
}

int			is_zoomable(int block_id)
{
	return ((block_id >= FIRST_FREE && block_id <= LAST_FREE)
			|| (block_id >= FIRST_SOLID && block_id <= LAST_SOLID - 3)
			|| (block_id >= FIRST_SPR && block_id <= FIRST_SPR + 1)
			|| (block_id >= FIRST_SHOP && block_id <= LAST_SHOP)
			|| (block_id >= FIRST_SHOP_5 && block_id <= LAST_SHOP_5));
}

void		e_pick_block(t_env *e)
{
	SDL_Rect	rect_block;

	SDL_SetRenderDrawColor(e->rend, 255, 255, 255, 128);
	SDL_RenderDrawRect(e->rend, &(SDL_Rect){e->screen.w - ED_HUD_RIGHT_SIZE
			- 93, e->screen.h - ED_HUD_BOTTOM_SIZE + 11, 83, 83});
	if (is_zoomable(e->ed.pick_block))
		rect_block = (SDL_Rect){e->screen.w - ED_HUD_RIGHT_SIZE - 115,
			e->screen.h - ED_HUD_BOTTOM_SIZE - 48, 130, 130};
	else
		rect_block = (SDL_Rect){e->screen.w - ED_HUD_RIGHT_SIZE - 92,
			e->screen.h - ED_HUD_BOTTOM_SIZE + 12, 80, 80};
	SDL_RenderCopy(e->rend, e->ed.tex[e->ed.pick_block - '1'], 0, &rect_block);
	if (e->ed.pick_block >= '<' && e->ed.pick_block <= '>')
	{
		SDL_SetRenderDrawColor(e->rend, 255, 255, 255, 42);
		SDL_RenderFillRect(e->rend, &rect_block);
	}
}

void		e_place_unique(t_env *e, SDL_Point coords, int block_id)
{
	SDL_Point	current;

	current = e_check_unique(e, block_id);
	if (current.x != -1)
		e->map->board[current.y][current.x] = '0';
	e->map->board[coords.y][coords.x] = block_id;
}

SDL_Point	e_check_unique(t_env *e, int block_id)
{
	SDL_Point	move;

	move = (SDL_Point){-1, -1};
	while (++move.x < e->map->nb_columns)
	{
		move.y = -1;
		while (++move.y < e->map->nb_lines)
		{
			if (e->map->board[move.y][move.x] == block_id)
				return ((SDL_Point){move.x, move.y});
		}
	}
	return ((SDL_Point){-1, -1});
}
