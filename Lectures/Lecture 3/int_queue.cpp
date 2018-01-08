#include "int_queue.h"

int_queue::int_queue() {
	capacity=100;
	A =  new int[capacity];
	front = 0;
	rear = 0;
	qSize = 0;
}

int int_queue::size() { return qSize;}

bool int_queue::empty(){return qSize==0;}
