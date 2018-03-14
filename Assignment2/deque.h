/* File: Deque.h
 *
 * Header file for simple doubly-linked list implemention 
 * of a Deque with a cursor, for Assignment 2.
 *
 * */
 
class Deque {

  public:

    /* Constructors and Destructor */
    Deque(); // Constructs a new empty deque.
    Deque( const Deque& dq );// Copy constructor.
    ~Deque();// Destructor.
    
    /* Insertion operators */
    void push_left( int item ); // Inserts <item> at left end.
    void push_right( int item ); // Inserts <item> at right end.

    /* Removal operators */
    int pop_left();  // removes item on left end.
        // Pre: Deque is not empty.
    int pop_right();  // removes item on right end.
        // Pre: Deque is not empty.
    void delete_all();

    /* Size functions */
    bool empty();  // Returns true iff the Deque contains no items.
    int size();  // Returns the current number of items in the deque.

    /* Cursor movement operators
    *  These move the cursor one node to the left or right and then 
    *  return true if such a move is possible.  If the move is not 
    *  possible (i.e., the cursor is already at the extreme end
    *  or the Deque is emty), no change occurs and false is returned. 
    */
    bool cursor_left(); // Move cursor left.
    bool cursor_right(); // Move cursor right.

    /* Accessor functions */
    int peek_left();  // Returns the left-most item without removing it.
        // Pre: Deque is not empty.
    int peek_right();  // Returns the right-most item without removing it.
        // Pre: Deque is not empty.
    int get_cursor(); // Return value the cursor currently is at, 
        // Pre: Deque is not empty.
    void set_cursor(int i);    
            // Pre: Deque is not empty.

    /* Utility functions */
    void display(); // prints a depiction of the deque contents to standard output.    
    void verbose_display(); // like display, but includes node addresses and pointer values.


  private:
    // Deque Node Class 
    class Node  // node type for the linked list 
    {
       public:
           Node(int new_data, Node * prev_node, Node * next_node ){
              data = new_data ;
	     	  prev = prev_node ;
              next = next_node ;
           }
           int data ;
	  	   Node * prev ;// pointer to pevious node, or NULL.
           Node * next ;// pointer to next node, or NULL.
    };

    /* Instance Variables */
    Node * left_p ; // Points to left end node, or NULL if Deque is empty.
    Node * rear_p ; // Points to right end node, or NULL if Deque is empty.
    int current_size ; // current number of elements in the queue.
    Node * cursor ; // pointer to "current" node (or NULL if deque is empty).
};