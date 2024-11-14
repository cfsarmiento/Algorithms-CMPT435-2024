/**
 * Graph Header File
 * Author: Christian Sarmiento
 * Purpose: Header file for Graph class. Allows it to be used in other files. 
 * Date Created: 11/10/24
 * Last Updated: 11/14/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 3             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

#ifndef GRAPH_H
#define GRAPH_H

// Dependencies 
#include <string>
#include "Vertex.h"

class Graph {

    public:

        // Instance Variables
        std::vector<Vertex*> myVertices;
        std::string myGraphName;
        std::vector<std::vector<std::string>> myGraphMatrix;
        int numVertices;

        // Constructors
        Graph();
        Graph(std::string newName);

        // Getters
        Vertex* Graph::getVertex(std::string vertexID);

        // Setters
        void Graph::addVertex(Vertex* newVertex);
        void Graph::addEdge(std::string vertex1ID, std::string vertex2ID);

        // Class Methods
        void Graph::adjacencyList();
        void Graph::adjacencyMatrix();
        void Graph::depthFirstTraversal(Vertex* currVertex);
        void Graph::breadthFirstTraversal(Vertex* currVertex);
    
}; // Class Graph

#endif // GRAPH_H