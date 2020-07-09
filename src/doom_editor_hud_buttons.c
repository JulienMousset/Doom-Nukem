/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_editor_hud_buttons.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 20:01:11 by julien            #+#    #+#             */
/*   Updated: 2020/05/29 20:09:32 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		write_metadata(t_env *e, int fd)
{
	char	a;
	char	b;

	a = e->map->lvl + '0';
	b = e->map->lvl_music + '0';
	write(fd, &a, 1);
	write(fd, " ", 1);
	write(fd, &b, 1);
	write(fd, "\n", 1);
}

void		e_lvmus_button(t_env *e)
{
	SDL_Rect	v;
	SDL_Rect	w;

	v = (SDL_Rect){e->screen.w - 100, 0, 50, 50};
	SDL_RenderCopy(e->rend, e->ed.tex[e->map->lvl - 1], 0, &v);
	if (e_hover_mouse_blk(e, v, 1))
	{
		SDL_SetRenderDrawColor(e->rend, 255, 255, 255, 100);
		SDL_RenderFillRect(e->rend, &v);
		e_lvmus_click(e, 1);
	}
	w = (SDL_Rect){e->screen.w - 50, 0, 50, 50};
	SDL_RenderCopy(e->rend, e->ed.tex[e->map->lvl_music - 1], 0, &w);
	if (e_hover_mouse_blk(e, w, 1))
	{
		SDL_SetRenderDrawColor(e->rend, 255, 255, 255, 100);
		SDL_RenderFillRect(e->rend, &w);
		e_lvmus_click(e, 0);
	}
}

void		e_lvmus_click(t_env *e, int map_or_music)
{
	if (e->ed.mouse_click.x)
	{
		if (!e->ed.ek.b_lvmus)
		{
			e->ed.ek.b_lvmus = 1;
			if (map_or_music)
				e->map->lvl = 1 + ((e->map->lvl + 1) % 3);
			else
				e->map->lvl_music = 1 + ((e->map->lvl_music + 1) % 3);
		}
	}
	else
		e->ed.ek.b_lvmus = 0;
}
