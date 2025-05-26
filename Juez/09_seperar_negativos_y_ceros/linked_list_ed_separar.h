#ifndef linked_list_ed_separar_h
#define linked_list_ed_separar_h
#include <iostream>
#include "linked_list_ed.h"

using namespace std;

template <typename T>
class linked_list_ed_separar : public linked_list_ed<T> {
	using Nodo = typename linked_list_ed <T>::Nodo;
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
		}
		out << '\n';
	}


	void separar_negativos(linked_list_ed_separar <T>& negativos) { //negativos esta vacio
		if (!this->empty()) { //la lista actual no es vacia
			hasta_primer_positivo(negativos); 
			if (!this->empty()) {
				Nodo* aux = this->prim; //aux es el iterador.
				Nodo* positivo = this->prim;
				while (aux != nullptr) {
					if (aux->elem > 0) {
						positivo = aux;
					}
					else {
						if (aux->elem == 0) {
							positivo->sig = aux->sig; //elimino el que contiene 0
						}
						else {
							if (negativos.empty()) {
								negativos.prim = negativos.ult = aux; 
							}
							else {
								negativos.ult->sig = aux;
								negativos.ult = aux;
							}
							positivo->sig = aux->sig;
							negativos.ult->sig = nullptr;
						}
					}
					aux = positivo->sig;
				}
			}
			else {
				this->ult = this->prim;
			}
		}

	}
private:
	void hasta_primer_positivo(linked_list_ed_separar <T>& negativos) { //acorta la lista hasta el primer elemento positivo
		while (this->prim != nullptr && this->prim->elem <= 0) {
			if (this->prim->elem < 0) {
				if (negativos.empty()) {
					negativos.prim = negativos.ult = this->prim;
				}
				else {
					negativos.ult->sig = this->prim;
					negativos.ult = this->prim;
				}
				this->prim = this->prim->sig;
				negativos.ult->sig = nullptr;
			}
			else {
				this->prim = this->prim->sig;
			}

		}
	}
};


#endif