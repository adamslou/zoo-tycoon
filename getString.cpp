/*******************************************************************************
** Program name: getString.cpp
** Author:       Louis Adams
** Date:         2019-04-26     		             	
** Description:  This is the getString function specification file. This function
**               vaidates user input to ensure that a string of characters
**               (a-z/A-Z/" ") was entered. It then returns the string.
*******************************************************************************/ 
#include "getString.hpp"
#include <iostream>
#include <string>
#include <cctype>

std::string getString()
{   std::string input;
    bool inputValid = false;

    // Loop until valid input is entered
    while(!inputValid)
    {   getline(std::cin, input);
        inputValid = true;

        // If any character in the line is not a character a-z, A-Z, or " ", it is invalid
        for(unsigned int i = 0; i < input.length(); i++)
        {   if(!isalpha(input[i]) && input[i] != ' ')
            {   inputValid = false;
            }
        }

        if(!inputValid)
        {   std::cout << "Input is invalid. Please enter a valid input: ";
        }
    }
    return input;
}
