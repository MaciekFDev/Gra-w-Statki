#include <iostream>
#include <ctime>
#include <windows.h>
#include "gracz.h"
#include <iomanip>

#define ROZMIAR_X 10
#define ROZMIAR_Y 10
#define GESTOSC 44

using namespace std;

Gracz::Gracz()
{
    Moja_mapa=new int *[ROZMIAR_Y];

    for (int i=0; i<ROZMIAR_X; i++)
    {
        Moja_mapa[i]=new int [ROZMIAR_X];
    }

    for (int i=0; i<ROZMIAR_Y; i++)
    {
        for (int j=0; j<ROZMIAR_X; j++)
        {
            Moja_mapa[i][j]=5;
        }
    }

    Mapa_przeciwnika=new int *[ROZMIAR_Y];

    for (int i=0; i<ROZMIAR_X; i++)
    {
        Mapa_przeciwnika[i]=new int [ROZMIAR_X];
    }

    for (int i=0; i<ROZMIAR_Y; i++)
    {
        for (int j=0; j<ROZMIAR_X; j++)
        {
            Mapa_przeciwnika[i][j]=8;
        }
    }

    imie="SI";
    koniecGry=false;
}

// Metody wspolne dla czlowieka i SI
// Mapa wyswietlana jest na zasadzie kolorowania poszczegolnych pol tablicy w zaleznosci od ich wartosci,
// czyli rodzaju statku. Dostepne sa 4 rodzaje statkow o wielkosci 3 oraz 2 rodzaje statkow o wielkosci 5.
// Kazdy graczz ma dwa modele z kazdego rodzaju statkow, jednak sa one zawsze ustawione wzgledem siebie prostopadle.
// Pozostale wartosci tablicy reprezentuja wode oraz nieodkryta jeszcze czesc mapy.
void Gracz::wyswietl_mapy()
{
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );

    cout<<"Przeglad pola bitwy"<<endl;
    cout<<endl<<endl<<"Twoje statki"<<endl;
    for (int i=0; i<ROZMIAR_Y; i++)
    {
        cout<<endl;
        for (int j=0; j<ROZMIAR_X; j++)
        {
            // Woda
            if (Moja_mapa[i][j]==5)
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | BACKGROUND_BLUE );
                cout<<Moja_mapa[i][j]<<" ";
            }

            // Mgla wojny
            else if (Moja_mapa[i][j]==0)
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED | BACKGROUND_BLUE
                                                                                | BACKGROUND_RED );
                cout<<Moja_mapa[i][j]<<" ";
            }

            else if (Moja_mapa[i][j]==1)
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | BACKGROUND_GREEN );
                cout<<Moja_mapa[i][j]<<" ";
            }

            else if (Moja_mapa[i][j]==2)
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED | BACKGROUND_BLUE
                                   | BACKGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY );
                cout<<Moja_mapa[i][j]<<" ";
            }

            else if (Moja_mapa[i][j]==3)
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | BACKGROUND_GREEN
                                         | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY );
                cout<<Moja_mapa[i][j]<<" ";
            }

            else if (Moja_mapa[i][j]==6)
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_RED | BACKGROUND_RED | FOREGROUND_GREEN
                                                                               | BACKGROUND_GREEN );
                cout<<Moja_mapa[i][j]<<" ";
            }

            else if (Moja_mapa[i][j]==7)
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_RED | BACKGROUND_RED | FOREGROUND_GREEN
                                | BACKGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY );
                cout<<Moja_mapa[i][j]<<" ";
            }

            else if (Moja_mapa[i][j]==4)
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_RED | BACKGROUND_RED | FOREGROUND_INTENSITY
                                                                                | BACKGROUND_INTENSITY );
                cout<<Moja_mapa[i][j]<<" ";
            }
        }
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    }

    cout<<endl<<endl<<"Statki przeciwnika"<<endl;
    for (int i=0; i<ROZMIAR_Y; i++)
    {
        cout<<endl;
        for (int j=0; j<ROZMIAR_X; j++)
        {
            if (Mapa_przeciwnika[i][j]==5)
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | BACKGROUND_BLUE );
                cout<<Mapa_przeciwnika[i][j]<<" ";
            }

            else if (Mapa_przeciwnika[i][j]==0)
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED | BACKGROUND_BLUE
                                                                                | BACKGROUND_RED );
                cout<<Mapa_przeciwnika[i][j]<<" ";
            }

            else if (Mapa_przeciwnika[i][j]==1)
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | BACKGROUND_GREEN );
                cout<<Mapa_przeciwnika[i][j]<<" ";
            }

            else if (Mapa_przeciwnika[i][j]==2)
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_RED | BACKGROUND_BLUE
                                   | BACKGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY );
                cout<<Mapa_przeciwnika[i][j]<<" ";
            }

            else if (Mapa_przeciwnika[i][j]==3)
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | BACKGROUND_GREEN
                                         | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY );
                cout<<Mapa_przeciwnika[i][j]<<" ";
            }

            else if (Mapa_przeciwnika[i][j]==6)
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_RED | BACKGROUND_RED | FOREGROUND_GREEN
                                                                               | BACKGROUND_GREEN );
                cout<<Mapa_przeciwnika[i][j]<<" ";
            }

            else if (Mapa_przeciwnika[i][j]==7)
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_RED | BACKGROUND_RED | FOREGROUND_GREEN
                                | BACKGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY );
                cout<<Mapa_przeciwnika[i][j]<<" ";
            }

            else if (Mapa_przeciwnika[i][j]==4)
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_RED | BACKGROUND_RED | FOREGROUND_INTENSITY
                                                                            | BACKGROUND_INTENSITY );
                cout<<Mapa_przeciwnika[i][j]<<" ";
            }


            // Mgla wojny
            else if (Mapa_przeciwnika[i][j]==8)
            {
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED
                                                | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED );
                cout<<Mapa_przeciwnika[i][j]<<" ";
            }
        }
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    }
    cout<<endl<<endl;
}

