#include <iostream>
#include <fstream>
#include <list>
using namespace std;

bool resolver() {
	list<int> lista; 
	int num; 
	cin >> num; 
	if (!cin) return false; 

	while (num != 0) {
		lista.push_front(num); 
		cin >> num;
	}
	for (auto it = lista.begin(); it != lista.end(); ++it) {
		lista.insert(it, *it); 
	}
	for (auto it = lista.rbegin(); it != lista.rend(); ++it) {
		cout << *it << ' '; 
	}
	cout << endl;
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resolver());

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}