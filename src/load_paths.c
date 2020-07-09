/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:09:48 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/01 17:39:46 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	load_paths4(char **path)
{
	path[71] = TAG_5;
	path[72] = TAG_15;
	path[73] = TAG_99;
	path[74] = CEILING1;
	path[75] = CEILING2;
	path[76] = CEILING3;
	path[77] = POSTER1;
	path[78] = POSTER2;
	path[79] = BABY2;
	path[80] = DOPLE_L;
	path[81] = DOPLE_R;
	path[82] = WIZOOB2;
	path[83] = WIZOOB3;
	path[84] = WIZOOB4;
}

void	load_paths3(char **path)
{
	path[48] = LEVER_ON;
	path[49] = TROPHY;
	path[50] = SHOPKEEPER;
	path[51] = ERROR;
	path[52] = GUPPY;
	path[53] = HANGING;
	path[54] = BEGGAR_COIN;
	path[55] = BEGGAR_DEVIL;
	path[56] = BEGGAR_KEY;
	path[57] = DONATION_MACHINE_BLOOD;
	path[58] = WIZOOB1;
	path[59] = DOPLE;
	path[60] = ROTTY;
	path[61] = BABY1;
	path[62] = SHIFT_ON;
	path[63] = SHIFT_OFF;
	path[64] = PLAYER;
	path[65] = CONTAINER_HEART_RED;
	path[66] = CONTAINER_HEART_RED_HALF;
	path[67] = CONTAINER_HEART_EMPTY;
	path[68] = FLOOR1;
	path[69] = FLOOR2;
	path[70] = FLOOR3;
	load_paths4(path);
}

void	load_paths2(char **path)
{
	path[24] = DINNER;
	path[25] = SWALLOWED;
	path[26] = VAMPIRE;
	path[27] = CRICKET;
	path[28] = POLY;
	path[29] = IPECAC;
	path[30] = GODHEAD;
	path[31] = AXE;
	path[32] = HOLY_MANTLE;
	path[33] = QUARTER;
	path[34] = XRAY_VISION;
	path[35] = LOV;
	path[36] = COBWEB;
	path[37] = ROCK1;
	path[38] = ROCK2;
	path[39] = URN;
	path[40] = MUSHROOM1;
	path[41] = MUSHROOM2;
	path[42] = SKULL;
	path[43] = POOP;
	path[44] = TNT;
	path[45] = CAMPFIRE;
	path[46] = DONATION_MACHINE;
	path[47] = LEVER_OFF;
	load_paths3(path);
}

void	load_paths(char **path)
{
	path[0] = WALL1;
	path[1] = WALL2;
	path[2] = WALL3;
	path[3] = WALL_GLASS;
	path[4] = WALL_SHOP;
	path[5] = DOOR_LEVER;
	path[6] = DOOR_HEART;
	path[7] = DOOR_CLOSED;
	path[8] = DOOR_GOLDEN_CLOSED;
	path[9] = DOOR_OPEN;
	path[10] = DOOR_GOLDEN_OPEN;
	path[11] = DOOR_CURSE;
	path[12] = WALL1_SECRET;
	path[13] = WALL2_SECRET;
	path[14] = WALL3_SECRET;
	path[15] = HEART_RED;
	path[16] = HEART_RED_HALF;
	path[17] = KEY;
	path[18] = COIN;
	path[19] = NICKEL;
	path[20] = ODD;
	path[21] = MAP;
	path[22] = HEELS;
	path[23] = RED_CANDLE;
	load_paths2(path);
}
