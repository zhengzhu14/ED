#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>
#include <list>

using namespace std;

class carnet_puntos {
public:
	carnet_puntos() : tabla(), num_conductores(16) {}
	~carnet_puntos() {}

	void nuevo(std::string dni) {
		if (tabla.count(dni) == 1) {
			throw std::domain_error("Conductor duplicado");
		}
		tabla[dni] = { MAX_PUNTOS ,insertar_por_puntos(dni, MAX_PUNTOS) };
	}
	void recuperar(std::string dni, int puntos) {
		if (tabla.count(dni) == 0) {
			throw std::domain_error("Conductor inexistente");
		}
		std::pair<int, list<std::string>::iterator>& conductor = tabla[dni];
		if (conductor.first < 15 && puntos > 0) {
			num_conductores[conductor.first].erase(conductor.second);
			conductor.first = (conductor.first + puntos >= MAX_PUNTOS) ? MAX_PUNTOS : conductor.first + puntos;
			conductor.second = insertar_por_puntos(dni, conductor.first);
		}
		
	}
	void quitar(std::string dni, int puntos) {
		if (tabla.count(dni) == 0) {
			throw std::domain_error("Conductor inexistente");
		}
		std::pair<int, list<std::string>::iterator>& conductor = tabla[dni];
		if (conductor.first > 0 && puntos > 0) {
			num_conductores[conductor.first].erase(conductor.second);
			conductor.first = (conductor.first - puntos <= MIN_PUNTOS) ? MIN_PUNTOS : conductor.first - puntos;
			conductor.second = insertar_por_puntos(dni, conductor.first);
		}
		
		
	}

	int consultar(std::string dni) {
		if (tabla.count(dni) == 0) {
			throw std::domain_error("Conductor inexistente");
		}
		return tabla[dni].first;
	}

	int cuantos_con_puntos(int puntos) {
		if (puntos > MAX_PUNTOS || puntos < MIN_PUNTOS) {
			throw std::domain_error("Puntos no validos");
		}
		return num_conductores[puntos].size();
	}
	std::vector <string> lista_por_puntos(int puntos) {
		if (puntos > MAX_PUNTOS || puntos < MIN_PUNTOS) {
			throw std::domain_error("Puntos no validos");
		}
		std::vector <string> listado;
		for (std::string str : num_conductores[puntos]) {
			listado.push_back(str);
		}
		return listado; 
	}

private:
	const int MAX_PUNTOS = 15;
	const int MIN_PUNTOS = 0;
	std::unordered_map <std::string, std::pair<int, list<std::string>::iterator>> tabla;
	std::vector <list<std::string>> num_conductores; //Voy acumulando el numero de conductores que tienen determinada cantidad de puntos

	list<std::string>::iterator insertar_por_puntos(std::string dni, int puntos) {
		auto& lista = num_conductores[puntos];
		return lista.insert(lista.begin(), dni);
	}


};

bool resuelveCaso() {
	std::string orden, dni;
	int punt;
	std::cin >> orden;
	if (!std::cin)
		return false;

	carnet_puntos dgt;

	while (orden != "FIN") {
		try {
			if (orden == "nuevo") {
				std::cin >> dni;
				dgt.nuevo(dni);
			}
			else if (orden == "quitar") {
				std::cin >> dni >> punt;
				dgt.quitar(dni, punt);
			}
			else if (orden == "consultar") {
				std::cin >> dni;
				punt = dgt.consultar(dni);
				std::cout << "Puntos de " << dni << ": " << punt << '\n';
			}
			else if (orden == "cuantos_con_puntos") {
				std::cin >> punt;
				int cuantos = dgt.cuantos_con_puntos(punt);
				std::cout << "Con " << punt << " puntos hay " << cuantos << '\n';
			}
			else if (orden == "recuperar") {
				std::cin >> dni >> punt;
				dgt.recuperar(dni, punt);
			}
			else if (orden == "lista_por_puntos") {
				std::cin >> punt;
				std::vector<string> cuantos = dgt.lista_por_puntos(punt);
				std::cout << "Tienen " << punt << " puntos:";
				for (string str : cuantos) {
					std::cout << " " << str;
				}
				cout << std::endl;
			}
			else
				std::cout << "OPERACION DESCONOCIDA\n";
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