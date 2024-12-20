/**
 * Graphs & Binary Search Trees - C++
 * Author: Christian Sarmiento
 * Purpose: This program creates an undirected graph object from a text file and also creates a binary search tree.
 * Date Created: 11/10/24
 * Last Updated: 11/15/24
 * Compilation: g++ -std=c++20 -o GraphsAndBSTs main.cpp NodeLinkedList.cpp Graph.cpp NodeBinaryTree.cpp Queue.cpp Vertex.cpp BinarySearchTree.cpp
 * Run Program: ./GraphsAndBSTs
 * ------------------------------------------------------------------------------------------------------------------------------------------------
 * Assignment 3             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Dependencies
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include "Graph.h" 
#include "BinarySearchTree.h"
#include <sstream>

// Types
#include <string>
#include <vector>  // C++ dynamic list

/* Helper Methods */
void buildBinaryTree(NodeBinaryTree node) {

    // 
} // buildBinaryTree


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
    std::string searchItem = "";
    std::string content = "";
    int currGraphIndex = -1;
    std::string newVertexID = " ";
    std::string newEdge1 = " ";
    std::string newEdge2 = " ";
    std::string tempWord = " ";  // variable to save arbitrary words while processing
    int bstComparisons = 0;
    double avgBSTComparisons = 0.0;
    int componentCount = 0;

    /**
     * Graphs
    */
    
    // Open graphs1.txt file
    std::ifstream graphFile("graphs1.txt");

    // Check if file opens successfully
    if (!graphFile.is_open()) {

        std::cerr << "Failed to open file." << std::endl;
        return 1;

    } // if

    // Read in graph contents 
    while(std::getline(graphFile, content)) {

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
    graphFile.close();

    // Iterate through the graphs and make the required output (matrix, adj. list, traversals)
    for (int i=0; i < graphs.size(); i++) {

        // Print the adjacency matrix
        // TODO: remove extra column of zeros
        graphs[i].adjacencyMatrix();

        // Print the adjacency list
        graphs[i].adjacencyList();

        // Print the depth-first traversal
        componentCount = 0;
        std::cout << "Depth-First Traversal:" << std::endl;
        for (int j=0; j < graphs[i].myVertices.size(); j++) {  // iterate to make sure disconnected graphs are traversed

            // Check if the vertex is processed
            if (!(graphs[i].myVertices[j]->isProccessed())) {
                
                componentCount++;
                std::cout << "Component " << componentCount << ":" << std::endl;
                graphs[i].depthFirstTraversal(graphs[i].myVertices[j]);
                std::cout << std::endl;
                std::cout << std::endl;

            } // if

        } // for j

        // Print the breadth-first traversal
        graphs[i].resetProcessedFlag();
        componentCount = 0;
        std::cout << "Breadth-First Traversal:" << std::endl;
        for (int k=0; k < graphs[i].myVertices.size(); k++) {  

            // Check if the vertex is processed
            if (!(graphs[i].myVertices[k]->isProccessed())) {
                
                componentCount++;
                std::cout << "Component " << componentCount << ":" << std::endl;
                graphs[i].breadthFirstTraversal(graphs[i].myVertices[k]);
                std::cout << std::endl;
                std::cout << std::endl;

            } // if

        } // for k

    } // for i

    /**
     * Binary Search Tree
    */

    // Open magicitems.txt file
    std::ifstream bstFile("magicitems.txt");

    // Check if file open successfully
    if (!bstFile.is_open()) {

        std::cerr << "Failed to open file." << std::endl;
        return 1;

    } // if

    // Read in magic items to vector array
    while(std::getline(bstFile, item)) {

        magicItems.push_back(item);

    } // while

    // Close magicitems.txt
    bstFile.close();

    // Define binary search tree
    BinarySearchTree binaryTree;

    // Load the items into a binary search tree
    for (int l = 0; l < magicItems.size(); l++) {

        std::cout << magicItems[l] << ": " << " ";
        binaryTree.addData(magicItems[l]);
        std::cout << std::endl;

    } // for l

    // Perform an in-order traversal
    binaryTree.treeTraversal();

    // Load items to look for
    std::ifstream searchFile("magicitems-find-in-bst.txt");

    // Check if file open successfully
    if (!searchFile.is_open()) {

        std::cerr << "Failed to open file." << std::endl;
        return 1;

    } // if

    // Read in magic items to vector array
    while(std::getline(searchFile, searchItem)) {

        searchItems.push_back(searchItem);

    } // while

    // Close magicitems.txt
    searchFile.close();

    // Look for each of the items in the tree
    for (int m=0; m < searchItems.size(); m++) {

        bstComparisons = binaryTree.findItem(searchItems[m]);
        avgBSTComparisons += bstComparisons;
        std::cout << "Comparisons for " << searchItems[m] << ": " << bstComparisons << std::endl;

    } // for m

    std::cout << std::fixed << std::setprecision(2) << "Average Comparisons: " << (avgBSTComparisons / searchItems.size()) << std::endl;
    
}; // main()