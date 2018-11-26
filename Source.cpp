#include <iostream>
#include "queue_extend.h"
#include "horas.h"
using namespace std;

bool resuelveCaso() {
	int numElem;
	horas aux;
	cin >> numElem;
	if (numElem == 0)return false;
	QueueElim <horas> r;
	for (int i = 0; i < numElem; i++) {
		cin >> aux;
		r.push(aux);
	}
	r.borrarDecrec();
	r.print(); // falta ver como imprimo
	return true;
}

int main() {
	while (resuelveCaso()) {}
}