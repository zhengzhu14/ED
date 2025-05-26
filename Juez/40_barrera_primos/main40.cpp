#include <iostream>
#include <fstream>
#include <queue>
#include "bintree_eda.h"

using namespace std; 
using tPair = std::pair<int, int>; //first: valor , second: nivel;
bool isPrime(int n) {
	bool esPrimo = true;
	if (n < 2) esPrimo = false;
	int i = 2; 
	while (i * i <= n && esPrimo) {
		if (n % i == 0) esPrimo = false;
		++i;
	}
	return esPrimo;
}

tPair multiploMasAccesible(bintree <int> const& arbol) {
	bool encontrado = false;
	tPair sol;
	if (!arbol.empty()) {
		std::queue<std::pair<int, bintree<int>>> pendientes;
		int nivel = 1;
		pendientes.push({ nivel, arbol });
		while (!pendientes.empty() && !encontrado) {
			std::pair<int, bintree<int>> sig = pendientes.front();
			pendientes.pop();
			if (!isPrime(sig.second.root())) {
				if (nivel != sig.first) nivel = sig.first;
				if (sig.second.root() % 7 == 0) {
					encontrado = true;
					sol.first = sig.second.root();
					sol.second = nivel;
				}
				else {
					if (!sig.second.left().empty()) pendientes.push({ nivel + 1, sig.second.left()});
					if (!sig.second.right().empty()) pendientes.push({ nivel + 1, sig.second.right() });
				}
			}
			
		}
	}

	if (!encontrado) return { -1, -1 };
	else return sol;
}

void resolver() {
	bintree <int> arbol = leerArbol(-1);
	tPair sol = multiploMasAccesible(arbol);
	if (sol.first == -1) cout << "NO HAY";
	else cout << sol.first << ' ' << sol.second;
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