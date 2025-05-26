#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "autoescuela.h"

using namespace std;

bool resolver() {
	string op;
	cin >> op;
	if (!cin) return false;
	string alumno;
	string profesor;
	int puntos;
	autoescuela escuela;

	while (op != "FIN") {
		try {
			if (op == "alta") {
				cin >> alumno >> profesor;
				escuela.alta(alumno, profesor);
			}
			else if (op == "es_alumno") {
				cin >> alumno >> profesor;
				string aux = "";
				if (!escuela.es_alumno(alumno, profesor)) {
					aux = " no";
				}
				cout << alumno + aux + " es alumno de " + profesor << endl;

			}
			else if (op == "examen") {
				cin >> profesor >> puntos;
				std::vector <string> als = escuela.examen(profesor, puntos);
				cout << "Alumnos de " + profesor + " a examen:\n";
				for (string str : als) {
					cout << str << endl;
				}
			}
			else if (op == "actualizar") {
				cin >> alumno >> puntos;
				escuela.actualizar(alumno, puntos);
			}
			else if (op == "puntuacion") {
				cin >> alumno;
				int puntuacion = escuela.puntuacion(alumno);
				cout << "Puntuacion de " + alumno + ": " << puntuacion << endl; 
			}
			else if (op == "aprobar") {
				cin >> alumno;
				escuela.aprobar(alumno);
			}
		}
		catch (std::domain_error e) {
			cout << "ERROR\n";
		}
		cin >> op;
	}
	cout << "---\n";

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