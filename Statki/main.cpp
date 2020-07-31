#include <iostream>
#include <cstdlib>
#include "Gracz.h"
#include "Gra.h"
#include <windows.h>
#include <ctime>

using namespace std;

int main()
{
    Gra Nowa_gra;
    bool trafiony;
    char menu, decyzja;
    string tekst;
    int licznik, i;

    Wspolrzedne Do_strzalu;
    Wspolrzedne Do_zapisania;

    // Funkcje wyznaczaj¹ce nastêpne cele dla SI w przypadku trafienia
    Wspolrzedne (*wsk[4])(Wspolrzedne, int&);
    wsk[0]=&wyznacz_wspolrzedne_poziom_plus;
    wsk[1]=&wyznacz_wspolrzedne_poziom_minus;
    wsk[2]=&wyznacz_wspolrzedne_pion_plus;
    wsk[3]=&wyznacz_wspolrzedne_pion_minus;

    srand(time(NULL));

    Nowa_gra.wyswietl_info();
    Nowa_gra.wyswietl_pomoc();
    Nowa_gra.wyswietl_menu();
    while (menu!='q')
    {
        cout<<endl<<endl<<"--> ";
        cin>>menu;

        switch(menu)
        {
        case 'q':
            cout<<"Zamykanie programu"<<endl;
            exit(0);
            break;

        case 'm':
            Nowa_gra.wyswietl_info();
            Nowa_gra.wyswietl_pomoc();
            Nowa_gra.wyswietl_menu();
            break;

        case 'w':
            Nowa_gra.Human.wyswietl_mapy();
            break;

            //Inicjalizacja gry - zapisanie imienia gracza oraz rozstawienie statków na mapie
        case 'n':
            Nowa_gra.SI.imie="SI";
            cout<<"Podaj swoje imie: "; cin>>tekst;
            Nowa_gra.Human.imie=tekst;

            /*cout<<"Ustawic Twoje statki automatycznie? (y-tak, n-nie)"<<endl;
            cin>>decyzja;

            if (decyzja=='y')
            {
                Nowa_gra.Human.ustaw_statki_automatycznie();
            }

            else if (decyzja=='n')
            {
                Nowa_gra.Human.ustaw_statki_recznie();
            }*/

            Nowa_gra.Human.ustaw_statki_automatycznie();
            Nowa_gra.SI.ustaw_statki_automatycznie();
            cout<<"Ustawiono wszystkie statki, nacisnij r, aby rozpocz¹æ rozgrywke"<<endl;
            break;

            //Rozpoczêcie rozgrywki po inicjalizacji gry.
        case 'r':
            licznik=1; i=0;
            Nowa_gra.SI.usun_zapisane_wspolrzedne(Do_zapisania);

            while (Nowa_gra.SI.koniecGry!=true || Nowa_gra.Human.koniecGry!=true)
            {
                // Ruch czlowieka
                while (1)
                {
                    cout<<"____________"<<endl;
                    cout<<"Twoj ruch: "<<endl;
                    cout<<"Podaj wspolrzedna X: "; cin>>Do_strzalu.x;

                    if (Do_strzalu.x==-1)
                    {
                        Nowa_gra.wyswietl_pomoc();
                        cout<<"____________"<<endl;
                        cout<<"Twoj ruch: "<<endl;
                        cout<<"Podaj wspolrzedna X: "; cin>>Do_strzalu.x;
                    }

                    else if (Do_strzalu.x==-2) break;

                    cout<<"Podaj wspolrzedna Y: "; cin>>Do_strzalu.y;
                    cout<<endl;
                    trafiony=Nowa_gra.strzal_Human(Do_strzalu);

                    if (trafiony==true)
                    {
                        Nowa_gra.Human.wyswietl_info_trafiony(Do_strzalu);
                        Nowa_gra.Human.wyswietl_mapy();
                        Sleep(1000);
                    }

                    else if (trafiony==false)
                    {
                        Nowa_gra.Human.wyswietl_info_nietrafiony(Do_strzalu);
                        break;
                    }
                }

                Nowa_gra.SI.koniecGry=Nowa_gra.SI.czy_wszystko_zatopione();

                if (Nowa_gra.SI.koniecGry==true) break;

                if (Do_strzalu.x==-2) break;

                // Ruch SI
                while(1)
                {
                    // Przypadek, gdy SI nie trafila w cel w poprzedniej turze
                    if (Do_zapisania.x==-1 || Do_zapisania.y==-1)
                    {
                        Nowa_gra.SI.losuj_wspolrzedne(Do_strzalu);
                        trafiony=Nowa_gra.strzal_SI(Do_strzalu);

                        if (trafiony==true)
                        {
                            Nowa_gra.SI.zapisz_wspolrzedne(Do_zapisania, Do_strzalu);
                            Nowa_gra.SI.wyswietl_info_trafiony(Do_strzalu);
                            Nowa_gra.Human.wyswietl_mapy();
                            Sleep(1000);
                        }

                        else if (trafiony==false)
                        {
                            Nowa_gra.SI.wyswietl_info_nietrafiony(Do_strzalu);
                            break;
                        }
                    }

                    // Przypadek, gdy SI trafila w cel w poprzedniej turze
                    else if (Do_zapisania.x!=-1 && Do_zapisania.y!=-1)
                    {
                        // Jezeli sa dostepne jeszcze kierunki do ataku
                        if (i<4)
                        {
                            // Sprawdzanie czy nowo obrany cel nie znajdzie sie poza mapa
                            try
                            {
                                Do_strzalu=wsk[i](Do_zapisania, licznik);
                                trafiony=Nowa_gra.strzal_SI(Do_strzalu);
                            }
                            // Jezeli tak, nastepuje przejscie do nastepnej funkcji, z ta sama konfiguracja
                            catch (string wyjatek)
                            {
                                i++; licznik=1;
                            }

                            if (trafiony==true)
                            {
                                Nowa_gra.SI.wyswietl_info_trafiony(Do_strzalu);
                                Nowa_gra.Human.wyswietl_mapy();
                                Sleep(1000);
                            }

                            // W przypadku nietrafienia tura SI konczy sie
                            else if (trafiony==false)
                            {
                                i++; licznik=1;
                                Nowa_gra.SI.wyswietl_info_nietrafiony(Do_strzalu);
                                break;
                            }

                            // Obsluga algorytmu przy krawedziach mapy
                            if (Do_strzalu.x==9 && i==0 || i==4)
                            {
                                if (i==4)
                                {
                                    i=0; licznik++;
                                }

                                else if (i==0)
                                {
                                    i++; licznik=1;
                                }
                            }

                            else if (Do_strzalu.x==0 && i==1 || i==4)
                            {
                                if (i==4)
                                {
                                    i=0; licznik++;
                                }

                                else if (i==1)
                                {
                                    i++; licznik=1;
                                }
                            }

                            else if (Do_strzalu.y==9 && i==2 || i==4)
                            {
                                if (i==4)
                                {
                                    i=0; licznik++;
                                }

                                else if (i==2)
                                {
                                    i++; licznik=1;
                                }
                            }

                            else if (Do_strzalu.y==0 && i==3 || i==4)
                            {
                                if (i==4)
                                {
                                    i=0; licznik++;
                                }

                                else if (i==3)
                                {
                                    i++; licznik=1;
                                }
                            }
                        }

                        // Po przejsciu we wszystkich kierunkach SI przestaje kontynuowac te strategie
                        // oraz na nowo obiera punkt ataku
                        else if (i>=4)
                        {
                            Nowa_gra.SI.usun_zapisane_wspolrzedne(Do_zapisania);
                            i=0; licznik=1;
                        }
                    }
                }

                Nowa_gra.Human.koniecGry=Nowa_gra.Human.czy_wszystko_zatopione();
                Nowa_gra.Human.wyswietl_mapy();

                if (Nowa_gra.Human.koniecGry==true) break;
            }
            cout<<"Koniec gry!"<<endl;

            if (Nowa_gra.SI.koniecGry==true)
            {
                cout<<"Wygral gracz: "<<Nowa_gra.SI.imie<<endl;
                cout<<"Moze innym razem :("<<endl;
            }

            else if (Nowa_gra.Human.koniecGry==true)
            {
                cout<<"Wygral gracz: "<<Nowa_gra.Human.imie<<endl;
                cout<<"Gratulacje! ;)"<<endl;
            }

            else
            {
                cout<<"Zatrzymano gre"<<endl;
            }
            break;

        default:
            cout<<"Wybrano zla opcje"<<endl<<endl;
            Nowa_gra.wyswietl_menu();
            break;
        }
    }

    return 0;
}
