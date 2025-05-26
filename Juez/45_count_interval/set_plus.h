#ifndef set_plus_h
#define set_plus_h

#include <algorithm>
#include <functional>
#include <stack>
#include <stdexcept>
#include "set_eda.h"


template <class T, class Comparator = std::less<T>>
class set_plus : public set <T, Comparator> {
	using Link = typename set<T, Comparator>::Link;
public:
	set_plus(Comparator p = Comparator()) {
		set<T, Comparator>();
	}
	//Faltaria las demás constructoras


	int count_interval(T const& lower, T const& upper) const {
		return count_interval(lower, upper, this->raiz);
	}

private:
	int count_interval(T const& lower, T const& upper, Link const &raiz) const {
		if (raiz == nullptr) {
			return 0;
		}
		else {
			if (this->menor(upper, raiz->elem)) {
				return count_interval(lower, upper, raiz->iz);
			}
			else if (this->menor(raiz->elem, lower)){
				return count_interval(lower, upper, raiz->dr);
			}
			else { //raiz->elem pertenece [lower, upper]
				int iz = 0;
				if(this->menor(lower, raiz->elem))
					iz = count_interval(lower, upper, raiz->iz);
				int dr = 0;
				if (this->menor(raiz->elem,upper))
					dr = count_interval(lower, upper, raiz->dr);

				int sol = iz + dr + 1;
				return sol;
			}

			/*if (raiz->elem > lower) {
				int iz = count_interval(lower, upper, raiz->iz);
				int der = 0;
				int sol = 0;
				if (raiz->elem < upper) {
					der = count_interval(lower, upper, raiz->dr);
					sol = 1;
				}
				sol += (iz + der);
				return sol;
			}
			else if (raiz->elem < lower) return count_interval(lower, upper, raiz->dr);
			else return 1;*/
		}
	}
};
#endif