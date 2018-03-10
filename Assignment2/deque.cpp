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
		cursor = left_p;
	else {
		Node * new_left(item, left_p, NULL);
		left_p->next_node = new_left;
		left_p = new_left;
		cursor = left_p;
	}
	current_size++;
}

void Deque::push_right(int item) {
	if (empty())
		left_p = rear_p = Node *node(item, NULL, NULL);
	else {
		Node new_rear(item, NULL, rear_p);
		rear_p->prev_node = new_rear;
		rear_p = new_rear;
	}
	current_size++;
}

int Deque::pop_left() {
	Node *tmp = left_p
	int val = left_p->data;
	// there is only one element in deque
	if ((left_p->next_node == NULL) & (left_p->prev_node == NULL))
		left_p = rear_p = cursor = NULL;
		delete tmp;
		return val;
	else {
	left_p->prev_node->next_node = NULL;
	left_p = left_p->prev_node;
	cursor = left_p;
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

bool Deque::size() {
	return current_size;
}

bool Deque::empty() {
	return current_size == 0;
}

bool Deque::cursor_left() {
	if (empty())
		return false;
	if else(cursor->next_node == NULL)
		return false;
	cursor = cursor->next_node
	return true;
}

bool Deque::cursor_right() {
	if (empty())
		return false;
	if else(cursor->prev_node == NULL)
		return false;
	cursor = cursor->prev_node;
	return true;
}

void Deque::peak_left() {
	cout << left_p->data << endl;
}

void Deque::peak_right() {
	cout << right_p->data << endl;
}




