#ifndef  double_linked_list_ed_interseccion_h
#define double_linked_list_ed_interseccion_h
#include "double_linked_list_ed.h"
#include <iostream>

using namespace std;

template <typename T>
class double_linked_list_ed_interseccion : public double_linked_list_ed <T> {
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

	void interseccion(double_linked_list_ed_interseccion const & l2) { //Precondicion: ambas listas no estan vacias
		Nodo* n1 = this->fantasma->sig;
		Nodo* n2 = l2.fantasma->sig;
		while (n1 != this->fantasma && n2 != l2.fantasma) {
			if (n1->elem > n2->elem) {
				n2 = n2->sig;
			}
			else if (n1->elem < n2->elem) {
				n1->ant->sig = n1->sig;
				n1->sig->ant = n1->ant;
				Nodo* aux = n1;
				n1 = n1->sig;
				delete aux; //Libero dicho nodo
			}
			else {
				n1 = n1->sig;
				n2 = n2->sig;
			}
		}
		while (n1 != this->fantasma) {
			n1->ant->sig = n1->sig;
			n1->sig->ant = n1->ant;
			Nodo* aux = n1;
			n1 = n1->sig;
			delete aux; //Libero dicho nodo
		}

	}
};
#endif