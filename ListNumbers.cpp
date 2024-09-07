#include "ListNumbers.h"

ListNumber::ListNumber() {
	this->head = nullptr;
}

ListNumber::~ListNumber() {
	if (this->head != nullptr) {
		Node* aux = this->head->getNext();
		while (aux != nullptr) {
			this->pop(aux);
		}
		this->pop(aux);
	}
}

void ListNumber::deleteDuplicates() {
	if (this->head == nullptr) {
		return;
	}
	Node* aux = this->head;
	int id = 0;
	while (aux != nullptr) {
		id = aux->getId();
		bool first = true;
		if (countNodes(id) > 1) {
			Node* auxNode = this->head;
			Node* next = nullptr;
			while (auxNode != nullptr) {
				if (auxNode->getId() == id && first) {
					first = false;
				}
				else if (auxNode->getId() == id && !first) {
					next = auxNode->getNext();
					this->pop(auxNode);
					auxNode = next;
					continue;
				}
				auxNode = auxNode->getNext();
			}
		}
		aux = aux->getNext();
	}
}



void ListNumber::pop(Node* node) {
	if (this->head == nullptr) {
		return;
	}
	else {
		Node* aux = this->head;
		Node* previous = nullptr;
		if (node == aux) {
			node->setNext(aux->getNext());
			this->head = node;
			delete aux;
			return;
		}
		while (aux != nullptr) {
			if (aux == node) {
				previous->setNext(node->getNext());
				delete node;
				return;
			}
			previous = aux;
			aux = aux->getNext();
		}
	}
}

void ListNumber::push(Node* node) {
	if (this->head == nullptr) {
		this->head = node;
	}
	else {
		Node* aux = this->head;
		while (aux != nullptr) {
			if (aux->getNext() == nullptr) {
				aux->setNext(node);
				return;
			}
			aux = aux->getNext();
		}
	}
	return;
}


void ListNumber::print() {
	if (this->head == nullptr) {
		std::cout << "Lista vacía" << '\n';
	}
	else {
		Node* aux = this->head;
		while (aux != nullptr) {
			std::cout << "Id: " << aux->getId() << " Horas: " << aux->getHours() << '\n';
			aux = aux->getNext();
		}
	}
}

int ListNumber::countNodes(int id) {
	int i = 0;
	if (this->head != nullptr) {
		Node* aux = this->head;
		while (aux != nullptr) {
			if (aux->getId() == id) {
				i++;
			}
			aux = aux->getNext();
		}
	}
	return i;
}

Node* ListNumber::getHead() {
	if (this->head != nullptr) {
		return this->head;
	}
	return nullptr;

}
