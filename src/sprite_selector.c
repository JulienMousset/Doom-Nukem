/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_selector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 16:18:32 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/05/07 20:49:34 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		animate_sprite(t_map *map, int index)
{
	return (map->spr_block.x == map->anim[index].block.x &&
			map->spr_block.y == map->anim[index].block.y) ? 1 : 0;
}

void	cyclic_sprites(t_thread *t, t_env *env, t_map *map)
{
	ticks_init(&map->anim[A_CYCLIC].ticks);
	if (map->id == ID_CAMPFIRE - 49)
		t->color = get_pixel(env->cyclic[0][map->anim[A_CYCLIC].frames],
				t->tex.x, t->tex.y);
	else if (map->id == ID_COIN - 49)
		t->color = get_pixel(env->cyclic[1][map->anim[A_CYCLIC].frames],
				t->tex.x, t->tex.y);
	else if (map->id == ID_NICKEL - 49)
		t->color = get_pixel(env->cyclic[2][map->anim[A_CYCLIC].frames],
				t->tex.x, t->tex.y);
}

void	tnt_and_poop(t_thread *t, t_env *env, t_map *map)
{
	int tick;

	tick = query_hp(map, map->spr_block.x, map->spr_block.y, 0);
	if (tick == 3)
		t->color = get_pixel(env->t[map->id], t->tex.x, t->tex.y);
	else if (map->id == ID_TNT - 49)
		t->color = get_pixel(env->b[0][tick - 1], t->tex.x, t->tex.y);
	else
		t->color = get_pixel(env->b[1][tick - 1], t->tex.x, t->tex.y);
}

void	sprite_selector(t_thread *t, t_env *env, t_map *map)
{
	if (animate_sprite(map, A_BEGGAR))
		beggar_animation(env, t);
	else if (animate_sprite(map, A_BARREL))
		explosion_animation(env, t);
	else if ((map->id == ID_BABY1 - 49) &&
			!ticks_passed(&map->s[map->i].ticks_attack, 1))
		t->color = get_pixel(env->t[ID_BABY2], t->tex.x, t->tex.y);
	else if (map->id == ID_TROPHY - 49)
		cardinal_animation(env, env->map, t);
	else if (map->id == ID_TNT - 49 || map->id == ID_POOP - 49)
		tnt_and_poop(t, env, map);
	else if (map->id == ID_CAMPFIRE - 49 || ((map->id == ID_COIN - 49 ||
			map->id == ID_NICKEL - 49) && map->shine_freq == SHINE_FREQ))
		cyclic_sprites(t, env, map);
	else if (map->id == ID_DOPLE - 49)
		t->color = get_pixel(env->t[map->id + map->dople_spr],
				t->tex.x, t->tex.y);
	else if (map->id == ID_WIZOOB - 49)
		t->color = get_pixel(env->t[map->id + map->wiz_spr],
				t->tex.x, t->tex.y);
	else
		t->color = get_pixel(env->t[map->id], t->tex.x, t->tex.y);
	t->color = darken(env, t->color, map->spr_dist[map->i] / 15,
			map->item_candle);
}
