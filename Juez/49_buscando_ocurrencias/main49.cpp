#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;



bool resolver() {
	int n, m;
	cin >> n >> m;
	if (!cin) return false;
	map <int, std::vector<int> > tabla; 
	//La clave es el numero y el valor es un vector donde en cada casilla voy guardando el momento que aparece la clave.
	
	int aux;
	for (int i = 0; i < n; ++i) {
		cin >> aux;
		tabla[aux].push_back(i + 1);
	}
	int k, v;
	for (int i = 0; i < m; ++i) {
		cin >> k >> v;
		if (tabla.count(v)== 1 && k <= tabla.at(v).size()) {
			cout << tabla.at(v)[k - 1];
		}
		else {
			cout << "NO HAY";
		}
		cout << endl;
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