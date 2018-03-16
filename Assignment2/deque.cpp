#include <iostream>
#include <cstring>
#include "Deque.h"
using namespace std;

Deque::Deque() {
	left_p = NULL;
	rear_p = NULL;
	cursor = NULL;
	current_size = 0;
}

// need to implement this better.
Deque::Deque(const Deque& dq) {
	left_p = NULL;
	rear_p = NULL;
	cursor = NULL;
	current_size = 0;
	Node *tmp = dq.left_p;
	while (tmp != NULL) {
		push_right(tmp->data);
		tmp = tmp->next;
	}
	delete tmp;
	Node * tmp2 = dq.cursor;
	if (tmp2 == dq.left_p){
		cursor = left_p;
		delete tmp;
		return;
	}
	if (tmp2 == dq.rear_p) {
		cursor = rear_p;
		delete tmp;
		return;
	}
	int i = 0;
	while (tmp2->prev!=NULL) {
		tmp2 = tmp2->prev;	
		i++;
	}
	cursor = left_p;
	while (i > 0) {
		tmp2 = tmp2->next;
		cursor_right();
		i--;
	}
	delete tmp2;
	return;
}

Deque::~Deque() {
	delete_all();
}


void Deque::delete_all() {
	Node *tmp = left_p;
	while (tmp != NULL) {
		tmp = left_p->next;
		delete left_p;
		left_p = tmp;
	}
	delete tmp;
	
	left_p=NULL;
	rear_p=NULL;
	cursor=NULL;
	current_size=0;
}


void Deque::push_left(int item) {
	if (empty()) {
		Node *node = new Node(item, NULL, NULL);
		left_p = node;
		rear_p = node;
		cursor = node;
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
		cursor = node;
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
	} else {
		string output = "[";
		while (tmp != NULL) {
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
}

void Deque::verbose_display() {
	Node * tmp = left_p;

	if (tmp == NULL) {
		cout << "[] size=0, cursor=NULL" << endl;
		delete tmp;
		return;
	} else {
		cout << "---- front ----" << endl;
		while (tmp != NULL) {
			cout << to_string(tmp->data) << ", node address: " << tmp << ", pointer value: " << tmp << "." << endl;
			tmp = tmp->next;
		}
		cout << "---- rear ----" << endl;
		cout << "size = " << to_string(current_size) << ", cursor = " << to_string(cursor->data) << endl;
		delete tmp;
		return;
	}
}