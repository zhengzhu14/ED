#ifndef double_linked_list_ed_particion_h
#define double_linked_list_ed_particion_h
#include "double_linked_list_ed.h"
#include <iostream>
using namespace std;

template <typename T>
class double_linked_list_ed_particion : public double_linked_list_ed <T> {
	using Nodo = typename double_linked_list_ed <T>::Nodo;

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
	void particion(int pivote) { //Sabemos que no es vacio
		//El algoritmo movera los mayores al final de la lista para mantener el orden actual de la lista
		Nodo* p = this->fantasma->sig; 

		if (p->sig != this->fantasma) { //Compruebo que tiene mas de un elemento
			while (p!= this->fantasma && p->elem <= pivote) p = p->sig;
			Nodo* q = nullptr; 
			if (p != this->fantasma) { //Ha encontrado un numero mayor que el pivote
				q = p; 
				p = p->sig;

				q->ant->sig = q->sig;
				q->sig->ant = q->ant; 

				Nodo* ultimo = this->fantasma->ant; 
				this->fantasma->ant = q; 
				ultimo->sig = q;
				q->ant = ultimo; 
				q->sig = this->fantasma;

				Nodo* aux = nullptr;
				while (p != this->fantasma && p != q) {
					if (p->elem <= pivote) p = p->sig;
					else {
						aux = p;
						p = p->sig;
						aux->ant->sig = aux->sig;
						aux->sig->ant = aux->ant;

						Nodo* ultimo = this->fantasma->ant;
						this->fantasma->ant = aux;
						ultimo->sig = aux;
						aux->ant = ultimo;
						aux->sig = this->fantasma;
					}
				}

			}

			


		}

	}


	//void particion(int pivote) { //Sabemos que no es vacio
	//	Nodo* p = this->fantasma->sig;
	//	Nodo* q = this->fantasma->ant;
	//	if (p != q) { // Si tiene mas de un elemento
	//		while (p != q && q->sig != p){
	//			if (p->elem < pivote) {
	//				p = p->sig;
	//			}
	//			else if (q->elem > pivote) {
	//				q = q->ant;
	//			}
	//			else { // Caso p->elem >= pivote && q->elem <= pivote
	//				Nodo* anterior = q->ant; // en anterior guardo el anterior a q
	//				Nodo* siguiente = p->sig; //en siguiente guardo el siguiente a p
	//				
	//				//Cambio los elementos siguientes y anteriores a p y q para que apunten a ellos
	//				p->ant->sig = q; 
	//				siguiente->ant = q;
	//				q->sig->ant = p;
	//				anterior->sig = p;

	//				//Hago que el anterior de q sea el anterior de p
	//				q->ant = p->ant;
	//				p->sig = q->sig; //Hago que el siguiente de p sea el siguiente de q

	//				//Aqui cambio los anteriores y siguientes
	//				q->sig = siguiente; 
	//				p->ant = anterior;

	//				
	//				q = anterior; 
	//				p = siguiente;

	//			}


	//		}

	//	}

	//}
};



#endif