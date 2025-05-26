#include <iostream>
#include <fstream>
#include "double_linked_list_ed_doblar.h"

using namespace std;

void resolver() {
	int tam;
	cin >> tam;
	double_linked_list_ed_doblar<int> list; 

	int aux;
	for (int i = 0; i < tam; ++i) {
		cin >> aux;
		list.push_back(aux);
	}
	list.doblar(); 
	list.print(); 
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("sample-13.1.in");
	//std::ifstream in("datos.txt");

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