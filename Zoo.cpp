/*******************************************************************************
** Program name: Zoo.cpp
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
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "getInteger.hpp"
#include "getString.hpp"
#include "Zoo.hpp"
#include "outputMessage.hpp"
#include "inputMessage.hpp"

/*******************************************************************************
 *                          Zoo::Zoo Constructor                               *
 * This constructor is used to initialize member variables. It takes 3 int     *
 * parameters for the number of tigers, penguins, and turtles that the user    *
 * would like to start the game with. The sizes of the arrays of animals are   *
 * set to 10. Money that the user starts with is set to $100,000.              *
 ******************************************************************************/
Zoo::Zoo(int t, int p, int tur)
    :numTigers {t}, numPenguins {p}, numTurtles {tur}, numNewAnimals {0}, tigersSize {10},
    penguinsSize {10}, turtlesSize {10}, newAnimalsSize {10}, money {100000}
{
}

// Get function for money
int Zoo::getMoney()
{   return money;
}

// Get function for numTigers
int Zoo::getNumTigers()
{   return numTigers;
}

// Get function for numPenguins
int Zoo::getNumPenguins()
{   return numPenguins;
}

// Get function for numTurtles
int Zoo::getNumTurtles()
{   return numTurtles;
}

// Get function for numNewAnimals
int Zoo::getNumNewAnimals()
{   return numNewAnimals;
}

// Set function for money
void Zoo::setMoney(int m)
{   money = m;
}

// Set function for numTigers
void Zoo::setNumTigers(int t)
{   numTigers = t;
}

// Set function for numPenguins
void Zoo::setNumPenguins(int p)
{   numPenguins = p;
}

// Set function for numTurtles
void Zoo::setNumTurtles(int t)
{   numTurtles = t;
}

// Set function for numNewAnimals
void Zoo::setNumNewAnimals(int n)
{   numNewAnimals = n;
}

/*******************************************************************************
 *                          Zoo::startGame                                     *
 * This functions starts the Zoo Tycoon Game. First rand() is seeded so random *
 * numbers can be used for the random events that will occur. Then memory is   *
 * allocated for the arrays of pointers to Animal objects and for the various  *
 * derived Animal objects themselves. Then money is subtracted for the user's  *
 * total for the animals she/he purchased at the start of the game. Then a do- *
 * while loop is used to simulate a day (or turn) in the game. The game        *
 * continues on to the next day as long as the user's money is > 0. Throughout *
 * the day various events occur such as paying for feed costs, a random event, *
 * gaining profit from the zoo, and a chance for the user to buy an adult      *
 * animal. When the user has no money left or she/he wishes to quit, the game  *
 * ends.                                                                       *
 ******************************************************************************/
