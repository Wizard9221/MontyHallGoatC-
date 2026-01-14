// MontyHall.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "prize_handler.h"
#include "door_handler.h"

void play_game();
int get_input();
double test_switch_win_odds();
double test_no_switch_win_odds();

prize_handler Ed;
door_handler Bob;

int last_good = -1;
int last_bad = -1;

int main()
{
	srand(time(NULL));
	std::cout << "Welcome to good deal, bad deal!" << std::endl;
	std::cout << "I'm your host, Monty Hall. ";
	std::string input;

	for (;;)
	{
		play_game();
		std::cout << "Wanna play again? ";
		getline(std::cin, input);
		if (toupper(input[0]) == 'N') break;
	}

	return 0;
}

void play_game()
{
	std::string s;
	std::cout << "There are three doors: 1, 2 and 3. Which do you want to choose? ";
	int input = get_input();
	Bob.set_chosen(input);
	std::cout << "Before  I show you what's behind your chosen door, ";
	std::cout << "I'll show you what was behind a door you DIDN'T choose." << std::endl;

	std::cout << "Behind door " << Bob.get_loser() << " is..." << std::endl;
	std::cout << Ed.get_bad_prize(&last_bad) << std::endl << std::endl;

	std::cout << "Now, do you want to switch from door " << input << " to door ";
	std::cout << Bob.get_other() << "? ";
	std::cout << "(Y or N) ";
	getline(std::cin, s);
	if (toupper(s[0]) == 'Y') input = Bob.get_other();

	std::cout << "Alright, you won... ";
	if (Bob.peek_door(input)) std::cout << Ed.get_good_prize(&last_good);
	else std::cout << Ed.get_bad_prize(&last_bad) << "... I'm so sorry.";
	std::cout << std::endl << std::endl;
}

int get_input()
{
	std::string sInput;

	for (;;)
	{
		getline(std::cin, sInput);
		int input = stoi(sInput);
		if (input >= 1 && input <= 3) return input;
		else std::cout << "You have to put in a door between 1 and 3. Try again: ";
	}
}

double test_switch_win_odds() 
{
	double win_tally = 0;

	for (int a = 1; a <= 30000; a++) 
	{
		Bob.set_chosen(rand() % 3 + 1);
		if (Bob.peek_door(Bob.get_other())) win_tally += 1.0;
	}

	return win_tally / 1000;
}

double test_no_switch_win_odds() 
{
	double win_tally = 0;

	for (int a = 1; a <= 30000; a++)
	{
		int choose = rand() % 3 + 1;
		Bob.set_chosen(choose);
		if (Bob.peek_door(choose)) win_tally += 1.0;
	}

	return win_tally / 1000.0;
}