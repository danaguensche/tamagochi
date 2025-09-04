#ifndef animated_cat_sprite_functions_h
#define animated_cat_sprite_functions_h

#include <gb/gb.h>
#include <stdio.h>
#include "sprites/cat.h"

// Globale Variablen für Animation
static UBYTE frame_delay = 10;
static UBYTE current_frame = 0;
static UBYTE frame_counter = 0;
static UBYTE animation_active = 0;

// Function prototypes
void setup_cat(int start_x, int start_y);
void setup_cat_home(void);
void animate_cat_selection(void);
void start_cat_animation(void);
void stop_cat_animation(void);
void update_cat_animation(void);

#endif