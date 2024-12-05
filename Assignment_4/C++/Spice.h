/**
 * Spice Header File
 * Author: Christian Sarmiento
 * Purpose: Header file for the Spice class. Allows it to be used in other files. 
 * Date Created: 12/5/24
 * Last Updated: 12/5/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 4             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

#ifndef SPICE_H
#define SPICE_H

// Dependencies 
#include <string>

class Spice {

    public:

        // Instance Variables
        std::string mySpiceName = " ";
        double myTotalPrice = 0.0;
        int myQuantity = 0;
        double myUnitPrice = 0.0;


        // Constructors
        Spice();
        Spice(std::string newName);

        // Getters
        std::string getSpiceName() const;
        double getTotalPrice() const;
        int getQuantity() const;
        double getUnitPrice() const;

        // Setters
        void setSpiceName(std::string newName);
        void setTotalPrice(double newTotal);
        void setQuantity(int newQuantity);

        // Class Methods
        void computeUnitPrice();
    
}; // Class Graph

#endif // SPICE_H