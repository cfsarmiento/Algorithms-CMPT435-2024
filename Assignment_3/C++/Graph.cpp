/*
 * Graph Class
 * Author: Christian Sarmiento
 * Purpose: Class definition for a linked list data structure, used to store string values of palindromes.
 * Date Created: 11/10/24
 * Last Updated: 11/12/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 3             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Dependencies
#include "Graph.h" 
#include <iostream>

/* Method Implementations */

/**
 * Null Constructor for graph class
 */
Graph::Graph() {

    myVertices;
    myGraphName = " ";

} // Null Constructor

/**
 * Full Constructor for graph class
 */
Graph::Graph(std::string newName) {

    myVertices;
    myGraphName = newName;

} // Full Constructor

/* Getters */

/**
 * Getter method that gets a given vertex in the current graph. Takes in a vertex ID as a string. Returns
 * a pointer to the vertex requested.
*/
Vertex* Graph::getVertex(std::string vertexID) {

    // Variables
    Vertex* foundVertex;
    bool found = false;

    // Iterate through current verticies
    for(int i = 0; i < myVertices.size(); i++) {

        // Check for the vertex we are looking for
        if(myVertices[i]->getID() == vertexID) {
            
            // if found save the pointer to return to the user
            foundVertex = myVertices[i];
            found == true;

        } // if

    } // for i

    if (!found)
        std::cout << "Could not find vertex " << vertexID << "." << std::endl;

    return foundVertex;

} // getVertex()

/* Setters */
/**
 * Class method that adds a vertex to the graph 
*/
void Graph::addVertex(Vertex* newVertex) {

    myVertices.push_back(newVertex);

} // addVertex()

/**
 * Setter method that adds an edge between two verticies. Takes in two strings representing IDs belonging to the 1st 
 * and 2nd verticies to be added, respectively.
*/
void Graph::addEdge(std::string vertex1ID, std::string vertex2ID) {

    // Variables
    Vertex* vertex1;
    Vertex* vertex2;
    
    // Get both of the verticies
    vertex1 = getVertex(vertex1ID);
    vertex2 = getVertex(vertex2ID);

    // Add an edge between them if both verticies exist
    if (vertex1 && vertex2) {

        vertex1->addNeighbor(vertex2);
        vertex2->addNeighbor(vertex1);
        
        // Let the user know that the edges have been added
        std::cout << "Added an edge between " << vertex1ID << " and " << vertex2ID << "." << std::endl;

    } // if

    else
        std::cout << "Could not add an edge between " << vertex1ID << " and " << vertex2ID << "." << std::endl;

} // addEdge()

/* Class Methods */