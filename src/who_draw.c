/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 12:34:00 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/05/01 18:59:35 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		is_bluish(t_map *map, int id)
{
	return (((id == ID_CDOOR - 49 && map->item_mantle == 1) ||
		((id == ID_SECRET1 - 49 || id == ID_SECRET2 - 49 ||
		id == ID_SECRET3 - 49) &&
		map->item_xray == 1)) ? 1 : 0);
}

int		is_orientation(t_thread *t)
{
	int			ns;
	t_coord		poster;

	ns = t->ns_or_ew;
	poster = t->env->map->poster_or;
	if (ns == 0 && (ns == poster.x))
	{
		if ((t->step.x < 0 && poster.y < 0) ||
				(t->step.x >= 0 && poster.y >= 0))
			return (1);
	}
	else if (ns == 1 && (ns == poster.x))
	{
		if ((t->step.y < 0 && poster.y < 0) ||
				(t->step.y >= 0 && poster.y >= 0))
			return (1);
	}
	return (0);
}

int		is_poster(t_thread *t)
{
	if (ticks_passed(&t->env->map->poster_ticks, 1))
	{
		ticks_reset(&t->env->map->poster_ticks);
		t->env->map->poster_id = (t->env->map->poster_id == ID_POSTER1) ?
			ID_POSTER2 : ID_POSTER1;
	}
	if ((t->block.x == t->env->map->poster_pos.x &&
				t->block.y == t->env->map->poster_pos.y))
	{
		if (is_orientation(t))
			return (1);
	}
	return (0);
}

int		is_animation(t_thread *t)
{
	return ((t->block.x == t->env->map->anim[A_DOORS].block.x &&
				t->block.y == t->env->map->anim[A_DOORS].block.y)) ? 1 : 0;
}

int		is_shop(t_map *map, int id, int coin)
{
	return (((id >= FIRST_SHOP_99 && id <= LAST_SHOP_99 && coin >= 99) ||
				(id >= FIRST_SHOP_15 && id <= LAST_SHOP_15 && coin >= 15) ||
				(((id == ID_HEART_SHOP && map->pick_heart < map->container * 2)
				|| id == ID_KEY_SHOP) && coin >= 5)) ? 1 : 0);
}
