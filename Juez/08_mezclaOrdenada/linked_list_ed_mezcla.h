// Nombre del alumno: Zhengkai Zhu
// Usuario del Juez: A73

#ifndef linked_list_ed_mezcla_h
#define linked_list_ed_mezcla_h
#include <iostream>
#include "linked_list_ed.h"
using namespace std;

template <typename T>
class linked_list_ed_mezcla : public linked_list_ed <T> {
	using Nodo = typename linked_list_ed<T>::Nodo;

public: 
	void merge(linked_list_ed_mezcla<T>& list) {
		if (this->prim == nullptr) { // la primera lista es vacia
			this->prim = list.prim;
			this->ult = list.ult;
		}
		else { //la primera lista no es vacia
			Nodo* aux1 = this->prim;
			Nodo* aux2 = list.prim;
			
			if (aux2 != nullptr) {
				Nodo* anterior = nullptr;
				Nodo* temp;
				if (aux2->elem <= aux1->elem) {
					temp = aux2->sig; 
					aux2->sig = aux1;
					this->prim = aux2; //cambio el primer elemento de la lista 1
					anterior = aux2; 
					aux2 = temp;
				}
				while (aux1 != nullptr && aux2 != nullptr) {
					if (aux2->elem <= aux1->elem) {
						temp = aux2->sig;
						aux2->sig = aux1;
						anterior->sig = aux2;
						anterior = aux2;
						aux2 = temp;
					}
					else { //Si aux2->elem > aux1->elem iteramos hasta encontrar uno menor o igual
						anterior = aux1; 
						aux1 = aux1->sig;
					}
				}
				if (aux2 != nullptr) { //hemos llegado al final de la primera lista
					this->ult->sig = aux2;
					this->ult = list.ult;

				}
			}
		}
		//vaciamos la lista 2
		list.prim = nullptr;
		list.ult = nullptr;
	}

	void mostrar(ostream & out = std::cout) {
		Nodo* aux = this->prim;
		if (aux != nullptr) {
			out << aux->elem;
			aux = aux->sig;
			while (aux != nullptr) {
				out << ' ' << aux->elem;
				aux = aux->sig;
			}
		}
		
		out << '\n';
	}
};

#endif