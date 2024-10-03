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
 * Method that implements Selection Sort. Takes in an array of strings representing magic items. Returns the 
 * number of comparisons needed to complete the sort. 
*/
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

/**
 * Method for Insertion Sort. Takes in an array of magic items in string format. Returns the number of comparisons
 * needed. 
*/
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

/**
 * Helper method for Merge sort to help with the merging of arrays. Takes in an array and indexes for the 
 * beginning, middle, and end. Returns the number of comparisons needed.
*/
int mergeHelper(std::vector<std::string>& array, int left, int mid, int right) {

    // Variables
    int leftHalf = mid - left + 1;
    int rightHalf = right - mid;
    std::vector<std::string> leftArray(leftHalf);  // array of size equal to the # of elements in the left half
    std::vector<std::string> rightArray(rightHalf);
    int numComparisons = 0;

    // Put the respective halves into the temp arrays
    for (int i=0; i < leftHalf; i++) {

        leftArray[i] = array[left + i];

    } // for i
    for (int j=0; j < rightHalf; j++) {

        rightArray[j] = array[mid + 1 + j];
        
    } // for j

    // Merge the arrays together
    int k = 0, l = 0, m = left;
    while (k < leftHalf && l < rightHalf) {

        numComparisons++;
        if (leftArray[k] <= rightArray[l]) {

            array[m] = leftArray[k];
            k++;

        } // if
        else {

            array[m] = rightArray[l];
            l++;

        } // else

    } // while

    // Copy remaining elements if there are any left
    while (k < leftHalf) {

        array[m] = leftArray[k];
        k++;
        m++;

    } // while

    while (l < rightHalf) {

        array[m] = rightArray[l];
        l++;
        m++;

    } // while

    return numComparisons;

} // mergeHelper

/**
 * Method for Merge Sort implementation. Takes in an array of magic items (strings), as well as beginning and 
 * end indexes. Returns the number of comparisons needed to complete the sort. 
*/
int mergeSort(std::vector<std::string>& items, int leftPos, int rightPos) {

    // Variables
    int totalComparisons = 0;

    // Check to make sure there are still items to sort
    if (leftPos < rightPos) {

        // Get the midpoint
        int midpoint = leftPos + (rightPos - leftPos) / 2;

        // Sort the list using recursion
        mergeSort(items, leftPos, midpoint);
        mergeSort(items, midpoint + 1, rightPos);

        // Merge the sorted arrays
        totalComparisons = mergeHelper(items, leftPos, midpoint, rightPos);

    } // if

    return totalComparisons;

} // mergeSort()

/**
 * Helper method for Quick Sort to choose a pivot point. Takes in an array as well as starting, middle, 
 * and end indexes. Returns the pivot index.
*/
int choosePivot(std::vector<std::string>& array, int left, int mid, int right) {

    // Variables
    int pivotPostion = 0;

    // Find middle value out of left, mid, and right indexes
    if (array[left] < array[mid] && array[mid] < array[right])
        pivotPostion = mid;

    else if (array[mid] < array[left] && array[left] < array[right])
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
    swap(array[endPos], array[l+1]);

    // Output
    output[0] = l + 1;
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
 * Main function for the program. This finds palindromes given a list of magic items and then shuffles and sorts
 * the given array four times, using Selection, Insertion, Merge, and Quick Sort. 
*/
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
    mergeSortComparisons = mergeSort(magicItems, 0, magicItems.size() - 1);
    std::cout << "Merge Sort Total Comparisons: " << mergeSortComparisons << std::endl;

    // Quick sort
    knuthShuffle(magicItems);
    quickSortComparisons = quickSort(magicItems, 0, magicItems.size() - 1);
    std::cout << "Quick Sort Total Comparisons: " << quickSortComparisons << std::endl;

    return 0;

}; // main()