#include <iostream>
#include <fstream>
#include <stack>
#include "bintree_eda.h"

using namespace std;

using tSol = pair <int, int>; //first: equipos, second: maximo

tSol calcularRescate(bintree <int> const& arbol) {
	if (arbol.empty()) {
		return { 0,0 };
	}
	else {
		int raiz = arbol.root();
		tSol iz = calcularRescate(arbol.left());
		tSol der = calcularRescate(arbol.right());
		int first = iz.first + der.first;
		int second = std::max(iz.second, der.second) + raiz;
		if (first == 0 && raiz != 0) {
			++first;
		}
		return { first, second };
	}
}

void resolver() {
	bintree <int> arbol = leerArbol(-1);
	tSol sol = calcularRescate(arbol);
	cout << sol.first << ' ' << sol.second << endl;
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
