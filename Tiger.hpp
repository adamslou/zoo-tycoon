/*******************************************************************************
** Program name: Tiger.hpp
** Author:       Louis Adams
** Date:         2019-04-21     		             	
** Description:  The Tiger class represents a tiger that is part of a the zoo.
**               It is derived from the Animal class. It has a constructor which
**               is used to initialize member variables. It has a getName function
**               which returns the kind of animal it is.
*******************************************************************************/ 
#ifndef TIGER_HPP
#define TIGER_HPP
#include <string>
#include "Animal.hpp"

class Tiger : public Animal
{   public:
        Tiger(int);
        virtual std::string getName();
};
#endif
