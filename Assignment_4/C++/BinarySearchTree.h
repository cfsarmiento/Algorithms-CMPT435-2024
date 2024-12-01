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
#include "NodeBinaryTree.h"

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

class BinarySearchTree {

    private:

        // Instance Variables
        NodeBinaryTree* myRoot;
         

        // Class Methods
        NodeBinaryTree* insertNode(NodeBinaryTree* node, std::string data);
        void destroyTree(NodeBinaryTree* node);
        void inOrderTraversal(NodeBinaryTree* node);
        NodeBinaryTree* search(NodeBinaryTree* node, const std::string& value, int& comparisons) const;
    
    public:

        // Null & Full Constructors
        BinarySearchTree();
        BinarySearchTree(NodeBinaryTree* root);
        ~BinarySearchTree();

        // Class Methods
        void addData(std::string value);
        void treeTraversal();
        int findItem(const std::string& searchValue);
        

}; // Class NodeLinkedList

#endif // NODEBINARYTREE_H