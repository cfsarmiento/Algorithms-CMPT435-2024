/**
 * SSSP & Spice Heist - C++
 * Author: Christian Sarmiento
 * Purpose: This program creates a directed graph from a text file and conducts a Bellman-Ford Single Source Shortest
 * path algorithm on the graph. We also conduct a spice heist given a text file where we must solve a variation of a 
 * fractional knapsack problem with out directed graph. 
 * Date Created: 11/30/24
 * Last Updated: 12/5/24
 * Compilation: g++ -std=c++20 -o SSSP-Spice main.cpp Graph.cpp Vertex.cpp Spice.cpp
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
#include "Spice.h"

// Types
#include <string>
#include <vector>  // C++ dynamic list
#include <map>

/* Helper Functions */

/**
 * Helper method for bellmanFordSSSP() to help initalize the proper attributes to begin SSSP.
 */
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

/**
 * Helper function for bellmanFordSSSP() that helps find the minimum distance between two vertices. Takes in
 * two vertex objects for the start and end vertices and the weight for the edge between them. 
 */
void relax(Vertex*& startVertex, Vertex*& endVertex, int edgeWeight) {

    // Relax the path cost if the cost of getting to edge is greater than the current path
    if (endVertex->minDistance > startVertex->minDistance + edgeWeight) {

        endVertex->minDistance = startVertex->minDistance + edgeWeight;
        endVertex->predecessor = startVertex;

    } // if

} // relax()

/**
 * Helper function that uses recursion to find the path from an end vertex back to the inital vertex using
 * the predecessor edges. Takes in a vertex object as the end vertex and passes a vector of strings by 
 * reference in order to save the output appropriately.
 */
void getPath(Vertex* vertex, std::vector<std::string>& pathVector) {

    // Base case - null pointer for predecessor
    if (vertex->predecessor != nullptr)
        getPath(vertex->predecessor, pathVector);
    
    // Add the vertex ID to the path vector - in order with recursion
    pathVector.push_back(vertex->getID());

} // getPath()

/**
 * Helper method that helps display the shortest path to each vertex in a graph from an inital vertex. Helper
 * method for the bellmanFordSSSP() function that takes in a vertex object for the intial vertex and a vector
 * of vertices. 
 */
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

/**
 * Helper methon that conducts Bellman-Ford Single Source Shortest Path (SSSP). Takes in a graph object as well
 * as a start vertex object to find the shortest path to all the other vertices from the start vertex. 
 */
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

/**
 * Helper method for parsing. This helps split a string on a given delimiter. Takes in a string of text and 
 * a character for the delimiter. 
 */
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

/**
 * Helper method to swap string elements in an array. 
*/
void swap(Spice& item1, Spice& item2) {

    // Variables
    Spice temp;

    // Swap
    temp = item1;
    item1 = item2;
    item2 = temp;

} // swap

/**
 * Helper method for Quick Sort to choose a pivot point. Takes in an array as well as starting, middle, 
 * and end indexes. Returns the pivot index.
*/
int choosePivot(std::vector<Spice>& array, int left, int mid, int right) {

    // Variables
    int pivotPostion = 0;

    // Find middle value out of left, mid, and right indexes
    if ((array[left].getUnitPrice() <= array[mid].getUnitPrice() && array[mid].getUnitPrice() <= array[right].getUnitPrice()) || 
        (array[right].getUnitPrice() <= array[mid].getUnitPrice() && array[mid].getUnitPrice() <= array[left].getUnitPrice()))
        pivotPostion = mid;

    else if ((array[mid].getUnitPrice() <= array[left].getUnitPrice() && array[left].getUnitPrice() <= array[right].getUnitPrice()) || 
             (array[right].getUnitPrice() <= array[left].getUnitPrice() && array[left].getUnitPrice() <= array[mid].getUnitPrice()))
        pivotPostion = left;

    else
        pivotPostion = right;

    return pivotPostion;

} // choosePivot()

