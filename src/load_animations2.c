/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_animations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:56:28 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/05/01 17:59:10 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	bloodtear_animation(t_env *env)
{
	env->tears[1][0] = load_sprite(env, RED_TEAR_1);
	env->tears[1][1] = load_sprite(env, RED_TEAR_2);
	env->tears[1][2] = load_sprite(env, RED_TEAR_3);
	env->tears[1][3] = load_sprite(env, RED_TEAR_4);
	env->tears[1][4] = load_sprite(env, RED_TEAR_5);
	env->tears[1][5] = load_sprite(env, RED_TEAR_6);
	env->tears[1][6] = load_sprite(env, RED_TEAR_7);
	env->tears[1][7] = load_sprite(env, RED_TEAR_8);
	env->tears[1][8] = load_sprite(env, RED_TEAR_9);
	env->tears[1][9] = load_sprite(env, RED_TEAR_10);
	env->tears[1][10] = load_sprite(env, RED_TEAR_11);
	env->tears[1][11] = load_sprite(env, RED_TEAR_12);
	env->tears[1][12] = load_sprite(env, RED_TEAR_13);
	env->tears[1][13] = load_sprite(env, RED_TEAR_14);
	env->tears[1][14] = load_sprite(env, RED_TEAR_15);
}

void	tear_animation(t_env *env)
{
	env->tears[0][0] = load_sprite(env, TEAR_1);
	env->tears[0][1] = load_sprite(env, TEAR_2);
	env->tears[0][2] = load_sprite(env, TEAR_3);
	env->tears[0][3] = load_sprite(env, TEAR_4);
	env->tears[0][4] = load_sprite(env, TEAR_5);
	env->tears[0][5] = load_sprite(env, TEAR_6);
	env->tears[0][6] = load_sprite(env, TEAR_7);
	env->tears[0][7] = load_sprite(env, TEAR_8);
	env->tears[0][8] = load_sprite(env, TEAR_9);
	env->tears[0][9] = load_sprite(env, TEAR_10);
	env->tears[0][10] = load_sprite(env, TEAR_11);
	env->tears[0][11] = load_sprite(env, TEAR_12);
	env->tears[0][12] = load_sprite(env, TEAR_13);
	env->tears[0][13] = load_sprite(env, TEAR_14);
	env->tears[0][14] = load_sprite(env, TEAR_15);
	bloodtear_animation(env);
}

void	beggar_animations(t_env *env)
{
	env->beggars[0][0] = load_sprite(env, BEGGAR_COIN_2);
	env->beggars[0][1] = load_sprite(env, BEGGAR_COIN_3);
	env->beggars[1][0] = load_sprite(env, BEGGAR_DEVIL_2);
	env->beggars[1][1] = load_sprite(env, BEGGAR_DEVIL_3);
	env->beggars[2][0] = load_sprite(env, BEGGAR_KEY_2);
	env->beggars[2][1] = load_sprite(env, BEGGAR_KEY_3);
	env->beggars[3][0] = load_sprite(env, BLOOD_MACHINE_2);
	env->beggars[3][1] = load_sprite(env, BLOOD_MACHINE_3);
	env->trophy[0] = load_sprite(env, TROPHY_1);
	env->trophy[1] = load_sprite(env, TROPHY_2);
	env->trophy[2] = load_sprite(env, TROPHY_3);
}
