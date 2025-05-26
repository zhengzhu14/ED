#include <iostream>
#include <fstream>
#include "set_plus.h"

using namespace std;

bool resolver() {
	int tam;
	cin >> tam;
	if (tam == 0) return false;
	set_plus <int> arbol;
	int aux;
	for (int i = 0; i < tam; ++i) {
		cin >> aux;
		arbol.insert(aux);
	}
	std::pair<bool, int> sol;
	int preguntas;
	cin >> preguntas;
	for (int i = 0; i < preguntas; ++i) {
		cin >> aux;
		sol = arbol.lower_bound(aux);
		if (!sol.first) {
			cout << "NO HAY";
		}
		else {
			cout << sol.second;
		}
		cout << endl;
	}
	cout << "---\n";

	return true;

}


int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resolver());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}