/**
 * Helper method for Quick Sort. Partitions the list to be sorted. Takes in an array, starting, 
 * end, and pivot indexes. Returns an array of output containing the number of comparisons as well
 * as an index for future sorting iterations. 
*/
std::vector<int> partition(std::vector<Spice>& array, int startPos, int endPos, int pivotPoint) {

    // Variables
    int l = startPos - 1;
    int numComparisons = 0;
    std::vector<int> output(2);

    // Swap elements at the partition
    swap(array[pivotPoint], array[endPos]);

    // Sort through partitions
    for (int i = startPos; i <= endPos - 1; i++) {

        numComparisons++;
        if (array[i].getUnitPrice() > array[endPos].getUnitPrice()) {
            
            l++;
            swap(array[l], array[i]);

        } // if

    } // for i

    // Final swap
    swap(array[l+1], array[endPos]);

    // Output
    output[0] = l + 1;  // partition point
    output[1] = numComparisons;

    return output;

} // partition()

/**
 * Method that implements quick sort on an array of strings. Takes in an array, and the starting and end indexes.
 * Returns the number of comparisons.
*/
int quickSort(std::vector<Spice>& items, int leftPos, int rightPos) {

    //Variables
    int totalComparisons = 0;
    int pivot = 0;
    int midpoint = 0;
    int partitionPoint = 0;
    std::vector<int> response(2);

    // Base case
    if (leftPos < rightPos) {

        // Choose pivot
        midpoint = leftPos + (rightPos - leftPos) / 2;
        pivot = choosePivot(items, leftPos, midpoint, rightPos);

        // Partition the array
        response = partition(items, leftPos, rightPos, pivot);
        partitionPoint = response[0];
        totalComparisons += response[1];

        // Recursive sort
        totalComparisons += quickSort(items, leftPos, partitionPoint - 1);
        totalComparisons += quickSort(items, partitionPoint + 1, rightPos);

    } // if

    return totalComparisons;

} // quickSort()

/**
 * Helper method that runs a greedy algorithm to fill various knapsacks (bags) with spices. Takes in 
 * a vector of integers representing the respective sizes of the bags as well as a vector of Spice objects.
 */
void greedySpiceCollection(std::vector<int> bags, std::vector<Spice> spiceObjects) {

    // Variables
    int currKnapsackSize = 0;
    int currSpiceQty = 0;
    double currUnitPrice = 0.0;
    double totalKnapsackCost = 0.0;
    std::string finalOutput = "";
    std::string scoopOutput = "";
    int validSpices = 0;
    int numCurrSpices = 0;

    // Iterate through the knapsack sizes
    for (int l=0; l < bags.size(); l++) {

        // Loop variables
        currKnapsackSize = bags[l];
        totalKnapsackCost = 0.0;
        finalOutput = "";
        scoopOutput = "";
        std::map<std::string, int> spiceScoops;
        std::ostringstream roundedKnapsackCost;

        // Start building string
        finalOutput += "Knapsack of capacity " + std::to_string(currKnapsackSize) + " is worth ";

        // Make sure there is still space in the knapsack
        while (currKnapsackSize > 0) {

            // Iterate through the sorted spices
            for (int m=0; m < spiceObjects.size(); m++) {

                // Initalize our constrains/counts
                currSpiceQty = spiceObjects[m].getQuantity();
                currUnitPrice = spiceObjects[m].getUnitPrice();
                spiceScoops[spiceObjects[m].getSpiceName()] = 0;

                // Make sure there is still spice to grab
                while (currSpiceQty > 0 && currKnapsackSize > 0) {

                    // Add a scoop
                    totalKnapsackCost += currUnitPrice;
                    currSpiceQty--;
                    currKnapsackSize--;
                    spiceScoops[spiceObjects[m].getSpiceName()]++;

                } // while

            } // for m

        } // while

        // Count the number of valid elements for output purposes
        // (a valid element is an element that has more than 0 scoops)
        for (const auto& n : spiceScoops)
            if (n.second > 0) 
                validSpices++;
        
        // Iterate through our scoops to build our output
        for (auto n = spiceScoops.begin(); n != spiceScoops.end(); ++n) {

            // Ensure it is worthwhile to display
            if (n->second != 0) {

                numCurrSpices++;
                scoopOutput +=  std::to_string(n->second) + " scoops of " + n->first;

                // Add comma delimiter if it isn't the last element
                if (numCurrSpices < validSpices)  
                    scoopOutput += ", ";

            } // if

        } // for n

        // Add total number of quatloos obtained for the knapsack
        roundedKnapsackCost << std::fixed << std::setprecision(1) << totalKnapsackCost;
        finalOutput += roundedKnapsackCost.str() + " quatloos and contains ";

        // Add total number of scoops
        finalOutput += scoopOutput + ".";
        
        // Final output
        std::cout << finalOutput << std::endl;

    } // for l

} // greedySpiceCollection()

