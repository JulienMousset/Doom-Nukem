/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_nukem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:58:21 by jmousset          #+#    #+#             */
/*   Updated: 2020/06/05 21:20:24 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_NUKEM_H
# define DOOM_NUKEM_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>
# include <SDL_mixer.h>
# include "libft.h"
# include "animations.h"
# include "audio.h"
# include "colors.h"
# include "sprites.h"
# include "strings.h"

# define W 1024
# define H 768

# define TS 64
# define PW 480
# define PH 240

# define THREADS 4
# define FOR_WALLS 1
# define FOR_SPRITES 2

# define MOVE_SPEED 0.15
# define ROT_SPEED 0.08
# define SCALE_MS 2
# define SCALE_TEAR 0.5
# define SENSIBILITY 1
# define INTERVAL 1000
# define CANDLE_INT 3
# define RESET_TIME 1.5
# define SHINE_FREQ 5
# define JUMP_LIMIT 7
# define FLY_LIMIT 10
# define CROUCH_LIMIT 10

# define ED_HUD_RIGHT_SIZE 360
# define ED_HUD_ITEM_SIZE 45
# define ED_HUD_ITEM_PER_ROW 8
# define ED_HUD_BOTTOM_SIZE 100
# define ED_HUD_BOTTOM_INFO_SIZE 40

# define FT_MENU_SZ 40
# define FT_MENU_SZ_HELP 35

# define SDL_INIT_TIMER_VIDEO_EVENTS 0x00004021

typedef struct		s_editorkeys
{
	int	b_add_columns;
	int	b_rem_columns;
	int	b_add_lines;
	int	b_rem_lines;
	int	b_save;
	int	b_lvmus;
}					t_editorkeys;

typedef struct		s_editor
{
	SDL_Point		offset;
	int				zoom;
	int				quit;
	int				keys[SDL_NUM_SCANCODES];
	SDL_Point		mouse_click;
	int				pick_block;
	SDL_Point		mouse;
	SDL_Texture		*tex[NUM_TEX];
	SDL_Texture		*text_tex[18];
	SDL_Rect		text_tex_size[18];
	t_editorkeys	ek;
	int				info_texindex;
	int				info_opacity;
	int				nb_lines_bcpy;
}					t_editor;

typedef struct		s_coord
{
	int	x;
	int	y;
}					t_coord;

typedef struct		s_complex
{
	double	x;
	double	y;
}					t_complex;

typedef struct		s_lst
{
	t_coord			c;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_sprite
{
	double		x;
	double		y;
	int			i;
	int			hp;
	t_coord		old_pos;
	t_coord		new_pos;
	Uint32		ticks_move;
	Uint32		ticks_attack;
}					t_sprite;

typedef struct		s_spr
{
	double		x;
	double		y;
	int			width;
	int			height;
}					t_spr;

typedef struct		s_pointer_param
{
	SDL_Point	resol;
	int			prev_menu;
	SDL_Rect	rect;
	int			val_sd[10];
	int			level;
}					t_pointer_param;

typedef struct		s_anim
{
	int			frames;
	Uint32		ticks;
	double		sec;
	int			max_frames;
	t_coord		block;
}					t_anim;

typedef struct		s_card
{
	int	north;
	int	east;
	int	south;
	int	west;
}					t_card;

typedef struct		s_bre
{
	t_coord	delta;
	int		boo;
	int		inc;
	double	div;
	int		i;
	int		j;
}					t_bre;

typedef struct		s_map
{
	int			close_requested;
	char		**board;
	char		**board_cpy;
	char		**tmp;
	char		*line;
	int			nb_lines;
	int			nb_columns;
	t_coord		fac;
	Uint32		reset_ticks;
	t_lst		*tnt_lst;
	t_coord		first_tnt;
	t_complex	pos;
	t_complex	pos_cpy;
	SDL_Point	orig_ppos;
	char		*level;
	int			h2;
	t_complex	dir;
	t_complex	plane;
	int			y_start;
	int			y_end;
	int			d;
	int			nb_sprites;
	t_sprite	*s;
	int			*spr_order;
	double		*spr_dist;
	double		*z_buffer;
	t_spr		spr;
	double		inv_det;
	t_complex	transform;
	int			ssx;
	int			x_start;
	int			x_end;
	int			v_move;
	t_coord		poster_pos;
	t_coord		poster_or;
	t_card		card;
	int			poster_id;
	Uint32		poster_ticks;
	double		jump;
	int			isaac_high;
	int			isaac_dir;
	Uint32		isaac_ticks;
	int			jump_bool;
	int			fly_bool;
	int			crouch_bool;
	int			space_times;
	t_coord		hud_margin;
	char		*hud_str;
	int			score;
	int			container;
	int			pick_heart;
	int			pick_key;
	int			pick_coin;
	int			item_odd;
	Uint32		odd_ticks;
	int			item_map;
	int			item_heels;
	int			item_candle;
	int			item_dinner;
	int			item_swallowed;
	int			item_vampire;
	int			item_cricket;
	int			item_poly;
	int			item_ipecac;
	int			item_godhead;
	int			item_quarter;
	int			item_axe;
	int			item_mantle;
	int			item_xray;
	int			item_lov;
	int			admin_mode;
	int			opt;
	t_coord		mm_start;
	t_coord		mm_center;
	t_coord		mm_end;
	int			mm_size;
	int			mm_vis;
	int			mm_block_size;
	t_coord		mm_margin;
	int			mm_color;
	int			i;
	int			r;
	int			id;
	double		move_coef;
	double		rot_coef;
	int			color;
	t_coord		prev_id;
	int			nb_lever;
	int			nb_lever_doors;
	int			lever_counter;
	Uint32		lever_ticks;
	int			up;
	int			down;
	int			left;
	int			right;
	int			strafe_left;
	int			strafe_right;
	int			look_up;
	int			look_down;
	int			run;
	int			bool_dead;
	int			bool_win;
	int			bool_tear;
	t_coord		spr_block;
	t_anim		anim[NUM_ANIM];
	int			run_anim;
	int			intro;
	int			check_hit;
	int			shine_freq;
	double		camera_x;
	t_complex	ray_dir;
	t_coord		block;
	t_complex	side;
	t_complex	delta;
	double		perp;
	t_coord		step;
	int			hit;
	int			ns_or_ew;
	t_coord		tear_pos;
	double		tear_scale;
	t_coord		new_pos;
	int			dople_spr;
	int			wiz_spr;
	Mix_Music	*music[NUM_MUSIC];
	Mix_Chunk	*sfx[NUM_SFX];
	int			music_on;
	int			sfx_on;
	int			volume_music;
	int			volume_sfx;
	int			hurt;
	int			transition;
	int			lvl;
	int			lvl_music;
	int			menu_transition;
	int			intro_transition;
	int			final_score;
	double		move_speed;
}					t_map;

typedef struct		s_env
{
	SDL_Window		*win;
	Uint32			render_flags;
	SDL_Renderer	*rend;
	SDL_Surface		*surface;
	SDL_Event		event;
	t_map			*map;
	int				w;
	int				h;
	SDL_DisplayMode	desktop_dm;
	SDL_DisplayMode	window_dm;
	SDL_DisplayMode	screen;
	SDL_Color		font_color;
	SDL_Color		white;
	int				font_size;
	char			*font_path;
	Uint32			ticks;
	t_coord			fps;
	char			*fps_str;
	SDL_Surface		*t[NUM_TEX];
	SDL_Surface		*cyclic[3][6];
	SDL_Surface		*doors[3][12];
	SDL_Surface		*beggars[4][2];
	SDL_Surface		*trophy[3];
	SDL_Surface		*tears[2][15];
	SDL_Surface		*explosions[2][8];
	SDL_Surface		*b[2][2];
	SDL_Surface		*panel[7];
	char			*story[7];
	t_coord			margin;
	char			*path[NUM_TEX];
	char			*door_paths[3][12];
	TTF_Font		*ft;
	TTF_Font		*ft_help;
	int				fullscreen;
	int				menu;
	SDL_Point		press;
	SDL_Point		mouse_menu;
	t_pointer_param	pt;
	SDL_Surface		*image[3];
	SDL_Texture		*texture[3];
	SDL_Texture		*hud[NUM_TEX];
	int				mouse;
	t_coord			mouse_pos;
	t_editor		ed;
	SDL_Texture		*text;
	t_coord			add;
}					t_env;

typedef struct		s_thread
{
	pthread_t	t;
	int			n;
	t_env		*env;
	int			x_start;
	int			x_end;
	double		camera_x;
	t_complex	ray_dir;
	t_coord		block;
	t_complex	side;
	t_complex	delta;
	double		perp;
	t_coord		step;
	int			hit;
	int			ns_or_ew;
	int			line_height;
	int			y_start;
	int			y_end;
	int			id;
	int			x_saved;
	int			saved;
	int			skip;
	int			glass_hit;
	int			line_start;
	int			line_end;
	int			line_dif;
	t_coord		tex;
	int			color;
	int			i;
	double		wall_x;
	int			dif;
	t_complex	floor;
	double		dist_wall;
	double		dist_play;
	double		dist_curr;
	t_complex	curr_floor;
}					t_thread;

typedef uint32_t	(*t_timerhook)(uint32_t interval, t_env *e);
typedef int		(*t_eventhook)(t_env *e);

t_sprite			add_sprite(t_map *map, double x, double y, int i);
void				admin_mode(t_map *map);
void				alloc_arrays(t_env *env);
int					animate_sprite(t_map *map, int index);
void				animation_manager(t_env *env, t_anim *anim);
char				*array_cpy(char *src, int size);
void				beggar_animation(t_env *env, t_thread *t);
void				beggar_animations(t_env *env);
void				bloodtear_animation(t_env *env);
char				**board_cpy(char **src, int nb_lines, int nb_columns);
int					bresenham(t_map *map, t_coord a, t_coord b);
void				bubble_sort(int *order, double *dist, int amount);
void				button(t_env *p, char *str, void func(t_env *), int index);
void				buy_item(t_map *map, int id);
void				buy_item2(t_map *map, int id);
void				buy_item_99(t_map *map, int id);
void				cardinal_animation(t_env *env, t_map *map, t_thread *th);
int					ch_resol(t_env *p, int x, int y);
void				change_level(t_env *p);
void				change_menu(t_env *p);
void				free_menu(t_env *env);
void				change_resol(t_env *p);
int					check_board(t_map *map);
int					check_file(t_env *env, char *file);
int					check_map(char *s);
int					choose_color(t_map *map, char id);
void				close_program(t_env *env, int value);
t_coord				coord(t_env *env, int id, int n);
int					count_columns(char *s);
int					count_lines(t_map *map, char *file);
SDL_Rect			create_big_menu(t_env *p);
SDL_Rect			create_menu(t_env *p);
void				create_sprites_array(t_env *env);
void				create_threads(t_env *env, int id);
void				credits(t_env *p);
void				crouch(t_map *map);
void				curse_door(t_map *map, int id);
void				cyclic_sprites(t_thread *t, t_env *env, t_map *map);
void				damage_enemy(t_env *env, int id);
void				damage_near_blocks(t_env *env, t_coord i);
Uint32				darken(t_env *env, Uint32 c, double d, int candle);
void				dda(t_thread *t);
void				dda_tear(t_map *map);
void				dda_values_tear(t_map *map);
void				disable_mouse(t_env *env);
void				display_info(t_env *e, int texindex);
void				display_menu(t_env *p);
int					doom_editor(char *file);
int					doom_nukem(char *file, int is_arg);
void				draw_aim(t_env *env);
void				draw_background(t_env *env);
void				draw_intro(t_env *env, int id, t_coord margin, int scale);
void				draw_line(t_env *env, t_thread *th, int x, int y_start);
void				draw_mini_background(t_env *env, t_map *map);
void				draw_minimap(t_env *env, t_map *map);
void				draw_text(t_env *env, char *text, int x, int y);
int					draw_text_help(t_env *p, char *text, SDL_Point coord,
SDL_Color color);
int					draw_text_rdr(t_env *p, char *text, SDL_Point coord,
SDL_Color color);
void				drop(t_map *map, int x, int y, int id);
void				e_add_columns(t_env *e);
void				e_add_lines(t_env *e);
void				e_boolcheck(t_env *e, int sdl_scancode, int *b_check,
void (*b_func)(t_env *));
SDL_Point			e_check_unique(t_env *e, int block_id);
void				e_draw_bottom_hud(t_env *e);
void				e_draw_bottom_hud_info(t_env *e);
void				e_draw_right_hud(t_env *e);
void				e_draw_right_hud_block(t_env *e, SDL_Point baseline,
int count, int *hudcount);
void				e_draw_right_hud_countfor(t_env *e, int first, int last,
int *hudcount);
void				e_draw_right_hud_elements(t_env *e, int *hudcount,
SDL_Point baseline);
void				e_draw_right_hud_special(t_env *e);
void				e_drawquad(t_env *e);
void				e_drawsquare(t_env *e, SDL_Point pos, SDL_Point qc);
SDL_Rect			e_drhb_not_zoom(SDL_Point bl, int *hc);
SDL_Rect			e_drhb_zoom(SDL_Point bl, int *hc);
int					e_events_hook(t_env *e);
void				e_funcpoint(t_env *e, int block_id, SDL_Point coords);
int					e_hover_mouse_blk(t_env *e, SDL_Rect rect, int is_hud);
int					e_init(t_env **e);
int					e_init_structure(t_env *env, char *file);
void				e_lvmus_button(t_env *e);
void				e_lvmus_click(t_env *e, int map_or_music);
int					e_mapcheck(t_env *e);
int					e_mapcheck_isblock(int block_id);
void				e_offsets(t_env *e);
void				e_pick_block(t_env *e);
void				e_place_unique(t_env *e, SDL_Point coords, int block_id);
void				e_rem_columns(t_env *e);
void				e_rem_lines(t_env *e);
void				e_replace_player(t_env *e);
void				e_save(t_env *e);
int					e_save_map(t_env *e);
void				e_save_and_play(t_env *e);
void				e_ttf_init(t_env *env);
void				e_var_init(t_env *env);
void				e_write_map(t_env *env);
int					east(t_map *map, int x);
void				editor_loop(t_env *e, t_timerhook render,
t_eventhook event);
uint32_t			editor_render_hook(uint32_t interval, t_env *e);
void				editor_switch(int map_id);
void				end_game(t_env *env, t_map *map);
void				enemies(t_map *map);
void				enemy_baby(t_map *map, t_coord pos_player, int i);
void				enemy_dople(t_map *map, t_coord pos_player, int i);
void				enemy_rotty(t_map *map, t_coord pos_player, int i);
void				enemy_wizoob(t_map *map, t_coord pos_player, int i);
void				env_init(t_env *e);
void				env_init2(t_env *e);
void				events(t_env *env);
void				exit_program(t_env *env, char *error);
void				exit_program_in_tab(t_env *env, int *i, char *error);
void				explosion_animation(t_env *env, t_thread *t);
int					fill_board(t_env *env, int fd);
int					fill_board2(t_env *env, int *i, int *j, int *player);
void				filling(t_env *env, int i, int *j, int *player);
int					final_score(t_map *map);
void				first_spacebar_pressed(t_map *map);
void				floor_and_ceiling(t_thread *t, t_env *env, t_map *map,
int x);
void				floor_casting(t_thread *t, t_env *env, t_map *map, int x);
void				fly(t_map *map);
void				fps_think(t_env *env);
void				free_and_display_usage(t_env *env, char *s);
void				free_anim_ticks(t_env *env);
void				free_beggars(t_env *env);
void				free_doors(t_env *env);
void				free_ed_textures(t_env *env);
void				free_explosions(t_env *env);
void				free_lst(t_lst **lst);
void				free_panels(t_env *env);
void				free_program(t_env *env);
void				free_program_in_tab(t_env *env, int *i);
void				free_shared_structures(t_env *env);
void				free_shared_structures_in_tab(t_env *env, int i);
void				free_sounds(t_map *map);
void				free_structures(t_env *env);
void				free_tears(t_env *env);
void				free_textures(t_env *env);
void				free_threads(t_thread *t);
void				ft_lst_add(t_lst **alst, t_lst *new);
void				ft_lst_del(t_lst **alst);
int					ft_lst_iter(t_map *map, t_lst *alst, t_coord c);
t_lst				*ft_lst_new(t_env *env, int x, int y);
void				ft_lst_realloc(t_env *env, t_lst *alst);
void				gain_item(t_map *map, int id);
void				gain_item2(t_map *map, int id);
void				gain_item3(t_map *map, int id);
void				gain_item4(t_map *map, int id);
void				gamble(t_map *map, char **board);
void				gamble_beggar_heart(t_map *map);
void				get_hud_text(t_env *env, t_map *map);
Uint32				get_pixel(SDL_Surface *surface, int x, int y);
Uint32				get_pixel2(SDL_Surface *surface, int x, int y);
void				get_shop_text(t_env *env, t_map *map, char **board);
void				get_sprite_text(t_env *env, int id);
void				glass_wall_init(t_thread *t);
void				glass_wall_reset(t_thread *t);
void				go_to_editor(t_env *p);
void				help_menu(t_env *p);
void				*horizontal_loop(void *vt);
int					hover_mouse(t_env *p, SDL_Rect rect);
void				hud(t_env *env, t_map *map, char **board);
void				image_to_window(t_env *env, t_map *map);
void				init_audio(t_env *env);
int					init_menu(t_env *env, int is_arg);
void				init_music(t_env *env);
void				init_sfx(t_env *env);
void				init_sfx_2(t_env *env);
void				interact_beggar(t_map *map, int id);
void				interact_keys(t_map *map);
void				intro(t_env *env, t_map *map);
void				intro_menu(t_env *p);
int					is_animation(t_thread *t);
int					is_any_wall(int id);
int					is_beggar(int id);
int					is_bluish(t_map *map, int id);
int					is_destroy(t_map *map, int id);
int					is_destroyable(t_map *map, int id);
void				is_destroyed(t_env *env, int id);
int					is_door(t_map *map, int id, int x, int y);
int					is_door_closed(t_map *map, int id, int x, int y);
int					is_enemy_id(int id);
int					is_hit(t_thread *t);
int					is_id(t_map *map, t_coord c);
int					is_isaac(t_map *map, t_coord c);
int					is_isaac_near(t_map *map, t_sprite *spr, t_coord pos);
int					is_not_busy(t_anim anim);
int					is_orientation(t_thread *t);
int					is_pickable(t_map *map, int id);
int					is_poster(t_thread *t);
int					is_secret(t_map *map);
int					is_shop(t_map *map, int id, int coin);
int					is_tear_obstacle(int id);
int					is_valid(char *s, int i);
int					is_valid_char(int i);
int					is_valid_first_line(t_map *map, char *s, int *first);
int					is_walk(int id);
int					is_walkable(t_env *env, int id, int x, int y);
int					is_zoomable(int block_id);
void				isaac_hurt(t_map *map);
void				isaac_is_attacked(t_map *map, t_sprite *spr);
void				isaac_moves(t_map *map);
void				jump(t_map *map);
void				jump_hud(t_env *e, int *hudcount, int txti);
void				key_press(t_env *env, t_map *map, SDL_Event event);
void				key_press2(t_env *env, t_map *map, SDL_Event event);
void				key_press3(t_env *env, t_map *map, SDL_Event event);
void				key_press4(t_env *env, t_map *map, SDL_Event event);
void				key_release(t_map *map, SDL_Event event);
void				left_or_right(t_env *env, double rot_coef);
void				level_editor(t_env *p);
void				level_processing(t_env *env);
void				levels_menu(t_env *p);
void				load_anim_ticks(t_env *env);
void				load_animations(t_env *env);
void				load_door_paths_1(char **path);
void				load_door_paths_2(char **path);
void				load_door_paths_3(char **path);
void				load_explosions(t_env *env);
Mix_Music			*load_music(t_env *env, char *filename);
void				load_panels(t_env *env);
void				load_paths(char **path);
void				load_paths2(char **path);
void				load_paths3(char **path);
void				load_paths4(char **path);
Mix_Chunk			*load_sfx(t_env *env, char *filename);
SDL_Surface			*load_sprite(t_env *env, char *path);
void				load_sprites(t_env *env);
void				load_story(t_env *env);
SDL_Texture			*load_tex(t_env *env, char *path);
void				load_tex2(t_env *e);
void				main_menu(t_env *p);
void				mouse_events(t_env *env, t_map *map);
void				mouse_move(t_env *env, t_map *map);
void				mouse_press(t_map *map);
void				move_enemy(t_map *map, t_coord pos_spr, int i, int enemy);
void				multiple_events(t_env *env);
void				mushroom(unsigned char *r, unsigned char *g,
unsigned char *b, double d);
int					nb_sprites(t_map *map);
int					north(t_map *map, int x);
void				open_door_animation(t_env *env, t_thread *th);
void				open_lever_doors(t_map *map);
void				option_menu(t_env *p);
void				paint_walls(t_env *env, t_thread *th, int x, int y_start);
int					parsing(t_env *env, char *file);
void				pickup_chance(t_map *map, int id);
void				pickup_chance2(t_map *map, int id);
void				place_poster(t_map *map, t_card *card);
void				play_music(t_map *map, int i);
void				play_sfx(t_map *map, int i);
void				pre_set_values(t_env *env, char *file);
void				print_hearts(t_env *env, t_map *map);
void				print_hearts2(t_env *env, t_map *map);
void				print_items_hud(t_env *env, t_map *map, int n);
void				print_items_hud2(t_env *env, t_map *map, int n);
void				print_items_hud3(t_env *env, t_map *map, int n);
void				print_items_hud4(t_env *env, t_map *map, int n);
void				print_items_hud5(t_env *env, t_map *map, int n);
void				print_mini_sprite(t_env *env, int id, t_coord margin,
int scale);
void				print_mini_tear(t_env *env, int id, t_coord margin,
double scale);
void				print_tear(t_env *env, t_map *map);
void				process_music(t_env *env);
void				put_n_pixel(t_env *env, int xx, int yy, char id);
void				put_pixel(t_env *env, int x, int y, int color);
int					query_hp(t_map *map, int x, int y, int damage);
int					randomy(int min, int max);
void				*ray_casting(void *vt);
void				realloc_array(t_env *env, int x, int y, int id);
void				render_processing(t_env *env);
void				reset_game(t_env *env, t_map *map);
void				reset_mouse(t_env *env);
void				reset_player_movements(t_env *env);
void				resolution_menu(t_env *p);
void				resolution_reset_values(t_env *p);
void				run_hud(t_env *env, t_map *map);
int					run_loop(t_map *map, t_bre b, t_coord a);
void				save_sprite_id(t_map *map, int i);
void				sdl_init(t_env *env);
void				set_item_values(t_map *map);
void				set_keys_and_anim_values(t_map *map);
void				set_level_id(t_map *map);
void				set_line_values(t_thread *t);
void				set_orientation(t_map *map, t_card *card, t_coord ran);
void				set_poster_values(t_map *map, t_coord *c, int *n);
int					sdl_loop(t_env *env);
double				sensibility(double delta, int index);
void				set_boundaries(t_map *map);
void				set_casting_values(t_thread *t);
void				set_dda_values(t_thread *t, t_map *map);
int					set_dople_direction(t_map *map, int i, t_coord pos_player,
t_coord *c);
void				set_dople_sprite(t_map *map, t_coord c);
int					set_frame(t_anim *anim);
void				set_mmap_values(t_env *env, t_map *map, int opt);
void				set_nb_menu(t_env *p);
void				set_sprite_values(t_env *env, t_map *map, int i);
void				set_thread_values(t_thread *t, t_env *env, int i);
void				set_values(t_env *env, t_map *map);
void				set_values2(t_env *env, t_map *map);
void				set_walls(t_thread *t, t_map *map, int x_start);
void				set_wizoob_area(t_map *map, t_sprite *new, int x, int y);
void				set_wizoob_sprite(t_map *map);
void				shoot_tear(t_env *env, t_map *map);
void				shop_hud(t_env *env, t_map *map, char **board);
int					show_gamble_text(t_map *map, int id);
int					slider(t_env *p, char *str, int id);
SDL_Rect			slider_button(t_env *p, SDL_Rect rect2, int val, int index);
void				slider_text(t_env *p, SDL_Rect rect, char *str, int val);
int					slider_val(t_env *p, SDL_Rect rect2, int index,
int intval[10]);
void				spacebar_pressed(t_map *map);
void				sprite_selector(t_thread *t, t_env *env, t_map *map);
void				sprites(t_env *env, t_map *map);
int					south(t_map *map, int x);
void				start_new_run(t_env *p);
void				stop_animation(t_env *env, t_anim *anim, t_coord c, int i);
void				strafe(t_env *env, char **board, t_complex dir);
void				surface_processing(t_env *env);
void				take_poster(t_map *map);
void				tear_animation(t_env *env);
void				text_init(t_env *e);
void				text_init_tex(t_env *e, TTF_Font *font);
void				text_init_tex_size(t_env *e, TTF_Font *font);
void				text_init_tex_size2(t_env *e, TTF_Font *font);
void				text_manager(t_env *env, t_map *map, char **board);
SDL_Texture			*text2tex(t_env *e, TTF_Font *font, char *text,
SDL_Color color);
void				ticks_init(Uint32 *ticks);
int					ticks_passed(Uint32 *ticks, double sec);
void				ticks_reset(Uint32 *ticks);
void				tnt_and_poop(t_thread *t, t_env *env, t_map *map);
void				tnt_explosion(t_env *env, int x, int y);
void				toggle_fullscreen(t_env *p);
void				ttf_init(t_env *env);
void				up_or_down(t_env *env, char **board, t_complex dir);
void				vertical_loop(t_thread *t, t_env *env, t_map *map);
int					west(t_map *map, int x);
void				won_or_lost(t_env *env, t_map *map);
void				write_metadata(t_env *e, int fd);

#endif
