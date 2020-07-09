/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_editor_init_texts.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 20:02:15 by julien            #+#    #+#             */
/*   Updated: 2020/06/05 13:27:34 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		text_init(t_env *e)
{
	TTF_Font *font;

	if (!(font = TTF_OpenFont(ED_FONT_PATH, 28)))
		exit_program(e, (char *)TTF_GetError());
	text_init_tex(e, font);
	text_init_tex_size(e, font);
	text_init_tex_size2(e, font);
	TTF_CloseFont(font);
}

void		text_init_tex(t_env *e, TTF_Font *font)
{
	e->ed.text_tex[0] = text2tex(e, font, ED_LINES, e->white);
	e->ed.text_tex[1] = text2tex(e, font, ED_COLUMNS, e->white);
	e->ed.text_tex[2] = text2tex(e, font, ED_ZOOM, e->white);
	e->ed.text_tex[3] = text2tex(e, font, ED_PICK, e->white);
	e->ed.text_tex[4] = text2tex(e, font, ED_MOVE, e->white);
	e->ed.text_tex[5] = text2tex(e, font, ED_SAVE, e->white);
	e->ed.text_tex[6] = text2tex(e, font, ED_SAVEPLAY, e->white);
	e->ed.text_tex[7] = text2tex(e, font, ED_QUIT, e->white);
	e->ed.text_tex[8] = text2tex(e, font, ED_ERR_W, (SDL_Color){255, 0, 0, 0});
	e->ed.text_tex[9] = text2tex(e, font, ED_SAVED, e->white);
	e->ed.text_tex[10] = text2tex(e, font, ED_OBJ_BLOCKS, e->white);
	e->ed.text_tex[11] = text2tex(e, font, ED_OBJ_ITEMS1, e->white);
	e->ed.text_tex[12] = text2tex(e, font, ED_OBJ_ITEMS2, e->white);
	e->ed.text_tex[13] = text2tex(e, font, ED_OBJ_ITEMS3, e->white);
	e->ed.text_tex[14] = text2tex(e, font, ED_OBJ_ITEMS4, e->white);
	e->ed.text_tex[15] = text2tex(e, font, ED_OBJ_SOLID, e->white);
	e->ed.text_tex[16] = text2tex(e, font, ED_OBJ_INTER, e->white);
	e->ed.text_tex[17] = text2tex(e, font, ED_LVMUS, e->white);
}

void		text_init_tex_size2(t_env *e, TTF_Font *font)
{
	TTF_SizeText(font, ED_OBJ_BLOCKS,
			&e->ed.text_tex_size[10].w, &e->ed.text_tex_size[10].h);
	TTF_SizeText(font, ED_OBJ_ITEMS1,
			&e->ed.text_tex_size[11].w, &e->ed.text_tex_size[11].h);
	TTF_SizeText(font, ED_OBJ_ITEMS2,
			&e->ed.text_tex_size[12].w, &e->ed.text_tex_size[12].h);
	TTF_SizeText(font, ED_OBJ_ITEMS3,
			&e->ed.text_tex_size[13].w, &e->ed.text_tex_size[13].h);
	TTF_SizeText(font, ED_OBJ_ITEMS4,
			&e->ed.text_tex_size[14].w, &e->ed.text_tex_size[14].h);
	TTF_SizeText(font, ED_OBJ_SOLID,
			&e->ed.text_tex_size[15].w, &e->ed.text_tex_size[15].h);
	TTF_SizeText(font, ED_OBJ_INTER,
			&e->ed.text_tex_size[16].w, &e->ed.text_tex_size[16].h);
	TTF_SizeText(font, ED_LVMUS,
			&e->ed.text_tex_size[17].w, &e->ed.text_tex_size[17].h);
}

void		text_init_tex_size(t_env *e, TTF_Font *font)
{
	TTF_SizeText(font, ED_LINES,
			&e->ed.text_tex_size[0].w, &e->ed.text_tex_size[0].h);
	TTF_SizeText(font, ED_COLUMNS,
			&e->ed.text_tex_size[1].w, &e->ed.text_tex_size[1].h);
	TTF_SizeText(font, ED_ZOOM,
			&e->ed.text_tex_size[2].w, &e->ed.text_tex_size[2].h);
	TTF_SizeText(font, ED_PICK,
			&e->ed.text_tex_size[3].w, &e->ed.text_tex_size[3].h);
	TTF_SizeText(font, ED_MOVE,
			&e->ed.text_tex_size[4].w, &e->ed.text_tex_size[4].h);
	TTF_SizeText(font, ED_SAVE,
			&e->ed.text_tex_size[5].w, &e->ed.text_tex_size[5].h);
	TTF_SizeText(font, ED_SAVEPLAY,
			&e->ed.text_tex_size[6].w, &e->ed.text_tex_size[6].h);
	TTF_SizeText(font, ED_QUIT,
			&e->ed.text_tex_size[7].w, &e->ed.text_tex_size[7].h);
	TTF_SizeText(font, ED_ERR_W,
			&e->ed.text_tex_size[8].w, &e->ed.text_tex_size[8].h);
	TTF_SizeText(font, ED_SAVED,
			&e->ed.text_tex_size[9].w, &e->ed.text_tex_size[9].h);
}

void		load_tex2(t_env *e)
{
	int count;
	int fakecount;

	count = -1;
	while (++count < NUM_TEX)
	{
		if (count == ID_SHIFT_ON)
			fakecount = ID_RHEART - 49;
		else if (count == ID_SHIFT_OFF)
			fakecount = ID_KEY - 49;
		else
			fakecount = count;
		if (!(e->ed.tex[count] = SDL_CreateTextureFromSurface(e->rend,
						e->t[fakecount])))
		{
			ft_putendl("Failed to allocate textures from the editor.");
			ft_putendl("Exiting safely.");
			exit(1);
		}
	}
}
