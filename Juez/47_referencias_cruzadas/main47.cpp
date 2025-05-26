#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

void a_minusculas(std::string& str) {
	for (char & c : str) {
		if (isupper(c)) {
			c = tolower(c);
		}
	}
	
}
void mostrar(map <std::string, set<int>> const& tabla) {
	for (auto const& cv : tabla) {
		cout << cv.first;
		set <int> arbol = cv.second;
		for (int i : arbol) {
			cout << ' ' << i;
		}
		cout << endl;
		
	}
	cout << "---\n";
}
bool resolver() {
	int lineas; 
	cin >> lineas; 
	if (lineas == 0) return false;

	map<std::string, set<int>> tabla;
	std::string str; 
	std::getline(std::cin, str);
	for (int i = 0; i < lineas; ++i) {
		std::getline(std::cin, str);
		std::stringstream ss(str);
		std::string aux; 
		while (ss >> aux) {
			if (aux.length() > 2) {
				a_minusculas(aux);
				tabla[aux].insert(i + 1);
			}
			
		}
		
	}
	mostrar(tabla);

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