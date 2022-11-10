#include <iostream>

using std::string;

namespace stefani_datastructure {
	class Link {

	private:
		string value_;
		Link* prev_;
		Link* succ_;

	public:
		Link(const string& value, Link* p = nullptr, Link* s = nullptr)
			: value_{ value }, prev_{ p }, succ_{ s } {}

		// Funzione insert: inserisce il node prima del previous_node
		// Utilizzo: miaLista = insert(miaLista, nodoNuovo) ????
		Link* insert(Link* previous_node, Link* node);

		// Funzione insert: inserisce il node dopo del next_node
		Link* add(Link* next_node, Link* node);

		// Funzione erase: rimuove il node
		Link* erase(Link* node);

		// Funzione find: trova un nodo con un certo valore
		Link* find(Link* node, string& value);

		// Funzione advance: trova il successivo di un nodo
		Link* advance(Link* node);

	};

	
}

