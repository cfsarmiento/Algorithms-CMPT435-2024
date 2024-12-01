/**
 * BinarySearchTree Class
 * Author: Christian Sarmiento
 * Purpose: Class definition for a binary search tree structure, used to store string values.
 * Date Created: 11/15/24
 * Last Updated: 11/15/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 3             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Dependencies
#include "NodeBinaryTree.h" 
#include "BinarySearchTree.h"
#include <iostream>

/* Method Implementations */
/**
 * Null Constructor for binary tree node class
 */
BinarySearchTree::BinarySearchTree() {

    myRoot = nullptr;

} // Null Constructor

// Full Constructor

/**
 * Full Constructor for binary tree node class
 * 
 * @param root data for the root node
 */
BinarySearchTree::BinarySearchTree(NodeBinaryTree* root) {  // "const std::string& ... " passes variables by reference

    myRoot = root;
    
} // Full Constructor

/**
 * Deconstructor to delete the tree from memory
*/
BinarySearchTree::~BinarySearchTree() {
            
    destroyTree(myRoot);
    
} // Deconstructor

/**
 * Class Methods
*/

/**
 * Class method that recursively inserts a node to the binary search tree. Takes in a node and a data value as 
 * a string.
*/
NodeBinaryTree* BinarySearchTree::insertNode(NodeBinaryTree* node, std::string newData) {

    // Check if root node is null
    if (node == nullptr) 
        node = new NodeBinaryTree(newData);
    
    // If the data is greater than or equal to the node, add to the right
    else if (newData >= node->getData()) {

        std::cout << "R" << " ";
        node->myRight = insertNode(node->myRight, newData);

    } // if

    // If the data is less than the node, add to the left
    else if (newData < node->getData()) {

        std::cout << "L" << " ";
        node->myLeft = insertNode(node->myLeft, newData);

    } // if

    return node;

} // insertNode()

/**
 * Class method that adds a value to the binary tree. Takes in a string value.
*/
void BinarySearchTree::addData(std::string value) {

    myRoot = insertNode(myRoot, value);

} // addData()

/**
 * Class method that performs an in-order traversal of the binary tree
*/
void BinarySearchTree::inOrderTraversal(NodeBinaryTree* node) {

    // Check if the node exists
    if(node != nullptr) {

        // Traverse the tree
        inOrderTraversal(node->getLeft());
        std::cout << node->getData() << " ";
        inOrderTraversal(node->getRight());

    } // if

} // inOrderTraversal()

/**
 * Function that calls inOrderTraversal() with the root node.
*/
void BinarySearchTree::treeTraversal() {

    inOrderTraversal(myRoot);

} // treeTraversal()

NodeBinaryTree* BinarySearchTree::search(NodeBinaryTree* node, const std::string& value, int& comparisons) const {

    // Variables
    NodeBinaryTree* result = nullptr;

    // Make sure node is valid
    if (node != nullptr) {

        // Found the result
        comparisons++;
        if (node->getData() == value) {

            std::cout << "Found " << value << std::endl;
            result = node; 
        
        } // if

        // Result is less than
        else if (value < node->getData()) {

            std::cout << "L" << " ";
            result = search(node->getLeft(), value, comparisons); // Search in left subtree
        
        } // else if

        // Result is greater than or equal to
        else {

            std::cout << "R" << " ";
            result = search(node->getRight(), value, comparisons); // Search in right subtree

        } // else

    } // if

    return result; // Return the result at the end

} // search()

int BinarySearchTree::findItem(const std::string& searchValue) {
    
    // Variables
    int numComparisons = 0;

    // Search for the item
    search(myRoot, searchValue, numComparisons);

    return numComparisons;

} // findItem

/**
 * Class method to destroy the tree once it is no longer in use
*/
void BinarySearchTree::destroyTree(NodeBinaryTree* node) {

    if (node != nullptr) {

        destroyTree(node->myLeft);
        destroyTree(node->myRight);
        delete node;

    } // if

} // destroyTree()


