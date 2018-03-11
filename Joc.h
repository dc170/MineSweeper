/*
 * Joc.h
 *
 *  Created on: 9/5/2015
 *      Author: pau
 */

#ifndef JOC_H_
#define JOC_H_
#include "Tauler.h"
class Joc {
public:
	Joc();
	virtual ~Joc();
	void Menu();
	void Inicia(int llavor, int partida);
	void Acaba();
	bool ObrirCasella(Posicio p);
	bool MarcarBomba(Posicio p);
	void MostrarTauler();

private:
	Tauler a_tauler;
	Tauler a_bombes;

	int a_nbombes;
	int a_marques;
	int a_jugades;
	int a_clliures;
	int a_obertes;

	string a_estat;

	void textMenu();
};

#endif /* JOC_H_ */
