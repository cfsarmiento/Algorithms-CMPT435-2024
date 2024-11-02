/**
 * Palindrome Check - C++
 * Author: Christian Sarmiento
 * Purpose: This program reads in a list of magic items and selects 42 random items to search within the bigger array
 * using linear, binary search and hashing, counting the number of comparisons.
 * Date Created: 10/10/24
 * Last Updated: 11/1/24
 * Compilation: g++ -std=c++20 -o SearchingMethods main.cpp HashTable.cpp NodeLinkedList.cpp
 * Run Program: ./SearchingMethods
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 2             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Dependencies
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include<cstdlib>  // random numbers for shuffle
#include "HashTable.h" 

// Types
#include <string>
#include <vector>  // C++ dynamic list

/* Helper Methods */

/**
 * Helper method to swap string elements in an array. Takes in two strings as parameters.
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
        randomPos = rand() % items.size();

        // Save a random entry
        randomSelections.push_back(items[randomPos]);

    } // for i

    return randomSelections;

} // getSearchItems()

/**
 * Method that searches for a target value in the array element by element. Takes in a string for the target and
 * a vector or strings. Returns the number of comparisons neccessary.
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

    // Output results
    if (found) 
        std::cout << "Linear Search found " << target << "." << std::endl;
    
    else
        std::cout << "Linear Search could not Find " << target << "." << std::endl;

    return numComparisons;

} // linearSearch()

/**
 * Method that searches for a target value recursively using binary search. Takes in an a target value, an array of
 * items, start position, end position, and a flag value to determine if the target was found or not. 
*/
int recursiveBinarySearch(std::string target, std::vector<std::string> items, int startPos, int endPos, bool& flag) {

    // Variables
    int start = startPos;
    int end = endPos;
    int mid = 0;
    int numComparisons = 0;

    // Base case
    numComparisons++;
    if (end >= start) {

        // Find the midpoint of the current subarray
        mid = start + (end - start) / 2;

        // Find the item
        numComparisons++;
        if (target == items[mid]) {

            flag = true;
            std::cout << "Binary Search found " << target << "." << std::endl;
        
        } // if
        else if (target < items[mid])
            numComparisons += recursiveBinarySearch(target, items, start, mid - 1, flag);
        
        else
            numComparisons += recursiveBinarySearch(target, items, mid + 1, end, flag);

    } // if

    return numComparisons;

} // binarySearch()

/**
 * Method that searches for a target value using binary search. Takes in an a target value, a vector of
 * string items, start position, and end position. Returns the number of comparisons needed to find the target. 
*/
int binarySearch(std::string target, std::vector<std::string> items, int startPos, int endPos) {
    
    // Variables
    int low = startPos;
    int high = endPos;
    int mid = 0;
    int numComparisons = 0;
    bool found = false;

    // Search for the value
    while (!found && low <= high) {

        // Get the midpoint
        mid = low + (high - low) / 2;

        // Compare
        numComparisons++;
        if (target == items[mid])
            found = true;

        else if (target < items[mid])
            high = mid - 1;

        else
            low = mid + 1;

    } // while

    // Print results
    if (found)
        std::cout << "Binary Search found " << target << "." << std::endl;

    else
        std::cout << "Binary Search could not find " << target << "." << std::endl;

    return numComparisons;

} // binarySearch()

/* Main Function */

/**
 * Main function for the program. This picks 42 random items from an array of magic items and finds the items in that
 * larger array using Linear, Binary Search and Hashing. 
*/
int main() {
    
    // Variables
    std::vector<std::string> magicItems;
    std::vector<std::string> searchItems;
    std::string item = "";
    int linearSearchComparisons = 0;
    double avgLinearComparisons = 0.0;
    int binarySearchComparisons = 0;
    double avgBinaryComparisons = 0.0;
    int hashingComparisons = 0;
    double avgHashingComparisons = 0.0;

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
    while(std::getline(file, item)) {

        magicItems.push_back(item);

    } // while

    // Close magicitems.txt
    file.close();

    /**
     * Searching w/ Linear and Binary Search
    */

    // Get a subarray of 42 random items to search for
    searchItems = getSearchItems(magicItems);

    // Sort the original array for both Linear and Binary Search
    quickSort(magicItems, 0, magicItems.size() - 1);

    // Search for each of the items using linear search
    for (int i=0; i < searchItems.size(); i++) {

        // Search for the item
        linearSearchComparisons = linearSearch(searchItems[i], magicItems);
        avgLinearComparisons += linearSearchComparisons;

        // Output the number of comparisons
        std::cout << "(" << (i+1) << ") Comparisons used to find " << searchItems[i] << ": " << linearSearchComparisons << std::endl;
        std::cout << std::endl;

    } // for i

    // Output average comparisons for the 42 items
    avgLinearComparisons = avgLinearComparisons / searchItems.size();
    std::cout << std::fixed << std::setprecision(2) << "Average Comparisons: " << avgLinearComparisons << std::endl;
    std::cout << std::endl;

    // Search for each of the items using binary search
    for(int j=0; j < searchItems.size(); j++) {

        // Search for the item
        binarySearchComparisons = binarySearch(searchItems[j], magicItems, 0, magicItems.size() - 1);
        avgBinaryComparisons += binarySearchComparisons;

        // Output the number of comparisons
        std::cout << "(" << (j+1) << ") Comparisons used to find " << searchItems[j] << ": " << binarySearchComparisons << std::endl;
        std::cout << std::endl;

    } // for j

    // Print average comparisons
    avgBinaryComparisons = avgBinaryComparisons / searchItems.size();
    std::cout << std::fixed << std::setprecision(2) << "Average Comparisons: " << avgBinaryComparisons << std::endl;
    std::cout << std::endl;

    /**
     * Hashing
    */
    
    // Define the hashtable
    HashTable hashTable;  // null constructor will initialize to size of 250, no need to define that here

    // Load the magic items into the hash table
    for (int k=0; k < magicItems.size(); k++)
        hashTable.put(magicItems[k]);

    // Retrieve each item from the hash table, keeping track of gets + comparisons
    for (int l=0; l < searchItems.size(); l++) {

        // Get the item
        hashingComparisons = hashTable.get(searchItems[l]);
        hashingComparisons++;
        avgHashingComparisons += hashingComparisons;

        // Print the number of comparisons
        std::cout << "(" << (l+1) << ") Comparisons used to find " << searchItems[l] << ": " << hashingComparisons << std::endl;
        std::cout << std::endl;

    } // for l

    // Print average comparisons
    avgHashingComparisons = avgHashingComparisons / searchItems.size();
    std::cout << std::fixed << std::setprecision(2) << "Average Comparisons: " << avgHashingComparisons << std::endl;
    std::cout << std::endl;

    return 0;

}; // main()