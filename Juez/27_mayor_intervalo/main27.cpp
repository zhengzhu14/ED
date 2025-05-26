#include <iostream>
#include <fstream>
#include <deque>


using namespace std; 


bool resolver() {
	int n, k;
	cin >> n >> k;
	if (!cin) return false;
	deque <pair<int, int>> cola;
	pair <int, int> aux;
	cin >> aux.first; aux.second = 0;
	cola.push_back(aux);
	for (int i = 1; i < k; ++i) {
		cin >> aux.first; aux.second = i;
		while (!cola.empty() && (aux.first > cola.back().first)) {
			cola.pop_back();
		}
		cola.push_back(aux);
	}
	cout << cola.front().first;

	for (int i = k; i < n; ++i) {
		cin >> aux.first; aux.second = i;
		while (!cola.empty() && (aux.first > cola.back().first)) {
			cola.pop_back();
		}
		cola.push_back(aux);
		if ((i - cola.front().second) >= k) cola.pop_front();
		cout << ' ' << cola.front().first;
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
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}