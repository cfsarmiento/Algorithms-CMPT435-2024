/*
 * Vertex Class
 * Author: Christian Sarmiento
 * Purpose: Class definition for a vertex data structure
 * Date Created: 11/10/24
 * Last Updated: 11/12/24
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
 * Full Constructor for vertex class
 * 
 * @param newID ID for the vertex
 */
Vertex::Vertex(std::string newID) {  

    myID = newID;
    
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

/* Setters */

/**
 * Setter method to set the ID for the given vertex. Takes in a string as the ID and returns nothing. 
*/
void Vertex::setID(std::string newID) {

    myID = newID;

} // setID()

/**
 * Setter method for the processed flag. Sets the flag equal to true if called. 
*/
void Vertex::setProccessedFlag() {

    proccessed = true;
 
} // setProccessedFlag()

/**
 * Setter method to add a neighbor to the current vertex. Takes in a vertex pointer and returns nothing. 
*/
void Vertex::addNeighbor(Vertex* newVertex) {

    myNeighbors.push_back(newVertex);

} // addNeighbor()