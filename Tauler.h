/*
 * Tablero.h
 *
 *  Created on: 25/4/2015
 *      Author: pau
 */

#ifndef TAULER_H_
#define TAULER_H_
#include <cstdlib>
#include <string>
#include "Posicio.h"
using namespace std;

class Tauler {
public:
	Tauler();
	virtual ~Tauler();
	void Omple(int llavor, int mida, int bombes, Tauler & a_bombes);
	void Mostrar(Tauler bombes, string estat);

	void alliberarMemoria();
	void reservarMemoria(int mida);
	void copiar(const Tauler &t);
	Tauler & operator =(const Tauler &elem);

	bool ObrirCasella(Posicio p, Tauler bombes, int & obertes);
	void MarcarBomba(Posicio p, bool joc);
	bool Jugada(Posicio p);
	int Mida();
	bool ConsultaMarca(Posicio p);
	int Numero(Posicio p, Tauler bombes);
	void ColocaBomba(Posicio & p);
	bool MarquesBombes(Tauler bombes);

private:
	int a_mida;
	char ** a_taula;

	void Buida();


	void CosTauler(Tauler bombes, string estat, int i);
	//guardarem el numero a la casella
};

#endif /* TAULER_H_ */
