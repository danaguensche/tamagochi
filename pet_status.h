#ifndef PET_STATUS_H
#define PET_STATUS_H

#include <gb/gb.h>
// Pet types
#define PET_CAT    0
#define PET_POODLE 1


// Pet status structure
typedef struct {
    UBYTE love;
    UBYTE hunger; 
    UBYTE energy;
} PetStatus;

extern PetStatus pet_status;
extern UBYTE status_needs_update;

// Function declarations ()
void update_pet_stats(void) ;
void display_pet_status(void) ;
void setup_font(void) ;
void display_pet_status_if_needed(void);

// Pet action functions ()
void feed_pet(UBYTE amount);
void cuddle_pet(UBYTE amount);
void pet_sleep(UBYTE amount);

#endif // PET_STATUS_H
