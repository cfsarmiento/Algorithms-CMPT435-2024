/**
 * Queue Class
 * Author: Christian Sarmiento
 * Purpose: Class definition for a queue list data structure, used to store string values of palindromes.
 * Date Created: 9/18/24
 * Last Updated: 9/28/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 1             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/
// Dependencies
#include "Queue.h"

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
void Queue::enqueue(const std::string& data) {

    // Variables
    NodeLinkedList* newNode;

    // Instantiate new node object
    newNode = new NodeLinkedList();
    newNode->setData(data);

    // Enqueue to the queue
    newNode->setNext(myTail);
    myTail = newNode;

} // enqueue

/**
 * Method that takes an element off the front of the queue
*/
std::string Queue::dequeue() {

    // Variables
    std::string dequeuedItem;
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

