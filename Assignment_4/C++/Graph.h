/**
 * Graph Header File
 * Author: Christian Sarmiento
 * Purpose: Header file for Graph class. Allows it to be used in other files. 
 * Date Created: 11/30/24
 * Last Updated: 12/3/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 4             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
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
        std::vector<std::tuple<Vertex*, Vertex*, int>> myEdges;
        int numVertices;

        // Constructors
        Graph();
        Graph(std::string newName);
        //~Graph();

        // Getters
        Vertex* getVertex(std::string vertexID) const;

        // Setters
        void addVertex(Vertex* newVertex);
        void addEdge(std::string vertex1ID, std::string vertex2ID, int weightVal);

        // Class Methods
        void resetProcessedFlag();
        void adjacencyList() const;
        void adjacencyMatrix() const;
        void depthFirstTraversal(Vertex* currVertex);
        void breadthFirstTraversal(Vertex* currVertex);
    
}; // Class Graph

#endif // GRAPH_H