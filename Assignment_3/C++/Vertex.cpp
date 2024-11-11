/*
 * Vertex Class
 * Author: Christian Sarmiento
 * Purpose: Class definition for a vertex data structure
 * Date Created: 11/10/24
 * Last Updated: 11/10/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 3             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Dependencies
#include "Vertex.h" 

/* Method Implementations */

/**
 * Null Constructor for vertex class
 */
Vertex::Vertex() {

    myID = " ";
    proccessed = false;

} // Null Constructor

/**
 * Full Constructor for linked list node class
 * 
 * @param data data for the node
 * @param next next node linked to current node (if any)
 */
Vertex::Vertex(std::string data) {  

    myID = data;
    
} // Full Constructor

/* Getters */

/**
 * Getter method to return the vertex ID.
*/
std::string Vertex::getID() {

    return myID;

} // getID()

/**
 * Getter method that checks if the vertex has been proccessed or not. Returns a boolean flag. 
*/
bool Vertex::isProccessed() {

    return proccessed;

} // isProccessed()

/**
 * Getter method that returns the neighbors for the current vertex. A neighbor is another vertex that shares an edge
 * with the current vertex. Returns a vector of vertex class pointers. 
*/
std::vector<Vertex*> Vertex::getNeighbors() {

    return myNeighbors;

} // getNeighbors()
