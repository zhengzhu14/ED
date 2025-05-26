#include <iostream>
#include <fstream>
#include <vector>
#include "bintree_plus.h"

using namespace std;


void mostrar(std::vector<int> const& frontera) {
	if (!frontera.empty()) {
		cout << frontera[0];
		for (int i = 1; i < frontera.size(); ++i)  cout << ' ' << frontera[i];
	}
	cout << endl;
}

void resolver() {
	bintree_plus <int> arbol = leerArbol_plus(-1);
	std::vector <int> sol = arbol.get_rightFrontier();
	mostrar(sol);
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