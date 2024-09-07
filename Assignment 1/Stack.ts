class Stack {

// Instance Variables
private myTop: NodeLinkedList | null;

/* Constructor */
/**
 * Constructor for stack
 * @param top variable for top of the stack
 */
constructor(top: NodeLinkedList | null = null) {

    this.myTop = top;

} // constructor

/* Stack Methods */

/**
 * Method that determines if anything exists in the stack
 * @returns 
 */
isEmpty() {

    return (this.myTop == null);

} // isEmpty()

pop() {

    // Variables
    let poppedItem = null;
    
    // Pop from the stack
    if (!this.isEmpty()) {

        let poppedItem = this.myTop?.getData; 
        this.myTop = this.myTop?.getNext;
        
    } // if

    return poppedItem;

} // pop()


} // Class Stack