/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:03:30 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/05/05 13:10:43 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

Uint32	get_pixel2(SDL_Surface *surface, int x, int y)
{
	SDL_Color		color;
	unsigned char	*pixels;

	pixels = (unsigned char *)surface->pixels;
	color.r = pixels[4 * (y * surface->w + x) + 2];
	color.g = pixels[4 * (y * surface->w + x) + 1];
	color.b = pixels[4 * (y * surface->w + x) + 0];
	color.a = pixels[4 * (y * surface->w + x) + 3];
	return (rgb_to_int(color.r, color.g, color.b));
}

Uint32	get_pixel(SDL_Surface *surface, int x, int y)
{
	SDL_Color		color;
	unsigned char	*pixels;

	pixels = (unsigned char *)surface->pixels;
	color.r = pixels[4 * (y * surface->w + x) + 0];
	color.g = pixels[4 * (y * surface->w + x) + 1];
	color.b = pixels[4 * (y * surface->w + x) + 2];
	color.a = pixels[4 * (y * surface->w + x) + 3];
	return (rgb_to_int(color.r, color.g, color.b));
}

void	put_pixel(t_env *env, int x, int y, int color)
{
	Uint32	*pixels;

	pixels = (Uint32 *)env->surface->pixels;
	pixels[y * env->surface->w + x] = color;
}

void	paint_walls(t_env *env, t_thread *th, int x, int y_start)
{
	th->i = y_start - env->map->h2 + th->line_start;
	th->tex.y = ((th->i * TS) / th->line_height);
	if (th->id == ID_WALL_GLASS - 49)
	{
		if (!(th->color = get_pixel(env->t[3], th->tex.x, th->tex.y)))
			th->skip = 1;
	}
	else if (is_animation(th))
		open_door_animation(env, th);
	else if (is_poster(th))
	{
		if (!(th->color = get_pixel(env->t[env->map->poster_id],
						th->tex.x, th->tex.y)))
			th->color = get_pixel(env->t[th->id], th->tex.x, th->tex.y);
	}
	else if (is_bluish(env->map, th->id))
		th->color = get_pixel2(env->t[th->id], th->tex.x, th->tex.y);
	else
		th->color = get_pixel(env->t[th->id], th->tex.x, th->tex.y);
	if (th->skip == 0)
	{
		th->color = darken(env, th->color, th->perp, env->map->item_candle);
		put_pixel(env, x, y_start, th->color);
	}
	th->skip = 0;
}

void	draw_line(t_env *env, t_thread *t, int x, int y_start)
{
	if (t->ns_or_ew == 0)
		t->wall_x = env->map->pos.y + t->perp * t->ray_dir.y;
	else
		t->wall_x = env->map->pos.x + t->perp * t->ray_dir.x;
	t->wall_x -= floor((t->wall_x));
	t->tex.x = (int)(t->wall_x * (double)TS);
	if (t->ns_or_ew == 0 && t->ray_dir.x > 0)
		t->tex.x = TS - t->tex.x - 1;
	if (t->ns_or_ew == 1 && t->ray_dir.y < 0)
		t->tex.x = TS - t->tex.x - 1;
	while (y_start < t->y_end)
	{
		paint_walls(env, t, x, y_start);
		y_start++;
	}
}
