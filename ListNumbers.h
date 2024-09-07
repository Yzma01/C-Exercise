#pragma once
#include <iostream>
#include "Node.h"
class ListNumber {
private:
	int n;
	Node* head;
public:
	ListNumber();
	~ListNumber();
	void deleteDuplicates();
	void pop(Node* node);
	void push(Node*);
	void print();
	int countNodes(int);
	Node* getHead();
};