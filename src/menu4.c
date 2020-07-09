/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 22:25:09 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/05 12:38:26 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	resolution_reset_values(t_env *p)
{
	ft_memdel((void **)&(p->map->z_buffer));
	if (!(p->map->z_buffer = (double *)malloc(sizeof(double) * p->w)))
		exit_program(p, ERR_MALLOC);
	p->map->h2 = p->h / 2;
	SDL_FreeSurface(p->surface);
	p->surface = SDL_CreateRGBSurface(0, p->w, p->h, 32, 0, 0, 0, 0);
	set_mmap_values(p, p->map, p->map->opt);
}

void	toggle_fullscreen(t_env *p)
{
	p->fullscreen ^= 1;
	if (p->fullscreen)
	{
		SDL_GetWindowSize(p->win, &p->window_dm.w, &p->window_dm.h);
		SDL_RestoreWindow(p->win);
		SDL_SetWindowSize(p->win, p->desktop_dm.w, p->desktop_dm.h);
		SDL_SetWindowPosition(p->win, SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED);
		SDL_SetWindowFullscreen(p->win, SDL_WINDOW_FULLSCREEN_DESKTOP);
	}
	else
	{
		SDL_SetWindowFullscreen(p->win, 0);
		SDL_SetWindowSize(p->win, p->window_dm.w, p->window_dm.h);
		SDL_SetWindowPosition(p->win, SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED);
	}
	p->w = p->desktop_dm.w;
	p->h = p->desktop_dm.h;
	resolution_reset_values(p);
}

void	change_menu(t_env *p)
{
	if (!p->map->transition && !p->map->menu_transition)
	{
		Mix_HaltMusic();
		play_music(p->map, ID_TITLE);
		p->map->transition = 1;
	}
	if (p->menu == 0)
		p->menu = 1;
	else if (p->menu == 1)
	{
		p->menu = 0;
		Mix_HaltMusic();
		p->map->transition = 0;
	}
	else if (p->menu == 3 || p->menu == 4)
		p->menu = 2;
	else if (p->menu < 10)
		p->menu = 1;
	else if (p->menu == 11 || p->menu == 12 || p->menu == 15
		|| p->menu == 16)
	{
		p->menu = 10;
	}
	else if (p->menu == 13 || p->menu == 14)
		p->menu = 12;
}

int		hover_mouse(t_env *p, SDL_Rect rect)
{
	if (p->event.motion.x > rect.x && p->event.motion.x < rect.x + rect.w
		&& p->event.motion.y > rect.y && p->event.motion.y < rect.y + rect.h)
		return (1);
	else
		return (0);
}

void	change_level(t_env *p)
{
	char *file;

	SDL_Delay(1000);
	if (p->pt.level == 1)
		file = PATH_LEVEL_1;
	else if (p->pt.level == 2)
		file = PATH_LEVEL_2;
	else if (p->pt.level == 3)
		file = PATH_LEVEL_3;
	ft_tabdel(p->map->board, p->map->nb_lines);
	ft_tabdel(p->map->board_cpy, p->map->nb_lines);
	p->map->board = NULL;
	p->map->board_cpy = NULL;
	if (!(parsing(p, file)))
		exit_program(p, ERR_USAGE);
	p->map->level = file;
	reset_game(p, p->map);
	p->map->menu_transition = 0;
	p->pt.prev_menu = 0;
	set_nb_menu(p);
}