void Zoo::startGame()
{   int dayCounter = 0;
    int bonus;      // Represents the bonus for a boom in zoo attendance
    unsigned int seed = time(nullptr);
    srand(seed);
  
    // Dynamically allocate arrays of pointers to Animal objects
    tigers = new Animal *[tigersSize];
    for(int i = 0; i < numTigers; i++)
    {   tigers[i] = new Tiger(1);
    }

    penguins = new Animal *[penguinsSize];
    for(int i = 0; i < numPenguins; i++)
    {   penguins[i] = new Penguin(1);
    }

    turtles = new Animal *[turtlesSize];
    for(int i = 0; i < numTurtles; i++)
    {   turtles[i] = new Turtle(1);
    }

    newAnimals = new Animal *[newAnimalsSize];

    // Subtract cost of starting animals
    money -= (numTigers * 10000) + (numPenguins * 1000) + (numTurtles * 100);
    std::cout << "\nYou have purchased your starting animals and your new life as a "
              << "zoo tycoon has begun!" << std::endl;

    // Start a new day, while money in the bank is > 0
    do
    {   // Increment day counter
        dayCounter++;

        // Increase age of animals by a day
        for(int i = 0; i < numTigers; i++)
        {   tigers[i]->setAge(tigers[i]->getAge() + 1);
        }
        for(int i = 0; i < numPenguins; i++)
        {   penguins[i]->setAge(penguins[i]->getAge() + 1);
        }
        for(int i = 0; i < numTurtles; i++)
        {   turtles[i]->setAge(turtles[i]->getAge() + 1);
        }
        for(int i = 0; i < numNewAnimals; i++)
        {   newAnimals[i]->setAge(newAnimals[i]->getAge() + 1);
        }
 
        std::cout << "\nAnother day begins in the zoo. In fact, you've been a zoo tycoon for "
                  << dayCounter << " day(s)." << std::endl;
        std::cout << "You currently have $" << money << " in your account." << std::endl;

        // Prompt user for the feed type and pay the feeding cost
        int feedType;

        std::cout << "\nEnter the feed type for the animals today"
                  << "\n(cheap = 1, generic = 2, premium = 3): ";
        feedType = getInteger();
        while(feedType < 1 || feedType > 3)
        {   std::cout << "Please enter a number from 1 to 3: ";
            feedType = getInteger();
        }

        if(feedType == 1)
        {   std::cout << "You've chosen cheap feed. The animals of the zoo "
                      << "may suffer for this." << std::endl;
            for(int i = 0; i < numTigers; i++)
            {   money -= tigers[i]->getBaseFoodCost() / 2;
            }
            for(int i = 0; i < numPenguins; i++)
            {   money -= penguins[i]->getBaseFoodCost() / 2;
            }
            for(int i = 0; i < numTurtles; i++)
            {   money -= turtles[i]->getBaseFoodCost() / 2;
            }
            for(int i = 0; i < numNewAnimals; i++)
            {   money -= newAnimals[i]->getBaseFoodCost() / 2;
            }
        }
        else if(feedType == 2)
        {   std::cout << "You've chosen generic feed. Hopefully you know what you're "
                      << "doing..." << std::endl;
            for(int i = 0; i < numTigers; i++)
            {   money -= tigers[i]->getBaseFoodCost();
            }
            for(int i = 0; i < numPenguins; i++)
            {   money -= penguins[i]->getBaseFoodCost();
            }
            for(int i = 0; i < numTurtles; i++)
            {   money -= turtles[i]->getBaseFoodCost();
            }
            for(int i = 0; i < numNewAnimals; i++)
            {   money -= newAnimals[i]->getBaseFoodCost();
            }
        }
        else
        {   std::cout << "You've chosen the premium feed. The animals' lifespans "
                      << "should benefit from this." << std::endl;
            for(int i = 0; i < numTigers; i++)
            {   money -= tigers[i]->getBaseFoodCost() * 2;
            }
            for(int i = 0; i < numPenguins; i++)
            {   money -= penguins[i]->getBaseFoodCost() * 2;
            }
            for(int i = 0; i < numTurtles; i++)
            {   money -= turtles[i]->getBaseFoodCost() * 2;
            }
            for(int i = 0; i < numNewAnimals; i++)
            {   money -= newAnimals[i]->getBaseFoodCost() * 2;
            }
        } 
        std::cout << "After paying for the animals' feed for the day you have "
                  << "$" << money << " left in your account." << std::endl;

        // Daily random event occurs
        std::cout << "\nMaybe something random will happen in the zoo today..." << std::endl;
        bonus = randomEvent(feedType);

        // Calculate profit and add it to the user's money
        int profit = 0;
        if(numTigers > 0)
        {   profit += numTigers * tigers[0]->getPayoff();
        }
        if(numPenguins > 0)
        {   profit += numPenguins * penguins[0]->getPayoff();
        }
        if(numTurtles > 0)
        {   profit += numTurtles * turtles[0]->getPayoff();
        }
        if(numNewAnimals > 0)
        {   profit += numNewAnimals * newAnimals[0]->getPayoff();
        }
        profit += bonus;
        std::cout << "\nThe total profit for the day was $" << profit << "." << std::endl;
        money += profit;
        std::cout << "Your cash balance is now $" << money << "." << std::endl;
        
        // Ask user if she/he would like to buy an adult animal
        if(numNewAnimals < 1)
        {   std::cout << "\nYour animal supplier calls you. Would you like to purchase an adult animal?"
                      << "\n(tiger = 1, penguin = 2, turtle = 3, something new = 4, nothing = 5): ";
        }
        else
        {   std::cout << "\nYour animal supplier calls you. Would you like to purchase an adult animal?"
                      << "\n(tiger = 1, penguin = 2, turtle = 3, "
                      << newAnimals[0]->getName() << " = 4, nothing = 5): ";
        }
        int choice = getInteger();  // Stores the user's choice of animal to buy
        while(choice < 1 || choice > 5)
        {   std::cout << "Please choose a number from 1 to 5: ";
            choice = getInteger();
        }
        
        if(choice == 1)
        {   money -= 10000;
            addTiger(3);
            std::cout << "You have successfully bought a tiger." << std::endl;
        }
        else if(choice == 2)
        {   money -= 1000;
            addPenguin(3);
            std::cout << "You have successfully bought a penguin." << std::endl;
        }
        else if(choice == 3)
        {   money -= 100;
            addTurtle(3);
            std::cout << "You have successfully bought a turtle." << std::endl;
        }
        else if(choice == 4)
        {   if(numNewAnimals > 0)
            {   money -= newAnimals[0]->getCost();
                addNewAnimal(newAnimals[0]->getName(), 3, newAnimals[0]->getCost(),
                    newAnimals[0]->getNumberOfBabies(), newAnimals[0]->getBaseFoodCost(),
                    newAnimals[0]->getPayoff());
                std::cout << "You have successfully bought a " << newAnimals[0]->getName() 
                          << "." << std::endl;
            }
            else
            {   int cost,
                    numBabies,
                    foodCost,
                    payoff;
                std::string animalName;

                std::cout << "What is the name of the new animal you'd like to buy? ";
                animalName = getString();
                std::cout << "What is the cost of this animal? ";
                cost = getInteger();
                std::cout << "How many babies does this animal have in one birthing? ";
                numBabies = getInteger();
                std::cout << "How much does it cost daily for generic feed for this animal? ";
                foodCost = getInteger();
                std::cout << "How much can be expected for the daily payoff of this animal? ";
                payoff = getInteger();

                money -= cost;
                addNewAnimal(animalName, 3, cost, numBabies, foodCost, payoff);
                std::cout << "You have successfully bought a " << newAnimals[0]->getName() 
                          << " for the first time." << std::endl;
            }
        }

        std::cout << "\nAnother long day in the zoo is over. Would you like to continue "
                  << "playing?"
                  << "\n(continue = 1, quit = 2): ";
        int answer = getInteger();
        while(answer < 1 || answer > 2)
        {   std::cout << "Please press either 1 or 2: ";
            answer = getInteger();
        }
        if(answer == 2)
        {   money = 0;
        }

    }while(money > 0);

    std::cout << "\nIt seems you have run out of money and your run as zoo tycoon has come "
              << "\nto an end. The animals' fate is now out of your hands." << std::endl;

    // Deallocate all dynamically allocated memory
    for(int i = 0; i < numTigers; i++)
    {   delete tigers[i];
    }
    delete[] tigers;

    for(int i = 0; i < numPenguins; i++)
    {   delete penguins[i];
    }
    delete[] penguins;

    for(int i = 0; i < numTurtles; i++)
    {   delete turtles[i];
    }
    delete[] turtles;

    for(int i = 0; i < numNewAnimals; i++)
    {   delete newAnimals[i];
    }
    delete[] newAnimals;
}

