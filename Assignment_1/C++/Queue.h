/**
 * Queue Header File
 * Author: Christian Sarmiento
 * Purpose: Header file for Queue class. Allows it to be used in other files. 
 * Date Created: 9/28/24
 * Last Updated: 9/30/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 1             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

#ifndef QUEUE_H
#define QUEUE_H

// Dependencies
#include "NodeLinkedList.h"

class Queue {

     // Instance Variables
    public:
        NodeLinkedList* myHead;
        NodeLinkedList* myTail; 

    // Null & Full Constructors
    Queue();
    Queue(NodeLinkedList* node);

    // Class Method Headers
    bool isEmpty();
    void enqueue(char data);
    char dequeue();
    

}; // Class Stack 

#endif // QUEUE_H