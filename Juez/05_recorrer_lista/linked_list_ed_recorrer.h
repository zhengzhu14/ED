#ifndef linked_list_ed_recorrer_h
#define linked_list_ed_recorrer_h
#include <iostream>
#include <stdexcept>
#include "linked_list_ed.h"
using namespace std;

template <typename T> 
class linked_list_ed_recorrer : public linked_list_ed <T> {
	using Nodo = typename linked_list_ed<T>::Nodo;
public: 
	template <typename Predicate>
	void mostrarPropiedad(Predicate pred, std::ostream& o = std::cout) {
		Nodo* aux = this->prim;
		while (aux != nullptr && !pred(aux->elem)) {
			aux = aux->sig;
		}
		if (aux != nullptr) {
			o << aux->elem;
			aux = aux->sig;
			while (aux != nullptr) {
				if (pred(aux->elem)) {
					o << ' ' << aux->elem;
				}
				aux = aux->sig;
			}
		}
		o << '\n';
	}

	void mostrar() {
		Nodo* aux = this->prim;
		while (aux != nullptr) {
			cout << aux->elem << " "; 
			aux = aux->sig;
		}
		cout << endl;
	}
};




#endif