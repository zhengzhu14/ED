#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std; 

class tValor {
public: 
	int tiempo; 
	int acertados;
	unordered_map<string, std::pair<int, bool>> cuestiones;

	tValor() : tiempo(0), acertados(0), cuestiones() {

	}
};

struct tSolucion {
	string equipo;
	int tiempo;
	int acertados;
};

class Comparador {
public: 
	Comparador (){}

	bool operator ()(tSolucion const& v1, tSolucion const& v2) {
		return (v1.acertados > v2.acertados) || (v1.acertados == v2.acertados && v1.tiempo < v2.tiempo) ||
			(v1.acertados == v2.acertados && v1.tiempo == v2.tiempo && v1.equipo < v2.equipo);
	}
};

void resolver() {
	unordered_map<string, tValor> tabla;
	string equipo;
	string problema;
	int t;
	string acert; 
	bool acertado;
	cin >> equipo;
	while (equipo != "FIN") {
		cin >> problema >> t >> acert;
		if (acert == "AC") acertado = true;
		else acertado = false;
		tValor &valor = tabla[equipo];
		pair <int, bool> &par = valor.cuestiones[problema];
		if (acertado) {
			if (!par.second) {
				valor.tiempo += par.first + t;
				valor.acertados++;
				par = { par.first + t, acertado };
			}
		}
		else {
			if (!par.second) {
				par = { par.first + 20, acertado };
			}
		}
		cin >> equipo;
	}


	std::vector<tSolucion> solucion;
	for (std::pair <string, tValor> const& cv : tabla) {
		solucion.push_back({ cv.first, cv.second.tiempo, cv.second.acertados });
	}
	std::sort(solucion.begin(), solucion.end(), Comparador());
	for (tSolucion sol : solucion) {
		cout << sol.equipo << ' ' << sol.acertados << ' ' << sol.tiempo << endl;
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
	for (int i = 0; i < casos; ++i) resolver();

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}