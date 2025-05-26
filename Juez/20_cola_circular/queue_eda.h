#ifndef queue_eda_h
#define queue_eda_h
#include <stdexcept>  // std::domain_error
#include <utility>


template <typename T>
class queue {
protected: 
	static const int TAM_INICIAL = 10;
	size_t capacidad;
	size_t first;
	size_t last;
	size_t nelems;
	T* array;
	

public:
	queue() :capacidad(TAM_INICIAL), first(0), last(-1), nelems(0) , array(new T[capacidad]) {}
	~queue() {
		libera();
	}
	queue(queue <T> const& other) {
		libera(); 
		copia(other);
	}
	queue<T>& operator =(queue <T> const& other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}


	void push(T const &elem) {
		array[(last + 1)%capacidad] = elem;
		last = (last + 1)%capacidad;
		++nelems;
		if (nelems == capacidad)
			amplia();
	}

	T const & front() const {
		if (empty())
			throw std::domain_error("la cola vacia no tiene primer elemento");
		return array[first];

	}

	void pop() {
		if (empty())
			throw std::domain_error("la cola esta vacia");
		first = (first + 1)%capacidad;
		--nelems;
	}

	bool empty() const {
		return nelems == 0;
	}

	// consultar el tamaño de la pila
	size_t size() const {
		return nelems;
	}


private:
	void libera() {
		delete[] array;
	}
	void copia(queue <T> const& other) {
		capacidad = other.capacidad + TAM_INICIAL;
		nelems = other.nelems;
		array = new T[capacidad];
		for (size_t i = 0; i < nelems; ++i) {
			array[i] = other.array[(other.first + i)%other.capacidad];
		}
	}

	void amplia() {
		T * viejo = array;
		size_t oldCapacity = capacidad;
		capacidad *= 2; 
		array = new T[capacidad];
		for (size_t i = 0; i < nelems; ++i) {
			array[first + i] = std::move(viejo[(first + i) % oldCapacity]);
		}
		last = first + nelems - 1;
		delete[] viejo;
	}
};


#endif