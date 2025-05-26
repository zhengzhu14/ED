// IMPORTANTE
// Nombre del alumno: Zhengkai Zhu
// Usuario del juez: A73

// Las torres del desierto

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <map>



enum Direccion { Norte, Sur, Este, Oeste };

class Desierto {

public:

    //En esta funcion la operacion de añadir una posicion a tabla es cte.
    //Las operaciones mas costosas es añadir elementos al set de cada x o y en las tablas de abscisas y ordenadas.
    //El caso peor es cuando todos los elementos se encuentran en una misma X o en una misma Y.
    //Ahi agregar un elemento tiene coste O(log(n)) siendo n el numero de elementos
    void anyadir_torre(const std::string& nombre, int x, int y) {
        if (tabla.count(nombre) == 1) { //Coste cte
            throw std::domain_error("Torre ya existente");
        }
        else if (abscisas.count(x) == 1 && abscisas.at(x).count(y) == 1) {
            //En el caso peor donde todas las torres estan en esa x, el coste seria log(n) del numero de torres
            throw std::domain_error("Posicion ocupada");
        }

        tabla[nombre] = { x, y };
        abscisas[x][y] = nombre;
        ordenadas[y][x] = nombre;
    }


    //En esta funcion pasa algo parecido que al anyadir. 
    //En el caso peor el coste es de O(log(n)) en el numero de torres
    void eliminar_torre(const std::string& nombre) {
        if (tabla.count(nombre) == 0) {
            throw std::domain_error("Torre no existente");
        }
        std::pair <int, int> par = tabla[nombre];
        tabla.erase(nombre);
        abscisas[par.first].erase(par.second);
        ordenadas[par.second].erase(par.first);
    }

    //Esta funcion tiene coste constante pues tabla es un unordered_map
    std::pair <int, int> posicion(const std::string& nombre) const {
        if (tabla.count(nombre) == 0) {
            throw std::domain_error("Torre no existente");
        }
        return tabla.at(nombre);
    }

    //Esta funcion tiene coste O(log(n)) en el numero de elementos, para el caso peor que es el mismo para las operaciones anteriores
    //Como estamos buscando un elemento en un mapa ordenado con la operacion
    //abscisas.at(x).count(y).
    std::pair <bool, std::string> torre_en_posicion(int x, int y) const {
        std::pair <bool, std::string> sol = { false, "" };
        if (abscisas.count(x) == 1 && abscisas.at(x).count(y) == 1) {
            sol = { true, abscisas.at(x).at(y) };
        }
        return sol;
    }



    //El caso peor para esta funcion es el mismo para la funcion anyadir, con el elemento del nombre al final del mapa ordenado
    //La operacion find(x) para un mapa ordenado tiene coste log(n) en el numero de torres en el caso peor.
    //Entonces la funcion tiene coste log(n) en el numero de torres
    std::string torre_mas_cercana(const std::string& nombre, const Direccion& dir) const{
        if (tabla.count(nombre) == 0) {
            throw std::domain_error("Torre no existente");
        }
        std::pair<int, int> const & posicion = tabla.at(nombre);
        std::string str = "";
        switch (dir) {
        case Norte: { //Misma x, primer y mayor
            //Empiezo desde el final del map hasta el principio de abscisas.at(x)

            std::map<int, std::string> const& mapa = abscisas.at(posicion.first); 
            //Mapa de las torres que pasan por esa X
            
            auto it = mapa.find(posicion.second);
            ++it;
            if (it != mapa.end()) {
                str = it->second;
            }

            break;
        }
        case Sur: { //Misma x, primer y menor
            //Empiezo desde el principio del map hasta el final de abscisas.at(x)
            std::map<int, std::string> const& mapa = abscisas.at(posicion.first);
            //Mapa de las torres que pasan por esa X
            auto it = mapa.find(posicion.second);
            if (it != mapa.begin()) {
                --it;
                str = it->second;
            }
            
            break;
        }
        case Oeste: { //Misma y, primer x menor
            //Empiezo desde el principio del hasta el final de ordenadas.at(y)
            std::map<int, std::string> const& mapa = ordenadas.at(posicion.second);
            auto it = mapa.find(posicion.first);
            if (it != mapa.begin()) {
                --it;
                str = it->second;
            }
            break;
        }
        case Este: { //Misma y, primer x mayor
            //Empiezo desde el final ..
            std::map<int, std::string> const& mapa = ordenadas.at(posicion.second);
            auto it = mapa.find(posicion.first);
            ++it;
            if (it != mapa.end()) {
                str = it->second;
            }
            break;
        }
        }

        if (str == "") {
            throw std::domain_error("No hay torres en esa direccion");
        }

        return str;
    }
private: 
    //Mapa con el nombre como clave y las posiciones {x, y} como valores
    std::unordered_map <std::string, std::pair<int, int>> tabla; 

    //Mapa para guardas las x como claves y luego un mapa para guardar las torres y las Y de la horizontal
    std::unordered_map<int, std::map<int, std::string>> abscisas;

    //Mapa para guardar las y como claves y luego un mapa para guardar las torres y las X de la vertical
    std::unordered_map <int, std::map<int, std::string>> ordenadas;

};

// Transforma un string en el tipo enumerado Direccion
// Para la llamada a la función torre_mas_cercana
Direccion calculaDir(std::string const& d) {
    if (d == "Sur") return Sur;
    else if (d == "Norte") return Norte;
    else if (d == "Este") return Este;
    else return Oeste;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    std::string op;
    std::cin >> op; // lectura del nombre de la operacion
    if (!std::cin) return false;
    Desierto d;
    while (op != "FIN") { // Lectura de todas las operaciones
        try {
            if (op == "anyadir_torre") {
                std::string nombre; int x, y;
                std::cin >> nombre >> x >> y;
                d.anyadir_torre(nombre, x, y);
            }
            else if (op == "eliminar_torre") {
                std::string nombre;
                std::cin >> nombre;
                d.eliminar_torre(nombre);
            }
            else if (op == "posicion") {
                std::string nombre;
                std::cin >> nombre;
                std::pair<int, int> sol = d.posicion(nombre);
                std::cout << sol.first << ' ' << sol.second << '\n';
            }
            else if (op == "torre_en_posicion") {
                int x, y; std::cin >> x >> y;
                std::pair<bool, std::string> sol = d.torre_en_posicion(x, y);
                if (sol.first)
                    std::cout << "SI " << sol.second << '\n';
                else std::cout << "NO\n";
            }
            else {
                std::string nombre; std::string dir;
                std::cin >> nombre >> dir;
                std::string sol = d.torre_mas_cercana(nombre, calculaDir(dir));
                std::cout << sol << '\n';
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
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    while (resuelveCaso());//Resolvemos todos los casos


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}