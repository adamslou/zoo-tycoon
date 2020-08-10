/*******************************************************************************
** Program name: Tiger.cpp
** Author:       Louis Adams
** Date:         2019-04-21     		             	
** Description:  The Tiger class represents a tiger that is part of a the zoo.
**               It is derived from the Animal class. It has a constructor which
**               is used to initialize member variables. It has a getName function
**               which returns the kind of animal it is.
*******************************************************************************/ 
#include "Tiger.hpp"
#include <string>

/*******************************************************************************
 *                          Tiger::Tiger Constructor                           *
 * This constructor initializes all the Tiger member variables. It takes an    *
 * int as a parameter to initialize the age variable which should be specified *
 * by the user.                                                                *
 ******************************************************************************/
Tiger::Tiger(int age = 0) : Animal {age} 
{   cost = 10000;
    numberOfBabies = 1;
    baseFoodCost = 1500; 
    payoff = 2000;
}

// Return the kind of animal
std::string Tiger::getName()
{   return "tiger";
}
