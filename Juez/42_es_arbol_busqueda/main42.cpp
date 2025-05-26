#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

struct tSol {
	int min;
	int max;
	bool esArbol;
};

tSol comprobar(bintree<int> const& arbol) {
	if (arbol.empty()) {
		return { -1, -1, true };
	}
	else if (arbol.left().empty() && arbol.right().empty()) {
		return { arbol.root(), arbol.root(), true };
	}
	else {
		tSol sol = { -1, -1, false };
		int raiz = arbol.root();
		tSol iz = comprobar(arbol.left());
		tSol der = comprobar(arbol.right());
		sol.esArbol = iz.esArbol && der.esArbol;
		if (sol.esArbol) {
			if (iz.max == -1) {
				sol.min = raiz;
			}
			else {
				if (raiz > iz.max) {
					sol.min = iz.min;
				}
				else {
					sol.esArbol = false;
				}
			}
			if (der.min == -1) {
				sol.max = raiz;
			}
			else {
				if (raiz < der.min) {
					sol.max = der.max;
				}
				else {
					sol.esArbol = false;
				}
			}
		}
		return sol;
	}
}

bool esDeBusqueda(bintree<int> const& arbol) {
	return comprobar(arbol).esArbol;
}

void resolver() {
	bintree <int> arbol = leerArbol(-1);
	bool sol = esDeBusqueda(arbol);
	if (sol) cout << "SI";
	else cout << "NO";
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