#include <iostream>
#include "Gra.h"
#include "gracz.h"
#include <iomanip>
#include <windows.h>

using namespace std;

void Gra::wyswietl_menu()
{
    cout<<endl<<"MENU"<<endl<<endl;
    cout<<" q - wyjscie z gry"<<endl;
    cout<<" m - wyswietl menu gry"<<endl;
    cout<<" n - inicjalizuj gre"<<endl;
    cout<<" r - rozpocznij rozgrywke"<<endl;
    cout<<" w - wyswietl swoje mapy"<<endl;
}

void Gra::wyswietl_pomoc()
{
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );

    cout<<endl<<"POMOC "<<endl<<endl;
    SetConsoleTextAttribute( hOut, BACKGROUND_BLUE );
    cout<<"Kolor pola bez statku"<<endl;
    SetConsoleTextAttribute( hOut, BACKGROUND_RED );
    cout<<"Kolor pola ze zniszczonym statkiem"<<endl;
    SetConsoleTextAttribute( hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | FOREGROUND_BLUE );
    cout<<"Kolor nieodkrytego pola"<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cout<<"Pola ze statkami sa kolorowe, inne niz wymienione powyzej"<<endl;
}

void Gra::wyswietl_info()
{
    cout<<endl<<"INFORMACJE"<<endl<<endl;
    cout<<" Aby przygotowac gre wybierz opcje 'n'."<<endl;
    cout<<" Aby rozpoczac rozgrywke wybierz opcje 'r'."<<endl;
    cout<<" Po rozpoczeciu gry menu bedzie dostepne menu pomocy."<<endl;
    cout<<" Aby je otworzyc nalezy podczas podawania wspolrzednej X wpisac -1."<<endl;
    cout<<" Aby wyjsc z rozpoczetej gry nalezy podczas podawania wspolrzednej X wpisac -2."<<endl;
}

bool Gra::strzal_Human (Wspolrzedne Do_strzalu)
{
    if (SI.Moja_mapa[Do_strzalu.y][Do_strzalu.x]==5)
    {
        Human.Mapa_przeciwnika[Do_strzalu.y][Do_strzalu.x]=5;

        return false;
    }

    else if (SI.Moja_mapa[Do_strzalu.y][Do_strzalu.x]==0)
    {
        Human.Mapa_przeciwnika[Do_strzalu.y][Do_strzalu.x]=4;
        SI.Moja_mapa[Do_strzalu.y][Do_strzalu.x]=4;

        return true;
    }

    else if (SI.Moja_mapa[Do_strzalu.y][Do_strzalu.x]==1)
    {
        Human.Mapa_przeciwnika[Do_strzalu.y][Do_strzalu.x]=4;
        SI.Moja_mapa[Do_strzalu.y][Do_strzalu.x]=4;

        return true;
    }

    else if (SI.Moja_mapa[Do_strzalu.y][Do_strzalu.x]==2)
    {
        Human.Mapa_przeciwnika[Do_strzalu.y][Do_strzalu.x]=4;
        SI.Moja_mapa[Do_strzalu.y][Do_strzalu.x]=4;

        return true;
    }

    else if (SI.Moja_mapa[Do_strzalu.y][Do_strzalu.x]==3)
    {
        Human.Mapa_przeciwnika[Do_strzalu.y][Do_strzalu.x]=4;
        SI.Moja_mapa[Do_strzalu.y][Do_strzalu.x]=4;

        return true;
    }

    else if (SI.Moja_mapa[Do_strzalu.y][Do_strzalu.x]==6)
    {
        Human.Mapa_przeciwnika[Do_strzalu.y][Do_strzalu.x]=4;
        SI.Moja_mapa[Do_strzalu.y][Do_strzalu.x]=4;

        return true;
    }

    else if (SI.Moja_mapa[Do_strzalu.y][Do_strzalu.x]==7)
    {
        Human.Mapa_przeciwnika[Do_strzalu.y][Do_strzalu.x]=4;
        SI.Moja_mapa[Do_strzalu.y][Do_strzalu.x]=4;

        return true;
    }
}

