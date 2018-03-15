#include <iostream>
#include <cstring>
#include "deque.h"
using namespace std;

Deque::Deque() {
	left_p = NULL;
	rear_p = NULL;
	cursor = NULL;
	current_size = 0;
}


// need to implement this better.
Deque::Deque(const Deque& dq) {
	Node *tmp = dq.left_p;
	left_p=NULL;
	rear_p=NULL;
	cursor=NULL;
	current_size=0;
	/*
	if (current_size > 0) { 
		delete_all();
	} else {
		left_p=NULL;
		rear_p=NULL;
		cursor=NULL;
	}
	*/
	while (tmp->prev != NULL) {
		push_right(tmp->data);
		tmp = tmp->prev;
	}
	push_right(tmp->data);
	delete tmp;
}

Deque::~Deque() {
	cout << "good bye!" << endl;
}

/*
void Deque::delete_all() {
	Node *tmp = left_p;
	while (tmp->prev != NULL) {
		tmp = left_p->prev;
		delete left_p;
		left_p = tmp;
	}
	delete tmp;
	delete left_p;
	delete rear_p;
	delete cursor;
	
	left_p=NULL;
	rear_p=NULL;
	cursor=NULL;
	current_size=0;

}
*/

void Deque::push_left(int item) {
	if (empty()) {
		Node *node = new Node(item, NULL, NULL);
		left_p = node;
		rear_p = node;
		cursor = left_p;
	} else {
		Node *new_left = new Node(item, NULL, left_p);
		left_p->prev = new_left;
		left_p = new_left;
	}
	current_size++;
}

void Deque::push_right(int item) {
	if (empty()) {
		Node *node = new Node(item, NULL, NULL);
		left_p = node;
		rear_p = node;
		cursor = rear_p;
	} else {
		Node *new_rear = new Node(item, rear_p, NULL);
		rear_p->next = new_rear;
		rear_p = new_rear;
	}
	current_size++;
}

int Deque::pop_left() {
	Node *tmp = left_p;
	int val = left_p->data;
	// there is only one element in deque
	if ((left_p->prev == NULL) & (left_p->next == NULL)) {
		left_p = NULL;
		rear_p = NULL;
		cursor = NULL;
		delete tmp;
		current_size--;
		return val;
	} else {
		left_p->next->prev = NULL;
		left_p = left_p->next;
		if (cursor == tmp)
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
	if ((left_p->next == NULL) & (left_p->prev == NULL)) {
		left_p = NULL;
		rear_p = NULL;
		cursor = NULL;
		delete tmp;
		current_size--;
		return val;
	} else {
		rear_p->prev->next = NULL;
		rear_p = rear_p->prev;
		if (cursor == tmp)
			cursor = rear_p;
	}
	delete tmp;
	current_size--;
	return val;
}

int Deque::size() {
	return current_size;
}

bool Deque::empty() {
	if (current_size == 0)
		return true;
	return false;
}

bool Deque::cursor_left() {
	if (empty()) {
		return false;
	}
	else if(cursor->prev == NULL) {
		return false;
	}
	cursor = cursor->prev;
	return true;
}

bool Deque::cursor_right() {
	if (empty()) {
		return false;
	}
	else if(cursor->next == NULL) {
		return false;
	}
	cursor = cursor->next;
	return true;
}

int Deque::peek_left() {
	return left_p->data;
}

int Deque::peek_right() {
	return rear_p->data;
}

int Deque::get_cursor() {
	return cursor->data;
}

void Deque::set_cursor(int i) {
	cursor->data = i;
}

void Deque::display() {

	Node * tmp = left_p;

	if (tmp == NULL) {
		cout << "[] size=0, cursor=NULL." << endl;
		delete tmp;
		return;
	}

	else {
		string output = "[";
		while ((tmp != NULL)) {
			output += to_string(tmp->data);
			output += ";";
			tmp = tmp->next;
		}
		output += "]";
		output += " size=";
		output += to_string(current_size);
		output += ",";
		output += " cursor=";
		output += to_string(cursor->data);
		output += ".";
		cout << output << endl;
		delete tmp;
		return;
	}


	return;

	
	

	/*		
	string output = "[";
	if (tmp == NULL) {
		output += ";]";
		output += " size=0";
		output += " cursor=NULL.";
		cout << output << endl;
		return;
	}
	
	while ((tmp != NULL) || (tmp->prev != NULL)) {
		output += tmp -> data;
		output += "; ";
		tmp = tmp->prev;
	}
	output += tmp -> data;
	output += ";]" ;
	output += " size=" ;
	output += current_size;
	output += " cursor=";
	output += cursor->data; 
	output += ".";
	cout << output << endl;
	*/
}

void Deque::verbose_display() {
	if (empty()) {
		cout << "Empty!" << endl;
	} else {
		
	}
}
















