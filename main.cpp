#include <iostream>
#include "List.h";
#include <vector>;
#include "ListNumbers.h";
#include "InterleaveLists.h";
using namespace std;

struct Worker {
	int id;
	int hours;
};

int main() {
	std::vector<Worker> workers(30);
	List* workersList = new List();
	ListNumber* listNumber = new ListNumber();
	// Llenar el vector con datos de prueba
	for (int i = 0; i < 30; ++i) {
		workers[i].id = (i % 5) + 1; // Repetir id cada 5 empleados
		workers[i].hours = (i + 1) * 10; // Ejemplo de horas trabajadas
	}

	for (Worker worker : workers) {
		workersList->push(new Node(worker.id, worker.hours));
	}
	for (Worker worker : workers) {
		listNumber->push(new Node(worker.id));
	}
	cout << "Lista de empleados: " << '\n' << '\n';
	for (Worker worker : workers) {
		cout << "Id: " << worker.id << " Horas: " << worker.hours << '\n';
	}
	cout << "\n\n#1. Dada una lista de empleados donde cada nodo contiene los campos int idEmpleado" <<
		"int horasTrabajadas y un puntero Empleado * Sig, escribe una función que retorne una lista" <<
		"con un único nodo por empleado, donde el campo horasTrabajadas contenga la suma de todas las " <<
		"horas trabajadas por dicho empleado." << '\n' << '\n';
	workersList->print();
	listNumber->deleteDuplicates();
	cout << "\n\n#2. Dada una lista simple de números enteros, escribe una función que elimine todos los " <<
		"elementos duplicados de la lista, de forma que solo quede una única instancia de cada número. (Utiliza la lista de empleados)" << '\n' << '\n';
	listNumber->print();
	cout << "\n\n#3. Escribe una función que permita insertar un nuevo nodo en una posición específica de la lista " <<
		"(por ejemplo, en la posición n).La función debe recibir como parámetros el valor a insertar y la posición deseada." <<
		"Si la posición no es válida(por ejemplo, si es mayor al tamaño de la lista), la función debe manejar el error adecuadamente." << '\n' << '\n';
	workersList->insert(new Node(0, 1000), 0);
	workersList->print();
	cout << "\n\n#4. Dadas dos listas simples de números enteros, implementa una función que las intercale en una sola lista," <<
		"de manera que se alternen los nodos de la primera y la segunda lista.Si una lista es más corta, la nueva lista debe " <<
		"continuar con los nodos restantes de la lista más larga. (Entrelaza las 2 listas anteriores)" << '\n' << '\n';
	InterleaveLists* interleaveList = nullptr;
	interleaveList = interleaveList->insert(workersList, listNumber);
	interleaveList->print();
	cout << "\n\n#5. Escribe una función que elimine el nodo con el valor más pequeño en una lista de números enteros. " <<
		"Si hay varios nodos con el mismo valor mínimo, solo se debe eliminar el primero que aparece en la lista. (Utiliza la lista anterior)" << '\n' << '\n';
	interleaveList->deleteNodeWithTheSmallestValue();
	interleaveList->print();
	cout << "\n\n#6. Implementa una función que recorra una lista simple y devuelva el número total de nodos que contiene. (Utiliza la lista anterior)" << '\n' << '\n';
	cout << "El tamaño de la lista es de: " << interleaveList->size();
	cout << "\n\n#7. Escribe una función que determine si una lista simple de números enteros está ordenada de manera ascendente." <<
		"La función debe retornar un valor booleano indicando si la lista está o no ordenada. (Utiliza la lista anterior)" << '\n' << '\n';
	cout << "La lista está "<< (interleaveList->isSort() ? "ordenada" : "desordenada")<<'\n'<<'\n';
	return 0;
}