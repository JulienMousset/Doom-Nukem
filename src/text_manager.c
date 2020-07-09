/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:13:50 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/03 19:16:00 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		show_gamble_text(t_map *map, int id)
{
	return (((id == ID_BEGGAR_COIN && map->pick_coin > 0) ||
				(id == ID_BEGGAR_KEY && map->pick_key > 0) ||
				(id == ID_BEGGAR_HEART) ||
				(id == ID_BLOOD_MACHINE)) &&
			(is_not_busy(map->anim[A_BEGGAR])));
}

void	get_sprite_text(t_env *env, int id)
{
	t_coord	c;

	c = (t_coord) {.x = env->w / 2 - 100, .y = env->h / 2 - 125};
	if (id == ID_LEVER_OFF)
		draw_text(env, PRESS2, c.x - 75, c.y);
	else if (id == ID_ERROR)
	{
		draw_text(env, QUOTE1_1, c.x - 75, c.y);
		draw_text(env, QUOTE1_2, c.x - 65, c.y + 20);
	}
	else if (id == ID_GUPPY)
	{
		draw_text(env, QUOTE2_1, c.x + 40, c.y);
		draw_text(env, QUOTE2_2, c.x, c.y + 20);
	}
	else if (id == ID_HANGING)
	{
		draw_text(env, QUOTE3_1, c.x - 100, c.y);
		draw_text(env, QUOTE3_2, c.x - 40, c.y + 20);
	}
	else if (show_gamble_text(env->map, id))
		draw_text(env, PRESS, c.x + 20, c.y + 400);
}

void	get_shop_text(t_env *env, t_map *map, char **board)
{
	t_coord	c;
	int		id;

	c = (t_coord) {.x = env->w / 2 - 100, .y = env->h / 2};
	id = board[(int)map->pos.x][(int)map->pos.y];
	if ((id >= FIRST_SHOP_99 && id <= LAST_SHOP_99 && map->pick_coin < 99) ||
			(id >= FIRST_SHOP_15 && id <= LAST_SHOP_15 && map->pick_coin < 15)
			|| (id >= ID_HEART_SHOP && id <= ID_KEY_SHOP && map->pick_coin < 5))
		draw_text(env, POOR, c.x, c.y);
	else if (id == ID_HEART_SHOP && map->pick_heart == map->container * 2)
		draw_text(env, FULL_HEALTH, c.x, c.y);
}

void	get_hud_text(t_env *env, t_map *map)
{
	t_coord	c;
	int		margin;

	margin = 40;
	if (env->h <= 720)
		c = (t_coord) {.x = 60, .y = 90};
	else if (env->h > 720 && env->h <= 768)
		c = (t_coord) {.x = 60, .y = 100};
	else if (env->h > 768 && env->h <= 900)
		c = (t_coord) {.x = 70, .y = 140};
	else if (env->h > 900 && env->h <= 1080)
		c = (t_coord) {.x = 80, .y = 190};
	else
		c = (t_coord) {.x = 90, .y = 200};
	if (env->h >= 900)
		margin = 50;
	if (!(map->hud_str = ft_itoa(map->pick_coin)))
		exit_program(env, ERR_MALLOC);
	draw_text(env, map->hud_str, c.x, c.y);
	ft_memdel((void **)&(map->hud_str));
	if (!(map->hud_str = ft_itoa(map->pick_key)))
		exit_program(env, ERR_MALLOC);
	draw_text(env, map->hud_str, c.x, c.y + margin);
	ft_memdel((void **)&(map->hud_str));
	draw_text(env, CON_0, per(env->w, 92), per(env->h, 95));
}

void	text_manager(t_env *env, t_map *map, char **board)
{
	int	id;

	id = board[(int)(map->pos.x + map->dir.x)][(int)(map->pos.y + map->dir.y)];
	get_hud_text(env, map);
	if (id == ID_LEVER_OFF)
		draw_text(env, PRESS2, per(env->w, 45), per(env->h, 60));
	if (map->lever_ticks)
	{
		if (!ticks_passed(&map->lever_ticks, 2))
			draw_text(env, ISAAC_HEARS, env->w / 2, per(env->h, 70));
		else
			map->lever_ticks = 0;
	}
	get_shop_text(env, map, board);
	if (id >= FIRST_INTER && id <= LAST_INTER)
		get_sprite_text(env, id);
}
