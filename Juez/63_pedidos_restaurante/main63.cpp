#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>
#include <stdexcept>
#include <list>
#include <string>
#include <vector>

using namespace std;

using mesaPlato = std::pair <int, string>;
class restaurante {
private: 
	std::unordered_map <int, std::map<string, std::list<list<mesaPlato>::iterator>>> mesas;
	std::list < mesaPlato> pedidos;
public:
	void nueva_mesa(int num) {
		auto it = mesas.find(num);
		if (it != mesas.end()) {
			throw std::domain_error("Mesa ocupada");
		}
		mesas[num];
	}
	void nuevo_pedido(int mesa, const string& plato) {
		auto it = mesas.find(mesa);
		if (it == mesas.end()) {
			throw std::domain_error("Mesa vacia");
		}
		std::list<list<mesaPlato>::iterator>& lista = it->second[plato];
		lista.insert(lista.begin(), pedidos.insert(pedidos.begin(), { mesa, plato }));
	}
	void cancelar_pedido(int mesa, const string& plato) {
		auto it = mesas.find(mesa);
		if (it == mesas.end()) {
			throw std::domain_error("Mesa vacia");
		}
		auto pedidosPlato = it->second.find(plato);
		if (pedidosPlato == it->second.end()) {
			throw std::domain_error("Producto no pedido por la mesa");
		}
		list<mesaPlato>::iterator reciente = pedidosPlato->second.front(); //El plato no ha sido servido todavia
		pedidos.erase(reciente);
		pedidosPlato->second.pop_front();//Borro el plato mas reciente
		if (pedidosPlato->second.empty()) {
			it->second.erase(pedidosPlato); //No hay mas pedidos del plato
		}
	}
	pair<int, string> servir() {
		if (pedidos.empty()) {
			throw std::domain_error("No hay pedidos pendientes");
		}
		std::pair <int, string> par = pedidos.back();
		pedidos.pop_back();
		auto it = mesas.find(par.first);
		auto pedidosPlato = it->second.find(par.second);
		pedidosPlato->second.pop_back(); //Borro el ultimo pedido de la lista
		if (pedidosPlato->second.empty()) { //Si ya no quedan mas pedidos lo borro
			it->second.erase(pedidosPlato);
		}
		return par;
	}
	vector<string> que_falta(int mesa) const {
		std::vector<string> faltantes;
		auto it = mesas.find(mesa);
		if (it == mesas.end()) {
			throw std::domain_error("Mesa vacia");
		}
		for (auto iterator : it->second) {
			faltantes.push_back(iterator.first);
		}
		return faltantes;
	}

};

bool resuelveCaso() {
	string orden;
	std::cin >> orden;
	if (!std::cin)
		return false;

	restaurante rest;
	int mesa; 
	std::string plato;

	while (orden != "FIN") {
		try {
			if (orden == "nueva_mesa") {
				cin >> mesa;
				rest.nueva_mesa(mesa);
			}
			else if (orden == "nuevo_pedido") {
				cin >> mesa >> plato;
				rest.nuevo_pedido(mesa, plato);
			}
			else if (orden == "cancelar_pedido") {
				cin >> mesa >> plato;
				rest.cancelar_pedido(mesa, plato);
			}
			else if (orden == "servir") {
				std::pair <int, string> servido = rest.servir();
				cout << servido.second << ' ' << servido.first << endl;
			}
			else if (orden == "que_falta") {
				cin >> mesa; 
				std::vector <string> faltantes = rest.que_falta(mesa);
				cout << "En la mesa " << mesa << " falta:" << endl;
				for (string str : faltantes) {
					cout << "  " << str << endl;
				}
			}
		}
		catch (std::domain_error e) {
			std::cout << "ERROR: " << e.what() << '\n';
		}
		std::cin >> orden;
	}
	std::cout << "---\n";
	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}