void Gracz::ustaw_statki_automatycznie()
{
    int i=0;
    int a,b;

    // Ustawianie statkow o wielkosci 3 poziomo
    while (i<4)
    {
        while (1)
        {
            a=rand()%ROZMIAR_X;
            b=rand()%ROZMIAR_Y;

            if (b>=2 && b<=ROZMIAR_X-2) break;
        }

        if (Moja_mapa[a][b]==5 && Moja_mapa[a][b+1]==5 && Moja_mapa[a][b-1]==5)
        {
            Moja_mapa[a][b]=i;
            Moja_mapa[a][b+1]=i;
            Moja_mapa[a][b-1]=i;

            i++;
        }
    }

    // Ustawianie statkow o wielkosci 3 pionowo
    i=0;
    while (i<4)
    {
        while (1)
        {
            a=rand()%ROZMIAR_X;
            b=rand()%ROZMIAR_Y;

            if (a>=2 && a<=ROZMIAR_Y-2) break;
        }

        if (Moja_mapa[a][b]==5 && Moja_mapa[a+1][b]==5 && Moja_mapa[a-1][b]==5)
        {
            Moja_mapa[a][b]=i;
            Moja_mapa[a+1][b]=i;
            Moja_mapa[a-1][b]=i;

            i++;
        }
    }

    // Ustawianie statkow o wielkosci 5 poziomo
    i=6;
    while (i<8)
    {
        while (1)
        {
            a=rand()%ROZMIAR_X;
            b=rand()%ROZMIAR_Y;

            if (b>=3 && b<=ROZMIAR_X-3) break;
        }

        if (Moja_mapa[a][b]==5 && Moja_mapa[a][b+1]==5 && Moja_mapa[a][b+2]==5 && Moja_mapa[a][b-1]==5 && Moja_mapa[a][b-2]==5)
        {
            Moja_mapa[a][b]=i;
            Moja_mapa[a][b+1]=i;
            Moja_mapa[a][b+2]=i;
            Moja_mapa[a][b-1]=i;
            Moja_mapa[a][b-2]=i;

            i++;
        }
    }

    // Ustawianie statkow o wielkosci 5 pionowo
    i=6;
    while (i<8)
    {
        while (1)
        {
            a=rand()%ROZMIAR_X;
            b=rand()%ROZMIAR_Y;

            if (a>=3 && a<=ROZMIAR_Y-3) break;
        }

        if (Moja_mapa[a][b]==5 && Moja_mapa[a+1][b]==5 && Moja_mapa[a+2][b]==5 && Moja_mapa[a-1][b]==5 && Moja_mapa[a-2][b]==5)
        {
            Moja_mapa[a][b]=i;
            Moja_mapa[a+1][b]=i;
            Moja_mapa[a+2][b]=i;
            Moja_mapa[a-1][b]=i;
            Moja_mapa[a-2][b]=i;

            i++;
        }
    }
    i=0;
}

