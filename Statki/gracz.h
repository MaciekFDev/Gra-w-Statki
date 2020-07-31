#ifndef GRACZ_H
#define GRACZ_H

using namespace std;

struct Wspolrzedne
{
    int x;
    int y;
};

class Gracz
{
public:

    string imie;
    bool koniecGry;
    int **Moja_mapa;
    int **Mapa_przeciwnika;

    Gracz();
    void wyswietl_mapy();
    void ustaw_statki_automatycznie();
    void ustaw_statki_recznie();
    void wyswietl_info_trafiony(Wspolrzedne Do_strzalu);
    void wyswietl_info_nietrafiony(Wspolrzedne Do_strzalu);
    void losuj_wspolrzedne (Wspolrzedne &Do_strzalu);
    bool czy_wszystko_zatopione ();
    void zapisz_wspolrzedne (Wspolrzedne &Do_zapisania, Wspolrzedne Do_strzalu);
    void usun_zapisane_wspolrzedne (Wspolrzedne &Do_zapisania);
};

#endif // GRACZ_H
