#include <iostream>
#include <fstream>
#include "linked_list_ed_invertir.h"

using namespace std;

bool resolver() {
	int aux;
	cin >> aux;
	if (!cin) return false;
	linked_list_ed_invertir <int> list;
	while (aux != 0) {
		list.push_back(aux);
		cin >> aux;
	}

	list.invertir();
	list.mostrar();

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("sample-07.1.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resolver());
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}