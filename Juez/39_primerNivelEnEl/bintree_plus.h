#ifndef bintree_plus_h
#define bintree_plus_h

#include "bintree_eda.h"
#include <queue>


template <typename T>
class bintree_plus : public bintree<T> {
	using Link = typename bintree <T >::Link;
public:
	bintree_plus() : bintree <T >() {}
	bintree_plus(bintree_plus <T > const& l, T const& e, bintree_plus <T > const& r) :
		bintree <T>(l, e, r) {}

	int primerNivelEnAparecer(T value) {
		bool encontrado = false;
		int nivel = 1; 
		if (!this->empty()) {
			std::queue<std::pair<int, Link>> pendientes;
			pendientes.push({nivel, this->raiz});
			int apariciones = 0;
			while (!pendientes.empty() && !encontrado) {
				std::pair<int,Link> sig = pendientes.front();
				pendientes.pop();
				if (sig.first != nivel) {
					nivel = sig.first;
					apariciones = 0;
				}
				if (sig.second->elem == value) ++apariciones;
				if (apariciones > 1) encontrado = true;
				else {
					if (sig.second->left != nullptr) {
						pendientes.push({ nivel + 1, sig.second->left });
					}
					if (sig.second->right != nullptr) {
						pendientes.push({ nivel + 1, sig.second->right });
					}
				}
			}
		}

		if (!encontrado) return -1;
		else return nivel;

	}
	

private:


};



template <typename T >
inline bintree_plus <T> leerArbol_plus(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un arbol vacio
		return {};
	}
	else { // leer recursivamente los hijos
		bintree_plus <T > iz = leerArbol_plus(vacio);
		bintree_plus <T > dr = leerArbol_plus(vacio);
		return { iz , raiz , dr };
	}
}

#endif