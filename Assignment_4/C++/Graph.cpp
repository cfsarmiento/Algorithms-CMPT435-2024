/*
 * Graph Class
 * Author: Christian Sarmiento
 * Purpose: Class definition for a linked list data structure, used to store string values of palindromes.
 * Date Created: 11/30/24
 * Last Updated: 12/4/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 4             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Dependencies
#include "Graph.h" 
#include <iostream>
#include <tuple>

/* Method Implementations */

/**
 * Null Constructor for graph class
 */
Graph::Graph() {

    myGraphName = " ";
    numVertices = 0;
    myGraphMatrix.push_back({""});

} // Null Constructor

/**
 * Full Constructor for graph class
 */
Graph::Graph(std::string newName) {

    myGraphName = newName;

} // Full Constructor

/* Getters */

/**
 * Getter method that gets a given vertex in the current graph. Takes in a vertex ID as a string. Returns
 * a pointer to the vertex requested.
*/
Vertex* Graph::getVertex(std::string vertexID) const {

    // Variables
    Vertex* foundVertex = nullptr;
    bool found = false;

    // Iterate through current verticies
    for(int i = 0; i < myVertices.size(); i++) {

        // Check for the vertex we are looking for
        if(myVertices[i]->getID() == vertexID) {
            
            // if found save the pointer to return to the user
            foundVertex = myVertices[i];
            found = true;

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

    // Add vertex to the graph 
    myVertices.push_back(newVertex);
    numVertices++;

    // Add a row in the graph matrix
    myGraphMatrix.push_back(std::vector<std::string>(numVertices + 1, "0"));

    // Add column to the graph matrix
    for (int i=0; i <= numVertices; i++)
        myGraphMatrix[i].push_back("0");

    // Set vertex ID for the matrix
    myGraphMatrix[numVertices][0] = newVertex->getID(); 
    myGraphMatrix[0][numVertices] = newVertex->getID();

} // addVertex()

/**
 * Setter method that adds an edge between two verticies. Takes in two strings representing IDs belonging to the 1st 
 * and 2nd verticies to be added, respectively as well as a weight. The second parameter (vertex2ID) will always
 * be what the first parameter (vertex1ID) is pointing to for the direction of the edge.
*/
void Graph::addEdge(std::string vertex1ID, std::string vertex2ID, int weightVal) {

    // Variables
    Vertex* vertex1;
    Vertex* vertex2;

    // Get both of the verticies
    vertex1 = getVertex(vertex1ID);
    vertex2 = getVertex(vertex2ID);

    // Add an edge between them if both vertices exist - directed edge 
    if (vertex1 && vertex2) {

        // Create a tuple with the neighbor vertex and weight
        std::tuple<Vertex*, int> weightedEdge(vertex2, weightVal);

        // Add edge 
        vertex1->addNeighbor(weightedEdge); 

        // Create a tuple for edges and weights
        std::tuple<Vertex*, Vertex*, int> edgeWeightPairs(vertex1, vertex2, weightVal);
        myEdges.push_back(edgeWeightPairs);

    } // if

    else
        std::cout << "Could not add an edge between " << vertex1ID << " and " << vertex2ID << "." << std::endl;

} // addEdge()






