/**
 * NodeBinaryTree Header File
 * Author: Christian Sarmiento
 * Purpose: Header file for NodeLinkedList class. Allows it to be used in other files. 
 * Date Created: 11/14/24
 * Last Updated: 11/14/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 3             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Dependencies
#include <string>

#ifndef NODEBINARYTREE_H
#define NODEBINARYTREE_H 

class NodeBinaryTree {

     // Instance Variables
    public:

        std::string myData = " ";
        NodeBinaryTree* myLeft = nullptr;
        NodeBinaryTree* myRight = nullptr;  


        // Null & Full Constructors
        NodeBinaryTree();
        NodeBinaryTree(std::string data);

        // Getters
        std::string getData();
        NodeBinaryTree* getLeft();
        NodeBinaryTree* getRight();

        // Setters
        void setData(std::string data);
        void setLeft(NodeBinaryTree* node);
        void setRight(NodeBinaryTree* node);

}; // Class NodeLinkedList

#endif // NODEBINARYTREE_H