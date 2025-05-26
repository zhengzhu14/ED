#include <iostream>
#include <fstream>
#include "bintree_plus.h"
using namespace std;


void resolver() {
	char type;
	cin >> type; 
	int sol;
	if (type == 'N') {
		int value;
		cin >> value;
		bintree_plus<int> arbol = leerArbol_plus(-1);
		sol = arbol.primerNivelEnAparecer(value);
	}
	else {
		char value;
		cin >> value;
		bintree_plus<char> arbol = leerArbol_plus('.');
		sol = arbol.primerNivelEnAparecer(value);
	}
	if (sol == -1) cout << "NO EXISTE";
	else cout << sol;
	cout << endl;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
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