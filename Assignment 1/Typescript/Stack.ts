class Stack {

    // Instance Variables
    private myTop: NodeLinkedList | null | undefined;
    
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
    
        return this.myTop == null;
    
    } // isEmpty()
    
    /**
     * Method that removes and returns the top most value from the stack
     * @returns top node object from stack
     */
    pop() {
    
        // Variables
        let poppedItem: string | null | undefined = null;
        
        // Pop from the stack
        if (!this.isEmpty() ) {
    
            poppedItem = this.myTop?.getData; 
            this.myTop = this.myTop?.getNext;
            
        } // if
    
        return poppedItem;
    
    } // pop()
    
    /**
     * Method that adds a new object to the top of the stack 
     * @param data data value to be pushed on to the stack 
     */
    push(data: string) {
    
        // Variables
        let newNode: NodeLinkedList;
    
        // Instantiate new node object & save new data
        newNode = new NodeLinkedList();
        newNode.setData = data;
    
        // Update stack
        newNode.setNext = this.myTop;
        this.myTop = newNode;
    
    } // push()
    
    
    } // Class Stack