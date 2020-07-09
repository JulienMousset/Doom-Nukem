/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:40:18 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/03 18:59:45 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	set_mmap_values(t_env *env, t_map *map, int opt)
{
	map->mm_size = (opt == 2) ? per(env->w, 22) : per(env->w, 15);
	map->mm_margin = (t_coord) {.x = per(env->w, 2), .y = per(env->h, 2)};
	map->mm_vis = 20 * opt;
	map->mm_block_size = (env->w / 64 / 3);
	map->mm_start.x = env->w - map->mm_margin.x - map->mm_size;
	map->mm_start.y = map->mm_margin.y;
	map->mm_center.x = env->w - map->mm_margin.x - map->mm_size / 2;
	map->mm_center.y = map->mm_margin.y + map->mm_size / 2;
	map->mm_end.x = env->w - map->mm_margin.x;
	map->mm_end.y = map->mm_margin.y + map->mm_size;
	map->mm_color = 1;
}

void	set_keys_and_anim_values(t_map *map)
{
	map->up = 0;
	map->down = 0;
	map->left = 0;
	map->right = 0;
	map->strafe_left = 0;
	map->strafe_right = 0;
	map->look_up = 0;
	map->look_down = 0;
	map->run = 0;
	map->anim[A_INTRO] = (t_anim) {0, 0, 15, 7, {.x = -1, .y = -1}};
	map->anim[A_DOORS] = (t_anim) {0, 0, 0.1, 12, {.x = -1, .y = -1}};
	map->anim[A_BEGGAR] = (t_anim) {0, 0, 0.7, 2, {.x = -1, .y = -1}};
	map->anim[A_TEAR] = (t_anim) {0, 0, 0.03, 15, {.x = -1, .y = -1}};
	map->anim[A_BARREL] = (t_anim) {0, 0, 0.07, 8, {.x = -1, .y = -1}};
	map->anim[A_CYCLIC] = (t_anim) {0, 0, 0.1, 6, {.x = -1, .y = -1}};
}

void	set_item_values(t_map *map)
{
	map->container = 3;
	map->pick_heart = 6;
	map->pick_coin = 0;
	map->pick_key = 0;
	map->item_map = 0;
	map->item_heels = 0;
	map->item_candle = 15;
	map->item_dinner = 0;
	map->item_poly = 0;
	map->item_ipecac = 0;
	map->item_godhead = 0;
	map->item_quarter = 0;
	map->item_axe = 0;
	map->item_mantle = 0;
	map->item_xray = 0;
	map->item_lov = 0;
	map->item_odd = 0;
	map->item_swallowed = 0;
	map->item_vampire = 0;
	map->item_cricket = 0;
	map->odd_ticks = 0;
	map->score = 0;
	map->v_move = 0;
}

void	set_values2(t_env *env, t_map *map)
{
	map->run_anim = 0;
	map->spr_block = (t_coord) {.x = -1, .y = -1};
	map->shine_freq = 0;
	map->dople_spr = 0;
	map->wiz_spr = 0;
	map->poster_pos = (t_coord) {.x = 0, .y = 0};
	map->poster_or = (t_coord) {.x = 0, .y = 0};
	map->card = (t_card) {0, 0, 0, 0};
	map->poster_id = ID_POSTER1;
	map->poster_ticks = SDL_GetTicks();
	map->jump = 0;
	map->isaac_high = 0;
	map->isaac_dir = 1;
	map->isaac_ticks = 0;
	map->jump_bool = 0;
	map->fly_bool = 0;
	map->crouch_bool = 0;
	map->space_times = 0;
	map->hud_margin = (t_coord) {.x = (-env->h / 12) / 1.5,
		.y = (-env->h / 12) * 1.75};
	map->nb_lever = 0;
	map->nb_lever_doors = 0;
	map->lever_counter = 0;
	map->lever_ticks = 0;
	map->first_tnt = (t_coord) {.x = -1, .y = -1};
}

void	set_values(t_env *env, t_map *map)
{
	env->fps = (t_coord) {.x = 0, .y = 0};
	map->hurt = 0;
	if (!(map->z_buffer = (double *)malloc(sizeof(double) * env->w)))
		exit_program(env, ERR_MALLOC);
	map->pos = map->pos_cpy;
	map->dir = (t_complex) {.x = -1, .y = 0};
	map->plane = (t_complex) {.x = 0, .y = 0.66};
	map->move_coef = MOVE_SPEED;
	map->rot_coef = ROT_SPEED;
	map->h2 = env->h / 2;
	map->tnt_lst = NULL;
	map->opt = 1;
	map->bool_win = 0;
	map->bool_dead = 0;
	map->bool_tear = 0;
	map->final_score = 0;
	map->admin_mode = 0;
	set_values2(env, map);
	set_item_values(map);
	set_mmap_values(env, map, map->opt);
	set_keys_and_anim_values(map);
	set_level_id(map);
	place_poster(map, &map->card);
}
