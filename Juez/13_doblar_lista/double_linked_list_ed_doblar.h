#ifndef double_linked_list_ed_doblar_h
#define double_linked_list_ed_doblar_h

#include <iostream>
#include "double_linked_list_ed.h"

using namespace std; 

template <typename T>
class double_linked_list_ed_doblar : public double_linked_list_ed<T> {
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

	void doblar() {
		if (this->fantasma != this->fantasma->sig) { //No es vacio
			Nodo* front = this->fantasma->sig; 
			Nodo* back = this->fantasma->ant; 
			while (front != back && front->sig != back) {
				Nodo* siguiente = front->sig; 
				Nodo* anterior = back->ant; 

				anterior->sig = back->sig; 

				front->sig = back;
				back->ant = front; 
				back->sig = siguiente;

				front = siguiente; 
				back = anterior; 
			}
		}
	}
};

#endif