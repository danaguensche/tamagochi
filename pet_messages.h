#ifndef PET_MESSAGES_H
#define PET_MESSAGES_H
#include <gb/gb.h>
#include <stdio.h>
#include "include/vwf.h"
#include "include/vwf_font_ru.h"

void feed_pet_display_message(UBYTE selected_pet);
void cuddle_pet_display_message(UBYTE selected_pet);
void sleep_pet_display_message(UBYTE selected_pet);
void up_key_display_message(UBYTE selected_pet);
void down_key_display_message(UBYTE selected_pet);
void left_key_display_message(UBYTE selected_pet);
void right_key_display_message(UBYTE selected_pet);


#endif