/*******************************************************************************
 *                          Zoo::randomEvent                                   *
 * This function causes a random event to take place in the zoo. Either a      *
 * sickeness occurs to an animal and the animal dies, a boom in zoo attendance *
 * occurs generating a bonus payoff, a baby animal is born, or nothing happens.*
 * The function returns the amount of the bonus payoff. If this event doesn't  *
 * happen the amount would be 0. It takes the feedType as a parameter. The     *
 * feed type affects the chance of the first event ocurring.                   *
 ******************************************************************************/
int Zoo::randomEvent(int feedType)
{   int bonus = 0;              // Represents the bonus payoff that will be returned
    int event;                  // Represents the event that will take place
    std::string inputString;    // Represents a line of text read from a file

    if(feedType == 1)
    {   event = rand() % 6 + 1;
    }
    else if(feedType == 2)
    {   event = rand() % 4 + 1;
    }
    else
    {   event = rand() % 24 + 1;
    }

    // The first event is the sickness and death of a random animal in the zoo
    if((feedType == 1 && event <= 3) || (feedType == 2 && event == 1) ||
       (feedType == 3 && event <= 3))
    {   // Get a random value for the animal type that will die
        // 1 = tiger, 2 = penguin, 3 = turtle, 4 = new animal
        int animalType = rand() % 4 + 1;
        if(animalType == 1 && numTigers > 0)
        {   deleteTiger();
            outputMessage("Unfortunately, a tiger has died after battling sickness.");
            inputString = inputMessage(1);
            std::cout << inputString << std::endl;
        }
        else if(animalType == 2 && numPenguins > 0)
        {   deletePenguin();
            outputMessage("Unfortunately, a penguin has died after battling sickness.");
            inputString = inputMessage(1);
            std::cout << inputString << std::endl;
        }
        else if(animalType == 3 && numTurtles > 0)
        {   deleteTurtle();
            outputMessage("Unfortunately, a turtle has died after battling sickness.");
            inputString = inputMessage(1);
            std::cout << inputString << std::endl;
        }
        else if(numNewAnimals > 0)
        {   outputMessage("Unfortunately, a " + newAnimals[0]->getName() + 
                          " has died after battling sickness.");
            inputString = inputMessage(1);
            std::cout << inputString << std::endl;
            deleteNewAnimal();
        }
        else
        {   outputMessage("The animals of the zoo have escaped sickness this time.");
            inputString = inputMessage(1);
            std::cout << inputString << std::endl;
        }
        return bonus;
    }

    // The second event is a boom in zoo attendance, which generates a bonus payoff
    else if((feedType == 1 && event == 4) || (feedType == 2 && event == 2) ||
            (feedType == 3 && event >= 4 && event <= 10))
    {   for(int i = 0; i < numTigers; i++)
        {   bonus += rand() % 251 + 250;
        }

        outputMessage("There was a boom in zoo attendance today! This generated a bonus payoff of $"
                      + std::to_string(bonus) + ".");
        inputString = inputMessage(1);
        std::cout << inputString << std::endl;

        return bonus;
    }

    // The third event is a baby animal being born. This only happens if there is
    // an animal old enough to be a parent.
    else if((feedType == 1 && event == 5) || (feedType == 2 && event == 3) ||
            (feedType == 3 && event >= 11 && event <= 17))
    {   bool babyEventDone = false,
             tigerParentPossible = false,
             penguinParentPossible = false,
             turtleParentPossible = false,
             newAnimalParentPossible = false;

        // Check whether its possible for the animals to be parents
        for(int i = 0; i < numTigers; i++)
        {   if(tigers[i]->getAge() >= 3)
            {   tigerParentPossible = true;
            }
        }
        for(int i = 0; i < numPenguins; i++)
        {   if(penguins[i]->getAge() >= 3)
            {   penguinParentPossible = true;
            }
        }
        for(int i = 0; i < numTurtles; i++)
        {   if(turtles[i]->getAge() >= 3)
            {   turtleParentPossible = true;
            }
        }
        for(int i = 0; i < numNewAnimals; i++)
        {   if(newAnimals[i]->getAge() >= 3)
            {   newAnimalParentPossible = true;
            }
        }

        // If there are no possible parents, the event is done
        if(tigerParentPossible == false && penguinParentPossible == false &&
           turtleParentPossible == false && newAnimalParentPossible == false)
        {   babyEventDone = true;
            outputMessage("There are no animals capable of having babies in the zoo.");
            inputString = inputMessage(1);
            std::cout << inputString << std::endl;
        }
        
        // Otherwise, animals are selected randomly until one has a baby(babies)
        else
        {   int animalType;
            
            while(babyEventDone == false)
            {   animalType = rand() % 4 + 1;
                
                if(animalType == 1 && tigerParentPossible == true)
                {   addTiger(0);
                    outputMessage("A tigress has given birth to a cute little tiger cub.");
                    inputString = inputMessage(1);
                    std::cout << inputString << std::endl;
                    babyEventDone = true;
                }
                else if(animalType == 2 && penguinParentPossible == true)
                {   for(int i = 0; i < 5; i++)
                    {   addPenguin(0);
                    }
                    outputMessage("A penguin has given birth to 5 cute little baby penguins.");
                    inputString = inputMessage(1);
                    std::cout << inputString << std::endl;
                    babyEventDone = true;
                }
                else if(animalType == 3 && turtleParentPossible == true)
                {   for(int i = 0; i < 10; i++)
                    {   addTurtle(0);
                    }
                    outputMessage("A turtle has given birth to 10 ferocious looking baby turtles.");
                    inputString = inputMessage(1);
                    std::cout << inputString << std::endl;
                    babyEventDone = true;
                }
                else if(animalType == 4 && newAnimalParentPossible == true)
                {   for(int i = 0; i < newAnimals[0]->getNumberOfBabies(); i++)
                    {   addNewAnimal(newAnimals[0]->getName(), 0, newAnimals[0]->getCost(),
                                     newAnimals[0]->getNumberOfBabies(), newAnimals[0]->getBaseFoodCost(),
                                     newAnimals[0]->getPayoff());
                    }
                    outputMessage("A " + newAnimals[0]->getName() + " has given "
                                 + "birth to " + std::to_string(newAnimals[0]->getNumberOfBabies()) 
                                 + " adorable " + newAnimals[0]->getName() + " babies!");
                    inputString = inputMessage(1);
                    std::cout << inputString << std::endl;
                    babyEventDone = true;
                }
            }
        }
        return bonus;
    }

    // The last event is that nothing happens
    else
    {   outputMessage("Nothing particularly random has occurred in the zoo today.");
        inputString = inputMessage(1);
        std::cout << inputString << std::endl;
        return bonus;
    }
}

