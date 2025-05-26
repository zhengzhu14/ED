#include <iostream>
#include <queue>
#include <fstream>


using namespace std;

bool resolver() {
	int numAlumnos;
	int salto;
	cin >> numAlumnos >> salto;
	if (numAlumnos == 0 && salto == 0) return false;
	queue <int> cola;
	for (int i = 0; i < numAlumnos; ++i) {
		cola.push(i + 1);
	}

	int cont = 0;
	while (cola.size() > 1) {
		if (cont != salto) {
			cola.push(cola.front());
		}
		else cont = -1;
		++cont;
		cola.pop();
	}
	if (!cola.empty()) cout << cola.front() << '\n';


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