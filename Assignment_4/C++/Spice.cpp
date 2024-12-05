/*
 * Spice Class
 * Author: Christian Sarmiento
 * Purpose: Class definition for storing spice objects containing the spice na,e, price, quantity, and unit price.
 * Date Created: 12/5/24
 * Last Updated: 12/5/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 4             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

// Dependencies
#include "Spice.h" 

/**
 * Constructors
 */

/**
 * Null Constructor for Spice class
 */
Spice::Spice() {

    mySpiceName = " ";
    myTotalPrice = 0.0;
    myQuantity = 0;
    myUnitPrice = 0.0;

} // null constructor

/**
 * Full Constructor for Spice class
 */
Spice::Spice(std::string newName) {

    mySpiceName = newName;

} // full constructor

/**
 * Getters
 */

/**
 * Getter method that gets the name of the spice
 */
std::string Spice::getSpiceName() const {

    return mySpiceName;

} // getSpiceName

/**
 * Getter method that gets the total price of the spice
 */
double Spice::getTotalPrice() const {

    return myTotalPrice;

} // getTotalPrice()

/**
 * Getter method that gets the quantity of the spice
 */
int Spice::getQuantity() const {

    return myQuantity;

} // getQuantity()

/**
 * Getter method that gets the unit price of the spice
 */
double Spice::getUnitPrice() const {

    return myUnitPrice;

} // getUnitPrice()

/**
 * Setters
 */

/**
 * Setter method that changes the current name of the spice
 */
void Spice::setSpiceName(std::string newName) {

    mySpiceName = newName;

} // setSpiceName

/**
 * Setter method that changes the current total price of the spice
 */
void Spice::setTotalPrice(double newTotal) {

    myTotalPrice = newTotal;

} // setTotalPrice()

/**
 * Setter method that changes the current quantity of the spice
 */
void Spice::setQuantity(int newQuantity) {

    myQuantity = newQuantity;

} // setQuantity()

/**
 * Class Methods
 */
void Spice::computeUnitPrice() {

    // Variables
    double newUnitPrice = 0.0;

    // Compute our unit price
    newUnitPrice = myTotalPrice / myQuantity;

    // Save the unit price
    myUnitPrice = newUnitPrice;

} // computeUnitPrice()