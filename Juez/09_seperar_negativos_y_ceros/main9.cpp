#include <iostream>
#include <fstream>
#include "linked_list_ed_separar.h"

using namespace std;


bool resolver() {
	int tam; 
	cin >> tam;
	if(tam == -1) return false;
	linked_list_ed_separar <int> list;
	linked_list_ed_separar <int> negativos;
	int aux;
	for (int i = 0; i < tam; ++i) {
		cin >> aux;
		list.push_back(aux);
	}

	list.separar_negativos(negativos);

	list.print();
	negativos.print();

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("sample-09.1.in");
	//std::ifstream in("datos.txt");

	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resolver());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}