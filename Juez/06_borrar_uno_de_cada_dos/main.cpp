#include <iostream>
#include <fstream>
#include "horas.h"
#include "linked_list_ed_plus.h"

using namespace std;

bool resolver(){
	int tam; 
	cin >> tam;
	if (tam == 0) return false;
	horas h;
	linked_list_ed_plus<horas> list;
	for (int i = 0; i < tam; ++i) {
		cin >> h; 
		list.push_back(h);
	}

	list.eliminarEnPares();
	list.mostrar();


	return true;
}
int main() {
#ifndef DOMJUDGE
	ifstream in("sample-06.1.in");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	while (resolver());

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}