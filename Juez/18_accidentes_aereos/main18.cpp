#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;

bool resolver() {
	int casos; 
	cin >> casos; 
	if (!cin) return false; 

	std::stack <pair<string, int>> pila; 
	pair <string, int> aux; 
	for (int i = 0; i < casos; ++i) {
		cin >> aux.first >> aux.second;
		while (!pila.empty() && pila.top().second <= aux.second) {
			pila.pop();
		}
		if (pila.empty()) cout << "NO HAY"; 
		else cout << pila.top().first;
		cout << '\n'; 
		pila.push(aux); 
	}

	cout << "---\n"; 
	return true; 
}

int main() {
#ifndef DOMJUDGE
	ifstream in("sample-18.1.in");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	while (resolver());
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif



	return 0;
}