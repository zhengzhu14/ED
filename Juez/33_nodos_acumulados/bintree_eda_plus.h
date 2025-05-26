//Nombre: Zhengkai Zhu
//Juez: A73
//email: zhengzhu@ucm.es

#ifndef bintree_eda_plus_h
#define bintree_eda_plus_h
#include "bintree_eda.h"
#include <iostream>
using namespace std;

template <typename T> 
class bintree_eda_plus : public bintree<T> {
	using Link = typename bintree <T >::Link;
public:
	bintree_eda_plus() : bintree <T >() {}
	bintree_eda_plus(bintree_eda_plus <T > const& l, T const& e, bintree_eda_plus <T > const& r) :
		bintree <T>(l, e, r) {}

	int const calcularAcumulados() {
		return calcularAcumulados(this->raiz).second;
	}

private: 
	
	using tSol = pair <int, int>;// first: valor acumulado;  second: numero de nodos acumulados
	tSol calcularAcumulados(Link r) {
		if (r == nullptr) return { 0,0 };
		else {
			tSol iz = calcularAcumulados(r->left);
			tSol der = calcularAcumulados(r->right);
			int raiz = r->elem;
			int acumulacion = iz.first + der.first;
			int nAcumulados = iz.second + der.second;
			if (acumulacion == raiz) ++nAcumulados;
			return { acumulacion + raiz, nAcumulados };
		}
	}

};



template <typename T >
inline bintree_eda_plus <T> leerArbol_plus(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un arbol vacio
		return {};
	}
	else { // leer recursivamente los hijos
		bintree_eda_plus <T > iz = leerArbol_plus(vacio);
		bintree_eda_plus <T > dr = leerArbol_plus(vacio);
		return { iz , raiz , dr };
	}
}


#endif