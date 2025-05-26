#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;
using tSol = pair<int, int>;  //first: numero de caudales; second: caudal;

tSol calcCaudales(bintree <int> const& arbol) {
	if (arbol.empty()) return { 0,0 };
	else if (arbol.left().empty() && arbol.right().empty()) {
		return { 0, 1 };
	}
	else {
		tSol iz = calcCaudales(arbol.left());
		tSol der = calcCaudales(arbol.right());
		tSol sol;
		int consumido = arbol.root();
		sol.first = iz.first + der.first;
		sol.second = (iz.second + der.second) - consumido;
		if (sol.second <= 0) sol.second = 0;
		if (sol.second >= 3) ++sol.first;
		return sol;
	}
}
int numNavegables(bintree <int> const& arbol) {
	tSol sol = calcCaudales(arbol);
	if (sol.second >= 3) --sol.first;
	return sol.first;
}
void resolver() {
	bintree <int> arbol = leerArbol(-1);
	int sol = numNavegables(arbol);
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