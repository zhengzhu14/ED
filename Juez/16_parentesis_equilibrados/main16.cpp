#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std; 


// c == '[' || c == '(' || c == '{';
// c == ']' || c == ')' || c == '}';

bool resolver() {
	std::string str; 
	std::getline(std::cin, str);
	if (!cin) {
		return false;
	}

	std::stack<char> parentesis;
	
	bool correcto = true;
	
	int i = 0; 
	char c; 
	while (i < str.length() && correcto) {
		c = str[i];
		if (c == '[' || c == '(' || c == '{') parentesis.push(c);
		else if (c == ']' || c == ')' || c == '}') {
			if (parentesis.empty()) correcto = false;
			else {
				switch (c) {
				case ')':
					if (parentesis.top() == '(') parentesis.pop();
					else correcto = false;
					break;
				case ']': 
					if (parentesis.top() == '[') parentesis.pop();
					else correcto = false;
					break;
				case '}': 
					if (parentesis.top() == '{') parentesis.pop();
					else correcto = false;
					break;
				}
			}
		}
		++i;
	}

	if (!parentesis.empty()) correcto = false;

	if (correcto) cout << "SI";
	else cout << "NO";
	cout << endl;

	return true; 
}

int main() {
#ifndef DOMJUDGE
	ifstream in("datos.txt"); 
	//ifstream in("sample-16.1.in");

	auto cinbuf = cin.rdbuf(in.rdbuf()); 
#endif

	while (resolver()); 

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif 
	return 0;
}