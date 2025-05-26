#include <iostream>
#include <fstream>
#include "double_linked_list_ed_intercambiar.h"

using namespace std;

bool resolver() {
	int tam; 
	cin >> tam;
	if (tam == 0) return false;
	double_linked_list_ed_intercambiar <int> list;
	int aux; 
	for (int i = 0; i < tam; ++i) {
		cin >> aux;
		list.push_back(aux);
	}
	list.intercambiar();
	list.print();

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("sample-10.1.in");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	while (resolver());

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}