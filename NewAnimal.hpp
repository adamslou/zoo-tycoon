/*******************************************************************************
** Program name: NewAnimal.hpp
** Author:       Louis Adams
** Date:         2019-04-21     		             	
** Description:  The NewAnimal class represents a user-specified animal that is 
**               part of a the zoo. It is derived from the Animal class. It has
**               a member variable, name, which is used to hold what kind of
**               animal it is, which is specified by the user. It has a 
**               constructor which is used to initialize member variables. It 
**               has a getName function which returns the kind of animal it is.
*******************************************************************************/ 
#ifndef NEW_ANIMAL_HPP
#define NEW_ANIMAL_HPP
#include <string>
#include "Animal.hpp"

class NewAnimal : public Animal
{   private:
        std::string name;
    public:
        NewAnimal(std::string, int, int, int, int, int);
        virtual ~NewAnimal();
        virtual std::string getName();
        void setName(std::string);
};
#endif
