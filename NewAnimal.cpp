/*******************************************************************************
** Program name: NewAnimal.cpp
** Author:       Louis Adams
** Date:         2019-04-21     		             	
** Description:  The NewAnimal class represents a user-specified animal that is 
**               part of a the zoo. It is derived from the Animal class. It has
**               a member variable, name, which is used to hold what kind of
**               animal it is, which is specified by the user. It has a 
**               constructor which is used to initialize member variables. It 
**               has a getName function which returns the kind of animal it is.
*******************************************************************************/ 
#include "NewAnimal.hpp"
#include <string>

/*******************************************************************************
 *                          NewAnimal::NewAnimal Constructor                   *
 * This constructor takes a string and 5 ints as parameters and then calls the *
 * base class constructor to initialize all of the ints.                       * 
 ******************************************************************************/
NewAnimal::NewAnimal(std::string s, int a, int c, int b, int f, int p) 
    : Animal {a, c, b, f, p}, name {s}
{ 
}

/*******************************************************************************
 *                          NewAnimal::~NewAnimal Destructor                   *
 * This is a virtual destructor for the NewAnimal class, which is derived from *
 * the Animal class.                                                           *
 ******************************************************************************/
NewAnimal::~NewAnimal()
{
}

// Get function for name
std::string NewAnimal::getName()
{   return name;
}

// Set function for name
void NewAnimal::setName(std::string s)
{   name = s;
}
