/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_editor_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 20:03:20 by julien            #+#    #+#             */
/*   Updated: 2020/05/29 21:07:37 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

uint32_t	editor_render_hook(uint32_t interval, t_env *e)
{
	SDL_SetRenderDrawColor(e->rend, 41, 44, 57, 255);
	SDL_RenderClear(e->rend);
	e->ed.zoom = e->ed.keys[SDL_SCANCODE_Z]
		&& e->ed.zoom < 700 ? e->ed.zoom + 1 : e->ed.zoom;
	e->ed.zoom = e->ed.keys[SDL_SCANCODE_X]
		&& e->ed.zoom > 50 ? e->ed.zoom - 1 : e->ed.zoom;
	e_offsets(e);
	e_drawquad(e);
	e_draw_bottom_hud(e);
	e_draw_bottom_hud_info(e);
	e_draw_right_hud(e);
	e_pick_block(e);
	e_boolcheck(e, SDL_SCANCODE_Q, &e->ed.ek.b_add_lines, &e_add_lines);
	e_boolcheck(e, SDL_SCANCODE_W, &e->ed.ek.b_rem_lines, &e_rem_lines);
	e_boolcheck(e, SDL_SCANCODE_A, &e->ed.ek.b_add_columns, &e_add_columns);
	e_boolcheck(e, SDL_SCANCODE_S, &e->ed.ek.b_rem_columns, &e_rem_columns);
	e_boolcheck(e, SDL_SCANCODE_D, &e->ed.ek.b_save, &e_save);
	e_boolcheck(e, SDL_SCANCODE_C, &e->ed.ek.b_save, &e_save_and_play);
	e_lvmus_button(e);
	SDL_RenderPresent(e->rend);
	return (e->ed.quit ? 0 : interval);
}
