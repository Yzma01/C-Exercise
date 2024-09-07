#pragma once
#include "Node.h";
#include "List.h";
#include "ListNumbers.h";
class InterleaveLists {
private:
	Node* head;
public:
	InterleaveLists();
	~InterleaveLists();
	InterleaveLists* insert(List*, ListNumber*);
	void push(Node*);
	void print();
	void pop(Node*);
	int size();
	bool isSort();
	void deleteNodeWithTheSmallestValue();
};