void Gracz::ustaw_statki_recznie()
{
    int i=0;
    int a,b;

    // Ustawianie statkow wielkosci 3 poziomo
    while(i<4)
    {
        while (1)
        {
            cout<<"Podaj wspolrzedne spelniajace nastepujacy warunek: "<<endl;
            cout<<"Y>=1 i Y<=9"<<endl;
            cout<<"Na ktorych nie ma jeszcze statkow"<<endl;
            cout<<"Podaj wspolrzedna X"<<endl; cin>>a;
            cout<<"Podaj wspolrzedna Y"<<endl; cin>>b;

            if (b>=2 && b<=8) break;

            else cout<<"Podano zle wspolrzedne"<<endl;
        }

        if (Moja_mapa[a][b]==0 && Moja_mapa[a][b+1]==0 && Moja_mapa[a][b-1]==0)
        {
            Moja_mapa[a][b]=1;
            Moja_mapa[a][b+1]=1;
            Moja_mapa[a][b-1]=1;

            i++;
        }

        else cout<<"Podano wspolrzedne, na ktorych znajduja sie juz statki"<<endl;
    }

    // Ustawianie statkow wielkosci 3 pionowo
    i=0;
    while (i<4)
    {
        while (1)
        {
            cout<<"Podaj wspolrzedne spelniajace nastepujacy warunek: "<<endl;
            cout<<"X>=1 i X<=9"<<endl;
            cout<<"Na ktorych nie ma jeszcze statkow"<<endl;
            cout<<"Podaj wspolrzedna X"<<endl; cin>>a;
            cout<<"Podaj wspolrzedna Y"<<endl; cin>>b;

            if (a>=2 && a<=8) break;

            else cout<<"Podano zle wspolrzedne"<<endl;
        }

        if (Moja_mapa[a][b]!=1 || Moja_mapa[a+1][b]!=1 || Moja_mapa[a-1][b]!=1)
        {
            Moja_mapa[a][b]=1;
            Moja_mapa[a+1][b]=1;
            Moja_mapa[a-1][b]=1;

            i++;
        }

        else cout<<"Podano wspolrzedne, na ktorych znajduja sie juz statki"<<endl;
    }

    // Ustawianie statkow wielkosci 5 poziomo
    i=0;
    while (i<2)
    {
        while (1)
        {
            cout<<"Podaj wspolrzedne spelniajace nastepujacy warunek: "<<endl;
            cout<<"Y>=2 i Y<=8"<<endl;
            cout<<"Na ktorych nie ma jeszcze statkow"<<endl;
            cout<<"Podaj wspolrzedna X"<<endl; cin>>a;
            cout<<"Podaj wspolrzedna Y"<<endl; cin>>b;

            if (b>=3 && b<=7) break;

            else cout<<"Podano zle wspolrzedne"<<endl;
        }

        if (Moja_mapa[a][b]==0 && Moja_mapa[a][b+1]==0 && Moja_mapa[a][b+2]==0 && Moja_mapa[a][b-1]==0 && Moja_mapa[a][b-2]==0)
        {
            Moja_mapa[a][b]=1;
            Moja_mapa[a][b+1]=1;
            Moja_mapa[a][b+2]=1;
            Moja_mapa[a][b-1]=1;
            Moja_mapa[a][b-2]=1;

            i++;
        }

        else cout<<"Podano wspolrzedne, na ktorych znajduja sie juz statki"<<endl;
    }

    // Ustawianie statkow wielkosci 5 pionowo
    i=0;
    while (i<2)
    {
        while (1)
        {
            cout<<"Podaj wspolrzedne spelniajace nastepujacy warunek: "<<endl;
            cout<<"X>=2 i X<=8"<<endl;
            cout<<"Na ktorych nie ma jeszcze statkow"<<endl;
            cout<<"Podaj wspolrzedna X"<<endl; cin>>a;
            cout<<"Podaj wspolrzedna Y"<<endl; cin>>b;

            if (a>=3 && a<=7) break;

            else cout<<"Podano zle wspolrzedne"<<endl;
        }

        if (Moja_mapa[a][b]!=1 || Moja_mapa[a+1][b]!=1 || Moja_mapa[a+2][b]!=1 || Moja_mapa[a-1][b]!=1 || Moja_mapa[a-2][b]!=1)
        {
            Moja_mapa[a][b]=1;
            Moja_mapa[a+1][b]=1;
            Moja_mapa[a+2][b]=1;
            Moja_mapa[a-1][b]=1;
            Moja_mapa[a-2][b]=1;

            i++;
        }

        else cout<<"Podano wspolrzedne, na ktorych znajduja sie juz statki"<<endl;
    }
}

