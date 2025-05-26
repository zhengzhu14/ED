#include <iostream>
#include <fstream>
#include "double_linked_list_ed_interseccion.h"
using namespace std;


void resolver() {
	double_linked_list_ed_interseccion <int> l1; 
	double_linked_list_ed_interseccion <int> l2;
	int aux; 
	cin >> aux;
	while (aux != 0) {
		l1.push_back(aux);
		cin >> aux;
	}
	cin >> aux;
	while (aux != 0) {
		l2.push_back(aux);
		cin >> aux;
	}

	l1.interseccion(l2);

	l1.print();


}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("sample-11.1.in");
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