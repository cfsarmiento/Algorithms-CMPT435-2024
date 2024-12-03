/**
 * Vertex Header File
 * Author: Christian Sarmiento
 * Purpose: Header file for Vertex class. Allows it to be used in other files. 
 * Date Created: 11/30/24
 * Last Updated: 12/3/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 4             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

#ifndef VERTEX_H
#define VERTEX_H 

// Dependencies 
#include <string>
#include <vector>
#include <tuple>

class Vertex {

    public:

        // Instance Variables
        std::string myID = " ";
        bool proccessed = false;
        std::vector<std::tuple<Vertex*, int>> myNeighbors;
        int minDistance = 0;
        Vertex* predecessor; 

        // Null & Full Constructors
        Vertex();
        Vertex(std::string data);

        // Getters
        std::string getID();
        bool isProccessed();
        std::vector<std::tuple<Vertex*, int>> getNeighbors();
        std::string getNeighborIDs();

        // Setters
        void setID(std::string newID);
        void addNeighbor(std::tuple<Vertex*, int> neighborWeightedEdge);

}; // Class Vertex

#endif // VERTEX_H