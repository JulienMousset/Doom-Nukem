/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:24:28 by pasosa-s          #+#    #+#             */
/*   Updated: 2020/06/01 17:42:41 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

# define NUM_TEX 85

# define LAST_SOLID_WALL '5'

# define FIRST_WALL '1'
# define LAST_WALL '?'

# define FIRST_SPR '@'

# define FIRST_FREE 'B'
# define LAST_FREE 'L'

# define FIRST_SHOP 'M'
# define LAST_SHOP 'T'

# define FIRST_SHOP_99 'M'
# define LAST_SHOP_99 'O'

# define FIRST_SHOP_15 'P'
# define LAST_SHOP_15 'T'

# define FIRST_SHOP_5 'o'
# define LAST_SHOP_5 'p'

# define FIRST_ITEM 'F'
# define LAST_ITEM 'T'

# define FIRST_WALK ':'
# define LAST_WALK 'U'

# define FIRST_DESTRUCT 'V'
# define LAST_DESTRUCT 92

# define FIRST_SOLID 'V'
# define LAST_SOLID '`'

# define FIRST_INTER 'b'
# define LAST_INTER 'n'

# define FIRST_ENEMY 'k'
# define LAST_ENEMY 'n'

# define START_MENU_WPP "resources/textures/menu_wallpaper.png"
# define GAME_MENU_WPP "resources/textures/menu_game_wallpaper.png"
# define MENU_LOGO "resources/textures/menu_logo.png"

# define WALL1 "resources/textures/texture_wall_1.png"
# define WALL2 "resources/textures/texture_wall_2.png"
# define WALL3 "resources/textures/texture_wall_3.png"
# define WALL_GLASS "resources/textures/texture_window.png"
# define WALL_SHOP "resources/textures/texture_wall_shop.png"

# define DOOR_LEVER "resources/textures/texture_door.png"
# define DOOR_HEART "resources/textures/texture_door_heart_1.png"
# define DOOR_CLOSED "resources/textures/texture_door_locked_1.png"
# define DOOR_GOLDEN_CLOSED "resources/textures/texture_door_golden_1.png"
# define DOOR_OPEN "resources/textures/texture_door_open.png"
# define DOOR_GOLDEN_OPEN "resources/textures/texture_door_golden_open.png"
# define DOOR_CURSE "resources/textures/texture_door_curse.png"

# define WALL1_SECRET "resources/textures/texture_wall_secret_1.png"
# define WALL2_SECRET "resources/textures/texture_wall_secret_2.png"
# define WALL3_SECRET "resources/textures/texture_wall_secret_3.png"

# define HEART_RED "resources/textures/pickup_heart.png"
# define HEART_RED_HALF "resources/textures/pickup_heart_half.png"
# define KEY "resources/textures/pickup_key.png"
# define COIN "resources/textures/pickup_penny_1.png"
# define NICKEL "resources/textures/pickup_nickel_1.png"
# define ODD "resources/textures/item_odd_mushroom_thin.png"

# define MAP "resources/textures/item_treasure_map.png"
# define HEELS "resources/textures/item_moms_heels.png"
# define RED_CANDLE "resources/textures/item_red_candle.png"
# define DINNER "resources/textures/item_dinner.png"
# define SWALLOWED "resources/textures/item_swallowed_penny.png"
# define VAMPIRE "resources/textures/item_charm_of_the_vampire.png"
# define CRICKET "resources/textures/item_cricket_head.png"

# define POLY "resources/textures/item_polyphemus.png"
# define IPECAC "resources/textures/item_ipecac.png"
# define GODHEAD "resources/textures/item_godhead.png"
# define AXE "resources/textures/item_notched_axe.png"
# define HOLY_MANTLE "resources/textures/item_holy_mantle.png"
# define QUARTER "resources/textures/item_a_quarter.png"
# define XRAY_VISION "resources/textures/item_xray_vision.png"
# define LOV "resources/textures/item_lov.png"

# define COBWEB "resources/textures/obstacle_cobweb.png"
# define ROCK1 "resources/textures/obstacle_rock_1.png"
# define ROCK2 "resources/textures/obstacle_rock_2.png"
# define URN "resources/textures/obstacle_urn.png"

# define MUSHROOM1 "resources/textures/obstacle_mushroom_1.png"
# define MUSHROOM2 "resources/textures/obstacle_mushroom_2.png"
# define SKULL "resources/textures/obstacle_skull.png"
# define POOP "resources/textures/obstacle_poop_1.png"
# define TNT "resources/textures/obstacle_tnt_1.png"
# define CAMPFIRE "resources/textures/obstacle_fireplace_1.png"
# define DONATION_MACHINE "resources/textures/obstacle_donation_machine.png"
# define LEVER_OFF "resources/textures/obstacle_lever_1.png"
# define LEVER_ON "resources/textures/obstacle_lever_2.png"

# define TROPHY "resources/textures/obstacle_trophy_1.png"
# define SHOPKEEPER "resources/textures/npc_shopkeeper.png"
# define ERROR "resources/textures/npc_error.png"
# define GUPPY "resources/textures/npc_guppy.png"
# define HANGING "resources/textures/npc_hanging_shopkeeper.png"
# define BEGGAR_COIN "resources/textures/npc_beggar_1.png"
# define BEGGAR_DEVIL "resources/textures/npc_devil_beggar_1.png"
# define BEGGAR_KEY "resources/textures/npc_key_beggar_1.png"
# define DONATION_MACHINE_BLOOD "resources/textures/npc_blood_machine_1.png"

# define MULLIGAN "resources/textures/enemy_mulligan_left_1.png"
# define WIZOOB1 "resources/textures/enemy_wizoob_1.png"
# define WIZOOB2 "resources/textures/enemy_wizoob_2.png"
# define WIZOOB3 "resources/textures/enemy_wizoob_3.png"
# define WIZOOB4 "resources/textures/enemy_wizoob_4.png"
# define DOPLE "resources/textures/enemy_dople_up.png"
# define DOPLE_L "resources/textures/enemy_dople_left.png"
# define DOPLE_R "resources/textures/enemy_dople_right.png"
# define ROTTY "resources/textures/enemy_rotty.png"
# define BABY1 "resources/textures/enemy_baby_1.png"
# define BABY2 "resources/textures/enemy_baby_2.png"

# define SHIFT_OFF "resources/textures/hud_run_off.png"
# define SHIFT_ON "resources/textures/hud_run_on.png"

# define PLAYER "resources/textures/player.png"

# define CONTAINER_HEART_EMPTY "resources/textures/hud_heart_empty.png"
# define CONTAINER_HEART_RED "resources/textures/hud_heart_full.png"
# define CONTAINER_HEART_RED_HALF "resources/textures/hud_heart_half.png"

# define FLOOR1 "resources/textures/texture_floor_1.png"
# define FLOOR2 "resources/textures/texture_floor_2.png"
# define FLOOR3 "resources/textures/texture_floor_3.png"

# define TAG_5 "resources/textures/hud_price_tag_5.png"
# define TAG_15 "resources/textures/hud_price_tag_15.png"
# define TAG_99 "resources/textures/hud_price_tag_99.png"

# define CEILING1 "resources/textures/texture_ceiling_1.png"
# define CEILING2 "resources/textures/texture_ceiling_2.png"
# define CEILING3 "resources/textures/texture_ceiling_3.png"

# define POSTER1 "resources/textures/obstacle_poster_1.png"
# define POSTER2 "resources/textures/obstacle_poster_2.png"

# define ID_WALL1 '1'
# define ID_WALL2 '2'
# define ID_WALL3 '3'
# define ID_WALL_GLASS '4'
# define ID_WALL_SHOP '5'

# define ID_DOOR_LEVER '6'
# define ID_DOOR_HEART '7'
# define ID_DOOR_C '8'
# define ID_GDOOR_C '9'
# define ID_DOOR_O ':'
# define ID_GDOOR_O ';'
# define ID_CDOOR '<'

# define ID_SECRET1 '='
# define ID_SECRET2 '>'
# define ID_SECRET3 '?'

# define ID_RHEART '@'
# define ID_RHEART_HALF 'A'
# define ID_KEY 'B'
# define ID_COIN 'C'
# define ID_NICKEL 'D'
# define ID_ODD 'E'

# define ID_MAP 'F'
# define ID_HEELS 'G'
# define ID_CANDLE 'H'
# define ID_DINNER 'I'
# define ID_SWALLOWED 'J'
# define ID_VAMPIRE 'K'
# define ID_CRICKET 'L'

# define ID_POLY 'M'
# define ID_IPECAC 'N'
# define ID_GODHEAD 'O'
# define ID_AXE 'P'
# define ID_MANTLE 'Q'
# define ID_QUARTER 'R'
# define ID_XRAY 'S'
# define ID_LOV 'T'

# define ID_WEB 'U'
# define ID_ROCK1 'V'
# define ID_ROCK2 'W'
# define ID_URN 'X'
# define ID_MUSHROOM1 'Y'
# define ID_MUSHROOM2 'Z'
# define ID_SKULL '['
# define ID_POOP 92
# define ID_TNT ']'
# define ID_CAMPFIRE '^'
# define ID_DMACHINE '_'
# define ID_LEVER_OFF '`'
# define ID_LEVER_ON 'a'

# define ID_TROPHY 'b'
# define ID_SHOPKEEPER 'c'
# define ID_ERROR 'd'
# define ID_GUPPY 'e'
# define ID_HANGING 'f'
# define ID_BEGGAR_COIN 'g'
# define ID_BEGGAR_HEART 'h'
# define ID_BEGGAR_KEY 'i'
# define ID_BLOOD_MACHINE 'j'

# define ID_WIZOOB 'k'
# define ID_DOPLE 'l'
# define ID_ROTTY 'm'
# define ID_BABY1 'n'

# define ID_HEART_SHOP 'o'
# define ID_KEY_SHOP 'p'
# define ID_PLAYER 'q'

# define ID_CONTAINER_RED 65
# define ID_CONTAINER_HALF 66
# define ID_CONTAINER_EMPTY 67
# define ID_SHIFT_ON 62
# define ID_SHIFT_OFF 63

# define ID_FLOOR1 68
# define ID_FLOOR2 69
# define ID_FLOOR3 70

# define ID_TAG_5 71
# define ID_TAG_15 72
# define ID_TAG_99 73

# define ID_CEILING1 74
# define ID_CEILING2 75
# define ID_CEILING3 76

# define ID_POSTER1 77
# define ID_POSTER2 78

# define ID_BABY2 79
# define ID_DOPLE_L 80
# define ID_DOPLE_R 81
# define ID_WIZOOB2 82
# define ID_WIZOOB3 83
# define ID_WIZOOB4 84

#endif
