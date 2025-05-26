#ifndef polinomio_h
#define polinomio_h
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

using tPair = pair<int, int>; //first: exp, second: coef

class polinomio {
public:

	polinomio (){
		std::vector<tPair> aux(0);
		v = aux;
	}


	void addElem(tPair monomio) {
		if (monomio.second != 0) {
			int i = 0;
			while (i < v.size() && monomio.first > v[i].first) {
				++i;
			}

			if (i < v.size()) {
				if (monomio.first == v[i].first) {
					v[i].second += monomio.second;
					if (v[i].second == 0) {
						v.erase(v.begin() + i);
					}
				}
				else {
					v.insert(v.begin() + i, monomio);

				}
			}
			else {
				v.push_back(monomio);
			}
		}

	}

	long long int evaluar(int n) {
		long long int x = 1;
		long long int valor = 0;
		int j = 1;
		for (int i = 0; i < v.size(); ++i) {
			while (j <= v[i].first) { // calcula el valor x al elevarlo hasta el exponente que nunca superara el grado del polinomio
				x *= n;
				++j;
			}
			valor += (x * v[i].second);
		}
		return valor;
	}


private:
	std::vector<tPair> v;


};

inline std::istream& operator >> (istream& in, polinomio& p) {
	tPair m;
	in >> m.second >> m.first;
	//if (in) {
		while (m.first != 0 || m.second != 0) {
			p.addElem(m);
			in >> m.second >> m.first;
		}

	//}
	return in;
}


#endif
