#include <iostream>
#include <fstream>
#include <string>
#include "set_eda.h"
using namespace std;

template <class T>
void mostrar(set<T> const& conjunto) {
	auto it = conjunto.begin();
	cout << *it;
	++it;
	for (; it != conjunto.end(); ++it) {
		cout << ' ' << *it;
	}
	cout << endl;
}

template <class Tipo>
void mayoresK(set<Tipo> & conjunto, Tipo fin, long long int k) {
	Tipo aux;
	/*for (long long int i = 0; i < k; ++i) {
		cin >> aux;
		conjunto.insert(aux);
	}*/
	while (conjunto.size() < k) {
		cin >> aux;
		conjunto.insert(aux);
	}
	auto it = conjunto.begin();
	cin >> aux;
	while (aux != fin) {
		Tipo minimo = *it;
		if (aux > minimo) { //Si el nuevo elemento es mayor que el begin (el valor mas pequenyo) se inserta
			// y se quita el mas pequenyo
			if (conjunto.insert(aux)) { //Si se consigue insertar es porque no estaba en la lista
				conjunto.erase(minimo); //borro el inicio
				it = conjunto.begin();
			}
		}
		cin >> aux;
	}
}

bool resolver() {
	char tipo;
	cin >> tipo;
	if (!cin) return false; 
	long long int k;
	cin >> k; 
	if (tipo == 'N') {
		int fin = -1;
		set<int> conjunto;
		mayoresK(conjunto, fin, k);
		mostrar(conjunto);
	}
	else {
		string fin = "FIN";
		set <string> conjunto;
		mayoresK(conjunto, fin, k);
		mostrar(conjunto);
	}
	

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
	while (resolver());
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}