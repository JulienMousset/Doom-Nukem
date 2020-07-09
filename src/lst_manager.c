/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:25:20 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/03 19:17:24 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	ft_lst_realloc(t_env *env, t_lst *alst)
{
	while (alst)
	{
		realloc_array(env, alst->c.x, alst->c.y, ID_TNT);
		alst = alst->next;
	}
}

void	ft_lst_del(t_lst **alst)
{
	t_lst	*ptr;

	while (*alst)
	{
		ptr = (*alst)->next;
		free(*alst);
		*alst = ptr;
	}
	*alst = NULL;
}

int		ft_lst_iter(t_map *map, t_lst *alst, t_coord c)
{
	if (map->first_tnt.x == c.x && map->first_tnt.y == c.y)
		return (1);
	while (alst)
	{
		if (alst->c.x == c.x && alst->c.y == c.y)
			return (1);
		alst = alst->next;
	}
	return (0);
}

void	ft_lst_add(t_lst **alst, t_lst *new)
{
	new->next = *alst;
	*alst = new;
}

t_lst	*ft_lst_new(t_env *env, int x, int y)
{
	t_lst	*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		exit_program(env, ERR_MALLOC);
	new->c = (t_coord) {.x = x, .y = y};
	new->next = NULL;
	return (new);
}
