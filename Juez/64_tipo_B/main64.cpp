
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector> 
#include <set>
#include <unordered_map>
#include <list>


// añade las librerías de la STL que necesites

using paciente = std::string;
using gravedad = int;

class urgencias {

    const int MAX_GRAVEDAD = 3;
    const int MIN_GRAVEDAD = 1;

    std::vector<std::list<paciente>> pacientes;
    std::unordered_map<paciente, std::pair<gravedad, std::list<paciente>::iterator>> tabla;

    std::set<paciente> recuperado;
public:
    urgencias() : pacientes(MAX_GRAVEDAD), tabla(), recuperado() {}

    void nuevo_paciente(paciente p, gravedad g) {
        if (tabla.count(p) == 1) {
            throw std::domain_error("Paciente repetido");
        }
        else if (g < MIN_GRAVEDAD || g > MAX_GRAVEDAD) {
            throw std::domain_error("Gravedad incorrecta");
        }
        tabla[p] = { g, pacientes[g - 1].insert(pacientes[g - 1].begin(), p) };

    }

    int gravedad_actual(paciente p) const {
        auto it = tabla.find(p);
        if (it == tabla.end()) {
            throw std::domain_error("Paciente inexistente");
        }
        return it->second.first;
    }
    paciente siguiente() {
        if (tabla.empty()) {
            throw std::domain_error("No hay pacientes");
        }
        int i = MAX_GRAVEDAD -1;
        while (pacientes[i].empty()) {
            --i;
        }
        paciente recu = pacientes[i].back();
        pacientes[i].pop_back();
        tabla.erase(recu);
        return recu;
    }

    void mejora(paciente p) {
        auto it = tabla.find(p);
        if (it == tabla.end()) {
            throw std::domain_error("Paciente inexistente");
        }
        gravedad g = it->second.first;
        if (g == MIN_GRAVEDAD) {
            recuperado.insert(it->first);
            pacientes[g - 1].erase(it->second.second);
            tabla.erase(it);
        }
        else {
            it->second.first--;
            pacientes[g - 1].erase(it->second.second);
            --g;
            it->second.second = pacientes[g - 1].insert(pacientes[g - 1].end(), it->first); 
            
        }
    }
    std::vector <paciente> recuperados() {
        std::vector<paciente> recup;
        for (auto it = recuperado.begin(); it != recuperado.end(); ++it) {
            recup.push_back(*it);
        }
        return recup;
    }
};





// No modificar el código a partir de aqui.
// Entrada y salida de datos
bool resuelveCaso() {
    std::string op;
    std::cin >> op;
    if (!std::cin) return false;

    urgencias hospital;
    while (op != "FIN") {
        try {
            if (op == "nuevo_paciente") {
                paciente p;
                gravedad g;
                std::cin >> p >> g;
                hospital.nuevo_paciente(p, g);
            }
            else if (op == "gravedad_actual") {
                paciente p;
                std::cin >> p;
                gravedad g = hospital.gravedad_actual(p);
                std::cout << "La gravedad de " << p << " es " << g << std::endl;
            }
            else if (op == "siguiente") {
                paciente p = hospital.siguiente();
                std::cout << "Siguiente paciente: " << p << std::endl;
            }
            else if (op == "mejora") {
                paciente p; 
                std::cin >> p;
                hospital.mejora(p);
            }
            else if (op == "recuperados") {
                std::vector <paciente> recuperados = hospital.recuperados();
                std::cout << "Lista de recuperados:";
                for (paciente p : recuperados) {
                    std::cout << ' ' << p;
                }
                std::cout << std::endl;
            }
        }
        catch (std::domain_error& e) {
            std::cout << "ERROR: " << e.what() << "\n";
        }
        std::cin >> op;
    }
    std::cout << "---\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

    while (resuelveCaso());

#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
