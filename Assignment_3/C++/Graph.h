/**
 * Graph Header File
 * Author: Christian Sarmiento
 * Purpose: Header file for Graph class. Allows it to be used in other files. 
 * Date Created: 10/31/24
 * Last Updated: 10/31/24
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

        // Constructors
        Graph();
        Graph(std::string newName);

        // Class Methods
        Vertex* Graph::getVertex(std::string vertexID);
        void Graph::addVertex(Vertex* newVertex);
        void Graph::addEdge(std::string vertex1ID, std::string vertex2ID);


    
}; // Class Graph

#endif // GRAPH_H