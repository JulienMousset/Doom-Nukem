/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 21:53:14 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/05/07 20:39:54 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		button(t_env *p, char *str, void func(t_env *), int index)
{
	SDL_Rect rect2;
	SDL_Rect size_txt;

	rect2 = (SDL_Rect){p->pt.rect.x + p->pt.rect.w / 2 - (p->pt.rect.w * 0.4)
		/ 2, p->pt.rect.y + (p->pt.rect.h * (index * 2 - 1) * 0.06)
		+ p->pt.rect.h / 4.5, p->pt.rect.w * 0.45, p->pt.rect.h * 0.07};
	TTF_SizeText(p->ft, str, &size_txt.w, &size_txt.h);
	if (hover_mouse(p, rect2))
	{
		draw_text_rdr(p, str, (SDL_Point){rect2.x + rect2.w / 2
			- size_txt.w / 2, rect2.y + rect2.h / 2 + size_txt.h / 2},
			(SDL_Color){81, 66, 49, 255});
		if (p->event.button.type == SDL_MOUSEBUTTONDOWN)
		{
			p->event.button.type = 0;
			(func)(p);
			play_sfx(p->map, randomy(ID_SFX_MENU_1, ID_SFX_MENU_2));
			p->map->intro = (!ft_strcmp(str, "New Run") ? 1 : 0);
		}
	}
	else
		draw_text_rdr(p, str, (SDL_Point){rect2.x + rect2.w / 2
			- size_txt.w / 2, rect2.y + rect2.h / 2 + size_txt.h / 2},
			(SDL_Color){124, 100, 74, 255});
}

void		slider_text(t_env *p, SDL_Rect rect, char *str, int val)
{
	char *str_val;

	if ((str_val = ft_itoa(val)))
	{
		draw_text_rdr(p, str, (SDL_Point){rect.x + rect.w * 0.03, rect.y
			- rect.h * 3}, (SDL_Color){124, 100, 74, 255});
		draw_text_rdr(p, str_val, (SDL_Point){rect.x + rect.w * 0.93, rect.y
			- rect.h * 3}, (SDL_Color){124, 100, 74, 255});
		free(str_val);
	}
}

SDL_Rect	slider_button(t_env *p, SDL_Rect rect2, int val, int index)
{
	SDL_Rect rect3;

	if (p->event.button.type == SDL_MOUSEBUTTONUP)
		p->press.x = 0;
	rect3 = (SDL_Rect){rect2.x + (rect2.w * val / 100), rect2.y - 2 * rect2.h,
		rect2.h * 3, rect2.h * 5};
	SDL_SetRenderDrawColor(p->rend, 124, 100, 74, 255);
	SDL_RenderFillRect(p->rend, &rect2);
	if (p->press.x == 1 && p->press.y == index)
	{
		SDL_SetRenderDrawColor(p->rend, 81, 66, 49, 255);
		SDL_RenderFillRect(p->rend, &rect3);
	}
	else
	{
		SDL_RenderFillRect(p->rend, &rect3);
	}
	return (rect3);
}

int			slider_val(t_env *p, SDL_Rect rect2, int index, int intval[10])
{
	int diff_mouse;
	int val;

	val = p->pt.val_sd[index];
	if (p->press.x == 1 && p->press.y == index)
	{
		diff_mouse = p->event.button.x - p->mouse_menu.x;
		diff_mouse = (diff_mouse > rect2.w ? rect2.w : diff_mouse);
		val = intval[index] + diff_mouse * 100 / rect2.w;
		val = (val > 100 ? 100 : val);
		val = (val < 0 ? 0 : val);
	}
	return (val);
}

int			slider(t_env *p, char *str, int id)
{
	int			val;
	double		size;
	static int	ivl[10];
	SDL_Rect	rect2;
	SDL_Rect	rect3;

	size = (p->menu > 10 ? 0.4 : 0.7);
	rect2 = (SDL_Rect){p->pt.rect.x + p->pt.rect.w / 2 - (p->pt.rect.w * size)
		/ 2 + (size - 0.7) * -100, p->pt.rect.y + (p->pt.rect.h * (id * 2 - 1)
		* 0.09) + p->pt.rect.h / 5.5, p->pt.rect.w * size, p->pt.rect.h / 100};
	val = slider_val(p, rect2, id, ivl);
	rect3 = slider_button(p, rect2, val, id);
	if (hover_mouse(p, rect3))
	{
		SDL_SetRenderDrawColor(p->rend, 81, 66, 49, 255);
		SDL_RenderFillRect(p->rend, &rect3);
		if (p->event.button.type == SDL_MOUSEBUTTONDOWN && (ivl[id] = val + 1))
		{
			p->press = (SDL_Point){1, id};
			p->mouse_menu.x = p->event.button.x;
			play_sfx(p->map, randomy(ID_SFX_MENU_1, ID_SFX_MENU_2));
		}
	}
	slider_text(p, rect2, str, val);
	return ((p->pt.val_sd[id] = val));
}
