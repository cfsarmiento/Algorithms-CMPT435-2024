/**
 * NodeLinkedList Class
 * Author: Christian Sarmiento
 * Purpose: Class definition for a linked list data structure, used to store string values of palindromes.
 * Date Created: 9/17/24
 * Last Updated: 9/18/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 1             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Dependencies
#include "NodeLinkedList.h"

// Types
#include <string>  

class NodeLinkedList {

    // Instance variables
    public:
        std::string myData;
        NodeLinkedList* myNext;  //  Object* is a pointer to the object

    /* Constructors */

    /**
     * Null Constructor for linked list node class
     */
    NodeLinkedList() {

        myData = "null";
        myNext = nullptr;

    } // Null Constructor

    // Full Constructor

    /**
     * Full Constructor for linked list node class
     * 
     * @param data data for the node
     * @param next next node linked to current node (if any)
     */
    NodeLinkedList(const std::string& data, NodeLinkedList* node) {  // "const std::string& ... " passes variables by reference

        myData = data;
        myNext = node;
        
    } // Full Constructor

    /* Getters */
    /**
     * Class method to return the data from the current node
    */
    std::string getData() {

        return myData;

    } // getData()

    /**
     * Class method that returns a pointer to the next node in the list
    */
    NodeLinkedList* getNext() {

        return myNext;

    } // getNext()

    /* Setters */
    /**
     * Class method that updates the data in the current node
    */
    void setData(const std::string& data) {

        myData = data;

    } // setData()

    /**
     * Class method that updates the pointer to the next node
    */
    void setNext(NodeLinkedList* node) {

        myNext = node;

    } // setNext()

}; // Class NodeLinkedList