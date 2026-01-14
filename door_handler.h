#pragma once
#ifndef DOOR_HANDLER_H
#define DOOR_HANDLER_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class door_handler
{
public:
    door_handler();
    void start_new_game();
    void set_chosen(int input);
    int get_winner();
    int get_loser();
    int get_other();
    bool peek_door(int n);

private:
    int winner;
    int loser;
    int other;
    int chosen;
};
#endif