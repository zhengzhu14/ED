#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;
using tSol = pair <int, int>;//first: longitud maximo; second: longitud actual;

bool esPar(int numero) {
	return numero % 2 == 0;
}

tSol longitudMaxima(bintree <int> const& arbol) {
	if (arbol.empty()) {
		return { 0,0 };
	}
	else {
		tSol iz = longitudMaxima(arbol.left());
		tSol der = longitudMaxima(arbol.right());
		int raiz = arbol.root();
		tSol sol;
		sol.first = std::max(iz.first, der.first);
		sol.second = 0;
		int longitudActual = 0;
		if (esPar(raiz)) longitudActual = iz.second + der.second + 1;
		if (longitudActual > sol.first) sol.first = longitudActual;
		if (esPar(raiz)) sol.second = std::max(iz.second, der.second) + 1;
		return sol;
	}
}

int longitudPares(bintree <int> const& arbol) {
	return longitudMaxima(arbol).first;
}

void resolver() {
	bintree <int> arbol = leerArbol(-1);
	int sol = longitudPares(arbol); 
	cout << sol << endl;
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