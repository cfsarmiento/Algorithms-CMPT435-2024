/**
 * 
*/

// Dependencies
#include <string> 

class NodeLinkedList {

    // Instance variables
    public:
        std::string myData;
        NodeLinkedList* myNext;

    /* Constructors */

    // Null Constructor
    NodeLinkedList() {

        myData = "null";
        myNext = nullptr;

    } // Null Constructor

    // Full Constructor
    NodeLinkedList() {

    } // Full Constructor

}; // Class NodeLinkedList