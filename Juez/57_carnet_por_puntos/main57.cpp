#include <iostream>
#include <fstream>
#include <string>
#include "carnetPuntos.h"

using namespace std;

bool resolver() {
    std::string orden, dni;
    int punt;
    std::cin >> orden;
    if (!std::cin)
        return false;

    CarnetPuntos dgt;

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
	while (resolver());

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
