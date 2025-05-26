#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

bool resolver() {
	int aux;
	cin >> aux; 
	if (aux == -1) return false;

	std::stack<int> pila; 
	while (aux != -1) {
		while (!pila.empty() && pila.top() <= aux) {
			pila.pop();
		}
		if (pila.empty()) cout << "NO HAY";
		else cout << pila.top();
		cout << endl;
		pila.push(aux); 
		cin >> aux;
	}
	cout << "---\n";


	return true;
}

int main() {
#ifndef DOMJUDGE
	ifstream in("sample-17.1.in");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	while (resolver());

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif



	return 0;
}