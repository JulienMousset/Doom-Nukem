/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:41:34 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/04 19:22:43 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		exit_program_in_tab(t_env *env, int *i, char *error)
{
	free_program_in_tab(env, i);
	end(error);
}

void		draw_aim(t_env *env)
{
	int i;

	i = -8;
	while (++i < 8)
	{
		if (i < -2 || i > 2)
		{
			put_pixel(env, env->w / 2 + i, env->h / 2, M);
			put_pixel(env, env->w / 2, env->h / 2 + i, M);
		}
	}
}

void		mushroom(unsigned char *r, unsigned char *g, unsigned char *b,
double d)
{
	if (*r > 0)
		*r = *r * (*r - d);
	if (*g > 0)
		*g = *g * (*g - d);
	if (*b > 0)
		*b = *b * (*b - d);
}

Uint32		darken(t_env *env, Uint32 c, double d, int candle)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = c;
	g = c >> 8;
	b = c >> 16;
	d = candle / (100 / d);
	if (d > 0.9)
		d = 0.9;
	if (env->map->item_odd)
		mushroom(&r, &g, &b, d);
	if (r > 0)
		r = r - (r * d);
	if (g > 0)
		g = g - (g * d);
	if (b > 0)
		b = b - (b * d);
	c = (r << 16) + (g << 8) + b;
	r = c;
	g = c >> 8;
	b = c >> 16;
	return ((r << 16) + (g << 8) + b);
}

void		bubble_sort(int *order, double *dist, int amount)
{
	int		i;
	int		j;
	int		gap;
	int		swapped;

	gap = amount;
	swapped = 0;
	while (gap > 1 || swapped)
	{
		gap = (gap * 10) / 13;
		(gap == 9 || gap == 10) ? gap = 11 : 0;
		(gap < 1) ? gap = 1 : 0;
		swapped = 0;
		i = -1;
		while (++i < amount - gap)
		{
			j = i + gap;
			if (dist[i] < dist[j])
			{
				ft_swap_double(&dist[i], &dist[j]);
				ft_swap(&order[i], &order[j]);
				swapped = 1;
			}
		}
	}
}
