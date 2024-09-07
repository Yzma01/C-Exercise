#include "Node.h"

Node::Node(int id, double hours){
	this->hours = hours;
	this->id = id;
	this->next = nullptr;
}

Node::Node(int id){
	this->id = id;
	this->hours = 0;
	this->next = nullptr;
}

Node::Node(Node* node){
	this->id = node->getId();
	this->hours = node->getHours();
	this->next = nullptr;
}

Node::~Node(){
	this->hours = 0;
	this->id = 0;
	this->next = nullptr;
}

void Node::setId(int id){
	this->id = id;
}

void Node::setHours(double hours){
	this->hours = hours;
}

void Node::setNext(Node* next){
	this->next = next;
}

int Node::getId()
{
	return this->id;
}

double Node::getHours()
{
	return this->hours;
}

Node* Node::getNext()
{
	return this->next;
}
