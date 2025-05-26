#include <iostream>
#include <fstream>
#include "stack_min.h"

using namespace std;


template <typename T> 
void calcular(stack_min<T> &pila, int ops) {
	char operacion; 
	for (int i = 0; i < ops; ++i) {
		cin >> operacion; 
		try {
			switch (operacion) {
			case'A':
				T aux;
				cin >> aux;
				pila.push(aux);
				break;
			case 'D':
				pila.pop();
				break;
			case 'C':
				cout << pila.top() << endl;
				break;
			case 'M':
				cout << pila.min_stack() << endl;
				break;
			}
		}
		catch (std::domain_error de) {
			cout << de.what() << endl; 
		}
		
	}
	cout << "---\n"; 

}

bool resolver() {
	int ops; 
	cin >> ops; 
	if (ops == 0) return false; 
	char tipos; 
	cin >> tipos; 
	if (tipos == 'I') {
		stack_min<int> pila; 
		calcular(pila, ops);
	}
	else {
		stack_min<char> pila; 
		calcular(pila, ops); 
	}

	return true; 
}

int main() {
#ifndef DOMJUDGE
	ifstream in("sample-19.1.in");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	while (resolver());
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif



	return 0;
}