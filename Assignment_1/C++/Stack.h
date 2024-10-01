/**
 * Stack Header File
 * Author: Christian Sarmiento
 * Purpose: Header file for Stack class. Allows it to be used in other files. 
 * Date Created: 9/28/24
 * Last Updated: 9/30/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 1             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

#ifndef STACK_H
#define STACK_H

// Dependencies
#include "NodeLinkedList.h"

class Stack {

     // Instance Variables
    public:
        NodeLinkedList* myTop; 

    // Null & Full Constructors
    Stack();
    Stack(NodeLinkedList* node);

    // Class Method Headers
    bool isEmpty();
    char pop();
    void push(const char data);

}; // Class Stack

#endif // STACK_H