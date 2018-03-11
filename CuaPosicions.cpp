/*
 * cuacomprador.cpp
 *
 *  Created on: 10/4/2015
 *      Author: pau
 */

#include "CuaPosicions.h"
#include <iostream>
#include <string>
#include "Posicio.h"
using namespace std;

// Pre: --; Post: cua buida
// COST: O(1)
CuaPosicions::CuaPosicions(){
    a_primer=a_darrer= NULL;
}
// Pre: --; Post: aquesta cua és còpia de la cua o
// COST: O(n)
CuaPosicions::CuaPosicions(const CuaPosicions& o){
    a_primer=a_darrer= NULL;
    copia(o); // crida a mètode privat
}
// Pre: --; Post: memòria alliberada
// COST: O(n)
CuaPosicions::~CuaPosicions(){
    allibera(); // crida a mètode privat
}

// CONSULTORS
// Pre: -- ; Post: retorna cert si la cua és buida; fals en c.c.
// COST: O(1)
bool CuaPosicions::buida() const{
    return a_primer==NULL;
}
// Pre: cua no buida; Post: retorna còpia del primer de la cua
// COST: O(1)
Posicio CuaPosicions::primer() const{
    return a_primer->valor;
    }

// MODIFICADORS
// Pre: --; Post: ha afegit s al final de la cua
// COST: O(1)
void CuaPosicions::encua(Posicio s){
    Node* nou= new Node;
    nou->valor= s; nou->seg= NULL;
    if (buida()) // this->buida()
        a_primer=a_darrer= nou;
    else {
        a_darrer->seg= nou; a_darrer= nou;
    }
}

// Pre: cua no buida; Post: ha eliminat el primer de la cua
// COST: O(1)
void CuaPosicions::desencua(){
    Node* aux= a_primer;
    if (a_primer==a_darrer)
        // només hi ha un element
        a_primer=a_darrer= NULL;
    else a_primer= a_primer->seg;
    delete aux;
}

// MÈTODES PRIVATS
// Pre: cua buida; Post: aquesta cua és còpia de o
// COST: O(n)
void CuaPosicions::copia(const CuaPosicions& o){
    for (Node* i= o.a_primer; i!=NULL; i=i->seg) // recorrem cua o
        encua(i->valor); // this->encua(i->valor)
    }
// Pre: --; Post: cua buida
// COST: O(n)
void CuaPosicions::allibera(){
    while (a_primer!=NULL){ //!buida()
        Node* aux= a_primer;
        a_primer= a_primer->seg;
        delete aux;
    }
    a_darrer= NULL;
}


// OPERADOR ASSIGNACIÓ
// Pre: -- ; Post: aquesta cua és còpia de o
// COST: O(n)
CuaPosicions& CuaPosicions::operator=(const CuaPosicions& o){
    if (this != &o){
        allibera();
        copia(o);
    }
    return *this;
}

