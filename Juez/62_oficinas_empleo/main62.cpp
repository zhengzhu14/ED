#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <stdexcept>
using namespace std;

class oficina_empleo {
private :
	std::unordered_map<string, std::list<string>> capacitados;
	std::unordered_map <string, std::set<string>> cualificaciones_orden;
	std::unordered_map<string, std::unordered_map<string, std::list<string>::iterator>> cualificacion_iterador;
public:
	oficina_empleo(){}
	~oficina_empleo() {}

	void altaOficina(string nombre, string empleo) {
		if (cualificacion_iterador[nombre].count(empleo) == 0) {
			auto& lista = capacitados[empleo];
			cualificaciones_orden[nombre].insert(empleo);
			cualificacion_iterador[nombre][empleo] = lista.insert(lista.begin(), nombre);
		}
	}
	string ofertaEmpleo(string empleo) {
		auto it = capacitados.find(empleo);
		if (it == capacitados.end()) {
			throw std::domain_error("No existen personas apuntadas a este empleo");
		}
		string parado = it->second.back();
		cualificaciones_orden.erase(parado);
		for (std::pair <string, std::list<string>::iterator> par : cualificacion_iterador[parado]) {
			capacitados[par.first].erase(par.second);
			if (capacitados[par.first].empty()) {
				capacitados.erase(par.first);
			}
		}
		cualificacion_iterador.erase(parado);
		return parado;
	}
	std::vector<string> listadoEmpleos(string persona) const{
		if (cualificacion_iterador.count(persona) == 0) {
			throw std::domain_error("Persona inexistente");
		}
		std::vector<string> lista;
		auto const& conjunto = cualificaciones_orden.at(persona);
		for (string str : conjunto) {
			lista.push_back(str);
		}
		return lista;
	}
};


bool resuelveCaso() {
	string orden;
	std::cin >> orden;
	if (!std::cin)
		return false;

	oficina_empleo oficina;
	string nombre;
	string empleo;

	while (orden != "FIN") {
		try {
			if (orden == "altaOficina") {
				cin >> nombre >> empleo;
				oficina.altaOficina(nombre, empleo);
			}
			else if (orden == "ofertaEmpleo") {
				cin >> empleo;
				string empleado = oficina.ofertaEmpleo(empleo);
				cout << empleo << ": " << empleado << endl;
			}
			else if (orden == "listadoEmpleos") {
				cin >> nombre;
				std::vector<string> listado = oficina.listadoEmpleos(nombre);
				cout << nombre << ":";
				for (string str : listado) {
					cout << ' ' << str;
				}
				cout << endl;
			}
		}	
		catch (std::domain_error e) {
			std::cout << "ERROR: " << e.what() << '\n';
		}
		std::cin >> orden;
	}
	std::cout << "---\n";
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
	
	while (resuelveCaso());

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}