/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:59:14 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/03/02 15:13:12 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		run_loop(t_map *map, t_bre b, t_coord a)
{
	if (b.boo)
	{
		while (b.i != b.delta.x)
		{
			b.j = (int)((double)b.i / b.div);
			if (b.i == 1 || b.i == -1)
				map->new_pos = (t_coord) {a.x + b.j, a.y + b.i};
			if (is_tear_obstacle(map->board[a.x + b.j][a.y + b.i]) && b.i)
				return (0);
			b.i += b.inc;
		}
	}
	else
	{
		while (b.i != b.delta.x)
		{
			b.j = (int)((double)b.i / b.div);
			if (b.i == 1 || b.i == -1)
				map->new_pos = (t_coord) {a.x + b.i, a.y + b.j};
			if (is_tear_obstacle(map->board[a.x + b.i][a.y + b.j]) && b.i)
				return (0);
			b.i += b.inc;
		}
	}
	return (1);
}

int		bresenham(t_map *map, t_coord a, t_coord b)
{
	t_bre		bre;

	bre.i = 0;
	bre.boo = 0;
	bre.delta.y = b.y - a.y;
	bre.delta.x = b.x - a.x;
	if (abs(bre.delta.y) > abs(bre.delta.x))
	{
		ft_swap(&bre.delta.y, &bre.delta.x);
		bre.boo = 1;
	}
	bre.inc = (bre.delta.x < 0) ? -1 : 1;
	(bre.delta.y == 0) ? (bre.div = bre.delta.x) :
		(bre.div = (double)bre.delta.x / (double)bre.delta.y);
	return (run_loop(map, bre, a));
}
