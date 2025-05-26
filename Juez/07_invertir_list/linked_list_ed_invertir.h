#ifndef linked_list_ed_invertir_h
#define linked_list_ed_invertir_h
#include <iostream>

#include "linked_list_ed.h"

using namespace std;

template <typename T>
class linked_list_ed_invertir : public linked_list_ed <T> {
	using Nodo = typename linked_list_ed<T>::Nodo;
public: 

	void mostrar(ostream& out = std::cout) {
		Nodo* aux = this->prim;
		while (aux != nullptr) {
			out << aux->elem << ' ';
			aux = aux->sig;
		}
		out << '\n';
	}
	
	void invertir() {
		Nodo* inversa = nullptr;
		if (this->prim != nullptr) {
			inversa = this->prim;
			this->ult = inversa;
			this->prim = this->prim->sig;
			inversa->sig = nullptr;
			while (this->prim != nullptr) {
				Nodo* a_mover = this->prim;
				this->prim = this->prim->sig;
				a_mover->sig = inversa;
				inversa = a_mover;
			}
			this->prim = inversa;
		}
	}


};



#endif