/*******************************************************************************
 *                          Zoo::allocTigers                                   *
 * This function doubles the size of the array of pointers to Animal objects.  *
 * These pointers can then point to additional Tiger objects.                  *
 ******************************************************************************/
void Zoo::allocTigers()
{   // Allocate temporary array to store the contents of the tigers array
    Animal **temp = new Animal *[tigersSize];

    // Copy the tigers array to the temp array
    for(int i = 0; i < tigersSize; i++)
    {   temp[i] = tigers[i];
    }

    // Deallocate the tigers array
    delete []tigers;

    // Double the size and reallocate the tigers array
    tigersSize *= 2;
    tigers = new Animal *[tigersSize];

    // Copy temp array back to tigers array
    for(int i = 0; i < (tigersSize / 2); i++)
    {   tigers[i] = temp[i];
    }

    // Deallocate the temp array
    delete []temp;
}

/*******************************************************************************
 *                          Zoo::allocPenguins                                 *
 * This function doubles the size of the array of pointers to Animal objects.  *
 * These pointers can then point to additional Penguin objects.                *
 ******************************************************************************/
void Zoo::allocPenguins()
{   // Allocate temporary array to store the contents of the penguins array
    Animal **temp = new Animal *[penguinsSize];

    // Copy the penguins array to the temp array
    for(int i = 0; i < penguinsSize; i++)
    {   temp[i] = penguins[i];
    }

    // Deallocate the penguins array
    delete []penguins;

    // Double the size and reallocate the penguins array
    penguinsSize *= 2;
    penguins = new Animal *[penguinsSize];

    // Copy temp array back to penguins array
    for(int i = 0; i < (penguinsSize / 2); i++)
    {   penguins[i] = temp[i];
    }

    // Deallocate the temp array
    delete []temp;
}

