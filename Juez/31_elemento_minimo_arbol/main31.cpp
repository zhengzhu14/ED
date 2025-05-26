#include <iostream>
#include <fstream>
#include <string>
#include "bintree_eda.h"

using namespace std; 


template <typename T> 
T buscarMinimo(bintree <T> const & arbol) {
	if (arbol.left().empty() && arbol.right().empty()) return arbol.root();
	else {
		T min = arbol.root();
		if (!arbol.left().empty()) {
			T leftMin = buscarMinimo(arbol.left());
			min = (leftMin < min) ? leftMin : min;
		}
		if (!arbol.right().empty()) {
			T rightMin = buscarMinimo(arbol.right());
			min = (rightMin < min) ? rightMin : min;
		}
		return min;
	}
}

bool resolver() {
	char op; 
	cin >> op; 
	if (!cin) return false;

	if (op == 'N') {
		bintree <int> arbol;
		arbol = leerArbol(-1);
		int min = buscarMinimo(arbol);
		cout << min;
	}
	else {
		string vacio = "#";
		bintree <std::string> arbol = leerArbol(vacio);
		string min = buscarMinimo(arbol);
		cout << min;
	}
	cout << endl;
	return true;
}

int main() {
#ifndef DOMJUDGE
	ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
	while (resolver());
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}