bool Gracz::czy_wszystko_zatopione()
{
    for (int i=0; i<ROZMIAR_X; i++)
    {
        for (int j=0; j<ROZMIAR_Y; j++)
        {
            if (Moja_mapa[i][j]==0)
            {
                return false;
            }

            else if (Moja_mapa[i][j]==1)
            {
                return false;
            }

            else if (Moja_mapa[i][j]==2)
            {
                return false;
            }

            else if (Moja_mapa[i][j]==3)
            {
                return false;
            }

            else if (Moja_mapa[i][j]==6)
            {
                return false;
            }

            else if (Moja_mapa[i][j]==7)
            {
                return false;
            }
        }
    }

    return true;
}

void Gracz::losuj_wspolrzedne(Wspolrzedne &Do_strzalu)
{
    while (1)
    {
        Do_strzalu.x=rand()%ROZMIAR_X;
        Do_strzalu.y=rand()%ROZMIAR_Y;

        if (Mapa_przeciwnika[Do_strzalu.y][Do_strzalu.x]==8) break;
    }
}

void Gracz::zapisz_wspolrzedne(Wspolrzedne &Do_zapisania, Wspolrzedne Do_strzalu)
{
    Do_zapisania.x=Do_strzalu.x;
    Do_zapisania.y=Do_strzalu.y;
}

void Gracz::usun_zapisane_wspolrzedne(Wspolrzedne &Do_zapisania)
{
    Do_zapisania.x=-1;
    Do_zapisania.y=-1;
}

void Gracz::wyswietl_info_trafiony (Wspolrzedne Do_strzalu)
{
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );

    cout<<endl<<"Ruch gracza: "<<imie<<endl;
    cout<<"Trafiono w cel. Wspolrzedne: "<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_INTENSITY| FOREGROUND_RED );
    cout<<" X: "<<Do_strzalu.x<<" Y: "<<Do_strzalu.y<<endl;
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
    cout<<" _________"<<endl<<endl;
}

void Gracz::wyswietl_info_nietrafiony (Wspolrzedne Do_strzalu)
{
    cout<<endl<<"Ruch gracza: "<<imie<<endl;
    cout<<"Pudlo. Wspolrzedne: "<<endl;
    cout<<" X: "<<Do_strzalu.x<<" Y: "<<Do_strzalu.y<<endl;
    cout<<" _________"<<endl<<endl;
}





































