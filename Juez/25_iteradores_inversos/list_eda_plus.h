#ifndef list_eda_plus_h
#define list_eda_plus_h
#include <stdexcept>
#include <cassert>
#include "list_eda.h"

template <class T>
class list_inverse : public list<T> {
protected: 
	using Nodo = typename list<T>::Nodo;
public: 

	list_inverse(){}

protected: 

	template <class Apunt>
	class ReverseIterator {
		Nodo* act;
		Nodo* fan;
	public: 
		ReverseIterator(): act(nullptr), fan(nullptr){}

		
		
		Apunt & elem() const {
			if (act == fan) throw std::out_of_range("fuera de la lista");
			return act->elem;
		}

		void advance() {
			if(act == fan) throw std::out_of_range("fuera de la lista");
			act = act->ant;
		}
		
		bool operator==(ReverseIterator const& that) const {
			return act == that.act && fan == that.fan;
		}

		bool operator!=(ReverseIterator const& that) const {
			return !(*this == that);
		}
	private: 
		friend class list_inverse;
		ReverseIterator(Nodo* ac, Nodo* fa) : act(ac), fan(fa) {}
	};

public: 
	using iterator = ReverseIterator<T>;

	// devuelve un iterador al principio de la lista
	iterator rbegin() {
		return iterator(this->fantasma->ant, this->fantasma);
	}

	// devuelve un iterador al final del recorrido y fuera de este
	iterator rend() {
		return iterator(this->fantasma, this->fantasma);
	}

	

};


#endif