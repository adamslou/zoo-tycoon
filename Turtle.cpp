/*******************************************************************************
** Program name: Turtle.cpp
** Author:       Louis Adams
** Date:         2019-04-21     		             	
** Description:  The Turtle class represents a turtle that is part of a the zoo.
**               It is derived from the Animal class. It has a constructor which
**               is used to initialize member variables. It has a getName function
**               which returns the kind of animal it is.
*******************************************************************************/ 
#include "Turtle.hpp"
#include <string>

/*******************************************************************************
 *                          Turtle::Turtle Constructor                         *
 * This constructor initializes all the Turtle member variables. It takes an   *
 * int as a parameter to initialize the age variable which should be specified *
 * by the user.                                                                *
 ******************************************************************************/
Turtle::Turtle(int age = 0) : Animal {age} 
{   cost = 100;
    numberOfBabies = 10;
    baseFoodCost = 150; 
    payoff = 5;
}

// Return the kind of animal
std::string Turtle::getName()
{   return "turtle";
}
