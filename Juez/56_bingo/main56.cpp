#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

//class tValor {
//public:
//	int acertados;
//	set<int> cartilla;
//	tValor(): acertados(0), cartilla(){}
//};


bool resolver() {
	int jugadores; cin >> jugadores;
	if (jugadores == 0) return false;

	unordered_map <int, std::vector<string>> tablaNum;
	unordered_map <string, int> tabla; //clave: nombre , valor: cantidad de numeros

	string nombre;
	int numero;
	for (int i = 0; i < jugadores; ++i) {
		cin >> nombre;
		cin >> numero;
		while (numero != 0) {
			tabla[nombre]++;
			tablaNum[numero].push_back(nombre);
			cin >> numero;
		}
	}

	std::vector <string> ganadores;
	bool hayGanador = false;
	int aux;
	while (!hayGanador) {
		cin >> aux;
		if (tablaNum.count(aux) == 1) { //Alguien tiene este numero
			std::vector <string> const& jug = tablaNum[aux];
			for (string name : jug) {
				int& cantidad = tabla[name];
				cantidad--;
				if (cantidad == 0) {
					hayGanador = true;
					ganadores.push_back(name);
				}
			}
		}
	}

	std::sort(ganadores.begin(), ganadores.end());
	if (!ganadores.empty()) {
		cout << ganadores[0];
		for (int i = 1; i < ganadores.size(); ++i) cout << ' ' << ganadores[i];
	}
	cout << endl;
	

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