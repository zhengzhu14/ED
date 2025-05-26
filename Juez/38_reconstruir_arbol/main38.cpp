#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "bintree_eda.h"
using namespace std; 

void mostrar(std::vector<int> vector) {
	for (int i = 0; i < vector.size(); ++i) {
		cout << vector[i] << ' ';
	}
	cout << endl;
}

void leerVector(std::vector<int>& vector, std::string const& str) {
	std::stringstream ss(str);
	int aux;
	std::vector<int> preorden;
	while (ss >> aux) {
		vector.push_back(aux);
	}
}

bintree <int> reconstruir(std::vector<int> const& preorden, std::vector<int> const& inorden,int pini, int pfin,
	int ini, int fin) {
	if (ini > fin) return bintree<int>();
	else if (ini == fin)
		return bintree<int>(inorden[ini]);
	else {
		int raiz = preorden[pini];
		int i = ini;
		while (ini <= fin && inorden[i] != raiz) {
			++i;
		}
		int lIz = i - ini;
		int lDer = fin - i;
		bintree <int> iz = reconstruir(preorden, inorden, pini + 1, pini + lIz, ini, i - 1);
		bintree <int> der = reconstruir(preorden, inorden, pini + lIz + 1, pfin, i + 1, fin);
		
		return bintree <int>(iz, raiz, der);

	}
}
bintree <int> reconstruir(std::vector<int> const& preorden, std::vector<int> const& inorden) {
	return reconstruir(preorden, inorden, 0, preorden.size() - 1, 0, inorden.size() - 1);
}

bool resolver() {
	std::string str;
	getline(std::cin, str);
	if (!cin) return false;

	std::vector<int> preorden;
	leerVector(preorden, str);
	std::vector<int> inorden;
	getline(std::cin, str);
	leerVector(inorden, str);
	bintree<int> arbol = reconstruir(preorden, inorden);
	std::vector <int> postorden = arbol.postorder();
	mostrar(postorden);

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	while (resolver());

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}