/*******************************************************************************
 *                          Zoo::allocTurtles                                  *
 * This function doubles the size of the array of pointers to Animal objects.  *
 * These pointers can then point to additional Turtle objects.                 *
 ******************************************************************************/
void Zoo::allocTurtles()
{   // Allocate temporary array to store the contents of the turtles array
    Animal **temp = new Animal *[turtlesSize];

    // Copy the turtles array to the temp array
    for(int i = 0; i < turtlesSize; i++)
    {   temp[i] = turtles[i];
    }

    // Deallocate the turtles array
    delete []turtles;

    // Double the size and reallocate the turtles array
    turtlesSize *= 2;
    turtles = new Animal *[turtlesSize];

    // Copy temp array back to turtles array
    for(int i = 0; i < (turtlesSize / 2); i++)
    {   turtles[i] = temp[i];
    }

    // Deallocate the temp array
    delete []temp;
}

/*******************************************************************************
 *                          Zoo::allocNewAnimals                               *
 * This function doubles the size of the array of pointers to Animal objects.  *
 * These pointers can then point to additional NewAnimal objects.              *
 ******************************************************************************/
void Zoo::allocNewAnimals()
{   // Allocate temporary array to store the contents of the newAnimals array
    Animal **temp = new Animal *[newAnimalsSize];

    // Copy the newAnimals array to the temp array
    for(int i = 0; i < newAnimalsSize; i++)
    {   temp[i] = newAnimals[i];
    }

    // Deallocate the newAnimals array
    delete []newAnimals;

    // Double the size and reallocate the newAnimals array
    newAnimalsSize *= 2;
    newAnimals = new Animal *[newAnimalsSize];

    // Copy temp array back to newAnimals array
    for(int i = 0; i < (newAnimalsSize / 2); i++)
    {   newAnimals[i] = temp[i];
    }

    // Deallocate the temp array
    delete []temp;
}

