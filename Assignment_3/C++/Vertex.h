/**
 * Vertex Header File
 * Author: Christian Sarmiento
 * Purpose: Header file for Vertex class. Allows it to be used in other files. 
 * Date Created: 10/31/24
 * Last Updated: 10/31/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 3             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

#ifndef VERTEX_H
#define VERTEX_H 

// Dependencies 
#include <string>

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
        std::string Vertex::getID();
        bool Vertex::isProccessed();
        std::vector<Vertex*> getNeighbors();
        std::string Vertex::getNeighborIDs();

        // Setters
        void Vertex::setID(std::string newID);
        void Vertex::setProccessedFlag();
        void Vertex::addNeighbor(Vertex* newVertex);

}; // Class Vertex

#endif // VERTEX_H