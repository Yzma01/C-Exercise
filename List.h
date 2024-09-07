#pragma once
#include <iostream>
#include "Node.h";
class List {
private:
	Node* head;
public:
	List();
	~List();
	void push(Node*);
	void insert(Node*, int);
	Node* search(Node*);
	void print();
	int size();
	Node* getHead();
};