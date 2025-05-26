#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
using namespace std; 

bool resolver() {
	int tam;
	cin >> tam;
	if (tam == 0) return false; 
	queue <int> cola; 
	int valor;
	for (int i = 0; i < tam; ++i) {
		cin >> valor; 
		cola.push(valor);
	}

	queue <int> positivos;
	stack<int> negativos;
	for (int i = 0; i < tam; ++i) {
		if (cola.front() < 0) {
			negativos.push(cola.front());
		}
		else {
			positivos.push(cola.front());
		}
		cola.pop();
	}

	while (!negativos.empty()) {
		cola.push(negativos.top()); 
		negativos.pop();
	}
	while (!positivos.empty()) {
		cola.push(positivos.front()); 
		positivos.pop();
	}

	cout << cola.front();
	cola.pop();
	for (int i = 1; i < tam; ++i) {
		cout << ' ' << cola.front(); 
		cola.pop();
	}

	cout << endl;
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	while (resolver());

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE"); 
#endif

	return 0;
}