/*******************************************************************************
 *                          Zoo::addTiger                                      *
 * This function instantiates a Tiger object and puts it in the tigers array.  *
 * The number of tigers is incremented and if the Tiger object has filled the  *
 * array, then allocTigers is called to allocate more space for more tigers.   *
 ******************************************************************************/
void Zoo::addTiger(int age)
{   tigers[numTigers] = new Tiger(age);
    numTigers++;

    // Check to see if the number of Tiger objects has filled the array
    if(numTigers == tigersSize)
    {   allocTigers();
    }
}

/*******************************************************************************
 *                          Zoo::addPenguin                                    *
 * This function instantiates a Penguin object and puts it in the penguins     *
 * array. The number of penguins is incremented and if the Penguin object has  *
 * filled the array, then allocPenguins is called to allocate more space for   * 
 * more penguins.                                                              *
 ******************************************************************************/
void Zoo::addPenguin(int age)
{   penguins[numPenguins] = new Penguin(age);
    numPenguins++;

    // Check to see if the number of Penguin objects has filled the array
    if(numPenguins == penguinsSize)
    {   allocPenguins();
    }
}

/*******************************************************************************
 *                          Zoo::addTurtle                                     *
 * This function instantiates a Turtle object and puts it in the Turtle array. *
 * The number of turtles is incremented and if the Turtle object has filled the*
 * array, then allocTurtles is called to allocate more space for more turtles. *
 ******************************************************************************/
void Zoo::addTurtle(int age)
{   turtles[numTurtles] = new Turtle(age);
    numTurtles++;

    // Check to see if the number of Turtle objects has filled the array
    if(numTurtles == turtlesSize)
    {   allocTurtles();
    }
}

/*******************************************************************************
 *                          Zoo::addNewAnimal                                  *
 * This function instantiates a NewAnimal object and puts it in the newAnimals *
 * array. The number of new animals is incremented and if the NewAnimal object *
 * has filled the array, then allocNewAnimals is called to allocate more space *
 * for more new animals.                                                       *
 ******************************************************************************/
void Zoo::addNewAnimal(std::string n, int a, int c, int b, int f, int p)
{   newAnimals[numNewAnimals] = new NewAnimal(n, a, c, b, f, p);
    numNewAnimals++;

    // Check to see if the number of NewAnimal objects has filled the array
    if(numNewAnimals == newAnimalsSize)
    {   allocNewAnimals();
    }
}

/*******************************************************************************
 *                          Zoo::deleteTiger                                   *
 * This function deletes a Tiger object from the array. The last tiger in the  *
 * array will be deleted which may be an adult or baby. numTigers is           *
 * decremented.                                                                *
 ******************************************************************************/
void Zoo::deleteTiger()
{   delete tigers[numTigers - 1];
    numTigers--;
}

/*******************************************************************************
 *                          Zoo::deletePenguin                                 *
 * This function deletes a Penguin object from the array. The last penguin in  *
 * the array will be deleted which may be an adult or baby. numPenguins is     *
 * decremented.                                                                *
 ******************************************************************************/
void Zoo::deletePenguin()
{   delete penguins[numPenguins - 1];
    numPenguins--;
}

/*******************************************************************************
 *                          Zoo::deleteTurtles                                 *
 * This function deletes a Turtle object from the array. The last turtle in the*
 * array will be deleted which may be an adult or baby. numTurtles is          *
 * decremented.                                                                *
 ******************************************************************************/
void Zoo::deleteTurtle()
{   delete turtles[numTurtles - 1];
    numTurtles--;
}

/*******************************************************************************
 *                          Zoo::deleteNewAnimal                               *
 * This function deletes a NewAnimal object from the array. The last newAnimal *
 * in the array will be deleted which may be an adult or baby. numNewAnimals is*
 * decremented.                                                                *
 ******************************************************************************/
void Zoo::deleteNewAnimal()
{   delete newAnimals[numNewAnimals - 1];
    numNewAnimals--;
}
