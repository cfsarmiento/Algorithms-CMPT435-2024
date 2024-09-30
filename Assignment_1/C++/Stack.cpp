/**
 * Stack Class
 * Author: Christian Sarmiento
 * Purpose: Class definition for a stack list data structure, used to store string values of palindromes.
 * Date Created: 9/18/24
 * Last Updated: 9/21/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 1             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Dependencies
#include "Stack.h"

// Types
#include <string>  

/* Method Implementations */
/**
 * Null Constructor for linked list node class
 */
Stack::Stack() {

    myTop = nullptr;

} // Null Constructor

// Full Constructor

/**
 * Full Constructor for linked list node class
 * 
 * @param node node to be put into the stack
 */
Stack::Stack(NodeLinkedList* node) {  

    myTop = node;
    
} // Full Constructor

/* Stack Methods */
/**
 * Class method to determine if the stack is empty
*/
bool Stack::isEmpty() {

    return (myTop == nullptr);

} // isEmpty())

/**
 * Class method that returns the string value that exists 
 * in the node at the top of the list
*/
std::string Stack::pop() {

    // Variables
    std::string poppedItem;
    NodeLinkedList* temp;

    // Pop from the stack
    if(!isEmpty()) {

        poppedItem = myTop->getData();
        temp = myTop;
        myTop = myTop->getNext();
        delete temp;  // getting rid of the popped node in memomry

    } // if
    
    return poppedItem;

}; // pop()

/**
 * Class method that adds a node with a new value to the 
 * top of the stack
 * @param data data value to be pushed on to the stack 
*/
void Stack::push(const std::string& data) {

    // Variables
    NodeLinkedList* newNode;

    // Instantiate new node object & save new data
    newNode = new NodeLinkedList();
    newNode->setData(data);

    // Update stack
    newNode->setNext(myTop);
    myTop = newNode;

}; // push()


