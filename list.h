/*
Student Name: Connor Sparkman
Student NetID: cps260
Compiler Used: Visual Studio
*/
#pragma once
#include <iostream>
#include <sstream>
#include <string>

using std::istream;
using std::stringstream;
using std::string;
using std::cout;
using std::endl;

class Tokenizer
{
private:
    stringstream ss;

public:
    Tokenizer() { ss.exceptions(std::ios::failbit); }
    Tokenizer(const string& source) { ss.str(source); ss.exceptions(std::ios::failbit); }


    void setString(const string& str);
    bool isEmpty() const;
    bool readLine(string& line);
    bool readString(string& val);
    bool readChar(char& val);



    void rewind();
    void clear();
};

class Node
{
public:
    string stringData;
    Node* next;
    Node* prev;

    Node() :
        stringData(""), next(nullptr), prev(nullptr) {}

    Node(string stringData) :
        stringData(stringData), next(nullptr), prev(nullptr) {}

    Node(string stringData, Node* next, Node* prev) :
        stringData(stringData), next(next), prev(prev) {}
};

class LinkedList
{
private:
    Node* head;
    Node* tail;

public:
    LinkedList() :
        head(nullptr), tail(nullptr) {}

    ~LinkedList();
    void append(string stringData);
    bool remove(string stringData);
    void display();
    void displayReverse();
};
