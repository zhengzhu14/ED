#ifndef carnetPuntos_h
#define carnetPuntos_h

#include <stdexcept>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>


class CarnetPuntos {
public: 
	CarnetPuntos(): tabla(), num_conductores(std::vector<int> (MAX_PUNTOS + 1)){}
	~CarnetPuntos(){}

	void nuevo(std::string dni) {
		if (tabla.count(dni) == 1) {
			throw std::domain_error("Conductor duplicado");
		}
		tabla[dni] = MAX_PUNTOS;
		num_conductores[MAX_PUNTOS]++;
	}
	void quitar(std::string dni, int puntos) {
		if (tabla.count(dni) == 0) {
			throw std::domain_error("Conductor inexistente");
		}
		int& antiguo = tabla[dni];
		num_conductores[antiguo]--;
		antiguo = (antiguo - puntos <= 0) ? 0 : antiguo - puntos;
		num_conductores[antiguo]++;
	}

	int consultar(std::string dni) {
		if (tabla.count(dni) == 0) {
			throw std::domain_error("Conductor inexistente");
		}
		return tabla[dni];
	}

	int cuantos_con_puntos(int puntos) {
		if (puntos > MAX_PUNTOS || puntos < MIN_PUNTOS) {
			throw std::domain_error("Puntos no validos");
		}
		return num_conductores[puntos];
	}

private: 
	const int MAX_PUNTOS = 15;
	const int MIN_PUNTOS = 0;
	std::unordered_map <std::string, int> tabla;
	std::vector <int> num_conductores; //Voy acumulando el numero de conductores que tienen determinada cantidad de puntos


};

#endif