/**
 * NodeBinaryTree Class
 * Author: Christian Sarmiento
 * Purpose: Class definition for a linked list data structure, used to store string values of palindromes.
 * Date Created: 11/14/24
 * Last Updated: 11/14/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 3             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Dependencies
#include "NodeBinaryTree.h" 

/* Method Implementations */
/**
 * Null Constructor for binary tree node class
 */
NodeBinaryTree::NodeBinaryTree() {

    myData = ' ';
    myLeft = nullptr;
    myRight = nullptr;

} // Null Constructor

// Full Constructor

/**
 * Full Constructor for binary tree node class
 * 
 * @param data data for the node
 * @param left left node linked to current node (if any)
 * @param right right node linked to current node (if any)
 */
NodeBinaryTree::NodeBinaryTree(std::string data, NodeBinaryTree* left, NodeBinaryTree* right) {  // "const std::string& ... " passes variables by reference

    myData = data;
    myLeft = left;
    myRight = right;
    
} // Full Constructor

/* Getters */
/**
 * Class method to return the data from the current node
*/
std::string NodeBinaryTree::getData() {

    return myData;

} // getData()

/**
 * Class method that returns a pointer to the left node in the tree
*/
NodeBinaryTree* NodeBinaryTree::getLeft() {

    return myLeft;

} // getLeft()

/**
 * Class method that returns a pointer to the right node in the tree
*/
NodeBinaryTree* NodeBinaryTree::getRight() {

    return myRight;

} // getRight()

/* Setters */

/**
 * Class method that updates the data in the current node
*/
void NodeBinaryTree::setData(std::string data) {

    myData = data;

} // setData()

/**
 * Class method that updates the pointer to the left node
*/
void NodeBinaryTree::setLeft(NodeBinaryTree* node) {

    myLeft = node;

} // setLeft()

/**
 * Class method that updates the pointer to the right node
*/
void NodeBinaryTree::setRight(NodeBinaryTree* node) {

    myRight = node;

} // setLeft()