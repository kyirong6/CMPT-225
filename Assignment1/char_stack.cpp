/* File: char_stack.cpp

  Implementation of functions for basic simple array-based implementation of a stack.

*/
#include "char_stack.h"// contains the declarations of the variables and functions.


char_stack::char_stack() {
	top_index = -1;
}

void char_stack::push(char item) {
	top_index++;
	array[top_index] = item;
}

char char_stack::pop() {
	top_index--;
	return array[top_index + 1];
}

char char_stack::top() {
	return array[top_index -1];
}

bool char_stack::empty() {
	return top_index == -1;
}

int char_stack::size() {
	return top_index + 1;
}
