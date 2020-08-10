/*******************************************************************************
** Program name: inputMessage.cpp
** Author:       Louis Adams
** Date:         2019-04-26     		             	
** Description:  This function inputs a string from a file. It inputs a line at
**               a time. It takes an int as a parameter which represents a line
**               number in the file. It returns a line of text as a string.
*******************************************************************************/ 
#include <iostream>
#include <string>
#include <fstream>

std::string inputMessage(int lineNum)
{   char ch;
    int counter = 0;
    std::string line;
    std::string inputLine;
    std::ifstream inputFile("file.txt");

    ch = inputFile.peek();
    while(ch != EOF)
    {   getline(inputFile, line);
        counter++;
        if(counter == lineNum)
        {   inputLine = line;
        }
        ch = inputFile.peek();
    }
    inputFile.close();
    return inputLine;
}
