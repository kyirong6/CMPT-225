#include "int_queue.h"

/* File: int_queue.cpp

  Implementation of functions for basic "circular-array" implementation of a Queue.

*/


int_queue::int_queue() {
	capacity=100;
	A =  new int[capacity];
	front = 0;
	rear = 0;
	qSize = 0;
}

int int_queue::size() { return qSize;}

bool int_queue::empty(){return qSize==0;}

int Basic_int_queue::front(){
  		return A[front_index];
	}

int Basic_int_queue::dequeue(){
  int item = A[front_index];
  front_index = ( front_index + 1 ) % capacity ;
  current_size -= 1 ;
  return item ;
}

void Basic_int_queue::enqueue( int item ){
  A[rear_index] = item ;
  rear_index = ( rear_index + 1 ) % capacity ;
  current_size += 1 ;
}

