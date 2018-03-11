/*
 * cuacomprador.h
 *
 *  Created on: 10/4/2015
 *      Author: pau
 */

#ifndef CUACOMPRADOR_H_
#define CUACOMPRADOR_H_
#include <string>
#include <iostream>
#include "Posicio.h"
using namespace std;
class CuaPosicions {
// Descripció: una cua de compradors
    public:
    // CONSTRUCTORS I DESTRUCTOR ----------------------------------
    // Pre: --; Post: cua buida
        CuaPosicions();// Pre: --; Post: aquesta cua és còpia de la Cua o
        CuaPosicions(const CuaPosicions & o); // const. de còpia // Pre: --; Post: memòria alliberada
        ~CuaPosicions();
        // CONSULTORS -------------------------------------------------
        // Pre: -- ; Post: retorna cert si la cua és buida; fals en c.c.
        bool buida() const;
        // Pre: cua no buida; Post: retorna còpia del primer comprador de la cua
        Posicio primer() const;
        // MODIFICADORS -----------------------------------------------
        // Pre: --; Post: ha afegit s al final de la cua
        void encua(Posicio s);
        // Pre: cua no buida; Post: ha eliminat el primer element de la cua
        void desencua();
        // OPERADORS REDEFINITS --------------------------------------
        // Pre: -- ; Post: aquesta cua és còpia de o
        CuaPosicions& operator=(const CuaPosicions& o);

    private:
        struct Node{
            Posicio valor;
            Node* seg;
        };
        Node* a_primer; // punter al primer de la cua
        Node* a_darrer; // punter al darrer de la cua

        void allibera();
        void copia(const CuaPosicions& o);
};
#endif /* CUACOMPRADOR_H_ */
