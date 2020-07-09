/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:28:17 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/05 13:22:40 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		draw_text_rdr(t_env *p, char *text, SDL_Point coord, SDL_Color color)
{
	SDL_Surface *surface;
	SDL_Texture *texture;
	SDL_Rect	rect;

	TTF_SizeText(p->ft, text, &rect.w, &rect.h);
	rect.x = coord.x;
	rect.y = coord.y - rect.h;
	if (!(surface = TTF_RenderText_Solid(p->ft, text, color)))
		return (-1);
	if ((texture = SDL_CreateTextureFromSurface(p->rend, surface)))
	{
		SDL_RenderCopy(p->rend, texture, 0, &rect);
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);
		return (0);
	}
	SDL_FreeSurface(surface);
	return (-1);
}

void	credits(t_env *p)
{
	SDL_Rect size_txt;

	p->pt.rect = create_big_menu(p);
	TTF_SizeText(p->ft, "CREDITS", &size_txt.w, &size_txt.h);
	draw_text_rdr(p, "CREDITS", (SDL_Point){p->pt.rect.w / 2 - size_txt.w / 2,
		p->pt.rect.h / 2 + size_txt.h / 2 - 120}, (SDL_Color){124, 100, 74,
		255});
	TTF_SizeText(p->ft, "jmousset", &size_txt.w, &size_txt.h);
	draw_text_rdr(p, "jmousset", (SDL_Point){p->pt.rect.w / 2 - size_txt.w / 2,
		p->pt.rect.h / 2 + size_txt.h / 2 - 40}, (SDL_Color){124, 100, 74,
		255});
	TTF_SizeText(p->ft, "pasosa-s", &size_txt.w, &size_txt.h);
	draw_text_rdr(p, "pasosa-s", (SDL_Point){p->pt.rect.w / 2 - size_txt.w / 2,
		p->pt.rect.h / 2 + size_txt.h / 2 + 10}, (SDL_Color){124, 100, 74,
		255});
	TTF_SizeText(p->ft, "neil", &size_txt.w, &size_txt.h);
	draw_text_rdr(p, "neil", (SDL_Point){p->pt.rect.w / 2 - size_txt.w / 2,
		p->pt.rect.h / 2 + size_txt.h / 2 + 60}, (SDL_Color){124, 100, 74,
		255});
	TTF_SizeText(p->ft, "brume", &size_txt.w, &size_txt.h);
	draw_text_rdr(p, "brume", (SDL_Point){p->pt.rect.w / 2 - size_txt.w / 2,
		p->pt.rect.h / 2 + size_txt.h / 2 + 110}, (SDL_Color){124, 100, 74,
		255});
}

int		draw_text_help(t_env *p, char *text, SDL_Point coord, SDL_Color color)
{
	SDL_Surface *surface;
	SDL_Texture *texture;
	SDL_Rect	rect;

	TTF_SizeText(p->ft_help, text, &rect.w, &rect.h);
	rect.x = coord.x;
	rect.y = coord.y - rect.h;
	if (!(surface = TTF_RenderText_Solid(p->ft_help, text, color)))
		return (-1);
	if ((texture = SDL_CreateTextureFromSurface(p->rend, surface)))
	{
		SDL_RenderCopy(p->rend, texture, 0, &rect);
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);
		return (0);
	}
	SDL_FreeSurface(surface);
	return (-1);
}

void	draw_text(t_env *env, char *text, int x, int y)
{
	TTF_Font		*font;
	SDL_Surface		*text_surface;
	SDL_Rect		text_location;

	if (!(font = TTF_OpenFont(env->font_path, env->font_size)))
		exit_program(env, (char *)TTF_GetError());
	if (env->map->intro)
		text_surface = TTF_RenderText_Blended_Wrapped(font,
				text, env->font_color, 1100);
	else
		text_surface = TTF_RenderText_Solid(font, text, env->font_color);
	text_location = (SDL_Rect) { x, y, 0, 0 };
	SDL_BlitSurface(text_surface, NULL, env->surface, &text_location);
	SDL_FreeSurface(text_surface);
	TTF_CloseFont(font);
}
