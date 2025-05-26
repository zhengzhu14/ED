//Nombre: Zhengkai Zhu
//Juez: A73
//email: zhengzhu@ucm.es

#include <iostream>
#include <fstream>


using namespace std; 


//Sin herencia ---------------------------------------------
//----------------------------------------------------------
#include "bintree_eda.h"
using tSol = pair <int, int>; // first: valor acumulado;  second: numero de nodos acumulados


tSol calcularAcumulados(bintree <int> const& arbol) { 
	if (arbol.empty()) {
		return { 0,0 };
	}
	else {
		tSol iz = calcularAcumulados(arbol.left());
		tSol der = calcularAcumulados(arbol.right());
		int raiz = arbol.root();
		int acumulacion = iz.first + der.first;
		int nAcumulados = iz.second + der.second;
		if (acumulacion == raiz) ++nAcumulados;
		return { acumulacion + raiz, nAcumulados };
	}
}
int acumulados(bintree <int> const& arbol) {
	return calcularAcumulados(arbol).second;
}
void resolver_externo() {
	bintree <int> arbol;
	arbol = leerArbol(-1);
	int sol = acumulados(arbol);
	cout << sol << endl;
}
//-----------------------------------------------------------
//-----------------------------------------------------------



//Con herencia ----------------------------------------------
//-----------------------------------------------------------
#include "bintree_eda_plus.h"
void resolver_heredar() {
	bintree_eda_plus <int>  arbol; 
	arbol = leerArbol_plus(-1);
	int sol = arbol.calcularAcumulados();
	cout << sol << endl; 
}
//-----------------------------------------------------------
//-----------------------------------------------------------

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) {
		//resolver_externo();
		resolver_heredar();
	}

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
