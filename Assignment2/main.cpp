#include <iostream>
#include "deque.h"
using namespace std;

int main() {
	Deque test1;

	for (int i=0; i<10; i++) {
		test1.push_left(i);
	}

	Deque test2 = test1;

	cout << test1.pop_left() << endl;
	cout << test1.pop_left() << endl;
	cout << test1.pop_left() << endl;
	cout << test2.pop_left() << endl;
	cout << test2.pop_left() << endl;
	cout << test2.pop_left() << endl;
	
}