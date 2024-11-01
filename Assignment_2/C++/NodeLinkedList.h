/**
 * NodeLinkedList Header File
 * Author: Christian Sarmiento
 * Purpose: Header file for NodeLinkedList class. Allows it to be used in other files. 
 * Date Created: 10/31/24
 * Last Updated: 10/31/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 2             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

#ifndef NODELINKEDLIST_H
#define NODELINKEDLIST_H 

// Dependencies 
#include <string>

class NodeLinkedList {

     // Instance Variables
    public:

        std::string myData;
        NodeLinkedList* myNext;  


        // Null & Full Constructors
        NodeLinkedList();
        NodeLinkedList(std::string data, NodeLinkedList* node);

        // Class Methods Headers
        std::string getData();
        NodeLinkedList* getNext();
        void setData(std::string data);
        void setNext(NodeLinkedList* node);

}; // Class NodeLinkedList

#endif // NODELINKEDLIST_H