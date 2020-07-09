/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_door_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:42:21 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/05/01 18:01:26 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	load_door_paths_3(char **path)
{
	path[0] = GOLDEN_1;
	path[1] = GOLDEN_2;
	path[2] = GOLDEN_3;
	path[3] = GOLDEN_4;
	path[4] = GOLDEN_5;
	path[5] = GOLDEN_6;
	path[6] = GOLDEN_7;
	path[7] = GOLDEN_8;
	path[8] = GOLDEN_9;
	path[9] = GOLDEN_10;
	path[10] = GOLDEN_11;
	path[11] = GOLDEN_12;
}

void	load_door_paths_2(char **path)
{
	path[0] = LOCKED_1;
	path[1] = LOCKED_2;
	path[2] = LOCKED_3;
	path[3] = LOCKED_4;
	path[4] = LOCKED_5;
	path[5] = LOCKED_6;
	path[6] = LOCKED_7;
	path[7] = LOCKED_8;
	path[8] = LOCKED_9;
	path[9] = LOCKED_10;
	path[10] = LOCKED_11;
	path[11] = LOCKED_12;
}

void	load_door_paths_1(char **path)
{
	path[0] = HEART_1;
	path[1] = HEART_2;
	path[2] = HEART_3;
	path[3] = HEART_4;
	path[4] = HEART_5;
	path[5] = HEART_6;
	path[6] = HEART_7;
	path[7] = HEART_8;
	path[8] = HEART_9;
	path[9] = HEART_10;
	path[10] = HEART_11;
	path[11] = HEART_12;
}
