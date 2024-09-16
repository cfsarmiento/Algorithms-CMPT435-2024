class NodeLinkedList {

    // Instance variables
    myData: string | null | undefined;
    myNext: NodeLinkedList | null | undefined;

    /* Constructor */
    /**
     * Constructor for linked list node class
     * 
     * @param data data for the node
     * @param next next node linked to current node (if any)
     */
    constructor(data: string | null = null, next: NodeLinkedList | null = null) {

        this.myData = data;
        this.myNext = next;

    } // constructor

    /* Getters */
    /**
     * Class method to get data from current node
     */
    get getData() {

        return this.myData;

    } // getData()

    /**
     * Class method to get next node
     */
    get getNext() {

        return this.myNext;

    } // getNext()

    /* Setters */
    /**
     * Class method to update data in current node
     */
    set setData(newData: string) {

        this.myData = newData;

    } // setData()

    /**
     * Class method to update next node
     */
    set setNext(newNext: NodeLinkedList | null | undefined) {

        this.myNext = newNext;

    } // setNext()

} // Class Node 