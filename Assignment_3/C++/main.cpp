/**
 * Graphs & Binary Search Trees - C++
 * Author: Christian Sarmiento
 * Purpose: 
 * Date Created: 11/10/24
 * Last Updated: 11/14/24
 * Compilation: g++ -std=c++20 -o GraphsAndBSTs main.cpp NodeLinkedList.cpp Graph.cpp NodeBinaryTree.cpp Queue.cpp Vertex.cpp
 * Run Program: ./GraphsAndBSTs
 * ---------------------------------------------------------------------------------------------------------------------------
 * Assignment 3             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Dependencies
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include "Graph.h" 
#include <sstream>

// Types
#include <string>
#include <vector>  // C++ dynamic list

/* Helper Methods */



/* Main Function */

/**
 * Main function for the program. 
*/
int main() {
    
    // Variables
    std::vector<std::string> magicItems;
    std::vector<Graph> graphs;
    std::vector<std::string> searchItems;
    std::string item = "";
    std::string content = "";
    int currGraphIndex = -1;
    std::string newVertexID = " ";
    std::string newEdge1 = " ";
    std::string newEdge2 = " ";
    std::string tempWord = " ";  // variable to save arbitrary words while processing

    /**
     * Read in contents from graphs1.txt into an array
    */
    
    // Open graphs1.txt file
    std::ifstream file("graphs1.txt");

    // Check if file opens successfully
    if (!file.is_open()) {

        std::cerr << "Failed to open file." << std::endl;
        return 1;

    } // if

    // Read in graph contents 
    while(std::getline(file, content)) {

        // Instantiating and saving new graphs
        if (content == "new graph") {

            Graph newGraph;
            graphs.push_back(newGraph);
            currGraphIndex++;

        } // if

        // Adding vertices to the graph
        else if (content.find("add vertex") != std::string::npos) {
            
            // Create vertex object and give it an ID
            newVertexID = content.substr(content.find("add vertex") + std::string("add vertex").size() + 1);
            Vertex* vertex = new Vertex(newVertexID);
            graphs[currGraphIndex].addVertex(vertex);

        } // else if

        // Adding edges to the graph
        else if (content.find("add edge") != std::string::npos) {
            
            // Parse out the vertexIDs to add the edges
            std::istringstream stream(content);
            stream >> tempWord;
            stream >> tempWord;
            stream >> newEdge1;
            stream >> tempWord;
            stream >> newEdge2;

            // Add the edge between the vertices
            graphs[currGraphIndex].addEdge(newEdge1, newEdge2);

        } // else if

    } // while

    // Close graphs1.txt
    file.close();

    // Iterate through the graphs and make the required output (matrix, adj. list, traversals)
    for (int i=0; i < graphs.size(); i++) {

        // Print the adjacency matrix
        // TODO: remove extra column of zeros
        //graphs[i].adjacencyMatrix();

        // Print the adjacency list
        //graphs[i].adjacencyList();

        // Print the depth-first traversal
        std::cout << "Depth-First Traversal:" << std::endl;
        graphs[i].depthFirstTraversal(graphs[i].myVertices[0]);
        std::cout << std::endl;
        std::cout << std::endl;

        // Print the breadth-first traversal
        graphs[i].resetProcessedFlag();
        std::cout << "Breadth-First Traversal:" << std::endl;
        graphs[i].breadthFirstTraversal(graphs[i].myVertices[0]);
        std::cout << std::endl;
        std::cout << std::endl;

    } // for i

    /**
     * Read in items from magicitems.txt into an array 
    

    // Open magicitems.txt file
    std::ifstream file("magicitems.txt");

    // Check if file open successfully
    if (!file.is_open()) {

        std::cerr << "Failed to open file." << std::endl;
        return 1;

    } // if

    // Read in magic items to vector array
    while(std::getline(file, item)) {

        magicItems.push_back(item);

    } // while

    // Close magicitems.txt
    file.close();

    */

}; // main()