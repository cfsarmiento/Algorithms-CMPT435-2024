/**
 * Graphs & Binary Search Trees - C++
 * Author: Christian Sarmiento
 * Purpose: 
 * Date Created: 11/10/24
 * Last Updated: 11/10/24
 * Compilation: g++ -std=c++20 -o GraphsAndBSTs main.cpp NodeLinkedList.cpp
 * Run Program: ./GraphsAndBSTs
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 3             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Dependencies
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>


// Types
#include <string>
#include <vector>  // C++ dynamic list

/* Helper Methods */



/* Main Function */

/**
 * Main function for the program. 
*/
int main() {
    
    // Variables
    std::vector<std::string> magicItems;
    std::vector<std::string> graphContents;
    std::vector<std::string> searchItems;
    std::string item = "";
    std::string content = "";

    /**
     * Read in contents from graphs1.txt into an array
    */
    
    // Open graphs1.txt file
    std::ifstream file("graphs1.txt");

    // Check if file opens successfully
    if (!file.is_open()) {

        std::cerr << "Failed to open file." << std::endl;
        return 1;

    } // if

    // Read in graph contents 
    while(std::getline(file, content)) {

        if (content == "new graph")
            std::cout << "Correct" << std::endl;

    } // while

    // Close magicitems.txt
    file.close();

    /**
     * Read in items from magicitems.txt into an array 
    

    // Open magicitems.txt file
    std::ifstream file("magicitems.txt");

    // Check if file open successfully
    if (!file.is_open()) {

        std::cerr << "Failed to open file." << std::endl;
        return 1;

    } // if

    // Read in magic items to vector array
    while(std::getline(file, item)) {

        magicItems.push_back(item);

    } // while

    // Close magicitems.txt
    file.close();

    */

}; // main()