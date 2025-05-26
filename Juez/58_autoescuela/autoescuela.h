#ifndef autoescuela_h
#define autoescuela_h
#include <iostream>
#include <stdexcept>
#include <set>
#include <unordered_map>
#include <vector>
#include <string>


class autoescuela {
	using tPair = std::pair <std::string, int>;
public: 
	autoescuela(): tabla(), asignaciones() {}
	~autoescuela(){}

	void alta(std::string a, std::string p) {
		if (tabla.count(a) == 1) {
			tPair& par = tabla[a];
			asignaciones[par.first].erase(a);
			par.first = p;
			asignaciones[p].insert(a);
		}
		else {
			tabla[a] = { p, 0 };
			asignaciones[p].insert(a);
		}
	}

	bool es_alumno(std::string a, std::string p) {
		return tabla.count(a) == 1 && tabla[a].first == p;
	}
	int puntuacion(std::string a) {
		if (tabla.count(a) == 0) {
			throw std::domain_error("El alumno " + a + " no esta matriculado");
		}
		return tabla[a].second;
	}

	void actualizar(std::string a, int n) {
		if (tabla.count(a) == 0) {
			throw std::domain_error("El alumno " + a + " no esta matriculado");
		}
		tabla[a].second += n;
	}

	std::vector <std::string> examen(std::string p, int n) {
		std::vector<std::string> sol;
		std::set<std::string> const& conjunto = asignaciones[p];
		for (std::string a : conjunto) {
			if (tabla[a].second >= n) {
				sol.push_back(a);
			}
		}
		return sol;
	}
	void aprobar(std::string a) {
		if (tabla.count(a) == 0) {
			throw std::domain_error("El alumno " + a + " no esta matriculado");
		}
		std::string profesor = tabla[a].first;
		tabla.erase(a);
		asignaciones[profesor].erase(a);

	}

private:
	std::unordered_map <std::string, tPair> tabla;
	std::unordered_map<std::string, std::set<std::string>> asignaciones;
};

#endif