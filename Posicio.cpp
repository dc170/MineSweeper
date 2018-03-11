#include <cstdlib>
#include "Posicio.h"



unsigned Posicio::a_llavor = 1;

Posicio::Posicio(){
	a_f = 0;
	a_c = 0;
}

Posicio::Posicio(int x, int y) {
	a_f = x;
	a_c = y;
}

void Posicio::iniLlavor(int llavor) {
    a_llavor = abs(llavor);
    if (a_llavor == 0)
        a_llavor++;
}



void Posicio::aleatoria(int max) {
    a_llavor = a_llavor * 1103515245 + 12345;
    a_f = (a_llavor/32) % 32768;
    a_f = a_f % max;

    a_llavor = a_llavor * 1103515245 + 12345;
    a_c = (a_llavor/32) % 32768;
    a_c = a_c % max;


}



int Posicio::obtX() {
	return a_f;
}

int Posicio::obtY() {
	return a_c;
}


bool Posicio::Correcte(int max){
	bool pos = false;
	pos = a_f >= 0 and a_f <max and a_c >= 0 and a_c <max;
	return pos;
}
ostream & operator<<(ostream &o, Posicio p) {
	o << "("<< p.obtX() << "," << p.obtY()<<")";
	return o;
}

istream & operator>>(istream &i, Posicio &p){
//Pre: es pot llegir d’i
//Post: p conté les coordenades llegides des d’i
double x, y;
i >> x >> y; p = Posicio(x,y);
return i;
}

//Pre: --
//Post: retorna el natural suma de l’objecte actual i n
Posicio Posicio::operator+(const Posicio &f) const {
return Posicio(a_f+f.a_f,a_c+f.a_c);
}


Posicio Posicio::operator*(const Posicio &f) const {
	return Posicio(a_f*f.a_f,a_c*f.a_c);
}

Posicio Posicio::operator-(const Posicio &f) const {
	return Posicio(a_f-f.a_f,a_c-f.a_c);
}

Posicio Posicio::operator/(const Posicio &f) const {
	return Posicio(a_f/f.a_f,a_c/f.a_c);
}
