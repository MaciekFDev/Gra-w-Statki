#ifndef GRA_H
#define GRA_H

#include "gracz.h"

using namespace std;

class Gra
{
public:

    Gracz Human;
    Gracz SI;

    void wyswietl_menu();
    void wyswietl_pomoc();
    void wyswietl_info();
    bool strzal_Human (Wspolrzedne Do_strzalu);
    bool strzal_SI (Wspolrzedne Do_strzalu);
};

    Wspolrzedne wyznacz_wspolrzedne_poziom_plus (Wspolrzedne Zapisane, int &licznik);
    Wspolrzedne wyznacz_wspolrzedne_poziom_minus (Wspolrzedne Zapisane, int &licznik);
    Wspolrzedne wyznacz_wspolrzedne_pion_plus (Wspolrzedne Zapisane, int &licznik);
    Wspolrzedne wyznacz_wspolrzedne_pion_minus (Wspolrzedne Zapisane, int &licznik);

#endif // GRA_H
