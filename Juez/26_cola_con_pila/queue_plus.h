#ifndef queue_plus_h
#define queue_plus_h

#include <stdexcept>  // std::domain_error
#include <stack> 
using namespace std;

template <class T>
class queue_plus {
protected:

    stack<T> principal;
    stack<T> secundario; 
    size_t nelems;


public:

    // constructor: cola vacía
    queue_plus() {
        nelems = 0;
    }


    // añadir un elemento al final de la cola
    void push(T const& elem) {

        principal.push(elem);
        ++nelems;
 
    }

    // consultar el primero de la cola
    T const& front() {
        if (empty())
            throw std::domain_error("la cola vacia no tiene primero");

        if (secundario.empty()) {
            cambiarCola();
        }
       
        return secundario.top();


    }

    // eliminar el primero de la cola
    void pop() {
        if (empty())
            throw std::domain_error("eliminando de una cola vacia");
        if (secundario.empty()) {
            cambiarCola();
        }
        secundario.pop();
        --nelems;
    }

    // consultar si la cola está vacía
    bool empty() const {
        return nelems == 0;
    }

    // consultar el tamaño de la cola
    size_t size() const {
        return nelems;


    }

private: 
    void cambiarCola() {
        while (!principal.empty()) {
            secundario.push(principal.top());
            principal.pop();
        }
    }
};

#endif // queue_eda_h