#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std; 

class comparacion {
public: 
	comparacion() {}
	bool operator () (std::pair <string, int> p, std::pair <string, int> s) {
		return (p.second > s.second) || (p.second == s.second && p.first < s.first);
	}
private: 
	
};

bool resolver() {
	string str; 
	cin >> str;
	if (!cin) return false;
	unordered_map <string, set<string>> tabla;  //clave: deporte, valor: lista de personas
	unordered_map <string, string> apuntados; //clave: nombres, valor: deporte
	string deporte;
	while (str != "_FIN_") {
		if (isupper(str.front())) {
			deporte = str;
			tabla[deporte]; //Agrego clave
		}
		else {
			if ((apuntados.count(str) == 1) && apuntados.at(str) != deporte) {
				tabla.at(apuntados.at(str)).erase(str); //borro de los deportes a los que esta apuntado el alumno.
			}
			else {
				tabla.at(deporte).insert(str); //Inserto al conjunto del deporte un alumno
				apuntados.insert({str, deporte});
			}
		}
		cin >> str;
	}
	
	std::vector<std::pair<string, int>> conteo;
	for (auto it = tabla.begin(); it != tabla.end(); ++it) {
		conteo.push_back({ (*it).first, (*it).second.size() });
	}
	

	std::sort(conteo.begin(), conteo.end(), comparacion());


	for (std::pair <string, int> p : conteo) {
		cout << p.first << ' ' << p.second << endl;
	}
	cout << "---\n";
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resolver());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0; 
}