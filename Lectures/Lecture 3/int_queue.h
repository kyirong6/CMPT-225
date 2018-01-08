class int_queue {
  public:
	   int_queue();
	   void enqueue(int item);
	   int dequeue();
     int size();
     bool empty();
  private:
	   int capacity;
	   int *Array;
	   int front;
	   int rear;
	   int qSize;
};
