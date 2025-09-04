#include "pet_status.h"
#include <stdio.h>
#include <string.h>
#include "include/vwf.h"
#include "include/vwf_font_ru.h"
#include <gbdk/emu_debug.h>
#include <stdlib.h>

UBYTE status_needs_update = 1;
PetStatus pet_status = {54, 32, 78};

void update_pet_stats()
{
    static UWORD time_counter = 0;
    time_counter++;

    // Alle 300 Frames (ca. 5 Sekunden bei 60 FPS)
    if (time_counter >= 300)
    {
        time_counter = 0;
        UBYTE changed = 0;

        // Hunger verringern
        if (pet_status.hunger > 0)
        {
            pet_status.hunger--;
            changed = 1;
        }

        // Energy verringern
        if (pet_status.energy > 0)
        {
            pet_status.energy--;
            changed = 1;
        }

        // Love verringern wenn hunger oder energy niedrig
        if ((pet_status.hunger < 30 || pet_status.energy < 30) && pet_status.love > 0)
        {
            pet_status.love--;
            changed = 1;
        }

        if (changed)
        {
            status_needs_update = 1;
        }
    }
}

void display_pet_status()
{    
    char love_str[8];
    char hunger_str[8];
    char energy_str[8];

    // int_to_str(pet_status.love, love_str);
    itoa(pet_status.love, love_str, 10);
    strcat(love_str, "/100");

    itoa(pet_status.hunger, hunger_str, 10);
    strcat(hunger_str, "/100");

    itoa(pet_status.energy, energy_str, 10);
    strcat(energy_str, "/100");

    vwf_draw_text(16, 0, 241, love_str);
    vwf_draw_text(16, 1, 247, hunger_str);
    vwf_draw_text(16, 2, 252, energy_str);
}

void display_pet_status_if_needed()
{
    if (status_needs_update)
    {
        display_pet_status();
        status_needs_update = 0;
    }
}

void cuddle_pet(UBYTE amount)
{
    UBYTE old_love = pet_status.love;

    if (pet_status.love + amount > 100)
        pet_status.love = 100;
    else
        pet_status.love += amount;

    if (old_love != pet_status.love)
    {
        status_needs_update = 1;
    }
}

void feed_pet(UBYTE amount)
{
    UBYTE old_hunger = pet_status.hunger;

    if (pet_status.hunger + amount > 100)
        pet_status.hunger = 100;
    else
        pet_status.hunger += amount;

    if (old_hunger != pet_status.hunger)
    {
        status_needs_update = 1;
    }
}

void pet_sleep(UBYTE amount)
{
    UBYTE old_energy = pet_status.energy;

    if (pet_status.energy + amount > 100)
        pet_status.energy = 100;
    else
        pet_status.energy += amount;

    if (old_energy != pet_status.energy)
    {
        status_needs_update = 1;
    }
}

void setup_font(void)
{
    vwf_load_font(0, font_ru, BANK(font_ru));
    vwf_activate_font(0);
    vwf_set_destination(VWF_RENDER_BKG);
    vwf_set_colors(3, 1);
}
