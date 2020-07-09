/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:13:42 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/03 19:06:54 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	won_or_lost(t_env *env, t_map *map)
{
	t_coord		c;

	c = (t_coord) {.x = env->w / 2 - 75, .y = 0};
	if (map->bool_dead)
	{
		print_mini_sprite(env, ID_HANGING - 49, c, 3);
		c = (t_coord) {.x = env->w / 2 - 125, .y = env->h / 1.75};
		draw_text(env, LOSE, c.x + 10, c.y - 160);
	}
	else if (map->bool_win)
	{
		print_mini_sprite(env, ID_GUPPY - 49, c, 3);
		c = (t_coord) {.x = env->w / 2 - 125, .y = env->h / 1.75};
		draw_text(env, WIN, c.x + 10, c.y - 160);
	}
}

int		final_score(t_map *map)
{
	int		bonus;

	bonus = 25;
	map->bool_win ? map->score += 250 : 0;
	map->score += map->pick_key * 5;
	map->score += map->pick_coin * 2;
	map->score -= (map->container * 2 - map->pick_heart) * 3;
	if (map->container * 2 == map->pick_heart)
		map->score += bonus;
	if (map->score < 0)
		map->score = 0;
	return (map->score);
}

void	end_game(t_env *env, t_map *map)
{
	t_coord	c;
	char	*score;
	char	*str;

	reset_player_movements(env);
	SDL_FillRect(env->surface, NULL, 0x000000);
	if (!(score = ft_itoa(final_score(map))))
		exit_program(env, ERR_MALLOC);
	if (!(str = ft_strjoin("        SCORE : ", score)))
		exit_program(env, ERR_MALLOC);
	won_or_lost(env, map);
	c = (t_coord) {.x = env->w / 2 - 125, .y = env->h / 1.75};
	draw_text(env, str, c.x + 25, c.y);
	draw_text(env, END1, c.x - 275, c.y + 160);
	if (map->bool_dead)
		draw_text(env, END2, c.x + 300, c.y + 160);
	else if (map->bool_win)
		draw_text(env, END3, c.x + 300, c.y + 160);
	ft_memdel((void **)&(score));
	ft_memdel((void **)&(str));
}
