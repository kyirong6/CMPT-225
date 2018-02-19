#include <iostream>
#include <string>
#include "char_stack.h"
using namespace std;

// function declarations
void add_to_stack(char character, char_stack &stack_ref);
string error_string_of_spaces(string line, int i);


// main loop
int main() {
	char val;
	char temp;
	char comp;
	int number_of_lines;
	string line_temp;
	string pop_chars = "})]";
	string push_chars = "{([";
	char_stack stack;

	// read each line from file via command line
	while (getline(cin, line_temp)) {
		number_of_lines++;
		// looping through each character of a line
		for (int i=0; i<line_temp.length(); i++) {
			// specific character of a line at index i
			val = line_temp[i];
			// check if character is opening
			if (val == '{' || val == '(' || val == '[') {
				add_to_stack(val, stack);
			}
			// check if character is closing
			else if(val == '}' || val == ')' || val == ']') {
				if (stack.empty()) {
					// error on line number_of_lines, too many val. return
					i++;
					cout << "Error on line: " << number_of_lines << ": " << "Too many " << val << endl;
					// prints beginning of string up to and including error character
					cout << line_temp.substr(0,i) << endl;
					// prints as many spaces as there are characters before error character and prints rest of string from and not including error character
					cout << error_string_of_spaces(line_temp, i) << line_temp.substr(i) << endl;
					return 0;
				}	
				temp = stack.pop();
				// a comparison string that is the opening pair from the closing val
				comp = push_chars[pop_chars.find(val)];
				// if last pushed open character is not equal to comp
				if(!(temp == comp)) {
					// error on line number_of_lines, read val, expected pop_chars[push_chars.find(temp)]. return
					i++;
					cout << "Error on line: " << number_of_lines << ": " << "Read, " << val << " " << "expected " << pop_chars[push_chars.find(temp)] << endl;
					cout << line_temp.substr(0,i) << endl;
					cout << error_string_of_spaces(line_temp,i) << line_temp.substr(i) << endl;
					return 0;
				}
			}
		}
	}
	if (!stack.empty()) {
		// error, too many stack.pop()
		cout << "Error at end of file: too many: " << stack.pop() << endl;
	}
}


// ---------------------------functions----------------------------
void add_to_stack(char character, char_stack &stack_ref) {
	stack_ref.push(character);
}

void print_stack(char_stack &stack_ref) {
	while (!stack_ref.empty()) {
		cout << stack_ref.pop() << endl;
	}
}

string error_string_of_spaces(string line, int i) {
	string message = "";
	for (int q=1; q<i; q++) {
		message += " ";
	}
	return message;
}