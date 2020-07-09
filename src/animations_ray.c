/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 19:59:49 by julien            #+#    #+#             */
/*   Updated: 2020/05/25 19:59:52 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	open_door_animation(t_env *env, t_thread *th)
{
	th->color = get_pixel(env->doors[th->id - 6]
			[env->map->anim[A_DOORS].frames], th->tex.x, th->tex.y);
}

void	beggar_animation(t_env *env, t_thread *th)
{
	th->color = get_pixel(env->beggars[env->map->id - 54]
			[env->map->anim[A_BEGGAR].frames], th->tex.x, th->tex.y);
}

void	cardinal_animation(t_env *env, t_map *map, t_thread *th)
{
	if (round(map->dir.x) == -1 && round(map->dir.y) == 0)
		th->color = get_pixel(env->trophy[0], th->tex.x, th->tex.y);
	else if (round(map->dir.x) == 1 && round(map->dir.y) == 0)
		th->color = get_pixel(env->trophy[1], th->tex.x, th->tex.y);
	else
		th->color = get_pixel(env->trophy[2], th->tex.x, th->tex.y);
}

void	explosion_animation(t_env *env, t_thread *t)
{
	int	id;

	id = (env->map->id == ID_TNT - 49) ? 0 : 1;
	t->color = get_pixel(env->explosions[id][env->map->anim[A_BARREL].frames],
			t->tex.x, t->tex.y);
}
