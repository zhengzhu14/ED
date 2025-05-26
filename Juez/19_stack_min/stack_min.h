#ifndef stack_min_h
#define stack_min_h

#include <stack>
#include <stdexcept>  // std::domain_error


template <typename T>
class stack_min {
public: 

	stack_min() {}
	stack_min(stack_min<T> const& other) {
		copia(other); 
	}
	~stack_min() {}
	stack_min<T>& operator=(stack_min<T> const& other) {
		if (this != &other) {
			copia(other);
		}
		return *this;
	}

	T const & min_stack() const {
		if (empty()) {
			throw std::domain_error("ERROR: Pila vacia");
		}
		return minimos.top();

	}

	void push(T const& elem) {
		pila.push(elem);
		T aux = elem;
		if (!minimos.empty()) {
			if (aux >= minimos.top()) aux = minimos.top();
		}
		minimos.push(aux);
	}


	T const& top() const {
		if (empty()) {
			throw std::domain_error("ERROR: Pila vacia");
		}
		return pila.top();
	}

	void pop() {
		if (empty()) {
			throw std::domain_error("ERROR: Pila vacia");
		}
		pila.pop();
		minimos.pop();
	}

	bool empty() const {
		return pila.empty();
	}

	int size() {
		return pila.size();
	}


protected: 
	std::stack<T> pila; 
	std::stack<T> minimos;

	void copia(stack_min <T>  const & other) {
		pila = other.pila; 
		minimos = other.minimos; 
	}

};

#endif