#include <iostream>
#include <fstream>
#include "set_plus.h"
using namespace std;

bool resolver() {
	int n, m;
	cin >> n >> m;
	if (!cin) return false;
	set_plus<int> conjunto;
	int aux;
	for (int i = 0; i < n; ++i) {
		cin >> aux; 
		conjunto.insert(aux);
	}
	int lower, upper;
	int sol;
	for (int i = 0; i < m; ++i) {
		cin >> lower >> upper;
		sol = conjunto.count_interval(lower, upper);
		cout << sol << endl;
	}
	cout << "---\n";
	return true;
}

int main(){
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