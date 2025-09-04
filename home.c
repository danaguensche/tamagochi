#include <gb/gb.h>
#include <stdio.h>
#include "home.h"
#include "include/vwf.h"
#include "include/vwf_font_ru.h"
#include "backgrounds/background_cat.h"
#include "backgrounds/background_dog.h"

#pragma bank 1

void setup_home_background_cat()
{
    set_bkg_data(0, 216, background_cat_tileset);
    set_bkg_tiles(0, 0, 20, 18, background_cat_tilemap);
    setup_font_bkg();
    display_pet_name();
    display_welcome_message();
    SHOW_BKG;
    DISPLAY_ON;
}
void setup_home_background_dog()
{
    set_bkg_data(0, 216, background_dog_tileset);
    set_bkg_tiles(0, 0, 20, 18, background_dog_tilemap);
    setup_font_bkg();
    display_pet_name();
    display_welcome_message();
    SHOW_BKG;
    DISPLAY_ON;
}

void display_pet_name()
{
    vwf_draw_text(5, 0, 217, get_pet_name());
}

void display_welcome_message()
{
    vwf_draw_text(2, 16, 224, "Hello! Take care of your Pet!");
}

void setup_font_bkg()
{
    vwf_load_font(0, font_ru, BANK(font_ru));
    vwf_activate_font(0);
    vwf_set_destination(VWF_RENDER_BKG);
    vwf_set_colors(3, 1);
}