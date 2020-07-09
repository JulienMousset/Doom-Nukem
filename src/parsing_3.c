/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:24:24 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/02 15:33:48 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		is_valid_char(int i)
{
	return ((i >= 48 && i <= 113) ? 1 : 0);
}

int		is_valid_first_line(t_map *map, char *s, int *first)
{
	(*first)++;
	if (ft_strlen(s) == 3)
	{
		if (s[0] == '1')
			map->lvl = 1;
		else if (s[0] == '2')
			map->lvl = 2;
		else if (s[0] == '3')
			map->lvl = 3;
		else
			return (0);
		if (s[1] != ' ')
			return (0);
		if (s[2] == '1')
			map->lvl_music = 1;
		else if (s[2] == '2')
			map->lvl_music = 2;
		else if (s[2] == '3')
			map->lvl_music = 3;
		else
			return (0);
		return (1);
	}
	else
		return (0);
}
