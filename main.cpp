/*******************************************************************************
** Program name: main.cpp
** Author:       Louis Adams
** Date:         2019-04-23     		             	
** Description:  This program allows the user to play the Zoo Tycoon Game. A Zoo
**               class object will be instantiated and its startGame function
**               will be called allowing the user to play the game as many times
**               as she/he wishes. The user may also specify the number of tigers
**               penguins, and turtles she/he would like to start the game with.
*******************************************************************************/ 
#include "menu.hpp"
#include "getInteger.hpp"
#include "Zoo.hpp"
#include <iostream>

int main()
{   int choice,             // Stores the user's menu choice
        numTigers = 1,      // The number of tigers the user would like to start the game with
        numPenguins = 1,    // The number of penguins the user would like to start the game with
        numTurtles = 1;     // The number of turtles the user would like to start the game with
    do
    {   choice = menu();

        switch(choice)
        {   case 1:
            {   Zoo zoo(numTigers, numPenguins, numTurtles);
                zoo.startGame();
                std::cout << "\nPress <Enter> to continue.";
                std::cin.get();
                break;
            }

            case 2: break;

            case 3:
            {   // Get the number of tigers from the user
                int input;
                std::cout << "Enter the number of tigers you would like to start the game with: ";
                input = getInteger();
                while(input < 1 || input > 2)
                {   std::cout << "Please enter a number from 1 to 2: ";
                    input = getInteger();
                }
                numTigers = input;
                
                // Get the number of penguins from the user
                std::cout << "Enter the number of penguins you would like to start the game with: ";
                input = getInteger();
                while(input < 1 || input > 2)
                {   std::cout << "Please enter a number from 1 to 2: ";
                    input = getInteger();
                }
                numPenguins = input;

                // Get the number of turtles from the user
                std::cout << "Enter the number of turtles you would like to start the game with: ";
                input = getInteger();
                while(input < 1 || input > 2)
                {   std::cout << "Please enter a number from 1 to 2: ";
                    input = getInteger();
                }
                numTurtles = input;
            }
        }
    }while(choice != 2);    // Loop until user selects 2 to quit

    return 0;
}
