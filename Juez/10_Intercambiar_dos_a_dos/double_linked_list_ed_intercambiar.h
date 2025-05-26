#ifndef double_linked_list_ed_intercambiar_h
#define double_linked_list_ed_intercambiar_h
#include "double_linked_list_ed.h"
#include <iostream>
using namespace std;
template <typename T>
class double_linked_list_ed_intercambiar : public double_linked_list_ed <T> {
	using Nodo = typename double_linked_list_ed <T>::Nodo;

public:
	void print(ostream& o = std::cout) const {
		Nodo* aux = this->fantasma->sig;
		if (aux != this->fantasma) {
			o << aux->elem;
			aux = aux->sig;
			while (aux != this->fantasma) {
				o << ' ' << aux->elem; 
				aux = aux->sig;
			}
		}
		o << '\n';
	}

	void intercambiar() {
		Nodo* primero = this->fantasma->sig;
		Nodo* segundo = primero->sig;
		Nodo* anterior; 
		Nodo* siguiente;
		while (primero != this->fantasma && segundo != this->fantasma) {
			anterior = primero->ant;
			siguiente = segundo->sig;

			//Cambio los punteros de los elementos anteriores y siguientes a la pareja
			anterior->sig = segundo;
			siguiente->ant = primero;


			primero->ant = segundo; 
			primero->sig = siguiente;

			segundo->sig = primero;
			segundo->ant = anterior;


			primero = siguiente;
			segundo = primero->sig;
		}
	}
};


#endif 