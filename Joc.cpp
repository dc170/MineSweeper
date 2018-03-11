/*
 * Joc.cpp
 *
 *  Created on: 9/5/2015
 *      Author: pau
 */

#include "Joc.h"

using namespace std;

Joc::Joc() {
	a_tauler =  Tauler();
	a_bombes = Tauler();
	a_nbombes = 0;
	a_jugades = 0;
	a_marques = 0;
	a_clliures = 0;
	a_obertes = 0;
}

Joc::~Joc() {
}


void Joc::Inicia(int llavor, int partida) {
	int mida = 0;
	int bombes = 0;
	if(partida == 0){
		mida = 4;
		bombes = 1;
	}
	if(partida == 1){
		mida = 9;
		bombes = 10;
	}
	if(partida == 2){
		mida = 16;
		bombes = 40;
	}
	if(partida == 3){
		mida = 32;
		bombes = 99;
	}
	a_nbombes = bombes;
	a_tauler.Omple(llavor,mida,bombes,a_bombes);
	a_estat="enjoc";
	a_clliures=mida*mida-a_nbombes;
}
void Joc::Acaba() {
	if(a_estat!="guanya"){
	if(a_tauler.MarquesBombes(a_bombes)){
			a_estat="guanya";
	}
	else{
		a_estat="perdut";
	}
	}
	cout << "TAULER FINAL" << endl;
	a_tauler.Mostrar(a_bombes,a_estat);
	cout << endl << "J:" << a_jugades<< " "<<"M:"<<a_marques<< " "<<"B:"<< a_nbombes;
	cout << endl;
	if(a_estat=="guanya"){
		cout << "HAS GUANYAT: ENHORABONA!" << endl;
	}
	else{
		cout << "AQUEST COP NO HAS POGUT GUANYAR!" << endl;
	}
	cout << "FINAL DEL PROGRAMA!" << endl;
	exit(0);
}

bool Joc::ObrirCasella(Posicio p) {
	bool correcte = true;
	int obertes = 0;
	a_jugades++;
	if(!p.Correcte(a_tauler.Mida())){
		cout << "POSICIO FORA DE RANG: " << p << endl;
		correcte = false;
	}
	else{
	if(a_tauler.Jugada(p)){
		cout << "POSICIO JA JUGADA: " << p << endl;
		correcte = false;
	}
	}
	if(correcte){
		if(!a_tauler.ObrirCasella(p,a_bombes,obertes)){
			a_estat="pedut";
			cout << "HI HA UNA BOMBA!" << endl;
			Acaba();
		}
		else{
			if(obertes==1)
				cout << "VEINS DE "<<p<<" AMB BOMBA: " << a_tauler.Numero(p,a_bombes) << endl;
			else
				cout << "S'HAN OBERT "<<obertes-1<<" VEINS DE "<< p << endl;
			a_obertes+=obertes;
			if(a_obertes==a_clliures){
				a_estat="guanya";
				Acaba();
			}
		}
	}
	return correcte;
}

bool Joc::MarcarBomba(Posicio p) {
	bool correcte = true;
	a_jugades++;
	if(!p.Correcte(a_tauler.Mida())){
		cout << "POSICIO FORA DE RANG: " << p << endl;
		correcte = false;
	}
	else if(a_tauler.Jugada(p)){
		cout << "POSICIO JA JUGADA: " << p << endl;
	}
	else{
		//Si esta marcada la desmarca si esta desmarcada la marca
		if(!a_tauler.ConsultaMarca(p))
			a_marques++;
		a_tauler.MarcarBomba(p,true);
	}
	return correcte;
}

void Joc::MostrarTauler() {
	cout << "TAULER DEL JOC"<< endl;
	a_tauler.Mostrar(a_bombes,a_estat);
	cout << endl << "J:" << a_jugades<< " "<<"M:"<<a_marques<< " "<<"B:"<< a_nbombes;
	cout << endl;
}



