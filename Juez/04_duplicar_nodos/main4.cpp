#include <iostream>
#include <fstream>
#include "linked_list_ed_duplicated.h"

using namespace std;

using tDuplicate = linked_list_ed_duplicated<int>;

bool resolver() {
	int num;
	cin >> num;
	if (!cin) return false;
	tDuplicate lista;
	while (num != 0) {
		lista.push_back(num);
		cin >> num;
	}
	lista.duplicate();

	lista.mostrar();

	lista.~linked_list_ed_duplicated<int>();

	//lista.mostrar();

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.in");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	while (resolver());

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}