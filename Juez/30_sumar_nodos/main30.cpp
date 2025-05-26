#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

bintree<int> leer_datos() {
	int valor; 
	cin >> valor;
	if (valor == -1) return bintree<int>();
	else {
		bintree <int> iz = leer_datos(); 
		bintree <int> der = leer_datos();
		return bintree<int>(iz, valor, der);
	}
}

int sumaNodos(bintree <int> const& arbol) {
	if (arbol.empty()) return 0; //Arbol vacio: caso base
	else {
		int iz = sumaNodos(arbol.left());
		int der = sumaNodos(arbol.right());
		if (iz == 0 && der == 0) return arbol.root(); //es una hoja: caso base
		else {
			return arbol.root() + iz + der;
		}
	}
}

void resolver() {
	bintree <int> arbol; 
	arbol =  leer_datos();
	int suma = sumaNodos(arbol);
	cout << suma << endl;
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
