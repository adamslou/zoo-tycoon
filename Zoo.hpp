/*******************************************************************************
** Program name: Zoo.hpp
** Author:       Louis Adams
** Date:         2019-04-21     		             	
** Description:  The Zoo class represents a game of zoo tycoon in which the user
**               will run a zoo as a business. The class will contain pointers
**               to arrays of pointers to Animal objects. When animals are added
**               to the zoo, objects of the corresponding derived Animal class
**               will be added to the array, which is dynamically allocated. When
**               the array is full, it will be reallocated at twice the current
**               size. There will be a pointer to an array for each derived class
**               including Tiger, Penguin, Turtle, and NewAnimal. There will also
**               be member variables to keep track of the number of each derived
**               Animal object, to keep track of the size of each array, and to 
**               keep track of the amount of money the tycoon has to work with.
**               There is a constructor to initialize variables storing the
**               number of animals the zoo will start with. The startGame function
**               contains most of the logic needed for the game itself, along with
**               the randomEvent function. There are function to add more animals
**               to the dynamic arrays when animals are bought or are born, called
**               addTiger, etc.  When an array is full, a function such as 
**               allocTigers, etc. will allocate more pointers to Animal objects
**               so that more animals can be added to the arrys. When an animal
**               dies, a function such as deleteTiger will deallocate the memory
**               for that derived Animal object.
*******************************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP

#include <string>
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "NewAnimal.hpp"

class Zoo
{   private:
        int numTigers;      // Stores the number of tigers in the zoo
        int numPenguins;    // Stores the number of penguins in the zoo
        int numTurtles;     // Stores the number of turtles in the zoo
        int numNewAnimals;  // Stores the number of new animals in the zoo
        int tigersSize;     // Stores the size of the tigers array
        int penguinsSize;   // Stores the size of the penguins array
        int turtlesSize;    // Stores the size of the turtles array
        int newAnimalsSize; // Stores the size of the newAnimals array
        int money;          // Stores the amount of money the zoo tycoon has
        Animal **tigers;    // To access the array of Tiger objects
        Animal **penguins;  // To access the array of Penguin objects
        Animal **turtles;   // To access the array of Turtle objects
        Animal **newAnimals;// To access the array of NewAnimal objects

    public:
        Zoo(int, int, int);
        int getMoney();
        int getNumTigers();
        int getNumPenguins();
        int getNumTurtles();
        int getNumNewAnimals();
        void setMoney(int);
        void setNumTigers(int);
        void setNumPenguins(int);
        void setNumTurtles(int);
        void setNumNewAnimals(int);
        void startGame();
        int randomEvent(int);
        void allocTigers();
        void allocPenguins();
        void allocTurtles();
        void allocNewAnimals();
        void addTiger(int);
        void addPenguin(int);
        void addTurtle(int);
        void addNewAnimal(std::string, int, int, int, int, int);
        void deleteTiger();
        void deletePenguin();
        void deleteTurtle();
        void deleteNewAnimal();
};
#endif
