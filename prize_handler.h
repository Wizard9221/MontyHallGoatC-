#pragma once
#ifndef PRIZE_HANDLER_H
#define PRIZE_HANDLER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class prize_handler
{
public:
	prize_handler();
	std::string get_good_prize(int* last);
	std::string get_bad_prize(int* last);
};

#endif