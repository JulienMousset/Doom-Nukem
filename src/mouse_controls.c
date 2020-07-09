/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:32:11 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/03 18:19:50 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

double	sensibility(double delta, int index)
{
	double		coef;

	if (index == 1)
	{
		if (delta >= -10 && delta < 10)
			coef = 0.006;
		else if (delta >= -20 && delta < 20)
			coef = 0.01;
		else if (delta >= -40 && delta < 40)
			coef = 0.05;
		else
			coef = 0.1;
	}
	if (index == 2)
	{
		if (delta >= -10 && delta < 10)
			coef = 5;
		else if (delta >= -20 && delta < 20)
			coef = 10;
		else if (delta >= -40 && delta < -40)
			coef = 30;
		else
			coef = 60;
	}
	return (coef * SENSIBILITY);
}

void	mouse_press(t_map *map)
{
	if (SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		map->bool_tear = 1;
		ticks_init(&map->anim[A_TEAR].ticks);
	}
}

void	mouse_move(t_env *env, t_map *map)
{
	t_coord		delta;

	delta.x = env->event.motion.xrel;
	delta.y = env->event.motion.yrel;
	if (delta.x > 0)
	{
		map->rot_coef = sensibility(delta.x, 1);
		map->right = 1;
		left_or_right(env, env->map->rot_coef);
		map->rot_coef = ROT_SPEED;
		map->right = 0;
	}
	else if (delta.x < 0)
	{
		map->rot_coef = sensibility(delta.x, 1);
		map->left = 1;
		left_or_right(env, env->map->rot_coef);
		map->rot_coef = ROT_SPEED;
		map->left = 0;
	}
	delta.y > 0 ? map->h2 -= sensibility(delta.y, 2) : 0;
	delta.y < 0 ? map->h2 += sensibility(delta.y, 2) : 0;
	map->h2 < -env->h ? map->h2 = -env->h : 0;
	map->h2 > env->h * 2 ? map->h2 = env->h * 2 : 0;
	(!env->menu) ? reset_mouse(env) : 0;
}

void	mouse_events(t_env *env, t_map *map)
{
	if ((env->mouse = SDL_GetMouseState(&env->mouse_pos.x, &env->mouse_pos.y)))
		mouse_press(map);
	if (env->event.type == SDL_MOUSEMOTION)
		mouse_move(env, map);
}
