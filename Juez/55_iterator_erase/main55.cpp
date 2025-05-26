// Programa para probar el problema 55 del juez
// Implementar erase con iterador en un hash_map

#include <iostream>
#include <fstream>
#include <cassert>

#include "hashmap_eda.h"

// para asegurarnos de tener listas con más de un elemento
// utilizamos esta función hash que envía todas las claves a
// la posición 0
class Hash_colisionador {
public:
    size_t operator()(int x) const {
        return 0;
    }
};

bool resuelveCaso() {
    int N;
    std::cin >> N;

    if (N == 0)
        return false;

    unordered_map<int, int> tabla;
    unordered_map<int, int, Hash_colisionador> tabla_colisiones;

    // leemos
    int clave;
    for (int i = 0; i < N; ++i) {
        std::cin >> clave;
        tabla[clave] = 0;
        tabla_colisiones[clave] = 0;
    }

    // borramos las claves pares
    int pares = 0;
    auto it = tabla.begin();
    while (it != tabla.end()) {
        if (it->clave % 2 == 0) {
            it = tabla.erase(it);
            ++pares;
        }
        else
            ++it;
    }
    // comprobamos que solamente han quedado claves impares
    int impares = 0;
    for (auto cv : tabla) {
        assert(cv.clave % 2 == 1);
        ++impares;
    }

    assert(pares + impares == N);

    // igual con colisiones aseguradas

    // borramos las claves pares
    auto it_col = tabla_colisiones.begin();
    pares = 0;
    while (it_col != tabla_colisiones.end()) {
        if (it_col->clave % 2 == 0) {
            it_col = tabla_colisiones.erase(it_col);
            ++pares;
        }
        else
            ++it_col;
    }
    // comprobamos que solamente han quedado claves impares
    impares = 0;
    for (auto cv : tabla_colisiones) {
        assert(cv.clave % 2 == 1);
        ++impares;
    }

    assert(pares + impares == N);

    std::cout << "TODO BIEN\n";

    return true;
}

int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
     system("PAUSE");
#endif
    return 0;
}