bool Gra::strzal_SI(Wspolrzedne Do_strzalu)
{
    if (Human.Moja_mapa[Do_strzalu.y][Do_strzalu.x]==5)
    {
        SI.Mapa_przeciwnika[Do_strzalu.y][Do_strzalu.x]=5;

        return false;
    }

    else if (Human.Moja_mapa[Do_strzalu.y][Do_strzalu.x]==0)
    {
        SI.Mapa_przeciwnika[Do_strzalu.y][Do_strzalu.x]=4;
        Human.Moja_mapa[Do_strzalu.y][Do_strzalu.x]=4;

        return true;
    }

        else if (Human.Moja_mapa[Do_strzalu.y][Do_strzalu.x]==1)
    {
        SI.Mapa_przeciwnika[Do_strzalu.y][Do_strzalu.x]=4;
        Human.Moja_mapa[Do_strzalu.y][Do_strzalu.x]=4;

        return true;
    }

        else if (Human.Moja_mapa[Do_strzalu.y][Do_strzalu.x]==2)
    {
        SI.Mapa_przeciwnika[Do_strzalu.y][Do_strzalu.x]=4;
        Human.Moja_mapa[Do_strzalu.y][Do_strzalu.x]=4;

        return true;
    }

    else if (Human.Moja_mapa[Do_strzalu.y][Do_strzalu.x]==3)
    {
        SI.Mapa_przeciwnika[Do_strzalu.y][Do_strzalu.x]=4;
        Human.Moja_mapa[Do_strzalu.y][Do_strzalu.x]=4;

        return true;
    }

    else if (Human.Moja_mapa[Do_strzalu.y][Do_strzalu.x]==6)
    {
        SI.Mapa_przeciwnika[Do_strzalu.y][Do_strzalu.x]=4;
        Human.Moja_mapa[Do_strzalu.y][Do_strzalu.x]=4;

        return true;
    }

    else if (Human.Moja_mapa[Do_strzalu.y][Do_strzalu.x]==7)
    {
        SI.Mapa_przeciwnika[Do_strzalu.y][Do_strzalu.x]=4;
        Human.Moja_mapa[Do_strzalu.y][Do_strzalu.x]=4;

        return true;
    }
}

Wspolrzedne wyznacz_wspolrzedne_poziom_plus(Wspolrzedne Zapisane, int &licznik)
{
    if (Zapisane.x==9)
    {
        string wyjatek="KoniecZakresu";
        throw wyjatek;
    }

    else
    {
        Wspolrzedne Nowe;

        Nowe.x=Zapisane.x+licznik;
        Nowe.y=Zapisane.y;
        licznik++;

        return Nowe;
    }
}

Wspolrzedne wyznacz_wspolrzedne_poziom_minus(Wspolrzedne Zapisane, int &licznik)
{
    if (Zapisane.x==0)
    {
        string wyjatek="KoniecZakresu";
        throw wyjatek;
    }

    else
    {
        Wspolrzedne Nowe;

        Nowe.x=Zapisane.x-licznik;
        Nowe.y=Zapisane.y;
        licznik++;

        return Nowe;
    }
}

Wspolrzedne wyznacz_wspolrzedne_pion_plus(Wspolrzedne Zapisane, int &licznik)
{
    if (Zapisane.y==9)
    {
        string wyjatek="KoniecZakresu";
        throw wyjatek;
    }

    else
    {
        Wspolrzedne Nowe;

        Nowe.y=Zapisane.y+licznik;
        Nowe.x=Zapisane.x;
        licznik++;

        return Nowe;
    }
}

Wspolrzedne wyznacz_wspolrzedne_pion_minus(Wspolrzedne Zapisane, int &licznik)
{
    if (Zapisane.y==0)
    {
        string wyjatek="KoniecZakresu";
        throw wyjatek;
    }

    else
    {
        Wspolrzedne Nowe;

        Nowe.y=Zapisane.y-licznik;
        Nowe.x=Zapisane.x;
        licznik++;

        return Nowe;
    }
}































