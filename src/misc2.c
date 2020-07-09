/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:23:31 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/03 22:03:01 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		randomy(int min, int max)
{
	return ((rand() % (max - min + 1)) + min);
}

void	admin_mode(t_map *map)
{
	map->pick_coin += 15;
	map->pick_key += 10;
	map->admin_mode = 1;
	map->container = 8;
	map->pick_heart = map->container * 2;
	map->item_heels = 1;
	map->item_candle = 3;
	map->item_map = 1;
	map->item_axe = 1;
	map->item_xray = 1;
	map->item_mantle = 1;
	map->item_swallowed = 1;
	map->item_vampire = 1;
	map->item_cricket = 1;
}

void	reset_game(t_env *env, t_map *map)
{
	if (ticks_passed(&map->reset_ticks, RESET_TIME))
	{
		Mix_HaltMusic();
		map->intro = 0;
		ft_memdel((void **)&(map->z_buffer));
		set_values(env, map);
		ft_memdel((void **)&(map->s));
		ft_memdel((void **)&(map->spr_order));
		ft_memdel((void **)&(map->spr_dist));
		ft_tabdel(map->board, map->nb_lines);
		if (!(map->board = board_cpy(map->board_cpy,
						map->nb_lines, map->nb_columns)))
			exit_program(env, ERR_MALLOC);
		create_sprites_array(env);
		map->reset_ticks = 0;
	}
}

char	*array_cpy(char *src, int size)
{
	char	*dst;
	int		i;

	if (!(dst = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	**board_cpy(char **src, int nb_lines, int nb_columns)
{
	char	**dst;
	int		i;

	i = 0;
	if (!(dst = (char **)malloc(sizeof(char *) * (nb_lines))))
		return (NULL);
	while (i < nb_lines)
	{
		if (!(dst[i] = array_cpy(src[i], nb_columns)))
		{
			ft_tabdel(dst, nb_lines);
			return (NULL);
		}
		i++;
	}
	return (dst);
}
