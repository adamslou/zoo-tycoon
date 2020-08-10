/*******************************************************************************
** Program name: Animal.hpp
** Author:       Louis Adams
** Date:         2019-04-21     		             	
** Description:  The Animal class represents an animal that is part of a zoo.
**               It is the base class for other derived classes of animals.
**               Member variables include traits common to all zoo animals including
**               age, cost, numberOfBabies, baseFoodCost, and payoff. Member
**               functions include get and set functions for all variables as
**               well as a getName function which simply returns what kind of
**               animal it is, which in this case is simply "animal".
*******************************************************************************/ 
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{   protected:
        int age;
        int cost;
        int numberOfBabies;
        int baseFoodCost;
        int payoff;
    public:
        Animal(int);
        Animal(int, int, int, int, int);
        virtual ~Animal();
        int getAge();
        int getCost();
        int getNumberOfBabies();
        int getBaseFoodCost();
        int getPayoff();
        void setAge(int);
        void setCost(int);
        void setNumberOfBabies(int);
        void setBaseFoodCost(int);
        void setPayoff(int);
        virtual std::string getName();
};
#endif
