#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;



void resolver() {
	string str;
	//Leo el salto de linea despues del n
	map<string, string> tab1;
	map<string, string> tab2;
	getline(cin, str);
	std::stringstream ss1(str);
	string clave, valor;
	while (ss1 >> clave) {
		ss1 >> valor;
		tab1[clave] = valor;
	}

	getline(cin, str);
	std::stringstream ss2(str);
	while (ss2 >> clave) {
		ss2 >> valor;
		tab2[clave] = valor;
	}

	std::map<string, string>::iterator it1 = tab1.begin();
	std::map<string, string>::iterator it2 = tab2.begin();

	std::vector<string> agregados;
	std::vector<string> eliminados;
	std::vector<string> modificados;
	while (it1 != tab1.end() && it2 != tab2.end()) {
		if (it1->first > it2->first) { //se ha agregado un valor porque hay una clave en 2 que esta por detras de 1
			agregados.push_back(it2->first);
			++it2;
		}
		else if (it1->first < it2->first){// se ha eliminado un valor porque el iterador de 1 esta por detras
			eliminados.push_back(it1->first);
			++it1;
		}
		else { //puede que se haya modificado
			if (it1->second != it2->second)
				modificados.push_back(it1->first);
			++it1; ++it2;
		}
	}

	while (it1 != tab1.end()) {
		eliminados.push_back(it1->first);
		++it1;
	}
	while (it2 != tab2.end()) {
		agregados.push_back(it2->first);
		++it2;
	}
	
	if (agregados.empty() && eliminados.empty() && modificados.empty()) {
		cout << "Sin cambios\n";
	}
	else {
		if (!agregados.empty()) {
			cout << "+";
			for (string a : agregados) {
				cout << ' ' << a;
			}
			cout << endl;
		}
		if (!eliminados.empty()) {
			cout << "-";
			for (string e : eliminados) {
				cout << ' ' << e;
			}
			cout << endl;
		}
		if (!modificados.empty()) {
			cout << "*";
			for (string m : modificados) {
				cout << ' ' << m;
			}
			cout << endl;
		}
	}
	cout << "---\n";
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	int casos;
	cin >> casos;
	string aux;
	getline(cin, aux);
	for (int i = 0; i < casos; ++i) resolver();

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}