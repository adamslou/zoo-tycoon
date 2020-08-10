/*******************************************************************************
** Program name: outputMessage.cpp
** Author:       Louis Adams
** Date:         2019-04-26     		             	
** Description:  This function outputs a string to a file. It takes a string as
**               a parameter. The function will out put to "file.txt".
*******************************************************************************/ 
#include <iostream>
#include <string>
#include <fstream>

void outputMessage(std::string msg)
{   std::ofstream outputFile("file.txt");
    outputFile << msg << std::endl;
    outputFile.close();
}
