#include "List.h"


List::List() {
	this->head = nullptr;
}

List::~List() {
	this->head = nullptr;
}

void List::push(Node* node) {
	if (this->head == nullptr) {
		this->head = node;
	}
	else {
		Node* current = this->search(node);
		if (current != nullptr) {
			current->setHours(current->getHours() + node->getHours());
			return;
		}
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

int List::size() {
	if (this->head == nullptr) {
		return 0;
	}
	if (this->head->getNext() == nullptr) {
		return 1;
	}
	Node* aux = this->head;
	int i = 0;
	while (aux != nullptr) {
		i++;
		aux = aux->getNext();
	}
	return i;
}

void List::insert(Node* node, int position) {
	int i = 1;
	if (position == 1) {
		node->setNext(this->head);
		this->head = node;
		return;
	}
	if (position > this->size()) {
		return;
	}
	if (this->head != nullptr) {
		Node* aux = this->head;
		Node* previous = nullptr;
		while (aux != nullptr) {
			if (i == position) {
				if (previous != nullptr) {
					previous->setNext(node);
				}
				node->setNext(aux);
				return;
			}
			i++;
			previous = aux;
			aux = aux->getNext();
		}
	}
}

Node* List::search(Node* node) {
	if (this->head == nullptr) {
		return nullptr;
	}
	else {
		Node* aux = this->head;
		while (aux != nullptr) {
			if (aux->getId() == node->getId()) {
				return aux;
			}
			aux = aux->getNext();
		}
	}
	return nullptr;
}

void List::print() {
	if (this->head == nullptr) {
		std::cout << "Lista vacía";
	}
	else {
		Node* aux = this->head;
		while (aux != nullptr) {
			std::cout << "Id: " << aux->getId() << " Horas: " << aux->getHours() << '\n';
			aux = aux->getNext();
		}
	}
}

Node* List::getHead() {
	if (this->head != nullptr) {
		return this->head;
	}
	return nullptr;
}

