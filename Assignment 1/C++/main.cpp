/**
 * Palindrome Check - C++
 * Author: Christian Sarmiento
 * Purpose: 
 * Date Created: 9/28/24
 * Last Updated: 9/28/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 1             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Dependencies
#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include <fstream>

// Types
#include <string>
#include <vector>  // C++ dynamic list

int main() {

    // Variables
    std::vector<std::string> magicItems;
    std::string item;

    /* Read in items from magicitems.txt into an array */
    // Open magicitems.txt file
    std::ifstream file("magicitems.txt");

    // Check if file open successfully
    if (!file.is_open()) {

        std::cerr << "Failed to open file." << std::endl;
        return 1;

    } // if

    // Read in magic items to vector array
    while( std::getline(file, item)) {

        magicItems.push_back(item);

    } // while

    // Close magicitems.txt
    file.close();

    





    return 0;
}; // main()