/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:11:30 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/05 13:21:10 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_H
# define STRINGS_H

# define ERR_USAGE "Usage: ./doom-nukem <filename>"
# define ERR_MALLOC "Error trying to allocate memory."
# define ERR_DIR "You're trying to read on a directory or a wrong file."
# define ERR_WRONG "Wrong input. Your map can only contain digits and letters."
# define ERR_BORDER "Invalid char in the borders of your map (empty or glass)."
# define ERR_NO_PLAYER "No player placed on your map."
# define ERR_PLAYER "More than one player placed on your map."
# define ERR_LINE "Your map needs the same number of lines for each column."
# define ERR_BOARD "Error trying to create the map."
# define ERR_SURFACE "Error trying to create surface."
# define ERR_TEX "Error trying to create texture."

# define PATH_FONT_GAME "resources/fonts/game.ttf"
# define FT_MENU_PATH "resources/fonts/menu.ttf"
# define ED_FONT_PATH "resources/fonts/editor.ttf"

# define PATH_LEVEL_0 "maps/level_0"
# define PATH_LEVEL_1 "maps/level_1"
# define PATH_LEVEL_2 "maps/level_2"
# define PATH_LEVEL_3 "maps/level_3"

# define ED_LINES "Lines +/- [Q/W]"
# define ED_COLUMNS "Columns +/- [A/S]"
# define ED_ZOOM "Zoom +/- [Z/X]"
# define ED_PICK "Pick Block [E]"
# define ED_MOVE "Move with arrows"
# define ED_SAVE "Save [D]"
# define ED_SAVEPLAY "Save & Play [C]"
# define ED_QUIT "Quit [ESC]"
# define ED_ERR_W "Map borders must be walls."
# define ED_SAVED "Map saved."

# define ED_OBJ_BLOCKS "Blocks"
# define ED_OBJ_ITEMS1 "$99 items"
# define ED_OBJ_ITEMS2 "$15 items"
# define ED_OBJ_ITEMS3 "$5 items"
# define ED_OBJ_ITEMS4 "Pickups"
# define ED_OBJ_SOLID "Solid objects"
# define ED_OBJ_INTER "Interactive entities"
# define ED_LVMUS "Niveau / musique"

# define CON "CONTROLS"
# define CON_0 "[M]ENU"
# define CON_1 "[WASD]/[ARROWS]: Move"
# define CON_2 "[Q]/[E]: Strafe"
# define CON_3 "[<]/[>]: Look Up/Down"
# define CON_4 "[SHIFT]: Run"
# define CON_5 "[SPACE]: Jump"
# define CON_6 "Double [SPACE]: Fly"
# define CON_7 "[LEFT CTRL]: Crouch"
# define CON_8 "[TAB]: Map"
# define CON_9 "Hold [R]: Restart level"
# define CON_10 "[1]/[2]: Gain Coins/Keys"
# define CON_11 "[3]/[4]: Loose/Gain Life"
# define CON_12 "[9]: Admin Mode"
# define CON_13 "[ESC]: Quit"

# define POOR "NOT ENOUGH COINS"
# define FULL_HEALTH "FULL HEALTH"
# define PRESS "PRESS [G] TO GAMBLE"
# define PRESS2 "PRESS [F] TO PULL"
# define ISAAC_HEARS "(...)"

# define QUOTE1_1 "Did you know that the end of the game"
# define QUOTE1_2 "is actually 4 tiles behind my back?"
# define QUOTE2_1 "I miss my owner."
# define QUOTE2_2 "He still has my left paw."
# define QUOTE3_1 "The first known account of execution by hanging"
# define QUOTE3_2 "was in Homer's Odyssey (Book XXII)."

# define WIN "Dear Diary, today I WON."
# define LOSE "Dear Diary, today I DIED."
# define END1 "Press [ESC] to EXIT."
# define END2 "Press [SPACE] to RETRY."
# define END3 "Press [SPACE] to CONTINUE."

#endif
