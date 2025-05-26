#ifndef linked_list_ed_duplicated_h
#define linked_list_ed_duplicated_h
#include <iostream>
#include "linked_list_ed.h"

using namespace std;

template <typename T>
class linked_list_ed_duplicated :public linked_list_ed <T>{
	using Nodo = typename linked_list_ed<T>::Nodo;
public: 

	void duplicate() {
		if (this->prim != nullptr) { //si no es un vector vacio
			Nodo* aux = this->prim; //Apunta al primer elemento de la lista
			Nodo* duplicado = new Nodo(aux->elem, aux->sig);
			//creo un nodo con los mismos elementos que el primer nodo.

			aux->sig = duplicado; //Hago que el elemento apunte al duplicado
			
			while (duplicado->sig != nullptr) {
				aux = duplicado->sig;
				duplicado = new Nodo(aux->elem, aux->sig);
				aux->sig = duplicado;
			}


		}
		

	}

	void mostrar(ostream& out = std::cout) {
		Nodo* aux = this->prim;
		while (aux != nullptr) {
			out << aux->elem << " ";
			aux = aux->sig;
		}
		out << endl;
	}

private:

protected:

};


#endif