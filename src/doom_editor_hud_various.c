/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_editor_hud_various.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 20:01:50 by julien            #+#    #+#             */
/*   Updated: 2020/05/25 20:01:52 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

SDL_Rect	e_drhb_zoom(SDL_Point bl, int *hc)
{
	return ((SDL_Rect){bl.y + (*hc % ED_HUD_ITEM_PER_ROW)
			* ED_HUD_ITEM_SIZE - ED_HUD_ITEM_SIZE / 2, *hc / ED_HUD_ITEM_PER_ROW
			* ED_HUD_ITEM_SIZE - ED_HUD_ITEM_SIZE - 5, ED_HUD_ITEM_SIZE
			* 2, ED_HUD_ITEM_SIZE * 2});
}

SDL_Rect	e_drhb_not_zoom(SDL_Point bl, int *hc)
{
	return ((SDL_Rect){bl.y + (*hc % ED_HUD_ITEM_PER_ROW)
			* ED_HUD_ITEM_SIZE, *hc / ED_HUD_ITEM_PER_ROW
			* ED_HUD_ITEM_SIZE, ED_HUD_ITEM_SIZE, ED_HUD_ITEM_SIZE});
}

void		jump_hud(t_env *e, int *hudcount, int txti)
{
	if (*hudcount % ED_HUD_ITEM_PER_ROW == 0)
		*hudcount += ED_HUD_ITEM_PER_ROW;
	else
		*hudcount += ED_HUD_ITEM_PER_ROW + (ED_HUD_ITEM_PER_ROW -
				*hudcount % ED_HUD_ITEM_PER_ROW);
	e->ed.text_tex_size[txti].x = e->screen.w - ED_HUD_RIGHT_SIZE + 17;
	e->ed.text_tex_size[txti].y = (ED_HUD_ITEM_SIZE)
		* (*hudcount / ED_HUD_ITEM_PER_ROW - 1)
		+ (ED_HUD_ITEM_SIZE / 2) - (e->ed.text_tex_size[txti].h) / 2;
	SDL_RenderCopy(e->rend, e->ed.text_tex[txti], 0,
			&e->ed.text_tex_size[txti]);
}

void		e_draw_bottom_hud_info(t_env *e)
{
	SDL_Rect	rect;
	SDL_Point	baseline;

	e->ed.info_opacity -= 3;
	if (e->ed.info_opacity > 0)
	{
		baseline = (SDL_Point){e->screen.h - ED_HUD_BOTTOM_SIZE
			- ED_HUD_BOTTOM_INFO_SIZE, e->screen.w};
		SDL_SetRenderDrawColor(e->rend, 0, 0, 0, e->ed.info_opacity);
		rect = (SDL_Rect){0, baseline.x, baseline.y - ED_HUD_RIGHT_SIZE,
			ED_HUD_BOTTOM_INFO_SIZE};
		SDL_RenderFillRect(e->rend, &rect);
		rect = (SDL_Rect){(e->screen.w - ED_HUD_RIGHT_SIZE) / 2
			- e->ed.text_tex_size[e->ed.info_texindex].w / 2, baseline.x + 6,
				e->ed.text_tex_size[e->ed.info_texindex].w,
				e->ed.text_tex_size[e->ed.info_texindex].h};
		SDL_RenderCopy(e->rend, e->ed.text_tex[e->ed.info_texindex], 0, &rect);
	}
}

void		e_draw_bottom_hud(t_env *e)
{
	SDL_Rect	rect;
	SDL_Point	baseline;
	int			count;

	baseline = (SDL_Point){e->screen.h - ED_HUD_BOTTOM_SIZE, e->screen.w};
	SDL_SetRenderDrawColor(e->rend, 0, 0, 0, 200);
	rect = (SDL_Rect){0, baseline.x, baseline.y - ED_HUD_RIGHT_SIZE,
		ED_HUD_BOTTOM_SIZE};
	SDL_RenderFillRect(e->rend, &rect);
	count = -1;
	while (++count < 10)
	{
		e->ed.text_tex_size[count].x = 20 + (count / 2) * 250;
		e->ed.text_tex_size[count].y = baseline.x + 25 + (count % 2) * 35;
		if (count < 8)
			SDL_RenderCopy(e->rend, e->ed.text_tex[count], 0,
					&e->ed.text_tex_size[count]);
	}
}
