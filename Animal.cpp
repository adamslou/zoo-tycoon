/*******************************************************************************
** Program name: Animal.cpp
** Author:       Louis Adams
** Date:         2019-04-21     		             	
** Description:  The Animal class represents an animal that is part of a zoo.
**               It is the base class for other derived classes of animals.
**               Member variables include traits common to all zoo animals including
**               age, cost, numberOfBabies, baseFoodCost, and payoff. Member
**               functions include a constructor which takes parameters to
**               initialize all of its member variables, get and set functions 
**               for all variables as well as a getName function which simply 
**               returns what kind of animal it is, which in this case is 
**               simply "animal".
*******************************************************************************/ 
#include "Animal.hpp"
#include <string>

/*******************************************************************************
*                           Animal::Animal Constructor                         *
* This constructor takes a single parameter to initialize only the age member  *
* variable.                                                                    *
*******************************************************************************/
Animal::Animal(int a) : age {a}
{
}

/*******************************************************************************
*                           Animal::Animal Constructor                         *
* This constructor takes 5 parameters to initialize its 5 member variables.    *
*******************************************************************************/
Animal::Animal(int a, int c, int b, int f, int p)
    : age {a}, cost {c}, numberOfBabies {b}, baseFoodCost {f}, payoff {p}
{
}

/*******************************************************************************
*                           Animal::~Animal Destructor                         *
* This is a virtual destructor for the Animal class.                           *
*******************************************************************************/
Animal::~Animal()
{
}

// Get function for age
int Animal::getAge()
{   return age;
}

// Get function for cost
int Animal::getCost()
{   return cost;
}

// Get function for numberOfBabies
int Animal::getNumberOfBabies()
{   return numberOfBabies;
}

// Get function for baseFoodCost
int Animal::getBaseFoodCost()
{   return baseFoodCost;
}

// Get function for payoff
int Animal::getPayoff()
{   return payoff;
}

// Set function for age
void Animal::setAge(int a)
{   age = a;
}

// Set function for cost
void Animal::setCost(int c)
{   cost = c;
}

// Set function numberOfBabies
void Animal::setNumberOfBabies(int b)
{   numberOfBabies = b;
}

// Set function for baseFoodCost
void Animal::setBaseFoodCost(int f)
{   baseFoodCost = f;
}

// Set function for payoff
void Animal::setPayoff(int p)
{   payoff = p;
}

// Returns the name of the animal
std::string Animal::getName()
{   return "animal";
}
