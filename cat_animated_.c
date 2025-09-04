#ifndef animated_cat_sprite_functions_h
#define animated_cat_sprite_functions_h
#include <gb/gb.h>
#include <stdio.h>
#include "sprites/cat.h"
#include "sprites/cat_animated_2.h"

// Globale Variablen für Animation
static UBYTE frame_delay = 20;
static UBYTE current_frame = 0;
static UBYTE frame_counter = 0;
static UBYTE animation_active = 0;


void setup_cat(int start_x, int start_y)
{
    set_sprite_data(0, cat_size, cat);
    for (int i = 0; i < cat_size; i++)
    {
        set_sprite_tile(i, cat_tilemap[i]);
    }
    int tile_width = 8;
    int tile_height = 8;
    int sprite_index = 0;
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            move_sprite(sprite_index, start_x + col * tile_width, start_y + row * tile_height);
            sprite_index++;
            if (sprite_index > 15)
                break;
        }
    }
    SHOW_SPRITES;
}

void animate_cat_selection()
{
    UBYTE local_frame_delay = 10;
    UBYTE local_current_frame = 0;
    UBYTE local_frame_counter = 0;
    while (1)
    {
        UBYTE joy = joypad();
        if (joy & (J_A | J_B))
        {
            break;
        }
        local_frame_counter++;
        if (local_frame_counter >= local_frame_delay)
        {
            local_frame_counter = 0;
            local_current_frame = !local_current_frame;
            if (local_current_frame == 0)
            {
                set_sprite_data(0, cat_size, cat);
            }
            else
            {
                set_sprite_data(0, cat_animated_2_size, cat_animated_2);
            }
        }
        wait_vbl_done();
    }
    set_sprite_data(0, cat_size, cat);
}

void start_cat_animation(void)
{
    animation_active = 1;
    frame_counter = 0;
    current_frame = 0;
}

void stop_cat_animation(void)
{
    animation_active = 0;
    set_sprite_data(0, cat_size, cat); 
}

void update_cat_animation(void)
{
    if (!animation_active) return;
    
    frame_counter++;
    if (frame_counter >= frame_delay)
    {
        frame_counter = 0;
        current_frame = !current_frame;
        if (current_frame == 0)
        {
            set_sprite_data(0, cat_size, cat);
        }
        else
        {
            set_sprite_data(0, cat_animated_2_size, cat_animated_2);
        }
    }
}

void setup_cat_home()
{
    setup_cat(100, 100);
    start_cat_animation(); 
}

#endif