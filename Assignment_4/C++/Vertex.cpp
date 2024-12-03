/*
 * Vertex Class
 * Author: Christian Sarmiento
 * Purpose: Class definition for a vertex data structure
 * Date Created: 11/30/24
 * Last Updated: 12/3/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 4             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
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
std::vector<std::tuple<Vertex*, int>> Vertex::getNeighbors() {

    return myNeighbors;

} // getNeighbors()

/**
 * Getter method that returns the IDs of the neighbors for the current vertex. Returns a string of IDs.
*/
std::string Vertex::getNeighborIDs() {

    // Variables
    std::vector<std::tuple<Vertex*, int>> currNeighbors = getNeighbors();
    std::string neighborIDs = "";

    // Iterate through the current neighbors
    for (int i = 0; i < currNeighbors.size(); i++) {

        // Save the output of the IDs nicely 
        if(i < currNeighbors.size() - 1)
            neighborIDs += std::get<0>(currNeighbors[i])->getID() + ", ";

        else
            neighborIDs += std::get<0>(currNeighbors[i])->getID();

    } // for

    return neighborIDs;

} // getNeighbors()

/* Setters */

/**
 * Setter method to set the ID for the given vertex. Takes in a string as the ID and returns nothing. 
*/
void Vertex::setID(std::string newID) {

    myID = newID;

} // setID()

/**
 * Setter method to add a neighbor to the current vertex. Takes in a tuple that holds a vertex pointer and the 
 * weight of the edge to get there
*/
void Vertex::addNeighbor(std::tuple<Vertex*, int> neighborWeightedEdge) {

    myNeighbors.push_back(neighborWeightedEdge);

} // addNeighbor()
