/*******************************************************************************
** Program name: menu.cpp
** Author:       Louis Adams
** Date:         2019-04-23     		             	
** Description:  This is the menu function implementation file.
*******************************************************************************/ 
#include "menu.hpp"
#include "getInteger.hpp"
#include <iostream>

int menu()
{   int choice;     // Holds the user's menu choice

    system("clear");  // Clear the screen

    std::cout << "\tWelcome to the Zoo Tycoon Game!\n\n"
              << "Default number of tigers: 1\n"
              << "Default number of penguins: 1\n"
              << "Default number of turtles: 1\n\n"
              << "1. Play game.\n"
              << "2. Exit game.\n"
              << "3. Change the number of animals to start the game with.\n"
              << "Please make a selection: ";

    choice = getInteger();

    while(choice < 1 || choice > 3)
    {   std::cout << "The only valid choices are 1-3. Please re-enter: ";
        choice = getInteger();
    }

    return choice;
}
