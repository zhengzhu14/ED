#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;
using tVector = std::vector<int>;

void mostrar(tVector const& solucion) {
	if (!solucion.empty()) {
		cout << solucion[0];
		for (int i = 1; i < solucion.size(); ++i) cout << ' ' << solucion[i];
	}
	cout << endl;
}


void fronteras(bintree <int> const& arbol, tVector& sol) {
	if (!arbol.empty()) {
		if (arbol.left().empty() && arbol.right().empty()) {
			sol.push_back(arbol.root());
		}
		else {
			fronteras(arbol.left(), sol);
			fronteras(arbol.right(), sol);
		}
	}
}

void resolver() {
	bintree <int> arbol = leerArbol(-1);
	tVector sol;
	fronteras(arbol, sol);
	mostrar(sol);
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
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif


	return 0;
}