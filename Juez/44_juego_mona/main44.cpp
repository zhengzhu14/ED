#include <iostream>
#include <fstream>
#include <vector>
#include "set_eda.h"

using namespace std;

bool resolver() {
	int n, m;
	cin >> n >> m; 
	if (!cin) return false;
	std::vector <set<int>> jugadores(n);
	int aux;
	for (int i = 0; i < m; ++i) {
		cin >> aux;
		int jug = i % n;
		if (!jugadores[jug].erase(aux)) {
			jugadores[jug].insert(aux);
		}
	}
	
	for (int i = 0; i < n; ++i) {
		cout << "J" << i + 1 << ": {";
		auto iterator = jugadores[i].begin();
		if (iterator != jugadores[i].end()) {
			cout << *iterator;
			++iterator;
			while (iterator != jugadores[i].end()) {
				cout << ", " << *iterator;
				++iterator;
			}
		}
		
		cout << "}\n";
	}
	cout << "---\n"; 
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