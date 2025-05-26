#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

void mostrar(map <std::string, int> const& tabla) {
	for (auto const& cv : tabla) {
		cout << cv.first << ", " << cv.second << endl;
	}
	cout << "---\n";
}

bool resolver() {
	int n;
	cin >> n;
	if (n == 0) return false; 
	map <std::string, int> tabla;
	std::string alumno;
	std::string correccion;
	getline(std::cin, alumno);
	for (int i = 0; i < n; ++i) {
		getline(std::cin, alumno);
		getline(std::cin, correccion);
		if (correccion == "CORRECTO") {
			++tabla[alumno];
		}
		else {
			--tabla[alumno];
		}
		if (tabla[alumno] == 0) {
			tabla.erase(alumno);
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