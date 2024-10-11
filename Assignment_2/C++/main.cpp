/**
 * Palindrome Check - C++
 * Author: Christian Sarmiento
 * Purpose: This program reads in a list of magic items and selects 42 random items to search within the bigger array
 * using linear, binary search and hashing, counting the number of comparisons.
 * Date Created: 10/10/24
 * Last Updated: 10/10/24
 * Compilation: g++ -std=c++11 -o SearchingMethods main.cpp
 * Run Program: ./SearchingMethods
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 1             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Dependencies
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include<cstdlib>  // random numbers for shuffle

// Types
#include <string>
#include <vector>  // C++ dynamic list

/* Helper Methods */

/**
 * Helper method to swap string elements in an array. 
*/
void swap(std::string& item1, std::string& item2) {

    // Variables
    std::string temp = " ";

    // Swap
    temp = item1;
    item1 = item2;
    item2 = temp;

} // swap

/**
 * Helper method for Quick Sort to choose a pivot point. Takes in an array as well as starting, middle, 
 * and end indexes. Returns the pivot index.
*/
int choosePivot(std::vector<std::string>& array, int left, int mid, int right) {

    // Variables
    int pivotPostion = 0;

    // Find middle value out of left, mid, and right indexes
    if ((array[left] <= array[mid] && array[mid] <= array[right]) || 
        (array[right] <= array[mid] && array[mid] <= array[left]))
        pivotPostion = mid;

    else if ((array[mid] <= array[left] && array[left] <= array[right]) || 
             (array[right] <= array[left] && array[left] <= array[mid]))
        pivotPostion = left;

    else
        pivotPostion = right;

    return pivotPostion;

} // choosePivot()

/**
 * Helper method for Quick Sort. Partitions the list to be sorted. Takes in an array, starting, 
 * end, and pivot indexes. Returns an array of output containing the number of comparisons as well
 * as an index for future sorting iterations. 
*/
std::vector<int> partition(std::vector<std::string>& array, int startPos, int endPos, int pivotPoint) {

    // Variables
    int l = startPos - 1;
    int numComparisons = 0;
    std::vector<int> output(2);

    // Swap elements at the partition
    swap(array[pivotPoint], array[endPos]);

    // Sort through partitions
    for (int i = startPos; i <= endPos - 1; i++) {

        numComparisons++;
        if (array[i] < array[endPos]) {
            
            l++;
            swap(array[l], array[i]);

        } // if

    } // for i

    // Final swap
    swap(array[l+1], array[endPos]);

    // Output
    output[0] = l + 1;  // partition point
    output[1] = numComparisons;

    return output;

} // partition()

/**
 * Method that implements quick sort on an array of strings. Takes in an array, and the starting and end indexes.
 * Returns the number of comparisons.
*/
int quickSort(std::vector<std::string>& items, int leftPos, int rightPos) {

    //Variables
    int totalComparisons = 0;
    int pivot = 0;
    int midpoint = 0;
    int partitionPoint = 0;
    std::vector<int> response(2);

    // Base case
    if (leftPos < rightPos) {

        // Choose pivot
        midpoint = leftPos + (rightPos - leftPos) / 2;
        pivot = choosePivot(items, leftPos, midpoint, rightPos);

        // Partition the array
        response = partition(items, leftPos, rightPos, pivot);
        partitionPoint = response[0];
        totalComparisons += response[1];

        // Recursive sort
        totalComparisons += quickSort(items, leftPos, partitionPoint - 1);
        totalComparisons += quickSort(items, partitionPoint + 1, rightPos);

    } // if

    return totalComparisons;

} // quickSort()

/**
 * Helper method used to shuffle an array in-place based off the Knuth Shuffle. Takes in an array to shuffle.
*/
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

/**
 * Method that gets a subarray of 42 random items given an array. Returns the subarray.
*/
std::vector<std::string> getSearchItems(std::vector<std::string> items) {

    // Variables
    int randomPos = 0;
    std::vector<std::string> randomSelections;
    srand((unsigned) time(NULL));  // setting seed value

    // Get 42 entries
    for (int i=0; i < 42; i++) {

        // Select a random position in the array
        randomPos = (rand() % 666) - 1;

        // Save a random entry
        randomSelections.push_back(items[randomPos]);

    } // for i

    return randomSelections;

} // getSearchItems()

/**
 * Method that searchs for a target value in the array element by element. Returns the 
 * number of comparisons neccessary
*/
int linearSearch(std::string target, std::vector<std::string> items) {

    // Variables
    bool found = false;
    int numComparisons = 0;
    int i = 0;

    // Search through the list
    while ((found != true) && (i < items.size())) {

        numComparisons++;
        if (items[i] == target)
            found = true;
        
        else
            i++;

    } // while

    std::cout << "Found " << target << "." << std::endl;

    return numComparisons;

} // linearSearch()
/**
 * Main function for the program. This finds palindromes given a list of magic items and then shuffles and sorts
 * the given array four times, using Selection, Insertion, Merge, and Quick Sort. 
*/
int main() {

    // Variables
    std::vector<std::string> magicItems;
    std::vector<std::string> searchItems;
    std::string item = "";
    int linearSearchComparisons = 0;
    int avgLinearComparisons = 0;

    /**
     * Read in items from magicitems.txt into an array 
    */

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

    /**
     * Searching w/ Linear and Binary Search
    */

    // Get a subarray of 42 random items to search for
    searchItems = getSearchItems(magicItems);

    // Search for each of the items
    for (int i=0; i < searchItems.size(); i++) {

        // Search for the item
        linearSearchComparisons = linearSearch(searchItems[i], magicItems);
        avgLinearComparisons += linearSearchComparisons;

        // Output the number of comparisons
        std::cout << "(" << i + 1 << ") " << "Comparisons to find " << searchItems[i] << ": " << linearSearchComparisons << std::endl;
        std::cout << std::endl;

    } // for i

    // Output average comparisons for the 42 items
    std::cout << std::fixed << std::setprecision(2) << "Average Comparisons: " << avgLinearComparisons / 42 << std::endl;

    return 0;

}; // main()