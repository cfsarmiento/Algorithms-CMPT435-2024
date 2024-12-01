/**
 * NodeLinkedList Header File
 * Author: Christian Sarmiento
 * Purpose: Header file for NodeLinkedList class. Allows it to be used in other files. 
 * Date Created: 11/10/24
 * Last Updated: 11/14/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 2             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Dependencies
#include "Vertex.h"

#ifndef NODELINKEDLIST_H
#define NODELINKEDLIST_H 

class NodeLinkedList {

     // Instance Variables
    public:

        Vertex* myData;
        NodeLinkedList* myNext;  


        // Null & Full Constructors
        NodeLinkedList();
        NodeLinkedList(Vertex* data, NodeLinkedList* node);

        // Class Methods Headers
        Vertex* getData();
        NodeLinkedList* getNext();
        void setData(Vertex* data);
        void setNext(NodeLinkedList* node);

}; // Class NodeLinkedList

#endif // NODELINKEDLIST_H