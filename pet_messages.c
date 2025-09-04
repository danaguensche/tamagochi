#include "pet_messages.h"


void feed_pet_display_message(UBYTE selected_pet)
{
    if (selected_pet == 0)
    {
        vwf_draw_text(2, 16, 224, "                                ");
        vwf_draw_text(2, 16, 224, "*crunch crunch* Meow!");
    }

    if (selected_pet == 1)
    {
        vwf_draw_text(2, 16, 224, "                                ");
        vwf_draw_text(2, 16, 224, "*chews happily* Yumm!");
    }
}

void cuddle_pet_display_message(UBYTE selected_pet)
{
    if (selected_pet == 0)
    {
        vwf_draw_text(2, 16, 224, "                                ");
        vwf_draw_text(2, 16, 224, "*purrs loudly* Meow!");
    }

    if (selected_pet == 1)
    {
        vwf_draw_text(2, 16, 224, "                                ");
        vwf_draw_text(2, 16, 224, "*wagging tail* Woof!");
    }
}

void sleep_pet_display_message(UBYTE selected_pet)
{
    if (selected_pet == 0)
    {
        vwf_draw_text(2, 16, 224, "                                ");
        vwf_draw_text(2, 16, 224, "*curls up and purrs* Zzz...");
    }

    if (selected_pet == 1)
    {
        vwf_draw_text(2, 16, 224, "                                ");
        vwf_draw_text(2, 16, 224, "*snores softly* Zzz...");
    }
}

void up_key_display_message(UBYTE selected_pet)
{
    if (selected_pet == 0)
    {
        vwf_draw_text(2, 16, 224, "                                ");
        vwf_draw_text(2, 16, 224, "*ears perk up* Meow?");
    }

    if (selected_pet == 1)
    {
        vwf_draw_text(2, 16, 224, "                                ");
        vwf_draw_text(2, 16, 224, "*looks up curiously* Woof?");
    }
}

void down_key_display_message(UBYTE selected_pet)
{
    if (selected_pet == 0)
    {
        vwf_draw_text(2, 16, 224, "                                ");
        vwf_draw_text(2, 16, 224, "*sniffs around* Meow!");
    }

    if (selected_pet == 1)
    {
        vwf_draw_text(2, 16, 224, "                                ");
        vwf_draw_text(2, 16, 224, "*sniffs the ground* Woof!");
    }
}

void left_key_display_message(UBYTE selected_pet)
{
    if (selected_pet == 0)
    {
        vwf_draw_text(2, 16, 224, "                                ");
        vwf_draw_text(2, 16, 224, "*stretches left* Meow?");
    }

    if (selected_pet == 1)
    {
        vwf_draw_text(2, 16, 224, "                                ");
        vwf_draw_text(2, 16, 224, "*turns left* Woof?");
    }
}

void right_key_display_message(UBYTE selected_pet)
{
    if (selected_pet == 0)
    {
        vwf_draw_text(2, 16, 224, "                                ");
        vwf_draw_text(2, 16, 224, "*stretches right* Meow?");
    }

    if (selected_pet == 1)
    {
        vwf_draw_text(2, 16, 224, "                                ");
        vwf_draw_text(2, 16, 224, "*turns right* Woof?");
    }
}