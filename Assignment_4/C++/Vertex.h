/**
 * Vertex Header File
 * Author: Christian Sarmiento
 * Purpose: Header file for Vertex class. Allows it to be used in other files. 
 * Date Created: 11/30/24
 * Last Updated: 11/30/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 4             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

#ifndef VERTEX_H
#define VERTEX_H 

// Dependencies 
#include <string>
#include <vector>

class Vertex {

    public:

        // Instance Variables
        std::string myID = " ";
        bool proccessed = false;
        std::vector<Vertex*> myNeighbors;  

        // Null & Full Constructors
        Vertex();
        Vertex(std::string data);

        // Getters
        std::string getID();
        bool isProccessed();
        std::vector<Vertex*> getNeighbors();
        std::string getNeighborIDs();

        // Setters
        void setID(std::string newID);
        void addNeighbor(Vertex* newVertex);

}; // Class Vertex

#endif // VERTEX_H