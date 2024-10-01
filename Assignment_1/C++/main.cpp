/**
 * Palindrome Check - C++
 * Author: Christian Sarmiento
 * Purpose: This program reads in a list of magic items and determines if the item is a palindrome or not. It also sorts
 * the list in various ways using selection	sort, insertion sort, merge sort, and quick sort, shuffiling it every time
 * and counting the number of comparisons.
 * Date Created: 9/28/24
 * Last Updated: 10/1/24
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
    std::string item = "";
    char character1 = ' ';
    char character2 = ' ';
    int palindromeCount = 0;

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

        // Palindrome check
        bool isPalindrome = true;

        // Save item entry to a variable to avoid updating the real data
        std::string magicItem = magicItems[i];
        
        // Clean data by removing spaces and normalizing capatilization
        magicItem.erase(std::remove(magicItem.begin(), magicItem.end(), ' '), magicItem.end());  // remove spaces 
        std::transform(magicItem.begin(), magicItem.end(), magicItem.begin(), [](unsigned char c) { 

            return std::tolower(c);

        }); // lamda function for lowercase conversion

        // Define stack and queue objects with automatic stack allocation
        // With this syntax, the objects are auto-deleted from memory once out of scope (end of for i loop)
        Stack stack;
        Queue queue;

        // Load each character from the string into a stack and queue
        for (size_t j=0; j < magicItem.length(); j++) {  // size_t for incrementor since .length() returns that type

            // Load each character into the stack and queue
            stack.push(magicItem[j]);
            queue.enqueue(magicItem[j]);

        } // for j

        // Check each character in stack and queue and compare
        for (size_t k=0; k < magicItem.length(); k++) {

            // Get characters from the stack and the queue
            character1 = stack.pop();
            character2 = queue.dequeue();


            // Check if the character matches or not
            if (character1 != character2) {

                isPalindrome = false;

            } // if
             
        } // for k

        // Print if it's a palindrome 
        if (isPalindrome) {

            std::cout << magicItem << std::endl;
            palindromeCount++;

        } // if
        
    } // for i

    // Print total palindrome count
    std::cout << "Total Palindromes: " << palindromeCount << std::endl;

    /* Sorting */


    return 0;

}; // main()

/* Helper Methods*/

void shuffle(std::vector<std::string> strings) {

}; // shuffle()

void selectionSort() {

} // selectionSort()

void insertionSort() {

} // insertionSort()	

void mergeSort() {

} // mergeSort()

void quickSort() {

} // quickSort()