#include <iostream>
#include <fstream>
#include "list_eda_plus.h"

using namespace std;


void resolver() {
	list_inverse <int> list;
	int num; 
	cin >> num; 
	while (num != 0) {
		list.push_back(num);
		cin >> num;
	}

	for (auto it = list.rbegin(); it != list.rend(); it.advance()) {
		cout << it.elem() << ' ';
	}
	cout << endl;

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt"); 
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int casos; 
	cin >> casos; 
	for (int i = 0; i < casos; ++i) resolver();

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf); 
	system("PAUSE");
#endif

	return 0;
}