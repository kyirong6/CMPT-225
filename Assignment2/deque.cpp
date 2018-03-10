#include <iostream>
#include "deque.h"
using namespace std;

Deque::Deque() {
	left_p = rear_p = curor = NULL;
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
}


