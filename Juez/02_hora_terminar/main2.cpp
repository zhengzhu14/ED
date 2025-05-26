#include <iostream>
#include <fstream>

#include "horas.h"

using namespace std;


void resolver() {
	horas h, duracion;
	cin >> h >> duracion;
	try {
		
		horas sol = h + duracion;
		cout << sol << endl;
	}
	catch (overflow_error e) {
		cout << e.what() << endl;
	}
	
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.in");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) resolver();

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}