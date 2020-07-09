/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 21:52:34 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/03/12 22:26:02 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

SDL_Rect	create_menu(t_env *p)
{
	int			width;
	int			height;
	SDL_Rect	rectangle;

	if (!p->fullscreen)
		SDL_GetWindowSize(p->win, &p->window_dm.w, &p->window_dm.h);
	width = (p->fullscreen ? p->desktop_dm.w : p->window_dm.w);
	height = (p->fullscreen ? p->desktop_dm.h : p->window_dm.h);
	rectangle = (SDL_Rect){width / 2 - (width * 0.6) / 2, height / 2 - (height
		* 0.7) / 2, width * 0.6, height * 0.7};
	SDL_RenderCopy(p->rend, p->texture[1], NULL, NULL);
	draw_text_rdr(p, "Back: M", (SDL_Point){rectangle.w + 30,
	rectangle.h + 100}, (SDL_Color){81, 66, 49, 255});
	return (rectangle);
}

SDL_Rect	create_big_menu(t_env *p)
{
	SDL_Rect	rectangle;
	int			width;
	int			height;

	if (!p->fullscreen)
		SDL_GetWindowSize(p->win, &p->window_dm.w, &p->window_dm.h);
	width = (p->fullscreen ? p->desktop_dm.w : p->window_dm.w);
	height = (p->fullscreen ? p->desktop_dm.h : p->window_dm.h);
	rectangle = (SDL_Rect){0, 0, width, height};
	SDL_RenderCopy(p->rend, p->texture[0], NULL, NULL);
	SDL_RenderCopy(p->rend, p->texture[2], NULL, NULL);
	draw_text_rdr(p, "Back: M", (SDL_Point){rectangle.w - 170,
			rectangle.h - 20}, (SDL_Color){81, 66, 49, 255});
	return (rectangle);
}

void		change_resol(t_env *p)
{
	if (p->fullscreen)
		toggle_fullscreen(p);
	SDL_SetWindowSize(p->win, p->pt.resol.x, p->pt.resol.y);
	SDL_SetWindowPosition(p->win, SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED);
	p->w = p->pt.resol.x;
	p->h = p->pt.resol.y;
	resolution_reset_values(p);
}

int			ch_resol(t_env *p, int x, int y)
{
	p->pt.resol = (SDL_Point){x, y};
	return (1);
}

void		resolution_menu(t_env *p)
{
	int i;

	i = 0;
	if (p->menu == 3)
		p->pt.rect = create_menu(p);
	else if (p->menu == 13)
		p->pt.rect = create_big_menu(p);
	if (p->desktop_dm.w >= 1024 && p->desktop_dm.h >= 768
		&& ch_resol(p, 1024, 768))
		button(p, "1024x768", &change_resol, ++i);
	if (p->desktop_dm.w >= 1280 && p->desktop_dm.h >= 720
		&& ch_resol(p, 1280, 720))
		button(p, "1280x720", &change_resol, ++i);
	if (p->desktop_dm.w >= 1366 && p->desktop_dm.h >= 768
		&& ch_resol(p, 1366, 768))
		button(p, "1366x768", &change_resol, ++i);
	if (p->desktop_dm.w >= 1600 && p->desktop_dm.h >= 900
		&& ch_resol(p, 1600, 900))
		button(p, "1600x900", &change_resol, ++i);
	if (!p->fullscreen)
		button(p, "Fullscreen", &toggle_fullscreen, ++i);
	else
		button(p, "Window", &toggle_fullscreen, ++i);
}
