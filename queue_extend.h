
#include "queue_eda.h"
#include <iostream>
using namespace std;
template <class T>
class QueueElim : public queue<T> {

	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí

public:


	void print(ostream & o=cout) const {
		if (this->empty()) { o << '\n'; }
		else {
			Nodo * aux = this->prim;
			Nodo *fin = this->ult;
			while (aux != fin) {
				o << aux->elem << ' ';
				aux = aux->sig;

			}
			o << fin->elem << '\n';
		}
	}

	void borrarDecrec() {
		Nodo *act = this->prim;
		Nodo *aux = act -> sig;
		Nodo *aux2;
		while (aux != nullptr){
			if (aux->elem < act->elem) {
				aux2 = aux;
				act->sig = aux;
				aux = aux->sig;
				delete aux2;
			}
			else {
				aux = aux->sig;
				act = act->sig;
			}
		}
		this->ult = act;
	
	}
	void pares() {
		Nodo *act = this->prim;
		Nodo *aux = act->sig;
		while (aux != nullptr) {
			this->ult = act;
			act->sig = aux->sig;
			act = aux->sig;
			delete aux;
			if (act == nullptr)aux = act;
			else {
				this->ult = act;
				aux = act->sig; }
		
		}
	}

};