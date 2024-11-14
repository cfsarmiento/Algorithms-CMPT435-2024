/**
 * Queue Class
 * Author: Christian Sarmiento
 * Purpose: Class definition for a queue list data structure, used to store string values of palindromes.
 * Date Created: 11/14/24
 * Last Updated: 11/14/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 3             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Dependencies
#include "Queue.h"
#include "Vertex.h"

// Types
#include <string> 



/* Method Implementations */

/**
 * Null Constructor for linked list node class
 */
Queue::Queue() {

    myHead = nullptr;
    myTail = nullptr;

} // Null Constructor

// Full Constructor

/**
 * Full Constructor for linked list node class
 * 
 * @param node node to be put into the stack
 */
Queue::Queue(NodeLinkedList* node) {  

    myHead = node;
    myTail = node;
    
} // Full Constructor

/* Queue Methods */
/**
 * Method that determines if anything exists in the queue
 * @returns boolean value that represents if there is anything at the head of the queue or not
 */
bool Queue::isEmpty() {

    return myHead == nullptr;

} // isEmpty()

/**
 * Method that adds an element to the back of the queue
 * @param data string value to be added to the back of the queue
 */
void Queue::enqueue(Vertex* data) {

    // Variables
    NodeLinkedList* newNode;

    // Instantiate new node object
    newNode = new NodeLinkedList();
    newNode->setData(data);

    // Enqueue to the queue
    if (isEmpty()) {

        myHead = newNode;
        myTail = newNode;

    } // if
    else {

        myTail->setNext(newNode);
        myTail = newNode;

    } // else
    
} // enqueue

/**
 * Method that takes an element off the front of the queue
*/
Vertex* Queue::dequeue() {

    // Variables
    Vertex* dequeuedItem;
    NodeLinkedList* temp;

    // Dequeue from the start of the queue
    if (!isEmpty()) {

        dequeuedItem = myHead->getData();
        temp = myHead;
        myHead = myHead->getNext();
        delete temp;  // gets rid of dequeued node in memory

    } // if

    return dequeuedItem;

} // dequeue

