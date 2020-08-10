/*******************************************************************************
** Program name: Penguin.cpp
** Author:       Louis Adams
** Date:         2019-04-21     		             	
** Description:  The Penguin class represents a penguin that is part of a the zoo.
**               It is derived from the Animal class. It has a constructor which
**               is used to initialize member variables. It has a getName function
**               which returns the kind of animal it is.
*******************************************************************************/ 
#include "Penguin.hpp"
#include <string>

/*******************************************************************************
 *                          Penguin::Penguin Constructor                       *
 * This constructor initializes all the Penguin member variables. It takes an  *
 * int as a parameter to initialize the age variable which should be specified *
 * by the user.                                                                *
 ******************************************************************************/
Penguin::Penguin(int age = 0) : Animal {age} 
{   cost = 1000;
    numberOfBabies = 5;
    baseFoodCost = 300;
    payoff = 100;
}

// Return the kind of animal
std::string Penguin::getName()
{   return "penguin";
}
