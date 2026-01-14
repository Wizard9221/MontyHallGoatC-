#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "prize_handler.h"

prize_handler::prize_handler() 
{ 
    srand(time(NULL)); 
}

std::string prize_handler::get_good_prize(int* last)
{
    static const std::string win_list[] =
    {
        "A BRAND NEW CAR!",
        "A PUREBRED DAIRY GOAT!",
        "A VACATION TO A DESTINATION OF YOUR CHOICE!",
        "A PENTHOUSE IN A CITY OF YOUR CHOSING!",
        "TEA WITH THE KING OF THE UK!",
        "A ROMANTIC GET-AWAY WITH YOUR CRUSH!"
    };

    int lg = sizeof(win_list) / sizeof(std::string);
    int roll = rand() % lg;

    while (roll == *last)
    {
        roll = rand() % lg;
    }
    *last = roll;

    return win_list[rand() % lg];
}

std::string prize_handler::get_bad_prize(int* last)
{
    static const std::string lose_list[] =
    {
        "a two-hour tickle-torture session",
        "a marathon through a bear farm whilst covered in honey",
        "a shabby apartment in a terrible neighborhood with an obnoxious roommate",
        "a water aerobics session in crocodile-infested waters",
        "an afternoon where you have to give pedicures to marathon runners that ran in the heat and in heavy socks",
        "a get-away with an individual you find repulsive both in looks and charm"
    };

    int lg = sizeof(lose_list) / sizeof(std::string);
    int roll = rand() % lg;

    while (roll == *last)
    {
        roll = rand() % lg;
    }
    *last = roll;

    return lose_list[roll];
}