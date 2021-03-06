/*
Student Name: Connor Sparkman
Student NetID: cps260
Compiler Used: Visual Studio
Program Description:
This program asks a user for strings, enters those strings into a linked list, and displays the reversed linked list back to the user
*/

// Add our class header files
#include "list.h"
#include <fstream>

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;

// Interactive Shell Function
bool processText(istream& is, LinkedList& ll, bool interactive)
{
	string line;
	string command;

	// Initialize our classes as objects
	Tokenizer tkn;

	while (true)
	{
		// Begin interactive tokenizer shell
		if (!interactive)
		{
			if (is.eof()) return true;
		}
		else { cout << ">> "; }

		// Read in a line from the user
		getline(is, line);

		// Set tokenizer line from user input
		tkn.setString(line);

		// Read the command string
		// Begin long chain of if statement
		tkn.readString(command);

		// add string to front of list
		ll.append(command);
		if (command != "STOP")
		{
			cout << "Please enter another string or enter STOP if finished." << endl;
		}

		if (command == "STOP")
		{
			// remove "STOP" from list
			ll.remove(command);
			return false;
		}
	}
}

int main()
{
	LinkedList ll;
	// Passes cin, a linked list, and a bool to the function
	// This is needed to create an interacive shell
	cout << "This program will read strings until STOP is entered." << endl;
	processText(cin, ll, true);
	ll.displayReverse();
	ll.~LinkedList();
	return 0;
}
