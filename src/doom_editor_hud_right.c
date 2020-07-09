/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_editor_hud_right.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 20:01:38 by julien            #+#    #+#             */
/*   Updated: 2020/05/25 20:01:39 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		e_draw_right_hud_special(t_env *e)
{
	SDL_Rect	rect_block;

	rect_block = (SDL_Rect){e->screen.w - ED_HUD_RIGHT_SIZE - 262,
		e->screen.h - ED_HUD_BOTTOM_SIZE + 12, 80, 80};
	SDL_RenderCopy(e->rend, e->ed.tex['q' - '1'], 0, &rect_block);
	if (e_hover_mouse_blk(e, rect_block, 1))
	{
		SDL_SetRenderDrawColor(e->rend, 255, 255, 255, 100);
		SDL_RenderFillRect(e->rend, &rect_block);
		e_funcpoint(e, 'q', (SDL_Point){-1, -1});
	}
	rect_block = (SDL_Rect){e->screen.w - ED_HUD_RIGHT_SIZE - 175,
		e->screen.h - ED_HUD_BOTTOM_SIZE + 12, 80, 80};
	SDL_RenderCopy(e->rend, e->ed.tex[FIRST_INTER - '1'], 0, &rect_block);
	if (e_hover_mouse_blk(e, rect_block, 1))
	{
		SDL_SetRenderDrawColor(e->rend, 255, 255, 255, 100);
		SDL_RenderFillRect(e->rend, &rect_block);
		e_funcpoint(e, FIRST_INTER, (SDL_Point){-1, -1});
	}
}

void		e_draw_right_hud_block(t_env *e, SDL_Point baseline,
		int count, int *hudcount)
{
	SDL_Rect	rect_block;
	SDL_Rect	rect_block_hover;

	SDL_SetRenderDrawColor(e->rend, 0, 0, 0, 200);
	if (is_zoomable(count))
		rect_block = e_drhb_zoom(baseline, hudcount);
	else
		rect_block = e_drhb_not_zoom(baseline, hudcount);
	rect_block_hover = (SDL_Rect){baseline.y + (*hudcount % ED_HUD_ITEM_PER_ROW)
		* ED_HUD_ITEM_SIZE, *hudcount / ED_HUD_ITEM_PER_ROW
			* ED_HUD_ITEM_SIZE, ED_HUD_ITEM_SIZE, ED_HUD_ITEM_SIZE};
	SDL_RenderCopy(e->rend, e->ed.tex[count - '1'], 0, &rect_block);
	if (count >= LAST_SOLID_WALL + 8 && count <= LAST_WALL)
	{
		SDL_SetRenderDrawColor(e->rend, 255, 255, 255, 42);
		SDL_RenderFillRect(e->rend, &rect_block);
	}
	if (e_hover_mouse_blk(e, rect_block_hover, 1))
	{
		SDL_SetRenderDrawColor(e->rend, 255, 255, 255, 100);
		SDL_RenderFillRect(e->rend, &rect_block_hover);
		e_funcpoint(e, count, (SDL_Point){-1, -1});
	}
	*hudcount += 1;
}

void		e_draw_right_hud_countfor(t_env *e, int first,
		int last, int *hudcount)
{
	SDL_Point	baseline;

	baseline = (SDL_Point){e->screen.h, e->screen.w - ED_HUD_RIGHT_SIZE};
	while (first <= last)
		e_draw_right_hud_block(e, baseline, first++, hudcount);
}

void		e_draw_right_hud_elements(t_env *e, int *hudcount,
		SDL_Point baseline)
{
	jump_hud(e, hudcount, 17);
	jump_hud(e, hudcount, 10);
	e_draw_right_hud_countfor(e, FIRST_WALL, LAST_WALL, hudcount);
	jump_hud(e, hudcount, 11);
	e_draw_right_hud_countfor(e, FIRST_SHOP_99, LAST_SHOP_99, hudcount);
	jump_hud(e, hudcount, 12);
	e_draw_right_hud_countfor(e, FIRST_SHOP_15, LAST_SHOP_15, hudcount);
	jump_hud(e, hudcount, 13);
	e_draw_right_hud_countfor(e, FIRST_SHOP_5, LAST_SHOP_5, hudcount);
	jump_hud(e, hudcount, 14);
	e_draw_right_hud_countfor(e, FIRST_SPR, FIRST_SPR + 1, hudcount);
	e_draw_right_hud_countfor(e, FIRST_FREE, LAST_FREE, hudcount);
	jump_hud(e, hudcount, 15);
	e_draw_right_hud_countfor(e, FIRST_SOLID, LAST_SOLID, hudcount);
	e_draw_right_hud_block(e, baseline, LAST_WALK, hudcount);
	jump_hud(e, hudcount, 16);
	e_draw_right_hud_countfor(e, FIRST_INTER + 1, LAST_INTER, hudcount);
	e_draw_right_hud_special(e);
}

void		e_draw_right_hud(t_env *e)
{
	SDL_Rect	rect;
	SDL_Point	baseline;
	int			hudcount;

	baseline = (SDL_Point){e->screen.h, e->screen.w - ED_HUD_RIGHT_SIZE};
	SDL_SetRenderDrawColor(e->rend, 0, 0, 0, 200);
	rect = (SDL_Rect){baseline.y, 0, ED_HUD_RIGHT_SIZE, baseline.x};
	SDL_RenderFillRect(e->rend, &rect);
	hudcount = 0;
	e_draw_right_hud_elements(e, &hudcount, baseline);
}
