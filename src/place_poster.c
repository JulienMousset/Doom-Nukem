/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_poster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:36:56 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/05/01 18:55:54 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	set_orientation(t_map *map, t_card *card, t_coord ran)
{
	if (card->north)
		map->poster_or = (t_coord) {.x = 0, .y = 1};
	else if (card->south)
		map->poster_or = (t_coord) {.x = 0, .y = -1};
	else if (card->east)
		map->poster_or = (t_coord) {.x = 1, .y = -1};
	else if (card->west)
		map->poster_or = (t_coord) {.x = 1, .y = 1};
	map->poster_pos = (t_coord) {.x = ran.y, .y = ran.x};
}

void	set_poster_values(t_map *map, t_coord *c, int *n)
{
	srand(time(NULL));
	*c = (t_coord) {.x = map->nb_columns, .y = map->nb_lines};
	*n = 0;
}

void	place_poster(t_map *map, t_card *card)
{
	t_coord		ran;
	t_coord		c;
	int			n;

	set_poster_values(map, &c, &n);
	while (!n)
	{
		ran.y = randomy(0, c.y - 1);
		ran.x = randomy(0, c.x - 1);
		if (map->board[ran.y][ran.x] == '1' || map->board[ran.y][ran.x] ==
				'2' || map->board[ran.y][ran.x] == '3')
		{
			if ((ran.y + 1) < c.y && map->board[ran.y + 1][ran.x] == '0')
				card->south = 1;
			else if ((ran.x + 1) < c.x && map->board[ran.y][ran.x + 1] == '0')
				card->east = 1;
			else if ((ran.y - 1) >= 0 && map->board[ran.y - 1][ran.x] == '0')
				card->north = 1;
			else if ((ran.x - 1) >= 0 && map->board[ran.y][ran.x - 1] == '0')
				card->west = 1;
			if (card->north || card->east || card->south || card->west)
				n = 1;
		}
	}
	set_orientation(map, card, ran);
}
