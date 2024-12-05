/**
 * SSSP & Spice Heist - C++
 * Author: Christian Sarmiento
 * Purpose: This program creates a directed graph from a text file and conducts a Bellman-Ford Single Source Shortest
 * path algorithm on the graph. We also conduct a spice heist given a text file where we must solve a variation of a 
 * fractional knapsack problem with out directed graph. 
 * Date Created: 11/30/24
 * Last Updated: 12/4/24
 * Compilation: g++ -std=c++20 -o SSSP-Spice main.cpp NodeLinkedList.cpp Graph.cpp Queue.cpp Vertex.cpp
 * Run Program: ./SSSP-Spice
 * ------------------------------------------------------------------------------------------------------------------------------------------------
 * Assignment 4             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
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

/* Helper Functions */

void initSingleSource(Graph graphObject, Vertex* initVertex) {

    // Variables 
    std::vector<Vertex*> graphVertices = graphObject.myVertices;
    int INIT_VERTEX_DISTANCE = 69696969;  // nice

    // Iterate through each vertex in the graph
    for (int i=0; i < graphVertices.size(); i++) {

        // Instansiate estimated distances and predecessor vertices
        graphVertices[i]->minDistance = INIT_VERTEX_DISTANCE;
        graphVertices[i]->predecessor = nullptr;

    } // for i

    // Set the minimum distance for the initial vertex
    initVertex->minDistance = 0;

} // initSingleSource()

void relax(Vertex*& startVertex, Vertex*& endVertex, int edgeWeight) {

    // Relax the path cost if the cost of getting to edge is greater than the current path
    if (endVertex->minDistance > startVertex->minDistance + edgeWeight) {

        endVertex->minDistance = startVertex->minDistance + edgeWeight;
        endVertex->predecessor = startVertex;

    } // if

} // relax()

void getPath(Vertex* vertex, std::vector<std::string>& pathVector) {

    // Base case - null pointer for predecessor
    if (vertex->predecessor != nullptr)
        getPath(vertex->predecessor, pathVector);
    
    // Add the vertex ID to the path vector - in order with recursion
    pathVector.push_back(vertex->getID());

} // getPath()

void outputShortestPath(Vertex* initVertex, std::vector<Vertex*> vertices) {

    // Variables
    std::string outputString = "";
    std::vector<std::string> idVector; 

    // Iterate through the vertices, not including the initial vertex
    for (int i=1; i < vertices.size(); i++) {

        // Build first part  of the string
        outputString += initVertex->getID();
        outputString += " --> ";
        outputString += vertices[i]->getID();
        outputString += " cost is ";
        outputString += std::to_string(vertices[i]->minDistance);
        outputString += "; path: ";

        // Call recursive function to get the path 
        getPath(vertices[i], idVector);

        // With populated vector, add ids to the output string
        for (int j=0; j < idVector.size(); j++) {

            if (j != idVector.size() - 1)
                outputString += idVector[j] + " --> ";
            
            else
                outputString += idVector[j];

        } // for j

        // Clear the vector for next iteration
        idVector.clear();

        // Add newline character to not crowd the output
        outputString += "\n";

    } // for i

    // Print final string
    std::cout << outputString << std::endl;

} // outputShortestPath


void bellmanFordSSSP(Graph& graph, Vertex* startVertex) {

    // Variables
    std::vector<Vertex*>& graphVertices = graph.myVertices;
    std::vector<std::tuple<Vertex*, Vertex*, int>>& graphEdges = graph.myEdges;
    bool success = true;

    // Initialize starting distances and predecessor vertex
    initSingleSource(graph, startVertex);


    // Iterate through the vertices
    for (int i=1; i <= (graphVertices.size() - 1); i++) {

        // Iterate through the edges
        for (int j=0; j < graphEdges.size(); j++) {

            relax(std::get<0>(graphEdges[j]), std::get<1>(graphEdges[j]), std::get<2>(graphEdges[j]));
    
        } // for j

    } // for i

    // Checking for negative weight cycle
    for (int k=0; k < graphEdges.size(); k++) {

        if (std::get<1>(graphEdges[k])->minDistance > (std::get<0>(graphEdges[k])->minDistance + std::get<2>(graphEdges[k])))
            success = false;

    } // for k


    // Print results
    if (success) 
        outputShortestPath(startVertex, graphVertices);
    
    else
        std::cout << "Negative weight cycle." << std::endl;
  

} // bellmanFordSSSP()

std::vector<std::string> split(const std::string& text, char delimiter) {

    // Variables
    std::vector<std::string> result;
    std::stringstream ss(text);
    std::string item;

    // Split the string on the given delimiter
    while (std::getline(ss, item, delimiter)) {

        result.push_back(item);

    } // while

    return result;

} // split()
/* Main Function */

/**
 * Main function for the program. 
*/
int main() {
    
    // Variables
    std::vector<Graph> graphs;
    std::string entry = "";
    std::string searchItem = "";
    std::string content = "";
    int currGraphIndex = -1;
    std::string newVertexID = " ";
    std::string newEdge1 = " ";
    std::string newEdge2 = " ";
    std::string tempWord = " ";  // variable to save arbitrary words while processing
    std::string spiceName = " ";
    int weight = 0;
    int componentCount = 0;
    std::vector<std::string> spiceAttributes; 

    /**
     * SSSP
    */
    
    // Open graphs2.txt file
    std::ifstream graphFile("graphs2.txt");

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
            stream >> tempWord;  // "add"
            stream >> tempWord;  // "edge"
            stream >> newEdge1;  // "{edge ID 1}"
            stream >> tempWord;  // "-"
            stream >> newEdge2;  // "{edge ID 2}"
            stream >> weight;    // "{weight}"
        
            // Add the edge between the vertices
            graphs[currGraphIndex].addEdge(newEdge1, newEdge2, weight);  

        } // else if

    } // while

    // Close graphs1.txt
    graphFile.close();

    // Iterate through the graphs and conduct Bellman-Ford SSSP
    for (int i=0; i < graphs.size(); i++) {

        std::cout << "Graph " << i + 1 << ":" << std::endl;
        bellmanFordSSSP(graphs[i], graphs[i].myVertices[0]);

    } // for i

   /**
    * Spice Heist - Fractional Knapsack
    */

    // Open spice.txt file
    std::ifstream spiceFile("spice.txt");

    // Check if file open successfully
    if (!spiceFile.is_open()) {

        std::cerr << "Failed to open file." << std::endl;
        return 1;

    } // if

    // Parse file to create spice objects
    while(std::getline(spiceFile, entry)) {

        // Check if we are at a spice object entry
        if (entry.find("spice") != std::string::npos) {

            // Make a vector that splits the entry on semicolons
            spiceAttributes = split(entry, ';');

            // Iterate through substring to build our spice object
            for (int j=0; j < spiceAttributes.size(); j++) {

                // Get name
                if (spiceAttributes[j].find("name =") != std::string::npos) {

                    // Parse out the name
                    std::istringstream stream(spiceAttributes[j]);
                    stream >> tempWord;  // "spice"
                    stream >> tempWord;  // "name"
                    stream >> tempWord;  // "="
                    stream >> spiceName;  // "{name}"
                    
                    std::cout << spiceName << std::endl;

                } // if 

            } // for j

        } // if

    } // while

    // Close magicitems.txt
    spiceFile.close();


}; // main()