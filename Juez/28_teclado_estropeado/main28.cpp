#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

bool esEspecial(char c) {
	return c == '-' || c == '*' || c == '+' || c == '3';
}

bool resolver() {
	string str;
	getline(std::cin, str);
	if (!cin) return false;
	list<char> lista;
	auto it = lista.begin();
	for (int i = 0; i < str.length(); ++i) {
		if (!esEspecial(str[i])) {
			lista.insert(it, str[i]);
		}
		else {
			if (str[i] == '3') {
				if (it != lista.end()) {
					it = lista.erase(it);
				}
			}
			else {
				switch (str[i]) {
				case '-': it = lista.begin();
					break;
				case '+': it = lista.end();
					break;
				default: 
					if (it != lista.end()) ++it;
					break;
				}
			}
		}
	}

	for (it = lista.begin(); it != lista.end(); ++it) {
		cout << *it;
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
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}