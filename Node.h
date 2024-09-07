#pragma once
/*
Dada una lista de empleados donde cada nodo contiene los campos int idEmpleado,
int horasTrabajadas y un puntero Empleado *Sig, escribe una función que retorne 
una lista con un único nodo por empleado, donde el campo horasTrabajadas contenga 
la suma de todas las horas trabajadas por dicho empleado.
*/
class Node {
private:
	int id;
	double hours;
	Node* next;
public:
	Node(int, double);
	Node(int);
	Node(Node*);
	~Node();
	void setId(int);
	void setHours(double);
	void setNext(Node*);
	int getId();
	double getHours();
	Node* getNext();
};