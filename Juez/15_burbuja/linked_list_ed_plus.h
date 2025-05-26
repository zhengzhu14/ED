#ifndef linked_list_ed_plus_h
#define linked_list_ed_plus_h
#include <iostream>

#include "linked_list_ed.h"

using namespace std;

template <typename T>
class linked_list_ed_plus : public linked_list_ed <T> {
	using Nodo = typename linked_list_ed<T>::Nodo;
public:

	void print(ostream& out = std::cout) {
		Nodo* aux = this->prim;
		if (aux != nullptr) {
			out << aux->elem; 
			aux = aux->sig;
			while (aux != nullptr) {
				out << ' ' << aux->elem;
				aux = aux->sig;
			}
			out << '\n';
		}

		
	}

	void ordBurbuja() {
		if (this->prim != nullptr) {
			Nodo* orden = nullptr; 
			while (this->prim != orden) {
				orden = flotar(orden);
			}

		}
	}

private: 
	Nodo* flotar(Nodo* orden) { // orden puede ser nullptr
		Nodo* aux = this->prim;
		if (this->prim != orden) {
			Nodo* siguiente = aux->sig; 
			if (siguiente != orden) {
				if (this->prim->elem > siguiente->elem) {
					this->prim->sig = siguiente->sig; 
					siguiente->sig = this->prim; 
					this->prim = siguiente; 

					siguiente = siguiente->sig;
				}
				
				Nodo* anterior = this->prim; 
				aux = siguiente;
				siguiente = siguiente->sig; 

				while (siguiente != orden){
					if (aux->elem > siguiente->elem) {
						anterior->sig = siguiente; 
						aux->sig = siguiente->sig; 
						siguiente->sig = aux;
						siguiente = siguiente->sig;
					}
					anterior = anterior->sig;
					aux = siguiente;
					siguiente = siguiente->sig;
				}
			}
			
		}
		return aux;

	}
};



#endif