#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;
using tSol = std::pair <int, int>; //first: diametro; second: maximo de las dos ramas;

tSol calcularDiametro(bintree <char> const& arbol) {
	if (arbol.empty()) return {0,0};
	else {
		tSol sol = { 1, 1 };
		tSol lIz = calcularDiametro(arbol.left());
		tSol lDer = calcularDiametro(arbol.right());

		//calculo el maximo de esta rama
		sol.second += (lIz.second > lDer.second) ? lIz.second : lDer.second;
		int caminoMaximo = (lIz.first > lDer.first) ? lIz.first : lDer.first;

		if ((sol.first + lIz.second + lDer.second) > caminoMaximo) sol.first += (lIz.second + lDer.second);
		else sol.first = caminoMaximo; 
		return sol;

	}
}

void resolver() {
	bintree <char> arbol = leerArbol('.');
	int sol = calcularDiametro(arbol).first;
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