/**
 * NodeLinkedList Header File
 * Author: Christian Sarmiento
 * Purpose: Header file for NodeLinkedList class. Allows it to be used in other files. 
 * Date Created: 9/18/24
 * Last Updated: 9/18/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 1             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

#ifndef NODELINKEDLIST_H
#define NODELINKEDLIST_H

// Types
#include <string>  

class NodeLinkedList {

     // Instance Variables
    public:

        std::string myData;
        NodeLinkedList* myNext;  


        // Null & Full Constructors
        NodeLinkedList();
        NodeLinkedList(const std::string& data, NodeLinkedList* node);

        // Class Methods Headers
        std::string getData();
        NodeLinkedList* getNext();
        void setData(const std::string& data);
        void setNext(NodeLinkedList* node);

}; // Class NodeLinkedList

#endif // NODELINKEDLIST_H