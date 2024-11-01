/**
 * HashTable Header File
 * Author: Christian Sarmiento
 * Purpose: Header file for HashTable class. Allows it to be used in other files. 
 * Date Created: 10/31/24
 * Last Updated: 10/31/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 2             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Header file definitions
#ifndef HASHTABLE_H
#define HASHTABLE_H

// Dependencies
#include <vector>
#include "NodeLinkedList.h" 
#include <string>

class HashTable {

    private:
        std::vector<NodeLinkedList*> myTable;  
        int HASH_TABLE_SIZE;

        // Hash method
        int makeHashCode(const std::string& item);

    public:

        // Constructors
        HashTable();
        HashTable(int tableSize);

        // Deconstructor
        ~HashTable();

        // Methods
        void put(const std::string& item);
        int get(const std::string& item);

}; // Class HashTable

#endif // HASHTABLE_H