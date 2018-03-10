#include <iostream>
#include "deque.h"
using namespace std;

Deque::Deque() {
	left_p = rear_p = cursor = NULL;
	current_size = 0;
}

void Deque::push_left(int item) {
	if (empty())
		left_p = rear_p = Node *node(item, NULL, NULL);
	else {
		Node * new_left(item, left_p, NULL);
		left_p->next_node = new_left;
		left_p = new_left;
	}
	current_size++;
}

void Deque::push_right(int item) {
	if (empty())
		left_p = rear_p = Node *node(item, NULL, NULL);
	else {
		Node new_rear(item, NULL, rear_p);
		left_p->prev_node = new_rear;
		rear_p = new_rear;
	}
	current_size++;
}

int Deque::pop_left() {
	Node *tmp = left_p
	int val = left_p->data;
	// there is only one element in deque
	if ((left_p->next_node == NULL) & (left_p->prev_node == NULL))
		left_p = rear_p = NULL;
		delete tmp;
		return val;
	else {
	left_p->prev_node->next_node = NULL;
	left_p = left_p->prev_node;
	}
	delete tmp;
	current_size--;	
	return val;
}

int Deque::pop_right() {
	Node *tmp = rear_p;
	int val = rear_p->data;
	//there is only one element in deque
	if ((left_p->next_node == NULL) & (left_p->prev_node == NULL))
		left_p = rear_p = NULL;
		delete tmp;
		return val;
	else {
		rear_p->next_node->prev_node = NULL;
		rear_p = rear_p->next_node;
	}
	delete tmp;
	current_size--;
	return val;
}



