#include <iostream>
#include <cstdlib>
#include <ctime>
#include "door_handler.h"

door_handler::door_handler() 
{ 
    srand(time(NULL)); 
}

void door_handler::start_new_game() { winner = rand() % 3 + 1; }
int door_handler::get_winner() { return winner; }
int door_handler::get_loser() { return loser; }
int door_handler::get_other() { return other; }
bool door_handler::peek_door(int n) {  return n == winner; }

void door_handler::set_chosen(int input)
{
    if (input == winner)
    {
        if (rand() % 2)
        {
            loser = (input + 1) % 3 + 1;
            other = (input + 2) % 3 + 1;
        }
        else
        {
            loser = (input + 2) % 3 + 1;
            other = (input + 1) % 3 + 1;
        }
    }
    else
    {
        other = winner;
        loser = 3 - input - other;
    }
}