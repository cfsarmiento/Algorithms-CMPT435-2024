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
 * and 2nd verticies to be added, respectively.
*/
void Graph::addEdge(std::string vertex1ID, std::string vertex2ID) {

    // Variables
    Vertex* vertex1;
    Vertex* vertex2;
    int start = -1;
    int end = -1;

    // Get both of the verticies
    vertex1 = getVertex(vertex1ID);
    vertex2 = getVertex(vertex2ID);

    // Add an edge between them if both vertices exist
    if (vertex1 && vertex2) {

        vertex1->addNeighbor(vertex2);
        vertex2->addNeighbor(vertex1);
        
        // Let the user know that the edges have been added
        std::cout << "Added an edge between " << vertex1ID << " and " << vertex2ID << "." << std::endl;

    } // if

    else
        std::cout << "Could not add an edge between " << vertex1ID << " and " << vertex2ID << "." << std::endl;

    // Find the index at where the vertices exist in the adjacency matrix
    for (int i = 1; i <= numVertices; i++) {

        if (myGraphMatrix[i][0] == vertex1ID)
            start = i;
        
        if (myGraphMatrix[0][i] == vertex2ID)
            end = i;

    } // for i

    // Add edge to the adjacency matrix
    myGraphMatrix[start][end] = "1";
    myGraphMatrix[end][start] = "1";

} // addEdge()

/* Class Methods */

/**
 * Class method that outputs an adjacency list for the graph
*/
void Graph::adjacencyList() {

    // Variables
    std::string currID = " ";
    std::string neighbors = " ";

    // Iterate through each vertex in the graph to output the IDs of each vertex
    std::cout << "Adjacency List" << std::endl;
    for (int i = 0; i < myVertices.size(); i++) {

        // Get the vertex ID
        currID = myVertices[i]->getID();

        // Get vertex neighbors
        neighbors = myVertices[i]->getNeighborIDs();

        // Print out the row for the adjacency list
        std::cout << currID << ": " << neighbors << std::endl;

    } // for i 

    std::cout << std::endl;

} // adjacencyList()

/**
 * Class method that prints out the adjacency matrix for the graph. 
*/
void Graph::adjacencyMatrix() {

    // Iterate through each row
    for (const auto& row : myGraphMatrix) {

        // Iterate through each cell and print out the value
        for (const auto& cell : row) {

            std::cout << (cell.empty() ? "0" : cell) << " ";

        } // for cell

        std::cout << std::endl;

    } // for row

} // adjacencyMatrix()