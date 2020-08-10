/*******************************************************************************
** Program name: Turtle.hpp
** Author:       Louis Adams
** Date:         2019-04-21     		             	
** Description:  The Turtle class represents a turtle that is part of a the zoo.
**               It is derived from the Animal class. It has a constructor which
**               is used to initialize member variables. It has a getName function
**               which returns the kind of animal it is.
*******************************************************************************/ 
#ifndef TURTLE_HPP
#define TURTLE_HPP
#include <string>
#include "Animal.hpp"

class Turtle : public Animal
{   public:
        Turtle(int);
        virtual std::string getName();
};
#endif
