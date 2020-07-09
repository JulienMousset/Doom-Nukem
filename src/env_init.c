/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:09:14 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/05/29 17:15:39 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	env_init(t_env *e)
{
	e->win = NULL;
	e->rend = NULL;
	e->surface = NULL;
	e->map->board = NULL;
	e->map->board_cpy = NULL;
	e->map->tmp = NULL;
	e->map->line = NULL;
	e->map->tnt_lst = NULL;
	e->map->level = NULL;
	e->map->hud_str = NULL;
	e->map->s = NULL;
	e->map->spr_order = NULL;
	e->map->spr_dist = NULL;
	e->map->z_buffer = NULL;
	e->font_path = NULL;
	e->fps_str = NULL;
	e->ft = NULL;
	e->ft_help = NULL;
	e->text = NULL;
	env_init2(e);
}

void	env_init2(t_env *e)
{
	**e->door_paths = NULL;
	*e->panel = NULL;
	*e->story = NULL;
	*e->image = NULL;
	*e->texture = NULL;
	*e->ed.tex = NULL;
	*e->ed.text_tex = NULL;
	*e->map->music = NULL;
	*e->map->sfx = NULL;
	*e->hud = NULL;
	*e->path = NULL;
	*e->t = NULL;
	*e->trophy = NULL;
	**e->cyclic = NULL;
	**e->doors = NULL;
	**e->beggars = NULL;
	**e->tears = NULL;
	**e->explosions = NULL;
	**e->b = NULL;
}
