#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <stack>
using namespace std; 


bool esVocal(char aux) {
	return aux == 'a' || aux == 'A' || aux == 'e' || aux == 'E' || aux == 'i' || aux == 'I'
		|| aux == 'o' || aux == 'O' || aux == 'u' || aux == 'U';
}
bool resolver() {
	string str;
	getline(std::cin, str);
	if (!cin) return false;
	deque<char> dcola;
	for (int i = str.length() - 1; i >= 0; --i){
		if (i % 2 == 0) dcola.push_front(str[i]);
		else dcola.push_back(str[i]);
	}

	stack<char> auxiliar;
	int numElem = (int)dcola.size();
	for (int i = 0; i < numElem; ++i) {
		if (esVocal(dcola.front())) {
			while (!auxiliar.empty()) {
				dcola.push_back(auxiliar.top());
				auxiliar.pop();
			}
			dcola.push_back(dcola.front());
		}
		else {
			auxiliar.push(dcola.front());
		}
		dcola.pop_front();

	}
	//desapilo las ultimas consonantes si las hay
	while (!auxiliar.empty()) {
		dcola.push_back(auxiliar.top());
		auxiliar.pop();
	}



	for (int i = 0; i < numElem; ++i) {
		cout << dcola.front();
		dcola.pop_front();
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
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}