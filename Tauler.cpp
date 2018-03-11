/*
 * Tablero.cpp
 *
 *  Created on: 25/4/2015
 *      Author: pau
 */

#include "Tauler.h"
#include "Posicio.h"
#include "CuaPosicions.h"
#include <iostream>
using namespace std;
Tauler::Tauler() {
	a_mida=0;
	a_taula=NULL;
}

Tauler::~Tauler() {
	//alliberarMemoria();
}

void Tauler::Omple(int llavor, int mida, int nbombes, Tauler & a_bombes) {
	a_mida = mida;
	a_taula=new char*[mida];
	reservarMemoria(mida);
	a_bombes.reservarMemoria(a_mida); //reservem memoria als 2 taulers
	Buida();
	a_bombes.Buida();
	Posicio p = Posicio();
	p.iniLlavor(llavor);
	int bombesAfegides = 0;
	while(bombesAfegides<nbombes){
		a_bombes.ColocaBomba(p);
		bombesAfegides++;
	}
}

void Tauler::alliberarMemoria()
{
    //Pre:cert
    //Post:elimina el tauler
    if(a_taula != NULL)
    {
        for(int i=0; i<a_mida; i++)
        {
            delete [] a_taula[i];
        }
        delete [] a_taula;
    }

}

void Tauler::copiar(const Tauler &t)
{
    //pre:tauler
    //post: copia el tauler
    a_mida=t.a_mida;
    for(int i=0; i<a_mida; i++)
    {
        for(int j=0; j<a_mida; j++)
        {
            a_taula[i][j]=t.a_taula[i][j];
        }
    }
}
Tauler & Tauler::operator=(const Tauler &t)
{
    if(this!=&t)
    {
        alliberarMemoria();
        reservarMemoria(t.a_mida);
        copiar(t);
    }
    return *this;
}


void Tauler::reservarMemoria(int mida)
{
	a_mida = mida;
    a_taula=new char*[mida];
    for(int i=0; i<mida; i++)
    {
        a_taula[i]=new char[mida];
    }
}

void Tauler::Mostrar(Tauler bombes, string estat) {
	if(a_mida>=10)
		cout << "     ";
	else
		cout << "    ";
	for(int n = 0; n<a_mida;n++){
		if(n+1>=10)
			cout << n;
		else
			cout << n << " ";
	}
	cout << endl;
	if(a_mida>=10)
		cout << "   +";
	else
		cout << "  +";
	for(int n = 0; n<a_mida-1;n++){
			cout << "--";
		}
	cout << "--+";
	cout << endl;
	for(int i = 0; i<a_mida; i++){
		if(a_mida>=10){
			if(i<10)
				cout << " " << i << " " << "|";
			else
				cout << i << " " << "|";
		}
		else
			cout << i << " " << "|";
		CosTauler(bombes,estat,i);

		cout << "|";
		cout << endl;
	}
	if(a_mida>=10)
			cout << "   +";
		else
			cout << "  +";
		for(int n = 0; n<a_mida;n++){
				cout << "--";
			}
	cout << "+";
}

int Tauler::Numero(Posicio p, Tauler bombes) {
	int res = 0;
	const Posicio veins[] = {Posicio(-1,-1),
		Posicio(-1,0), Posicio(-1,1), Posicio(0,-1),
		Posicio(0,1), Posicio(1,-1), Posicio(1,0),
		Posicio(1,1)};
	for(int i=0;i<8;i++){
				if((p+veins[i]).Correcte(a_mida) and bombes.ConsultaMarca(p+veins[i])){
					res++;
					//cout << (p+veins[i]);
				}
			}
	return res;
}

void Tauler::CosTauler(Tauler bombes, string estat, int i){
	for(int j = 0; j<a_mida; j++) {
		Posicio p = Posicio(i,j);
		if(estat=="enjoc"){
			if(a_taula[i][j]=='m'){
				cout << " " << "M";
			}//Mostrem el que toca, numero o espai, les bombes van a l'altre taula
			else{
				cout << " " << a_taula[i][j];
			}
		}
		else {//Si sacaba la partida
			if(a_taula[i][j]=='m' and bombes.ConsultaMarca(p)){
				cout << " " << "M";
			}
			if(a_taula[i][j]=='m' and !bombes.ConsultaMarca(p)){
				cout << " " << a_taula[i][j];
			}
			if(a_taula[i][j]==' ' and bombes.ConsultaMarca(p)){
				cout << " " << "b";
			}
			else if(a_taula[i][j]!='m'){
				cout << " " << a_taula[i][j];
			}
		}
	}
}



bool Tauler::ConsultaMarca(Posicio p) {
	int x = p.obtX();
	int y = p.obtY();
	return a_taula[x][y]=='m';
}

void Tauler::Buida() {
	for(int i = 0; i<a_mida; i++){
			for(int j = 0; j<a_mida; j++) {
				a_taula[i][j] = ' ';
			}
		}
}

void Tauler::ColocaBomba(Posicio & p) {
	p.aleatoria(a_mida);
	if(p.Correcte(a_mida) and !ConsultaMarca(p)){
		MarcarBomba(p,false);
	}
	else{
		ColocaBomba(p);
	}
}

bool Tauler::ObrirCasella(Posicio p, Tauler bombes, int & obertes) {
	bool estat = true;
	CuaPosicions cua = CuaPosicions();
	const Posicio veins[] = {Posicio(-1,-1),
	Posicio(-1,0), Posicio(-1,1), Posicio(0,-1),
	Posicio(0,1), Posicio(1,-1), Posicio(1,0),
	Posicio(1,1)};
	if(bombes.ConsultaMarca(p)){
		a_taula[p.obtX()][p.obtY()]='B';
		estat = false;
	}
	else{
		if(!Jugada(p)){
			char c = (char) Numero(p,bombes)+'0';
			a_taula[p.obtX()][p.obtY()]= c;
			obertes++;
		    estat = true;

		if(c=='0'){
		for(int i=0;i<8;i++){
			if((p+veins[i]).Correcte(a_mida) and !Jugada(p+veins[i])){
				cua.encua((p+veins[i]));
				//cout << (p+veins[i]);
			}
		}
		while(!cua.buida()){
			//cout << cua.primer();
			ObrirCasella(cua.primer(),bombes,obertes);
			cua.desencua();
		}
	}
	}
	}
	return estat;
}

void Tauler::MarcarBomba(Posicio p, bool joc = true) {
	int x = p.obtX();
	int y = p.obtY();
	if(joc){
	if(a_taula[x][y]=='m'){
		cout << "ES DESMARCA LA POSICIO: " << p << endl;
	}
	else{
		cout << "ES MARCA LA POSICIO: " << p << endl;
	}
	}
	if(a_taula[x][y]=='m'){
		a_taula[x][y]=' ';
	}
	else{
		a_taula[x][y]='m';
	}
}


int Tauler::Mida() {
	return a_mida;
}

bool Tauler::Jugada(Posicio p) {
	bool jugada = false;
	int x = p.obtX();
	int y = p.obtY();
	jugada=a_taula[x][y]>='0' and a_taula[x][y]<='8';
	return jugada;
}

bool Tauler::MarquesBombes(Tauler bombes) {
	bool res = true;
	int i = 0;
	int j = 0;
	while(res and i<a_mida){
		j=i;
		while(res and j<a_mida){
			res = (a_taula[i][j] != 'm' and !bombes.ConsultaMarca(Posicio(i,j))) or (a_taula[i][j] == 'm' and bombes.ConsultaMarca(Posicio(i,j)));
			j++;
		}
		i++;
	}
	return res;
}

