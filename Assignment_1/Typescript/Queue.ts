/**
 * Stack Class
 * Author: Christian Sarmiento
 * Purpose: Class definition for a stack list data structure, used to store string values of palindromes.
 * Date Created: 9/7/24
 * Last Updated: 9/15/24
 * -----------------------------------------------------------------------------------------------------------------------
 * Assignment 1             |               CMPT 435 - ALGORITHMS FALL 2024             |               DR. ALAN LABOUSEUR
*/

class Queue {

    // Instance Variables
    private myHead: NodeLinkedList | undefined | null;
    private myTail: NodeLinkedList | undefined | null;

    /* Constructor */
    /**
     * Contructor for queue class
     * @param data 
     */
    constructor(data: NodeLinkedList | null = null) {

        this.myHead = data;
        this.myTail = data;

    } // constructor

    /* Queue Methods */
    /**
     * Method that determines if anything exists in the queue
     * @returns boolean value that represents if there is anything at the head of the queue or not
     */
    isEmpty() {
    
        return this.myHead == null;
    
    } // isEmpty()

    /**
     * Method that adds an element to the back of the queue
     * @param data string value to be added to the back of the queue
     */
    enqueue(data: string) {

        // Variables
        let newNode: NodeLinkedList | null = null;

        // Instantiate new node object
        newNode = new NodeLinkedList();
        newNode.setData = data;

        // Enqueue to the queue
        newNode.setNext = this.myTail;
        this.myTail = newNode;

    } // enqueue

    /**
     * Method that removes and returns the element at the top of the queue
     * @returns returns the string value that is at the beginning/top of the queue
     */
    dequeue() {

        // Variables
        let returnedItem: string | null | undefined;

        // Remoove item at the start of the queue
        if (!this.isEmpty()) {

            returnedItem = this.myHead?.getData;
            this.myHead = this.myHead?.getNext;

        } // if 

        return returnedItem;

    } // dequeue

} // Class Queue