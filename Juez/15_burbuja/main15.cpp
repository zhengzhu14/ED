#include <iostream>
#include <fstream>
#include "linked_list_ed_plus.h"

using namespace std;

bool resolver() {
	int tam;
	cin >> tam;
	if (tam == 0) return false;
	linked_list_ed_plus <int> list;
	int aux;
	for (int i = 0; i < tam; ++i) {
		cin >> aux;
		list.push_back(aux);
	}
	list.ordBurbuja();
	list.print();

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("sample-15.1.in");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	while (resolver());

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}