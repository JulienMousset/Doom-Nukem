/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 20:00:36 by julien            #+#    #+#             */
/*   Updated: 2020/06/03 20:20:30 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	up_or_down(t_env *env, char **board, t_complex dir)
{
	env->map->move_speed = (env->map->run == 1) ? env->map->move_coef
	* 1.75 : env->map->move_coef;
	if (env->map->up == 1)
	{
		env->add.x = (env->map->pos.x + dir.x * env->map->move_coef * SCALE_MS);
		env->add.y = (env->map->pos.y + dir.y * env->map->move_coef * SCALE_MS);
		if (is_walkable(env, board[env->add.x][(int)env->map->pos.y],
		env->add.x, env->map->pos.y))
			env->map->pos.x += dir.x * env->map->move_speed;
		if (is_walkable(env, board[(int)env->map->pos.x][env->add.y],
		env->map->pos.x, env->add.y))
			env->map->pos.y += dir.y * env->map->move_speed;
	}
	if (env->map->down == 1)
	{
		env->add.x = (env->map->pos.x - dir.x * env->map->move_coef * SCALE_MS);
		env->add.y = (env->map->pos.y - dir.y * env->map->move_coef * SCALE_MS);
		if (is_walkable(env, board[env->add.x][(int)env->map->pos.y],
		env->add.x, env->map->pos.y))
			env->map->pos.x -= dir.x * env->map->move_speed;
		if (is_walkable(env, board[(int)env->map->pos.x][env->add.y],
		env->map->pos.x, env->add.y))
			env->map->pos.y -= dir.y * env->map->move_speed;
	}
}

void	left_or_right(t_env *env, double rot_coef)
{
	double	old_dir;
	double	old_plane;
	double	rot_speed;

	old_dir = env->map->dir.x;
	old_plane = env->map->plane.x;
	if (env->map->right == 1)
		rot_speed = rot_coef * -M_PI / 2;
	else
		rot_speed = rot_coef * M_PI / 2;
	env->map->dir.x = env->map->dir.x * cos(rot_speed) - env->map->dir.y
	* sin(rot_speed);
	env->map->dir.y = old_dir * sin(rot_speed) + env->map->dir.y
	* cos(rot_speed);
	env->map->plane.x = env->map->plane.x * cos(rot_speed) -
		env->map->plane.y * sin(rot_speed);
	env->map->plane.y = old_plane * sin(rot_speed) + env->map->plane.y
	* cos(rot_speed);
}

void	strafe(t_env *env, char **board, t_complex dir)
{
	env->map->move_speed = (env->map->run == 1) ? env->map->move_coef
	* 0.8 : env->map->move_coef;
	if (env->map->strafe_left)
	{
		env->add.x = (env->map->pos.x - dir.y * env->map->move_coef * SCALE_MS);
		env->add.y = (env->map->pos.y + dir.x * env->map->move_coef * SCALE_MS);
		if (is_walkable(env, board[env->add.x][(int)env->map->pos.y],
		env->add.x, env->map->pos.y))
			env->map->pos.x -= dir.y * env->map->move_speed;
		if (is_walkable(env, board[(int)env->map->pos.x][env->add.y],
		env->map->pos.x, env->add.y))
			env->map->pos.y += dir.x * env->map->move_speed;
	}
	if (env->map->strafe_right)
	{
		env->add.x = (env->map->pos.x + dir.y * env->map->move_coef * SCALE_MS);
		env->add.y = (env->map->pos.y - dir.x * env->map->move_coef * SCALE_MS);
		if (is_walkable(env, board[env->add.x][(int)env->map->pos.y],
		env->add.x, env->map->pos.y))
			env->map->pos.x += dir.y * env->map->move_speed;
		if (is_walkable(env, board[(int)env->map->pos.x][env->add.y],
		env->map->pos.x, env->add.y))
			env->map->pos.y -= dir.x * env->map->move_speed;
	}
}
