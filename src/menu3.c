/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 21:57:44 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/05/26 16:44:37 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	go_to_editor(t_env *p)
{
	if (p->pt.level == 1)
		p->map->close_requested = 2;
	else if (p->pt.level == 2)
		p->map->close_requested = 3;
	else if (p->pt.level == 3)
		p->map->close_requested = 4;
	else if (p->pt.level == 0)
		p->map->close_requested = 5;
}

void	levels_menu(t_env *p)
{
	p->pt.rect = create_big_menu(p);
	p->pt.level = 1;
	button(p, "Level 1", &change_level, 1);
	p->pt.level = 2;
	button(p, "Level 2", &change_level, 2);
	p->pt.level = 3;
	button(p, "Level 3", &change_level, 3);
}

void	level_editor(t_env *p)
{
	p->pt.rect = create_big_menu(p);
	p->pt.prev_menu = 0;
	p->pt.level = 1;
	button(p, "Level 1", &go_to_editor, 1);
	p->pt.level = 2;
	button(p, "Level 2", &go_to_editor, 2);
	p->pt.level = 3;
	button(p, "Level 3", &go_to_editor, 3);
	p->pt.level = 0;
	button(p, "New level", &go_to_editor, 4);
}

void	set_nb_menu(t_env *p)
{
	p->menu = p->pt.prev_menu;
}

void	start_new_run(t_env *p)
{
	p->pt.level = 1;
	change_level(p);
}