/* Main Function */

/**
 * Main function for the program. 
*/
int main() {
    
    // Variables
    std::string entry = "";
    std::string searchItem = "";
    std::string content = "";
    std::string newVertexID = " ";
    std::string newEdge1 = " ";
    std::string newEdge2 = " ";
    std::string tempWord = " ";  // variable to save arbitrary words while processing
    std::string spiceName = " ";
    int currGraphIndex = -1;
    int weight = 0;
    int currSpiceIndex = -1;
    int spiceQuantity = 0;
    int knapsackSize = 0;
    double spicePrice = 0.0;
    std::vector<Graph> graphs;
    std::vector<std::string> spiceAttributes;
    std::vector<Spice> spices;
    std::vector<int> knapsacks;

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

    // Close graphs2.txt
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
        if (entry.find("spice name =") != std::string::npos) {

            // Instansiate our Spice object and save it 
            Spice newSpice;
            spices.push_back(newSpice);
            currSpiceIndex++;

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

                    // Add the name to our current object
                    spices[currSpiceIndex].setSpiceName(spiceName);

                } // if 

                // Get the total price
                else if (spiceAttributes[j].find("total_price =") != std::string::npos) {
                    
                    // Parse out the total price
                    std::istringstream stream(spiceAttributes[j]);
                    stream >> tempWord;  // "total_price"
                    stream >> tempWord;  // "="
                    stream >> spicePrice;  // {total_price}
                    
                    // Add the name to our current object
                    spices[currSpiceIndex].setTotalPrice(spicePrice);

                } // else if

                // Get the quantity
                else if (spiceAttributes[j].find("qty =") != std::string::npos) {
                    
                    // Parse out the quantity
                    std::istringstream stream(spiceAttributes[j]);
                    stream >> tempWord;  // "qty"
                    stream >> tempWord;  // "="
                    stream >> spiceQuantity;  // {total_price}
                    
                    // Add the name to our current object
                    spices[currSpiceIndex].setQuantity(spiceQuantity);

                } // else if

            } // for j

        } // if

        // Get the available knapsacks
        else if (entry.find("knapsack capacity") != std::string::npos) {

            // Parse out the knapsack sizes
            std::istringstream stream(entry);
            stream >> tempWord;  // "knapsack"
            stream >> tempWord;  // "capacity"
            stream >> tempWord;  // "="
            stream >> knapsackSize;  // {knapsack_size}

            // Add to our knapsacks
            knapsacks.push_back(knapsackSize);

        } // else if

    } // while

    // Compute the unit price for each spice and save it to a vector
    for (int k=0; k < spices.size(); k++) {

        spices[k].computeUnitPrice();

    } // for k 

    // Sort the unit prices
    quickSort(spices, 0, spices.size() - 1);

    // Perform the greedy algorithm for filling our knapsacks
    greedySpiceCollection(knapsacks, spices);

    // Close spice.txt
    spiceFile.close();

}; // main()