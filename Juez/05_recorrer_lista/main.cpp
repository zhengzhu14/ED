#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "linked_list_ed_recorrer.h"
using namespace std;

bool resolver() {
	char c;
	cin >> c;
	if (!cin) return false;
	string str;
	getline(cin, str);
	getline(cin, str);
	stringstream ss(str);
	linked_list_ed_recorrer <string> list;
	while (ss) {
		string aux;
		ss >> aux;
		list.push_back(aux);
	}

	//list.mostrar();
	list.mostrarPropiedad([c](string str) -> bool {return str[0] == c; });

	return true;
}

int main() {
#ifndef DOMJUDGE
	ifstream in("sample-05.1.in");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	while (resolver());

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}