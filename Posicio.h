#ifndef POSICIO_H
#define POSICIO_H


#include <iostream>

using namespace std;

class Posicio
{
    public:


        Posicio();
        Posicio(int f, int c);

        void aleatoria(int max);
        void static iniLlavor(int llavor);

        bool Correcte(int max);
        int obtX();
        int obtY();

        Posicio operator+(const Posicio &n) const;
        Posicio operator-(const Posicio &n) const;
        Posicio operator*(const Posicio &n) const;
        Posicio operator/(const Posicio &n) const;

    protected:
    private:
        int a_f, a_c;

        static unsigned a_llavor;

};
ostream &operator<<(ostream &o, Posicio p);
istream &operator>>(istream &i, Posicio &p);
#endif
