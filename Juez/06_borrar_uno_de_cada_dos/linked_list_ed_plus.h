#ifndef linked_list_ed_plus_h
#define linked_list_ed_plus_h
#include <iostream>
#include "linked_list_ed.h"

using namespace std;

template <typename T>
class linked_list_ed_plus : public linked_list_ed <T> {
	using Nodo = typename linked_list_ed<T>::Nodo;

public:
	void eliminarEnPares() {
		int cont = 0;
		Nodo* aux = this->prim;
		Nodo* enPar = nullptr;// nodo auxiliar que apunta hacia el ultimo par, para modificar ->sig
		while(aux!= nullptr){
			if (cont % 2 == 0) {
				enPar = aux;
				aux = aux->sig;
			}
			else {//nunca entrara aqui cuando enPar sea nullptr
				enPar->sig = aux->sig;
				delete aux; //borro el actual
				aux = enPar->sig; // hago que apunto al siguiente que ya sera par

			}
			++cont;
			
		}
		
	}
	void mostrar(std::ostream& o = std::cout) {
		Nodo* aux = this->prim;
		while (aux != nullptr) {
			o << aux->elem << ' ';
			aux = aux -> sig;
		}
		o << '\n';
	}
};

#endif