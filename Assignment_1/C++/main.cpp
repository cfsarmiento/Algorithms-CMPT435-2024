/**
 * Palindrome Check - C++
 * Author: Christian Sarmiento
 * Purpose: 
 * Date Created: 9/28/24
 * Last Updated: 9/28/24
 * Compilation: g++ -std=c++11 -o PalindromeFinder main.cpp NodeLinkedList.cpp Queue.cpp Stack.cpp
 * Run Program: ./PalindromeFinder
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 1             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Dependencies
#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include <fstream>
#include <algorithm>
#include <cctype>

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
    
    /* Find Palindromes */
    // Iterate through each line in the array 
    for (int i = 0; i < magicItems.size(); i++) {

        // Save item entry to a variable to avoid updating the real data
        std::string magicItem = magicItems[i];
        
        // Clean data by removing spaces and normalizing capatilization
        magicItem.erase(std::remove(magicItem.begin(), magicItem.end(), ' '), magicItem.end());  // remove spaces 
        std::transform(magicItem.begin(), magicItem.end(), magicItem.begin(), [](unsigned char c) { 

            return std::tolower(c);

        }); // lamda function for lowercase conversion``

        // Load each character from the string into a stack and queue


    } // for i





    return 0;
}; // main()