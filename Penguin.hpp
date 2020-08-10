/*******************************************************************************
** Program name: Penguin.hpp
** Author:       Louis Adams
** Date:         2019-04-21     		             	
** Description:  The Penguin class represents a penguin that is part of a the zoo.
**               It is derived from the Animal class. It has a constructor which
**               is used to initialize member variables. It has a getName function
**               which returns the kind of animal it is.
*******************************************************************************/ 
#ifndef PENGUIN_HPP
#define PENGUIN_HPP
#include <string>
#include "Animal.hpp"

class Penguin : public Animal
{   public:
        Penguin(int);
        virtual std::string getName();
};
#endif
