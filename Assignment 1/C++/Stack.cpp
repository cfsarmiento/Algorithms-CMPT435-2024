/**
 * Stack Class
 * Author: Christian Sarmiento
 * Purpose: Class definition for a stack list data structure, used to store string values of palindromes.
 * Date Created: 9/18/24
 * Last Updated: 9/18/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 1             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Dependencies
#include "NodeLinkedList.h"

// Types
#include <string>  

class Stack {

    // Instance variables
    public:
        NodeLinkedList * myTop; 
    
    /**
     * Null Constructor for linked list node class
     */
    Stack() {

        myTop = nullptr;

    } // Null Constructor

    // Full Constructor

    /**
     * Full Constructor for linked list node class
     * 
     * @param node node to be put into the stack
     */
    Stack(NodeLinkedList* node) {  

        myTop = node;
        
    } // Full Constructor

    /* Stack Methods */
    /**
     * Class method to determine if the stack is empty
    */
    bool isEmpty() {

        return (myTop == nullptr);

    } // isEmpty())

    /**
     * Class method that returns the string value that exists 
     * in the node at the top of the list
    */
    std::string pop() {

        
    } // pop()

    /**
     * Class method that adds a node with a new value to the 
     * top of the stack
     * @param data data value to be pushed on to the stack 
    */
    void push(const std::string& data) {


    } // push()
    

}; // Class Stack