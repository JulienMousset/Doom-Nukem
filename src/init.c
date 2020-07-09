/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:30:04 by jmousset          #+#    #+#             */
/*   Updated: 2020/06/05 13:21:42 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	pre_set_values(t_env *env, char *file)
{
	env->w = W;
	env->h = H;
	env->map->level = file;
	env->map->close_requested = 0;
	env->map->transition = 0;
	env->map->menu_transition = 0;
	env->map->intro_transition = 0;
	env->map->intro = 0;
	env->map->reset_ticks = 0;
}

int		init_menu(t_env *env, int is_arg)
{
	if (!(env->ft = TTF_OpenFont(FT_MENU_PATH, FT_MENU_SZ)))
		exit_program(env, (char *)TTF_GetError());
	if (!(env->ft_help = TTF_OpenFont(FT_MENU_PATH, FT_MENU_SZ_HELP)))
		exit_program(env, (char *)TTF_GetError());
	env->fullscreen = 0;
	env->menu = 10;
	env->press = (SDL_Point){0, 0};
	env->map->volume_music = 50;
	env->map->volume_sfx = 50;
	SDL_GetDesktopDisplayMode(0, &env->desktop_dm);
	env->image[0] = IMG_Load(START_MENU_WPP);
	env->image[1] = IMG_Load(GAME_MENU_WPP);
	env->image[2] = IMG_Load(MENU_LOGO);
	if (env->image[0] == NULL || env->image[1] == NULL || env->image[2] == NULL)
		ft_putendl("Unable to load image");
	env->texture[0] = SDL_CreateTextureFromSurface(env->rend, env->image[0]);
	env->texture[1] = SDL_CreateTextureFromSurface(env->rend, env->image[1]);
	env->texture[2] = SDL_CreateTextureFromSurface(env->rend, env->image[2]);
	if (env->texture[0] == NULL || env->texture[1] == NULL ||
			env->texture[2] == NULL)
		ft_putendl("Unable to create texture");
	env->menu = (is_arg ? 0 : 10);
	return (1);
}

void	ttf_init(t_env *env)
{
	env->font_color = (SDL_Color) {255, 255, 255, 255};
	env->font_size = env->h / 42;
	env->font_path = PATH_FONT_GAME;
}

void	sdl_init(t_env *env)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS |
				SDL_INIT_TIMER))
		exit_program(env, (char *)SDL_GetError());
	if (TTF_Init() != 0)
		exit_program(env, (char *)TTF_GetError());
	if (Mix_Init(0))
		exit_program(env, (char *)Mix_GetError());
	if (IMG_Init(0))
		exit_program(env, (char *)IMG_GetError());
	env->win = SDL_CreateWindow("doom_nukem", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, env->w, env->h, 0);
	if (!env->win)
		exit_program(env, (char *)SDL_GetError());
	env->rend = SDL_CreateRenderer(env->win, -1, 0);
	if (!env->rend)
		exit_program(env, (char *)SDL_GetError());
	SDL_SetRenderDrawColor(env->rend, 0, 0, 0, 255);
	env->surface = SDL_CreateRGBSurface(0, env->w, env->h, 32, 0, 0, 0, 0);
	init_audio(env);
	ttf_init(env);
	load_sprites(env);
}
