/*

 * main.cpp
 *
 *  Created on: 25/4/2015
 *      Author: pau
 */

#include <iostream>
#include <string>

#include "Joc.h"
#include "Tauler.h"
#include "Posicio.h"


using namespace std;

void TextMenu() {
//Pre: --
//Post: mostra text del menu
	cout << "OPCIONS:" << endl;
	cout << "1: OBRIR UNA CASELLA" << endl;
	cout << "2: MARCAR UNA BOMBA" << endl;
	cout << "3: MOSTRAR EL TAULER" << endl;
	cout << "4: FINALITZAR PARTIDA" << endl;
	cout << "9: MOSTRAR EL MENU D'OPCIONS" << endl;
	cout << "0: SORTIR DEL PROGRAMA" << endl;
}

void ObrirCasella(Joc & partida) {
	Posicio p = Posicio();
	cout << "ENTRA LA CASELLA: " << endl;
	cin >> p;
	partida.ObrirCasella(p);


}

void MarcarBomba(Joc & partida) {
	Posicio p = Posicio();
	cout << "ENTRA LA CASELLA: " << endl;
	cin >>p;
	partida.MarcarBomba(p);
}

void Menu(Joc & partida) {
//Pre: --
//Post: interactuem amb el joc
	int opcio;
	TextMenu();
	cout << "OPCIO:"<<endl;
	cin >> opcio;
	while(opcio!=0){
		if(opcio==1){
			ObrirCasella(partida);
		}
		if(opcio==2){
			MarcarBomba(partida);
		}
		if(opcio==3){
			partida.MostrarTauler();
		}
		if(opcio==4){
			partida.Acaba();
		}
		if(opcio==9){
			TextMenu();
		}
		cout << "OPCIO:" << endl;
		cin >> opcio;
	}
}

void IniciarJoc(Joc & partida) {
//Pre: --
//Post: Generem el tauler
	int llavor = 0;
	int mida = 0;
	cout << "ENTRA LA LLAVOR:" << endl;
	cin >> llavor;
	cout << "ENTRA EL TIPUS DE PARTIDA (0/1/2/3):" << endl;
	cin >> mida;
	while(mida < 0 or mida >3){
		cout << "ENTRA EL TIPUS DE PARTIDA (0/1/2/3):" << endl;
	}
	partida.Inicia(llavor,mida);
}


int main() {
	Joc partida = Joc();
	IniciarJoc(partida);
	Menu(partida);
	return 0;
}


