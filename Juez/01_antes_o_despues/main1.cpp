#include <iostream>
#include <fstream>

#include "horas.h"


using namespace std;

void resolver() {
	horas h1, h2;
	cin >> h1 >> h2;
	if (h1 == h2) {
		cout << "IGUALES";
	}
	else if (h1 < h2) {
		cout << h1 << " " << h2;
	}
	else cout << h2 << " " << h1;

	cout << endl;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.in");
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