# SOURCES

SRC = animation_manager.c\
	  animations_ray.c\
	  big_menu.c\
	  buy_item.c\
	  bresenham.c\
	  compass.c\
	  controls.c\
	  create_sprites_array.c\
    	  create_threads.c\
	  doom_editor_hud.c\
	  doom_editor_hud_buttons.c\
	  doom_editor_hud_right.c\
	  doom_editor_hud_various.c\
	  doom_editor_init.c\
	  doom_editor_init_texts.c\
	  doom_editor_init_tools.c\
	  doom_editor_keycmds_mapsize.c\
	  doom_editor_keycmds_other.c\
	  doom_editor_keycmds_other2.c\
	  doom_editor_map.c\
	  doom_editor_map_quad.c\
	  doom_nukem.c\
	  draw.c\
	  draw_text.c\
	  elem_menu.c\
	  end_game.c\
	  enemies.c\
	  enemies2.c\
	  env_init.c\
	  events.c\
	  events2.c\
	  floor_and_ceiling.c\
	  free_functions.c\
	  free_functions2.c\
	  free_functions3.c\
	  free_functions4.c\
	  gain_item.c\
	  glass_wall.c\
	  hud.c\
	  hud2.c\
	  hud3.c\
	  init.c\
	  interact_arrows.c\
	  interact_keys.c\
	  intro.c\
	  isaac_moves.c\
	  load_animations.c\
	  load_animations2.c\
	  load_audio.c\
	  load_door_paths.c\
	  load_paths.c\
	  load_textures.c\
	  lst_manager.c\
	  main.c\
	  menu2.c\
	  menu3.c\
	  menu4.c\
	  minimap.c\
	  misc.c\
	  misc2.c\
	  misc3.c\
	  misc4.c\
	  mouse_controls.c\
	  parsing.c\
	  parsing_2.c\
	  parsing_3.c\
	  place_poster.c\
	  play_audio.c\
	  ray_casting.c\
	  set_values.c\
	  shooting.c\
	  sprite_selector.c\
	  sprites.c\
	  text_manager.c\
	  ticks_manager.c\
	  tnt_explosion.c\
	  who_draw.c\
	  who_enemies.c\
	  who_general.c\
	  who_interact_arrows.c\
	  who_shooting.c

# PATH

SRC_PATH := src
OBJ_PATH := obj
FRAMEWORK_PATH := frameworks
FRAMEWORK := SDL2 SDL2_ttf SDL2_image SDL2_mixer


LIB_PATH := ./libft
LIB := $(LIB_PATH)/libft.a

# OBJECTS AND DEPENDENCY

OBJ := $(SRC:%.c=$(OBJ_PATH)/%.o)
DEP := $(OBJ:%.o=%.d)

# GLOBAL

CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror
NAME = doom-nukem

ifeq ($(shell uname 2>/dev/null),Darwin) # Mac OS X
	LIB := -rpath @loader_path/$(FRAMEWORK_PATH) $(addprefix -framework ,$(FRAMEWORK)) $(FRAMEWORK_PATH:%=-F %) -lm
	HEADERS_PATHs := inc /usr/include/SDL2 libft
	INCLUDE := $(HEADERS_PATHs:%=-I%) $(FRAMEWORK:%=-I$(FRAMEWORK_PATH)/%.framework/Headers/)
endif
ifeq ($(shell uname 2>/dev/null),Linux)
	HEADERS_PATHs := inc /usr/include/SDL2 /usr/include/x86_64-linux-gnu/SDL2/ libft
	LIB := $(addprefix -l,$(FRAMEWORK)) -lm -lpthread
	INCLUDE := $(HEADERS_PATHs:%=-I%)
endif


# RULES

.PHONY: all
all:
	@echo "\033[32mCompilation's flags: \033[36m$(CFLAGS)"
	@echo "\033[32mFrameworks | Libs : \033[36m$(FRAMEWORK)"
	@echo "\033[32mGenerating objects :\033[0m"
	@$(MAKE) -C libft/ -j
	@$(MAKE) -j $(NAME)


$(NAME): $(OBJ)
	@echo "\033[34mGenerated : \033[5;36m$(NAME)\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDE) $^ $(LIB) -Llibft -lft -o $@

-include $(DEP)
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -MMD -c $< -o $@
	@echo "\033[1;31m  >>  \033[4;34m$@\033[0m"

.PHONY: clean
clean:
	@echo "\033[1;31mObject's removed\033[0m"
	@$(MAKE) -C libft/ clean
	@$(RM) -r $(OBJ_PATH)

.PHONY: fclean
fclean:
	@echo "\033[1;31m$(NAME) removed\033[0m"
	@$(MAKE) -C libft/ fclean
	@$(MAKE) clean
	@$(RM) $(NAME)

.PHONY: re
re:
	@$(MAKE) fclean
	@$(MAKE) all
