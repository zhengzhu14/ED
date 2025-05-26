#ifndef set_plus_h
#define set_plus_h
#include <algorithm>
#include <functional>
#include <stack>
#include <stdexcept>
#include <iostream>
#include "set_eda.h"


template <class T, class Comparator = std::less<T>>
class set_plus : public set <T, Comparator> {
	using Link = typename set<T, Comparator>::Link;
public: 
	set_plus(Comparator p = Comparator()) {
		set<T, Comparator>();
	}

	std::pair<bool, T> lower_bound(T const& e) const {
		std::pair <bool, T> sol = { false, 0 };
		lower_bound(e,this->raiz, sol);
		return sol;
	}

private:
	void lower_bound(T const& e, Link a, std::pair<bool, T>& sol) const {
		if (a != nullptr) {
			if (a->elem >= e) {
				sol.first = true;
				sol.second = a->elem;
				lower_bound(e, a->iz, sol);
			}
			else {
				lower_bound(e, a->dr, sol);
			}
		}
	}

};


#endif