#include <iostream>
#include <fstream>
#include <string>
#include "bintree_eda.h"


using namespace std;

int calcAltura(bintree <char> const& arbol) {
	if (arbol.empty()) return 0;
	else {
		int altIz = calcAltura(arbol.left());
		int altDer = calcAltura(arbol.right());
		if (altIz == 0 && altDer == 0) return 1;
		else {
			int max = 1;
			if (altIz > altDer) max += altIz;
			else max += altDer;
			return max;
		}
	}
}
int cantHijos(bintree <char> const& arbol) {
	if (arbol.empty()) return 0; 
	else {
		int hiz = cantHijos(arbol.left()); 
		int hder = cantHijos(arbol.right());
		if (hiz == 0 && hder == 0) return 1;
		else {
			return hiz + hder;
		}
	}
}

int cantNodos(bintree<char> const &arbol) {
	if (arbol.empty()) {
		return 0;
	}
	else {
		int niz = cantNodos(arbol.left());
		int nder = cantNodos(arbol.right());
		return (1 + niz + nder);
	}
}

bintree <char> leer_arbol() {
	char c; 
	cin >> c; 
	if (c == '.') return bintree<char>(); //devuelvo arbol vacio
	else {
		bintree<char> iz = leer_arbol();
		bintree<char> der = leer_arbol();
		return bintree<char>(iz, c, der);
	}
}

void resolver() {
	bintree<char> arbol; 
	arbol = leer_arbol();
	int nodos = cantNodos(arbol);
	int hijos = cantHijos(arbol);
	int altura = calcAltura(arbol);
	cout << nodos << ' ' << hijos << ' ' << altura << '\n';

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int casos; 
	cin >> casos; 
	for (int i = 0; i < casos; ++i) resolver();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif


	return 0;
}