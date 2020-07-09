/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 21:54:37 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/03/12 22:03:32 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	option_menu(t_env *p)
{
	if (p->menu == 2)
		p->pt.rect = create_menu(p);
	else if (p->menu == 12)
		p->pt.rect = create_big_menu(p);
	p->pt.prev_menu = (p->menu == 2 ? 4 : 14);
	button(p, "Help", &set_nb_menu, 1);
	p->pt.prev_menu = (p->menu == 2 ? 3 : 13);
	button(p, "Change Resolution", &set_nb_menu, 2);
	p->pt.val_sd[3] = p->map->volume_sfx;
	p->map->volume_sfx = slider(p, "Volume SFX", 3);
	p->pt.val_sd[4] = p->map->volume_music;
	p->map->volume_music = slider(p, "Volume Music", 4);
}

void	help_menu(t_env *p)
{
	int i;
	int dec;
	int space;

	i = -1;
	dec = (p->menu == 4 ? 75 : 0);
	space = (p->menu == 4 ? 27 : 32);
	if (p->menu == 4)
		p->pt.rect = create_menu(p);
	else if (p->menu == 14)
		p->pt.rect = create_big_menu(p);
	while (++i < 14)
		draw_text_help(p, (char*[14]){CON_1, CON_2, CON_3, CON_4, CON_5, CON_6,
			CON_7, CON_8, CON_9, CON_10, CON_11, CON_12, CON_13}[i],
			(SDL_Point){p->pt.rect.w / 3 + dec, p->pt.rect.h / 2.9 + i
			* space + dec}, (SDL_Color){124, 100, 74, 255});
}

void	main_menu(t_env *p)
{
	if (!p->map->transition && !p->map->menu_transition)
	{
		play_music(p->map, ID_TITLE);
		p->map->transition = 0;
		p->map->menu_transition = 1;
	}
	if (!p->menu)
		reset_game(p, p->map);
	p->pt.rect = create_big_menu(p);
	button(p, "New Run", &start_new_run, 1);
	p->pt.prev_menu = 11;
	button(p, "Level", &set_nb_menu, 2);
	p->pt.prev_menu = 16;
	button(p, "Editor", &set_nb_menu, 3);
	p->pt.prev_menu = 12;
	button(p, "Options", &set_nb_menu, 4);
	p->pt.prev_menu = 15;
	button(p, "Credits", &set_nb_menu, 5);
}

void	intro_menu(t_env *p)
{
	if (p->menu == 0 && p->map->transition && !p->map->bool_win)
	{
		p->map->intro_transition = 0;
		Mix_HaltMusic();
		p->map->transition = 0;
	}
	if (p->menu == 0 && p->map->menu_transition)
	{
		if (!p->map->intro)
			Mix_HaltMusic();
		p->map->menu_transition = 0;
	}
}

void	display_menu(t_env *p)
{
	intro_menu(p);
	if (p->menu == 1)
	{
		p->pt.rect = create_menu(p);
		p->pt.prev_menu = 2;
		button(p, "Options", &set_nb_menu, 1);
		p->pt.prev_menu = 10;
		button(p, "Exit", &set_nb_menu, 3);
		button(p, "Resume game", &change_menu, 2);
	}
	else if (p->menu == 2 || p->menu == 12)
		option_menu(p);
	else if (p->menu == 3 || p->menu == 13)
		resolution_menu(p);
	else if (p->menu == 4 || p->menu == 14)
		help_menu(p);
	else if (p->menu == 10)
		main_menu(p);
	else if (p->menu == 11)
		levels_menu(p);
	else if (p->menu == 15)
		credits(p);
	else if (p->menu == 16)
		level_editor(p);
}
