/**
 * HashTable Class
 * Author: Christian Sarmiento
 * Purpose: Class definition for a hash table, used to store key value pairs using chaining.
 * Date Created: 10/31/24
 * Last Updated: 10/31/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 2             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Dependencies
#include "HashTable.h" 
#include "NodeLinkedList.h"
#include <iostream>

/* Method Implementations */

/**
 * Null Constructor for hash table class
 */
HashTable::HashTable() {

    HASH_TABLE_SIZE = 250;
    myTable.resize(HASH_TABLE_SIZE, nullptr);

} // Null Constructor

/**
 * Full Constructor for hash table class
 * 
 * @param tableSize size for the hash table
 */
HashTable::HashTable(int tableSize) {  

    HASH_TABLE_SIZE = tableSize;
    myTable.resize(HASH_TABLE_SIZE, nullptr);
    
} // Full Constructor

/**
 * Deconstructor method to remove nodes in the hash table from memory. 
*/
HashTable::~HashTable() {

    // Variables
    NodeLinkedList* curr = nullptr;
    NodeLinkedList* temp = nullptr;

    // Iterate through the indexes
    for (int i=0; i < HASH_TABLE_SIZE; i++) {

        // Set current to the head at the index
        curr = myTable[i];

        // Go through the chain at the index and remove it from memory
        while (curr) {

            temp = curr;
            curr = curr->getNext();
            delete temp;

        } // while

    } // for

} // Deconstructor

/**
 * Method that creates the hashes for the hash table. Takes in the item to hash and returns the hash as an 
 * integer. Written by Dr. Labouseur. 
*/
int HashTable::makeHashCode(const std::string& item) {

   // Transform item to UPPER CASE.
   transform(item.begin(), item.end(), item.begin(),::toupper);

   // Iterate over all letters in the item string, totalling their ASCII values.
   int letterTotal = 0;
   for (int i = 0; i < item.length(); i++) {
      letterTotal = letterTotal + (int)item[i];
   }

   // Scale letterTotal to fit in HASH_TABLE_SIZE.
   int hashCode = letterTotal % HASH_TABLE_SIZE;  // % is the "mod" operator
   // TODO: Experiment with letterTotal * 2, 3, 5, 50, etc.

   return hashCode;

} // makeHashCode()

/**
 * Method that adds an element to the hash table. Takes in a string to add to the table and returns nothing. 
*/
void HashTable::put(const std::string& item) {

    // Variables
    int hashKey = 0;
    NodeLinkedList* newNode = new NodeLinkedList();

    if (newNode) {

        // Make key with the hash function
        hashKey = makeHashCode(item);

        // Make node with the item
        newNode->setData(item);

        // Add to the table
        newNode->setNext(myTable[hashKey]);
        myTable[hashKey] = newNode;

    } // if

    else
        std::cerr << "Memory allocation failed for new node" << std::endl;

} // put()

/**
 * Method that searches for an element in the hash table. Returns the number of comparisons. 
*/
int HashTable::get(const std::string& item) {

    // Variables
    int numComparisons = 0;
    int index = 0;
    NodeLinkedList* curr = nullptr;
    bool found = false;

    // Get index where item is stored
    index = makeHashCode(item);

    // Get to the node where it is stored
    curr = myTable[index];

    // Go through chain at the index
    while (!found && curr) {

        // Compare
        numComparisons++;
        if (curr->getData() == item) {

            std::cout << "Found " << item << " in the hash table." << std::endl;
            found = true;

        } // if

        curr = curr->getNext();

    } // while

    // Let user know if the item was never found
    if (!found)
        std::cout << "Cound not find " << item << " in the hash table." << std::endl;
    
    return numComparisons;

} // get()