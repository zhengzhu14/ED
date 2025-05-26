//******************************************************
// IMPORTANTE
// NOMBRE Y APELLIDOS DEL ALUMNO: Zhengkai Zhu
// USUARIO DEL JUEZ DE ESTE EXAMEN: A73
// LABORATORIO Y PUESTO: Lab 2, puesto 9
//******************************************************

// Explicación de la representación empleada. 
/*
He utilizado un unordered_map para guardar la informacion de la obra, artista, precio mas un iterador a la lista de obras que
va a servir como una cola para saber que obras llevan mas tiempo en la galeria.
El iterador nos servira para borrar con coste constante de la lista de obras cuando se venden. 

Luego he utilizado un entero para guardar el dinero maximo que han vendido artistas
Un unordered_map para guardar el dinero han vendido cada artista.
Luego un set (ordenado) para guardar en orden alfabetico los artistas que han vendido tanto dinero como el dinero maximo

*/



// Indicar el coste de cada método en un comentario al principio del método.





#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector> 
#include <set>
#include <unordered_map>
#include <list>


// añade las librerías de la STL que necesites



using artista = std::string;
using obra = std::string;

// Elige el tipo representante adecuado para el TAD GaleriaArte e
// implementa sus operaciones. Puedes añadir métodos o funciones privadas
// si lo consideras conveniente. Justifica la elección de los tipos y el
// coste de las operaciones.

class galeriaArte {

    // escribe aquí los atributos privados
    struct tDatos {
        artista a;
        int precio;
        std::list<obra>::iterator o;
    };
    std::unordered_map <obra, tDatos>  tabla; //tabla donde guardare como clave la obra, y como valor el artista, precio y
                                              //iterador a la lista donde voy a guardar las obras y saber cual lleva mas tiempo


    std::list<obra> obras; //lista de obras donde guardo las obras y asi saber cuales llevan más tiempo;


    //informacion para saber quienes han vendido mas en la galeria
    int dineroMaximo = 0;
    std::unordered_map<artista, int> vendidos; //tabla para saber lo que ha vendido cada artista;
    std::set <artista> artistasMasVendidos;


public:
    galeriaArte() {}


    //La funcion .count() y el operador [] tienen coste O(1) respecto del numero de elementos de la tabla al ser una tabla hash
    //Por tanto la funcion tiene coste O(1)
    void nueva_obra(obra const& c, artista const& a, int p) {
        if (tabla.count(c) == 1) {
            throw std::invalid_argument("Obra ya en la galeria");
        }

        tabla[c] = { a, p, obras.insert(obras.begin(), c) }; //inserto en la tabla la informacion;

    }

    //En esta funcion todas las funciones tienen coste constante excepto la funcion inset() del set artistasMasVendidos
    //El coste de la funcion insert() es O(log(m)) siendo m el numero de artistas que tienen obras en la galeria.
    //En el caso peor, todos los artistas que tienen obras en la galeria estan en el conjunto.
    void venta_obra(obra const& c) {
        auto it = tabla.find(c);
        if (it == tabla.end()) { //Compruebo si existe la obra
            throw std::invalid_argument("Obra no existente");
        }
        obras.erase(it->second.o); //Primero borro del la lista de obras la obra.


        vendidos[it->second.a] += it->second.precio;
        int venta = vendidos[it->second.a]; //Miro cuanto ha vendido.
        if (venta == dineroMaximo) {
            artistasMasVendidos.insert(it->second.a);
        }
        else if(venta > dineroMaximo) {
            dineroMaximo = venta; //Establezco el nuevo maximo.
            artistasMasVendidos.clear();
            artistasMasVendidos.insert(it->second.a);
        }

        tabla.erase(it); //Borro de la tabla principal

    }

    //Como esta funcion tenemos que recorrer todo el set de artistas, el coste de la funcion es O(m) 
    //m es el numero de artistas que hay registrados en la galeria de arte (en el caso peor, estarian todos)
    std::vector<artista> mas_vendidos() const {
        std::vector<artista> artistas;
        
        for (auto it = artistasMasVendidos.begin(); it != artistasMasVendidos.end(); ++it) {
            artistas.push_back(*it);
        }

        return artistas;
    }

    //El coste de la funcion es O(n) siendo n el numero de obras que hay en la galeria.
    //El caso peor k == tabla.size(). Entonces se tendria que anyadir todas las obras de la galeria, por eso el O(n)
    std::vector<obra> obras_por_antiguedad(int k) const {
        std::vector<obra> antiguos;
        auto it = obras.rbegin(); //empiezo desde el final que es donde estan las que mas tiempo estan
        while (it != obras.rend() && k > 0) {
            antiguos.push_back(*it);
            ++it;
            --k;
        }

        return antiguos;
    }
};





// No modificar el código a partir de aqui.
// Entrada y salida de datos
bool resuelveCaso() {
    std::string op;
    std::cin >> op;
    if (!std::cin) return false;

    galeriaArte galeria;
    while (op != "FIN") {
        try {
            if (op == "nueva_obra") {
                obra c; artista a; int p;
                std::cin >> c >> a >> p;
                galeria.nueva_obra(c, a, p);
            }
            else if (op == "venta_obra") {
                obra c;
                std::cin >> c;
                galeria.venta_obra(c);
            }
            else if (op == "mas_vendidos") {
                std::vector<artista> sol = galeria.mas_vendidos();
                std::cout << "Los artistas que mas han vendido son:\n";
                for (auto n : sol) std::cout << n << '\n';
            }
            else if (op == "obras_por_antiguedad") {
                int k;
                std::cin >> k;
                std::vector<obra> v = galeria.obras_por_antiguedad(k);
                std::cout << "Obras mas antiguas en la galeria:\n";
                for (obra o : v) std::cout << o << '\n';
            }
        }
        catch (std::invalid_argument& e) {
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
