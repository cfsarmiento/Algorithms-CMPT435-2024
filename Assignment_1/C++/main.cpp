/**
 * Palindrome Check - C++
 * Author: Christian Sarmiento
 * Purpose: This program reads in a list of magic items and determines if the item is a palindrome or not. It also sorts
 * the list in various ways using selection	sort, insertion sort, merge sort, and quick sort, shuffiling it every time
 * and counting the number of comparisons.
 * Date Created: 9/28/24
 * Last Updated: 10/2/24
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
#include<cstdlib>  // random numbers for shuffle

// Types
#include <string>
#include <vector>  // C++ dynamic list

/* Helper Methods */

void swap(std::string& item1, std::string& item2) {

    // Variables
    std::string temp = " ";

    // Swap
    temp = item1;
    item1 = item2;
    item2 = temp;

} // swap

void knuthShuffle(std::vector<std::string>& strings) {

    // Variables
    int endPos = strings.size() - 1;
    srand((unsigned) time(NULL));  // setting seed value

    // Shuffle the array
    for (int i = endPos; i >= 0; i--) {

        int j = rand() % (i + 1);
        swap(strings[i], strings[j]);

    } // for 

}; // knuthShuffle()

int selectionSort(std::vector<std::string>& items) {

    // Variables
    int numComparisons = 0;
    int arrayLength = items.size();

    // Anchor on an element
    for (int i=0; i <= arrayLength - 2; i++) {

        // Find the minimum
        int currentMin = i;
        for (int j=i+1; j <= arrayLength - 1; j++) {

            // Swap only if the number is less than the current mininum
            numComparisons++;
            if (items[j] < items[currentMin]) {

                currentMin = j;

            } // if

        } // for j

        // Swap after finding the minimum
        swap(items[i], items[currentMin]);

    } // for i

    return numComparisons;

} // selectionSort()

int insertionSort(std::vector<std::string>& items) {

    // Variables
    std::string currentElement = " ";
    int numComparisons = 0;

    // Anchor on an element
    for (int i=0; i < items.size() - 1; i++) {

        // Move elements if they are bigger than the current element
        currentElement = items[i];
        int j = i - 1;
        numComparisons++;
        while (j >= 0 && items[j] > currentElement) {

            items[j+1] = items[j];
            j--;

        } // while 

        // Move current element into proper place
        items[j+1] = currentElement;

    } // for i

    return numComparisons;

} // insertionSort()	

int mergeSort(std::vector<std::string>& items) {

    // Variables
    std::vector<std::string> lowerHalf = items;
    std::vector<std::string> upperHalf = items;
    if (items.size() > 1) {

        // Divide the list into two halves and sort
        int m = items.size() / 2;
        std::vector<std::string> slice(lowerHalf.begin() + 0, lowerHalf.begin() + m);
        mergeSort(lowerHalf);
        std::vector<std::string> slice(upperHalf.begin() + (m + 1), upperHalf.begin() + items.size());
        mergeSort(upperHalf);

        // Merge the lists
        mergeHelper();


    } // if
} // mergeSort()

void mergeHelper(std::vector<std::string>& array) {


} // mergeHelper

int quickSort(std::vector<std::string>& items) {

} // quickSort()

int main() {

    // Variables
    std::vector<std::string> magicItems;
    std::string item = "";
    char character1 = ' ';
    char character2 = ' ';
    int palindromeCount = 0;
    int selectionSortComparisons = 0;
    int insertionSortComparisons = 0;
    int mergeSortComparisons = 0;
    int quickSortComparisons = 0;


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

    // Selection sort
    knuthShuffle(magicItems);
    selectionSortComparisons = selectionSort(magicItems);
    std::cout << "Selection Sort Total Comparisons: " << selectionSortComparisons << std::endl;

    // Insertion sort
    knuthShuffle(magicItems);
    insertionSortComparisons = insertionSort(magicItems);
    std::cout << "Insertion Sort Total Comparisons: " << insertionSortComparisons << std::endl;

    // Merge sort
    knuthShuffle(magicItems);
    mergeSortComparisons = mergeSort(magicItems);
    std::cout << "Merge Sort Total Comparisons: " << mergeSortComparisons << std::endl;

    // Quick sort
    knuthShuffle(magicItems);
    quickSortComparisons = quickSort(magicItems);
    std::cout << "Quick Sort Total Comparisons: " << quickSortComparisons << std::endl;


    return 0;

}; // main()