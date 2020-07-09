/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:34:07 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/05/01 17:57:34 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	load_story(t_env *env)
{
	env->story[0] = "Isaac and his mother lived alone in a small house on a"
	" hill.";
	env->story[1] = "Isaac was playing as his mom watched Christian broadca"
	"sts\non the television.They were both happy.";
	env->story[2] = "That was, until the day Isaac's mom heard a voice from"
	"\nabove : \"Your son has become corrupted by sin! He needs\nto be save"
	"d!\" So she rushed into Isaac's room, removing\nall that was evil from"
	" his life.";
	env->story[3] = "Again, the voice called to her. So Isaac's mom locked "
	"Isaac\nin his room, away from the evils of the world.";
	env->story[4] = "One last time, Isaac's mom heard the voice of God call"
	"ing\nto her : \"You've done as I've asked, but I still question\nyour "
	"devotion to me. To prove it, I require the sacrifice\nof your son Isaa"
	"c.\" She agreed, grabbing a butcher's knife\nfrom the kitchen.";
	env->story[5] = "Isaac, watching through a crack in his door, trembled "
	"in\nfear. Scrambling around his room to find a hiding place, he\nnotic"
	"ed a trapdoor to the basement, hidden under his rug.";
	env->story[6] = "Without hesitation, he flung open the hatch just as hi"
	"s\nmother burst through his door and threw himself down into\nthe unk"
	"nown depths below.\n\nNow, fight your way through the unknown and get "
	"out of here.";
}

void	load_panels(t_env *env)
{
	env->panel[0] = load_sprite(env, PANEL1);
	env->panel[1] = load_sprite(env, PANEL2);
	env->panel[2] = load_sprite(env, PANEL3);
	env->panel[3] = load_sprite(env, PANEL4);
	env->panel[4] = load_sprite(env, PANEL5);
	env->panel[5] = load_sprite(env, PANEL6);
	env->panel[6] = load_sprite(env, PANEL7);
	load_story(env);
}

void	load_explosions(t_env *env)
{
	env->explosions[0][0] = load_sprite(env, EXP_NORMAL1);
	env->explosions[0][1] = load_sprite(env, EXP_NORMAL2);
	env->explosions[0][2] = load_sprite(env, EXP_NORMAL3);
	env->explosions[0][3] = load_sprite(env, EXP_NORMAL4);
	env->explosions[0][4] = load_sprite(env, EXP_NORMAL5);
	env->explosions[0][5] = load_sprite(env, EXP_NORMAL6);
	env->explosions[0][6] = load_sprite(env, EXP_NORMAL7);
	env->explosions[0][7] = load_sprite(env, EXP_NORMAL8);
	env->explosions[1][0] = load_sprite(env, EXP_FART1);
	env->explosions[1][1] = load_sprite(env, EXP_FART2);
	env->explosions[1][2] = load_sprite(env, EXP_FART3);
	env->explosions[1][3] = load_sprite(env, EXP_FART4);
	env->explosions[1][4] = load_sprite(env, EXP_FART5);
	env->explosions[1][5] = load_sprite(env, EXP_FART6);
	env->explosions[1][6] = load_sprite(env, EXP_FART7);
	env->explosions[1][7] = load_sprite(env, EXP_FART8);
}

void	load_anim_ticks(t_env *env)
{
	env->cyclic[0][0] = load_sprite(env, FIRE_TICK1);
	env->cyclic[0][1] = load_sprite(env, FIRE_TICK2);
	env->cyclic[0][2] = load_sprite(env, FIRE_TICK3);
	env->cyclic[0][3] = load_sprite(env, FIRE_TICK4);
	env->cyclic[0][4] = load_sprite(env, FIRE_TICK5);
	env->cyclic[0][5] = load_sprite(env, FIRE_TICK6);
	env->cyclic[1][0] = load_sprite(env, PENNY_TICK1);
	env->cyclic[1][1] = load_sprite(env, PENNY_TICK2);
	env->cyclic[1][2] = load_sprite(env, PENNY_TICK3);
	env->cyclic[1][3] = load_sprite(env, PENNY_TICK4);
	env->cyclic[1][4] = load_sprite(env, PENNY_TICK5);
	env->cyclic[1][5] = load_sprite(env, PENNY_TICK6);
	env->cyclic[2][0] = load_sprite(env, NICKEL_TICK1);
	env->cyclic[2][1] = load_sprite(env, NICKEL_TICK2);
	env->cyclic[2][2] = load_sprite(env, NICKEL_TICK3);
	env->cyclic[2][3] = load_sprite(env, NICKEL_TICK4);
	env->cyclic[2][4] = load_sprite(env, NICKEL_TICK5);
	env->cyclic[2][5] = load_sprite(env, NICKEL_TICK6);
	env->b[0][0] = load_sprite(env, TNT_TICK3);
	env->b[0][1] = load_sprite(env, TNT_TICK2);
	env->b[1][0] = load_sprite(env, POOP_TICK3);
	env->b[1][1] = load_sprite(env, POOP_TICK2);
}

void	load_animations(t_env *env)
{
	int		i;
	int		j;

	load_door_paths_1(env->door_paths[0]);
	load_door_paths_2(env->door_paths[1]);
	load_door_paths_3(env->door_paths[2]);
	j = -1;
	while (++j < 3)
	{
		i = -1;
		while (++i < 12)
			env->doors[j][i] = load_sprite(env, env->door_paths[j][i]);
	}
	beggar_animations(env);
	tear_animation(env);
	load_panels(env);
	load_explosions(env);
	load_anim_ticks(env);
}
