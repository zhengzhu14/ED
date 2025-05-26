// IMPORTANTE
// Nombre del alumno: Zhengkai Zhu
// Usuario del juez: A73


// Elecciones presidenciales

#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <stdexcept>
#include <unordered_map>
#include <map>
#include <set>


using namespace std;

class ConteoVotos {
    using mapStringInt = unordered_map<string, int>;
    using parVotos = std::pair <string, int>;
private:
    mapStringInt compromisarios;
    unordered_map<string, std::pair<int, mapStringInt>> votos; //Clave: partido, valor: par<num_compromisarios, mapa estado/votos>
    unordered_map<string, parVotos> mayoriasEstado;
    std::set<std::string> ganadores;
public:
    ConteoVotos(): compromisarios(), votos(), mayoriasEstado(), ganadores(){}
    ~ConteoVotos(){}

    void nuevo_estado(const string& nombre, int num_compromisarios) {
        if (compromisarios.count(nombre) == 1) {
            throw std::domain_error("Estado ya existente");
        }
        compromisarios[nombre] = num_compromisarios;
        mayoriasEstado[nombre] = { "", -1 };

    }
    void sumar_votos(const string& estado, const string& partido, int num_votos) {
        if (compromisarios.count(estado) == 0) {
            throw std::domain_error("Estado no encontrado");
        }

        std::pair <int, mapStringInt>& aux = votos[partido];
        aux.second[estado] += num_votos;
        int v = aux.second[estado];

        std::pair <string, int> &old_winner = mayoriasEstado[estado]; //Nombre, votos

        if (v > old_winner.second) { //El partido actual ha obtenido mas votos
            int compro_ganados = compromisarios[estado]; //Compromisario que va a ganar el partido.
            if (old_winner.first != partido) {
                aux.first += compro_ganados;
                ganadores.insert(partido);
                if (old_winner.second > 0) { //Pregunto si los votos del anterior ganador es menor que 0,
                                            //Si es menor que cero es porque es el caso inicial, cuando todavia no hubo ganadores
                    std::pair<int, mapStringInt>& anterior = votos[old_winner.first];
                    anterior.first -= compro_ganados;
                    if (anterior.first == 0) {
                        ganadores.erase(old_winner.first);
                    }

                }
            }
            old_winner = { partido, v }; //Actualizo el old winner por el nuevo ganador
        }













        //std::pair<int, mapStringInt> & aux = votos[partido];
        //aux.second[estado] += num_votos;
        //int v = aux.second[estado];
        //std::pair<string, int>& old = mayoriasEstado[estado]; //Anterior ganador
        //if (v > old.second) {
        //    int compro_ganados = compromisarios[estado];
        //    aux.first += compro_ganados;
        //    if (old.first != partido) {
        //        ganadores.insert(partido);
        //        std::pair<int, mapStringInt>& anterior = votos[old.first];
        //        anterior.first -= compro_ganados;
        //        if (anterior.first == 0) {
        //            ganadores.erase(old.first);
        //        }
        //    }
        //    old = { partido, v };
        //}
    }
    string ganador_en(const string& estado) const {
        if (compromisarios.count(estado) == 0) {
            throw std::domain_error("Estado no encontrado");
        }
        return mayoriasEstado.at(estado).first;
    }
    vector<pair<string, int>> resultados() const {
        vector<pair<string, int>> sol;
        for (string str : ganadores) {
            sol.push_back({ str, votos.at(str).first });
        }
        return sol;
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    std::string op;
    std::cin >> op; // lectura del nombre de la operacion
    if (!std::cin) return false;
    ConteoVotos cv;
    while (op != "FIN") { // Lectura de todas las operaciones
        try {
            if (op == "nuevo_estado") {
                std::string nombre; int num_compromisarios;
                std::cin >> nombre >> num_compromisarios;
                cv.nuevo_estado(nombre, num_compromisarios);
            }
            else if (op == "sumar_votos") {
                std::string estado, partido;
                int num_votos;
                std::cin >> estado >> partido >> num_votos;
                cv.sumar_votos(estado, partido, num_votos);
            }
            else if (op == "ganador_en") {
                std::string estado;
                std::cin >> estado;
                std::string sol = cv.ganador_en(estado);
                std::cout << "Ganador en " << estado << ": " << sol << '\n';
            }
            else if (op == "resultados") {
                std::vector<std::pair<std::string, int>> sol = cv.resultados();
                for (std::pair<std::string, int> const& s : sol)
                    std::cout << s.first << ' ' << s.second << '\n';
            }
        }
        catch (std::domain_error const& e) {
            std::cout << e.what() << '\n';
        }
        std::cin >> op;
    }
    std::cout << "---\n";
    return true;

}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());//Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}


