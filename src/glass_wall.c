/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glass_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 20:05:36 by julien            #+#    #+#             */
/*   Updated: 2020/05/25 20:06:05 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	glass_wall_init(t_thread *t)
{
	t->glass_hit = 0;
	if (t->saved == 2)
	{
		t->x_start = t->x_saved;
		t->saved = 3;
	}
}

void	glass_wall_reset(t_thread *t)
{
	if (t->x_start == t->x_end && t->saved == 1)
	{
		t->x_start = t->x_saved;
		t->saved = 3;
	}
}
