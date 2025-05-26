#ifndef double_linked_list_ed_elim_h
#define double_linked_list_ed_elim_h

#include <iostream>
#include "double_linked_list_ed.h"

using namespace std;

template <typename T>
class double_linked_list_ed_elim : public double_linked_list_ed<T> {
	using Nodo = typename double_linked_list_ed<T>::Nodo;
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

	void eliminar_decrecientes() { //precondicion: la lista no esta vacia
		Nodo* aux = this->fantasma->sig;
		Nodo* mayor = this->fantasma->sig; 

		Nodo* a_borrar = nullptr;
		while (aux != this->fantasma) {
			if (aux->elem < mayor->elem) {
				a_borrar = aux; 
				aux->ant->sig = aux->sig; 
				aux->sig->ant = aux->ant;
				aux = aux->sig;
				delete a_borrar;
			}
			else {
				mayor = aux;
				aux = aux->sig;
			}
		}
	}

};



#endif