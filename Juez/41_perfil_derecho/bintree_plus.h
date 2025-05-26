#ifndef bintree_plus_h
#define bintree_plus_h

#include "bintree_eda.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


template <typename T>
class bintree_plus : public bintree<T> {
	using Link = typename bintree <T>::Link;
public:
	bintree_plus() : bintree <T >() {}
	bintree_plus(bintree_plus <T > const& l, T const& e, bintree_plus <T > const& r) :
		bintree <T>(l, e, r) {}

	std::vector <T> get_rightFrontier() {
		std::vector <T> frontier;
		int nivel = 0;
		if (!this->empty()) {
			std::queue <std::pair<int, Link>> pendientes;
			pendientes.push({ 1, this->raiz });
			while (!pendientes.empty()) {
				std::pair<int, Link> sig = pendientes.front();
				pendientes.pop();
				if (nivel != sig.first) {
					nivel = sig.first;
					frontier.push_back(sig.second->elem);
				}
				if (sig.second->right != nullptr) {
					pendientes.push({ nivel + 1,  sig.second->right });
				}
				if (sig.second->left != nullptr) {
					pendientes.push({ nivel + 1,  sig.second->left });
				}
			}
		}
		return frontier;
		
	}

private:

	/*static void get_rightFrontier(Link a, std::vector<T>& rFrontier) {
		if (a != nullptr) {
			rFrontier.push_back(a->elem);
			if (a->right != nullptr) {
				get_rightFrontier(a->right, rFrontier);
			}
			else {
				get_rightFrontier(a->left, rFrontier);
			}
		}
	}*/

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