// Nombre del alumno: Zhengkai Zhu
// Usuario del Juez: A73

#include <iostream>
#include <iomanip>
#include <fstream>
#include "linked_list_ed_mezcla.h"
using namespace std;



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelver() {
    linked_list_ed_mezcla <int> l1;
    int aux; 
    cin >> aux; 
    while (aux != 0) {
        l1.push_back(aux);
        cin >> aux;
    }

    linked_list_ed_mezcla <int> l2;
    cin >> aux;
    while (aux != 0) {
        l2.push_back(aux);
        cin >> aux;
    }


    l1.merge(l2); //hago que se ordene en l1.
    l1.mostrar();


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    //std::ifstream in("sample-08.1.in");

    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelver();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}