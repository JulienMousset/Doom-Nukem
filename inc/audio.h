/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:10:24 by jmousset          #+#    #+#             */
/*   Updated: 2020/02/12 12:32:37 by jmousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUDIO_H
# define AUDIO_H

# define NUM_MUSIC 7
# define NUM_SFX 39

# define DEATH "resources/music/death.ogg"
# define EDITOR "resources/music/editor.ogg"
# define LEVEL_1 "resources/music/level_1.ogg"
# define LEVEL_2 "resources/music/level_2.ogg"
# define LEVEL_3 "resources/music/level_3.ogg"
# define STORE "resources/music/store.ogg"
# define TITLE "resources/music/title.ogg"

# define SFX_BUTTON "resources/sfx/button.wav"
# define SFX_DEATH_1 "resources/sfx/death_1.wav"
# define SFX_DEATH_2 "resources/sfx/death_2.wav"
# define SFX_DEATH_3 "resources/sfx/death_3.wav"
# define SFX_DOOR_OPEN "resources/sfx/door_open.wav"
# define SFX_ENEMY_BABY_1 "resources/sfx/enemy_baby_1.wav"
# define SFX_ENEMY_BABY_2 "resources/sfx/enemy_baby_2.wav"
# define SFX_ENEMY_DEATH "resources/sfx/enemy_death.wav"
# define SFX_ENEMY_ROTTY_1 "resources/sfx/enemy_rotty_1.wav"
# define SFX_ENEMY_ROTTY_2 "resources/sfx/enemy_rotty_2.wav"
# define SFX_ENEMY_WIZOOB "resources/sfx/enemy_wizoob.wav"
# define SFX_EXPLOSION "resources/sfx/explosion.wav"
# define SFX_GAMBLE_1 "resources/sfx/gamble_1.wav"
# define SFX_GAMBLE_2 "resources/sfx/gamble_2.wav"
# define SFX_GAMBLE_3 "resources/sfx/gamble_3.wav"
# define SFX_HEART_DOWN "resources/sfx/heart_down.wav"
# define SFX_HEART_UP "resources/sfx/heart_up.wav"
# define SFX_HIT "resources/sfx/hit.wav"
# define SFX_ITEM "resources/sfx/item.wav"
# define SFX_KEY "resources/sfx/key.wav"
# define SFX_MAP "resources/sfx/map.wav"
# define SFX_MENU_1 "resources/sfx/menu_1.wav"
# define SFX_MENU_2 "resources/sfx/menu_2.wav"
# define SFX_MUSHROOM_1 "resources/sfx/mushroom_1.wav"
# define SFX_MUSHROOM_2 "resources/sfx/mushroom_2.wav"
# define SFX_NICKEL "resources/sfx/nickel.wav"
# define SFX_PENNY "resources/sfx/penny.wav"
# define SFX_POOP "resources/sfx/poop.wav"
# define SFX_ROCK_1 "resources/sfx/rock_1.wav"
# define SFX_ROCK_2 "resources/sfx/rock_2.wav"
# define SFX_ROCK_3 "resources/sfx/rock_3.wav"
# define SFX_SECRET "resources/sfx/secret.wav"
# define SFX_SOLUTION "resources/sfx/solution.wav"
# define SFX_TEAR_1 "resources/sfx/tear_1.wav"
# define SFX_TEAR_2 "resources/sfx/tear_2.wav"
# define SFX_UNLOCK "resources/sfx/unlock.wav"
# define SFX_URN_1 "resources/sfx/urn_1.wav"
# define SFX_URN_2 "resources/sfx/urn_2.wav"
# define SFX_URN_3 "resources/sfx/urn_3.wav"

# define ID_DEATH 0
# define ID_EDITOR 1
# define ID_LEVEL_1 2
# define ID_LEVEL_2 3
# define ID_LEVEL_3 4
# define ID_STORE 5
# define ID_TITLE 6

# define ID_SFX_BUTTON 0
# define ID_SFX_DEATH_1 1
# define ID_SFX_DEATH_2 2
# define ID_SFX_DEATH_3 3
# define ID_SFX_DOOR_OPEN 4
# define ID_SFX_ENEMY_BABY_1 5
# define ID_SFX_ENEMY_BABY_2 6
# define ID_SFX_ENEMY_DEATH 7
# define ID_SFX_ENEMY_ROTTY_1 8
# define ID_SFX_ENEMY_ROTTY_2 9
# define ID_SFX_ENEMY_WIZOOB 10
# define ID_SFX_EXPLOSION 11
# define ID_SFX_GAMBLE_1 12
# define ID_SFX_GAMBLE_2 13
# define ID_SFX_GAMBLE_3 14
# define ID_SFX_HEART_DOWN 15
# define ID_SFX_HEART_UP 16
# define ID_SFX_HIT 17
# define ID_SFX_ITEM 18
# define ID_SFX_KEY 19
# define ID_SFX_MAP 20
# define ID_SFX_MENU_1 21
# define ID_SFX_MENU_2 22
# define ID_SFX_MUSHROOM_1 23
# define ID_SFX_MUSHROOM_2 24
# define ID_SFX_NICKEL 25
# define ID_SFX_PENNY 26
# define ID_SFX_POOP 27
# define ID_SFX_ROCK_1 28
# define ID_SFX_ROCK_2 29
# define ID_SFX_ROCK_3 30
# define ID_SFX_SECRET 31
# define ID_SFX_SOLUTION 32
# define ID_SFX_TEAR_1 33
# define ID_SFX_TEAR_2 34
# define ID_SFX_UNLOCK 35
# define ID_SFX_URN_1 36
# define ID_SFX_URN_2 37
# define ID_SFX_URN_3 38

#endif
