#include <iostream>
#include <fstream>
#include "polinomio.h"
using namespace std;


bool resolver() {

	polinomio p = polinomio();
	/*pair<int,int> m;*/
	/*cin >> m.second >> m.first;*/
	cin >> p;
	if (!cin) {
		/*cout << "Entro aqui";*/
		return false;
	}

	/*while (m.first != 0 || m.second != 0) {
		p.addElem(m);
		cin >> m.second >> m.first;
	}*/

	int casos; 
	cin >> casos;
	int n;
	long long int valor;
	for (int i = 0; i < casos; i++) {
		cin >> n;
		valor = p.evaluar(n);
		cout << valor << " ";
	}

	cout << endl;
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