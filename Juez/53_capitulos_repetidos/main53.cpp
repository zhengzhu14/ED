#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std; 

void resolver() {
	int n; 
	cin >> n;
	std::unordered_map<int, int> tabla; //clave: numero, valor: posicion
	int actual = 0;
	int maximo = 0;
	int aux;
	for (int i = 0; i < n; ++i) {
		cin >> aux; 
		if (tabla.count(aux) == 0) { //Es un numero nuevo
			tabla[aux] = i;
		}
		else {//La clave existe
			int dif = i - tabla[aux] -1;
			tabla[aux] = i;
			if (dif < actual) actual = dif;

		}
		++actual;
		if (actual > maximo) maximo = actual;
	}

	cout << maximo << endl;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
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