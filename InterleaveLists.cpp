#include "InterleaveLists.h"

InterleaveLists::InterleaveLists() {
	this->head = nullptr;
}

InterleaveLists::~InterleaveLists(){
	this->head = nullptr;
}

InterleaveLists* InterleaveLists::insert(List* list1, ListNumber* list2) {
	InterleaveLists* list = new InterleaveLists();
	Node* aux = list1->getHead();
	if (aux == nullptr) {
		aux = list2->getHead();
		if (aux == nullptr) {
			return nullptr;
		}
		while (aux != nullptr) {
			list->push(new Node(aux));
			aux = aux->getNext();
		}
		return list;
	}
	bool first = true;
	Node* secondHead = list2->getHead();
	while (aux != nullptr) {
		if (first) {
			list->push(new Node(aux));
			first = false;
			aux = aux->getNext();
		}
		else if (!first) {
			if (secondHead != nullptr) {
				list->push(new Node(secondHead));
				secondHead = secondHead->getNext();
			}
			first = true;
		}
	}
	if (secondHead != nullptr) {
		while (secondHead != nullptr) {
			list->push(new Node(secondHead));
			secondHead = secondHead->getNext();
		}
		return list;
	}
	return list;

}

void InterleaveLists::push(Node* node) {
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

void InterleaveLists::print() {
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
void InterleaveLists::pop(Node* node) {
	if (this->head == nullptr) {
		return;
	}
	Node* aux = this->head;
	if (node == aux) {
		this->head = aux->getNext();
		delete aux;
		return;
	}
	Node* previous = nullptr;
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

int InterleaveLists::size(){
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

bool InterleaveLists::isSort(){
	if (this->head == nullptr) {
		return true;
	}
	int i = 0;
	Node* aux = this->head;
	while (aux != nullptr) {
		if (aux->getId() >= i) {
			i = aux->getId();
		}
		else {
			return false;
		}
		aux = aux->getNext();
	}
	return true;
}

void InterleaveLists::deleteNodeWithTheSmallestValue() {
	if (this->head != nullptr) {
		int id = 100;
		Node* aux = this->head;
		Node* nodeToDelete = nullptr;
		while (aux != nullptr) {
			if (aux->getId() < id) {
				id = aux->getId();
				nodeToDelete = aux;
			}
			aux = aux->getNext();
		}
		this->pop(nodeToDelete);
		return;
	}
}
