/*
Student Name: Connor Sparkman
Student NetID: cps260
Compiler Used: Visual Studio
*/
#include "list.h"
#include <iostream>

using namespace::std;

void Tokenizer::setString(const string& str)
{
	ss.str(str);
	ss.clear();
}
bool Tokenizer::isEmpty() const
{
	if (ss.eof()) return true;
	return false;
}
bool Tokenizer::readLine(string& line)
{
	if (isEmpty()) return false;
	if (getline(ss, line)) return true;
	return false;
}
bool Tokenizer::readString(string& val)
{
	if (isEmpty()) return false;
	try
	{
		ss >> val;
	}
	catch (std::ios_base::failure)
	{
		ss.clear();
		return false;
	}
	return true;
}
bool Tokenizer::readChar(char& val)
{
	if (isEmpty()) return false;
	try
	{
		ss >> val;
	}
	catch (std::ios_base::failure)
	{
		ss.clear();
		return false;
	}
	return true;
}
void Tokenizer::rewind()
{
	ss.seekg(0, ss.beg);
}
void Tokenizer::clear()
{
	setString("");
	ss.setstate(std::ios::eofbit);
}


LinkedList::~LinkedList()
{
	Node* tmp = head;

	while (tmp != nullptr)
	{
		head = head->next;
		delete tmp;
		tmp = head;
	}

	tail = nullptr;
}


// Add node with string to front of list
void LinkedList::append(string stringData)
{
	Node* tmp = new Node(stringData);

	tmp->prev = tail;

	if (head == nullptr)
	{
		head = tmp;
	}
	else
	{
		tail->next = tmp;
	}

	tail = tmp;
}


// used to remove extra STOP input
bool LinkedList::remove(string stringData)
{
	Node* tmp = head;

	while (tmp != nullptr)
	{
		if (tmp->stringData == stringData) // Finds a string and then removes it
		{
			if (tmp->prev != nullptr)
			{
				tmp->prev->next = tmp->next;
			}
			if (tmp->next != nullptr)
			{
				tmp->next->prev = tmp->prev;
			}
			if (tmp == head)
			{
				head = tmp->next;
			}
			if (tmp == tail)
			{
				tail = tmp->prev;
			}

			delete tmp;
			return true;
		}

		tmp = tmp->next;
	}

	return false;
}

// display list starting at tail and going reverse
void LinkedList::displayReverse()
{
	cout << "" << endl;
	cout << "Here is a reversed list of the strings you entered:" << endl;
	Node* tmp = tail;

	while (tmp != nullptr)
	{
		cout << "->[ " << tmp->stringData << " ]<-";
		tmp = tmp->prev;
	}
	cout << endl;
}